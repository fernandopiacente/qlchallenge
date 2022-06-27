# qlchallenge

I'm testing the mqtt comunication with an online public server "test.mosquitto.org".

Building

It's necessary to install the Paho MQTT library.

mkdir build
cd build
cmake ..
cmake --build .

Running

1 - Start the python script:
python3 src/sub.py
2 - Execute the C++ program (as root due to the use of sockets):
sudo ./qlchallenge
