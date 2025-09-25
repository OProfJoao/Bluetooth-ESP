/**
 * @file ESP32 Bluetooth Serial Server
 * @brief Basic Bluetooth Serial communication server for ESP32
 *
 * This code sets up an ESP32 as a Bluetooth Serial server that can receive and send
 * messages from/to paired Bluetooth devices. The device advertises itself as
 * "ESP32_server" and forwards any received Bluetooth messages to the Serial
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
 * - Initializes Bluetooth Serial with device name "ESP32_server"
 * - Continuously listens for incoming Bluetooth messages
 * - Prints received messages to Serial monitor at 115200 baud rate
 *
 * Usage:
 * 1. Upload code to ESP32
 * 2. Wait some device to connect to the "ESP32_server" Bluetooth device
 * 3. Send messages via Bluetooth Serial terminal app
 * 4. Monitor received messages on Serial console
 */


#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
    Serial.begin(115200);
    SerialBT.begin("ESP32_server"); // Bluetooth device name
    Serial.println("Bluetooth Device is Ready to Pair");
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