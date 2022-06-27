#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "Ping.cpp"
#include "Pub.cpp"

using namespace std;

const string ADDRESS = "test.mosquitto.org";
const int NUMBER_OF_PCKTS = 10;

int main()
{
    string stats, payload, container_name = "\"container name...\"";

    stats = sendPing(ADDRESS, NUMBER_OF_PCKTS);    
    cout << endl << "ICMP stats: " << endl << stats << endl;
    stringstream ss;
    ss << "{" << stats << "\"Device\": " << container_name << "}";
    payload = ss.str();
    publish(ADDRESS, payload);

    return 0;
}
