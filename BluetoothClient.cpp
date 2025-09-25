/**
 * @file ESP32 Bluetooth Serial Client
 * @brief Basic Bluetooth Serial communication server for ESP32
 *
 * This code sets up an ESP32 as a Bluetooth Serial client that can receive and send
 * messages from/to paired Bluetooth devices. The device advertises itself as
 * "ESP32_client" and forwards any received Bluetooth messages to the Serial
 * monitor for debugging purposes.
 *
 * @author João Bornelli
 * @version 1.0
 * @date 25/09/2025
 *
 * Hardware Requirements:
 * - ESP32 development board with Bluetooth capability
 *
 * Functionality:
 * - Initializes Bluetooth Serial with device name "ESP32_client"
 * - Continuously listens for incoming Bluetooth messages
 * - Prints received messages to Serial monitor at 115200 baud rate
 *
 * Usage:
 * 1. Upload code to ESP32
 * 2. Pair with the "ESP32_server" Bluetooth device
 * 3. Send messages via Bluetooth Serial terminal app
 * 4. Monitor received messages on Serial console
 */

#include <BluetoothSerial.h>

BluetoothSerial SerialBT;


void setup() {
    Serial.begin(115200);
    SerialBT.begin("ESP32_client"); // Bluetooth device name
    Serial.println("Bluetooth Device is Ready to Pair");

    SerialBT.connect("ESP32_server"); // Connect to the server device
    if (SerialBT.connected()) {
        Serial.println("Connected to ESP32_server");
    }
    else {
        Serial.println("Failed to connect. Make sure the server is available.");
    }
}

void loop() {
    if (Serial.available() > 0) {
        String message = Serial.readStringUntil('\n');
        if (message.length() > 0) {
            SerialBT.println(message); // Send message over Bluetooth
            Serial.print("Sent over Bluetooth: ");
            Serial.println(message);
        }
    }
    if (SerialBT.available()) {
        String message = SerialBT.readString();
        Serial.print("Received over Bluetooth: ");
        Serial.println(message);
    }
}