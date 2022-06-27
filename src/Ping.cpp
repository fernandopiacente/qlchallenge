#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <cstring>
#include <sstream>

// define the packet constants
#define PING_PKT_S 32           /* ping packet size */
#define PORT_NO 0               /* automatic port number */
#define PING_SLEEP_RATE 1000000 /*  ping sleep rate */
#define RECIEVE_TIMEOUT 1       /*  timeout delay for receiving packets in secs  */

// define the Ping Loop to maintain infinite pinging
int pingLoop = 1;

using namespace std;

// ping packet structure
struct ping_pkt
{
    struct icmphdr hdr;
    char message[PING_PKT_S - sizeof(icmphdr)];
};

// calculate the check sum
unsigned short checksum(void *buffer, int length)
{
    unsigned short *buff = (unsigned short *)buffer;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; length > 1; length -= 2)
        sum += *buff++;

    if (length == 1)
        sum += *(unsigned char *)buff;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// interrupt handler
void interruptHandler(int var)
{
    pingLoop = 0;
}

// perform DNS lookup
char *dns_lookup(char *addr_host, struct sockaddr_in *addr_con)
{
    struct hostent *host_entity;
    char *ip = (char *)malloc(NI_MAXHOST * sizeof(char));

    // no IP found for hostname
    if ((host_entity = gethostbyname(addr_host)) == NULL)
    {
        return NULL;
    }

    // fill up address structure
    strcpy(ip, inet_ntoa(*(struct in_addr *)host_entity->h_addr));

    (*addr_con).sin_family = host_entity->h_addrtype;
    (*addr_con).sin_port = htons(PORT_NO);
    (*addr_con).sin_addr.s_addr = *(long *)host_entity->h_addr;

    return ip;
}

// Resolve the reverse lookup of the hostname
char *reverse_dns_lookup(char *ip_address)
{
    struct sockaddr_in temp_address;
    socklen_t len;
    char buf[NI_MAXHOST], *ret_buf;

    temp_address.sin_family = AF_INET;
    temp_address.sin_addr.s_addr = inet_addr(ip_address);
    len = sizeof(struct sockaddr_in);

    if (getnameinfo((struct sockaddr *)&temp_address,
                    len,
                    buf,
                    sizeof(buf),
                    NULL,
                    0,
                    NI_NAMEREQD))
    {
        cout << "\nCould not resolve reverse lookup of hostname.\n";
        return NULL;
    }

    ret_buf = (char *)malloc((strlen(buf) + 1) * sizeof(char));
    strcpy(ret_buf, buf);
    return ret_buf;
}

