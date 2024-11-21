#include <SoftwareSerial.h>

// Define the TX and RX pins
const int txPin = 13;
const int rxPin = 12;

// Create a SoftwareSerial object
SoftwareSerial pinSerial(txPin, rxPin);

void setup() {

  pinSerial.begin(9600);

  // Initialize serial communication at 9600 baudrate
  Serial.begin(9600);
}

void loop() {
  // Check if data is available to read
  if (pinSerial.available() > 0) {
    // Read the incoming byte and print it
    String received = pinSerial.readString();  // Read the entire line
    Serial.print("Received: ");
    Serial.println(received);
  }
}
