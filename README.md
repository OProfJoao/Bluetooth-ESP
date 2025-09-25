# ESP32 Bluetooth Serial Communication

This repository contains two example programs for bidirectional communication between two ESP32 devices using Bluetooth Serial. One ESP32 acts as a **server**, and the other acts as a **client**. These examples demonstrate how to send and receive messages over Bluetooth between the two devices.

## Features

- **Server**: The ESP32 server advertises itself as `ESP32_server` and listens for incoming connections from a client.
- **Client**: The ESP32 client connects to the server (`ESP32_server`) and exchanges messages.
- **Bidirectional Communication**: Messages sent from one device are received by the other and displayed on the Serial Monitor.
- **Debugging**: All messages are logged to the Serial Monitor for easy debugging.

## Files

- **`BluetoothServer.cpp`**: Code for the ESP32 acting as the Bluetooth server.
- **`BluetoothClient.cpp`**: Code for the ESP32 acting as the Bluetooth client.

## Requirements

- Two ESP32 development boards with Bluetooth capability.
- Arduino IDE or PlatformIO for uploading the code.
- A Bluetooth Serial terminal app (optional, for testing).

## Setup

1. **Hardware**:
   - Connect two ESP32 boards to your computer via USB.

2. **Software**:
   - Install the [Arduino IDE](https://www.arduino.cc/en/software) or PlatformIO.
   - Install the required ESP32 board package in the Arduino IDE.

3. **Upload Code**:
   - Open `BluetoothServer.cpp` in the Arduino IDE and upload it to the first ESP32.
   - Open `BluetoothClient.cpp` in the Arduino IDE and upload it to the second ESP32.

4. **Pairing**:
   - The client will automatically attempt to connect to the server (`ESP32_server`).
   - Ensure the server is powered on and ready to pair.

## Usage

1. Open the Serial Monitor for both ESP32 devices (set the baud rate to `115200`).
2. Send a message from the Serial Monitor of one device.
3. Observe the message being received on the other device's Serial Monitor.
4. Messages can be sent in both directions.

## Example Output

### Server

```cpp Bluetooth Device is Ready to Pair 
Received over Bluetooth: Hello from Client 
Sent over Bluetooth: Hello from Server```

### Client

```cpp Bluetooth Device is Ready to Pair 
Connected to ESP32_server 
Sent over Bluetooth: Hello from Client 
Received over Bluetooth: Hello from Server```


## Notes

- The client will attempt to reconnect to the server if the connection is lost.
- Ensure that the server is powered on before the client attempts to connect.
- You can modify the device names (`ESP32_server` and `ESP32_client`) in the code as needed.

## Author

João Bornelli  
Date: September 25, 2025