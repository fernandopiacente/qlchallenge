#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>	// For sleep
#include <atomic>
#include <chrono>
#include <cstring>
#include "mqtt/async_client.h"

using namespace std;

const string DFLT_SERVER_ADDRESS { "test.mosquitto.org:1883" };

const string TOPIC { "qlnetstats" };
const int QOS = 1;

const auto TIMEOUT = std::chrono::seconds(10);

int publish(string address, string pl)
{
	cout << "Initializing for server '" << address << "'..." << endl;
	mqtt::async_client cli(address, "");
	
	char payloads[pl.length()+1];
	strcpy(payloads, pl.c_str());

	try {
		cout << "Connecting..." << endl;
		cli.connect()->wait();

		cout << "Publishing messages..." << endl;

		mqtt::topic top(cli, "qlnetstats", QOS);
		mqtt::token_ptr tok;

		size_t i = 0;
		tok = top.publish(payloads);
		
		tok->wait();	// Just wait for the last one to complete.

		// Disconnect
		cout << "Disconnecting..." << endl;
		cli.disconnect()->wait();
	}
	catch (const mqtt::exception& exc) {
		cerr << exc << endl;
		return 1;
	}

 	return 0;
}