// make a ping Request
string send_ping(int ping_sockfd,
               struct sockaddr_in *ping_addr,
               char *ping_dom,
               char *ping_ip,
               char *rev_host)
{
    unsigned int
        ttl_val = 64,
        msg_count = 0,
        i,
        addr_len,
        flag = 1,
        msg_received_count = 0,
        packet_loss = 0;

    struct ping_pkt pckt;
    struct sockaddr_in r_addr;
    struct timespec
        time_start,
        time_end,
        tfs,
        tfe;
    long double rtt_msec = 0, total_msec = 0, max_rtt = 0, min_rtt = 0, avg_rtt = 0, last_rtt = 0, jitter = 0;
    struct timeval tv_out;
    tv_out.tv_sec = RECIEVE_TIMEOUT;
    tv_out.tv_usec = 0;

    clock_gettime(CLOCK_MONOTONIC, &tfs);

    // set socket options at ip to TTL and value to 64,
    // change to what you want by setting ttl_val
    if (setsockopt(ping_sockfd,
                   IPPROTO_IP,
                   IP_TTL,
                   &ttl_val,
                   sizeof(ttl_val)) != 0)
    {

        return "\nSetting socket options to TTL failed!\n";
        
    }

    // set timeout of recieve setting
    setsockopt(ping_sockfd,
               SOL_SOCKET,
               SO_RCVTIMEO,
               (const char *)&tv_out,
               sizeof(tv_out));

    // sennd the number of desired icmp packets in an loop
    while (msg_count < 10)
    {
        // flag is whether packet was sent or not
        flag = 1;

        // fill the packet randomly
        bzero(&pckt, sizeof(pckt));

        pckt.hdr.type = ICMP_ECHO;
        pckt.hdr.un.echo.id = getpid();

        for (i = 0; i < sizeof(pckt.message) - 1; i++)
            pckt.message[i] = i + '0';

        pckt.message[i] = 0;
        pckt.hdr.un.echo.sequence = msg_count++;
        pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));

        // usleep(PING_SLEEP_RATE);

        // send packet
        clock_gettime(CLOCK_MONOTONIC, &time_start);
        if (sendto(ping_sockfd,
                   &pckt,
                   sizeof(pckt),
                   0,
                   (struct sockaddr *)ping_addr,
                   sizeof(*ping_addr)) <= 0)
        {
            cout << "\nPacket Sending Failed!\n";
            flag = 0;
        }

        // receive packet
        addr_len = sizeof(r_addr);

        if (recvfrom(ping_sockfd,
                     &pckt,
                     sizeof(pckt),
                     0,
                     (struct sockaddr *)&r_addr,
                     &addr_len) <= 0 &&
            msg_count > 1)
        {
            cout << "\nPacket receive failed!\n";
        }
        else
        {
            clock_gettime(CLOCK_MONOTONIC, &time_end);
            double timeElapsed =
                ((double)(time_end.tv_nsec - time_start.tv_nsec) / 1000000.0);
            rtt_msec = (time_end.tv_sec - time_start.tv_sec) * 1000.0 + timeElapsed;

            // if packet was not sent, don't receive
            if (flag)
            {
                if (!(pckt.hdr.type == 69 && pckt.hdr.code == 0))
                {
                    cout << "Error...Packet received with ICMP type " << pckt.hdr.type
                         << " code " << to_string(pckt.hdr.code) << endl;
                }
                else
                {
                    /*cout << "\nPinging " << ping_dom << " [" << ping_ip << "] with "
                         << PING_PKT_S << " bytes of data:\n";
                    cout << "icmp_seq=" << msg_count
                         << " TTL=" << ttl_val
                         << " RTT=" << rtt_msec << " ms.\n";*/
                    msg_received_count++;

                    // get max and min rtt
                    if (rtt_msec > max_rtt)
                        max_rtt = rtt_msec;
                    if (min_rtt == 0)
                        min_rtt = rtt_msec;
                    if (rtt_msec < min_rtt)
                        min_rtt = rtt_msec;

                    avg_rtt += rtt_msec; // sum rtts for average
                    jitter += rtt_msec - last_rtt; // set the jitter "buffer"
                    last_rtt = rtt_msec;
                }
            }
        }
    }

    avg_rtt = avg_rtt / 10; // average for 10 packets
    jitter = jitter / 9;
    packet_loss = ((msg_count - msg_received_count) / msg_count) * 100.0 ;
    
    stringstream stats;
    stats << "\"Packet loss\": " << packet_loss << ","
         << "\"Jitter\": " << jitter << ","
         << "\"Min\": " << min_rtt << ","
         << "\"Avg_rtt\": " << avg_rtt << ","
         << "\"Max\": " << max_rtt << ",";                                                             
    
    return stats.str();
}

string sendPing(string addr, int reps)
{
    // convert string to array of char due to "dns_lookup()"
    char address[addr.length()+1];
    strcpy(address, addr.c_str());
    
    int sockfd; /* socket file descriptor */
    char *ip_addr, *reverse_hostname;
    struct sockaddr_in addr_con;
    int addrlen = sizeof(addr_con);
    char net_buf[NI_MAXHOST];

    ip_addr = dns_lookup(address, &addr_con);
    if (ip_addr == NULL)
    {
        cout << "\nDNS lookup failed! Could not resolve hostname.\n";
        return 0;
    }

    cout << "\nTrying to connect to " << address << "'s IP: " << ip_addr << endl;

    // socket
    if (getuid())
        sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    else
        sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1)
    {
        cout << "\nSocket file descriptor not received!\n";
        cerr << '\n'
             << "\nSocket error: " << strerror(errno) << endl;
        return 0;
    }

    // catch interrupt
    signal(SIGINT, interruptHandler);

    // send pings and return the stats
    return send_ping(sockfd,
              &addr_con,
              reverse_hostname,
              ip_addr,
              address);
}