Simple Telemetry Sharing

This is a simple implementation of an small C++ that send ICMP packets (ECHO), get some telemetry stats and send it over QMTT protocol to an online public Broker. Aditionally, a small python script subscribe to the broker and format the stats in a table based on JSON.

I'm testing the mqtt comunication with an online public server "test.mosquitto.org" to publish and to ping (get the stats).

Building

It's necessary to install the Paho MQTT library:

mkdir build  
cd build  
cmake ..  
cmake --build .  

Running

1 - Start the python script:  
python3 src/sub.py  
2 - Execute the C++ program (as root due to the use of sockets):  
sudo ./qlchallenge
