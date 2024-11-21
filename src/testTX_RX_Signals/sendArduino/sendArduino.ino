#include <SoftwareSerial.h>

// Define the TX and RX pins
const int txPin = 12;
const int rxPin = 13;

// Create a SoftwareSerial object
SoftwareSerial pinSerial(txPin, rxPin);

void setup() {

  pinSerial.begin(9600);

  // // Initialize serial communication at 9600 baudrate
  // Serial.begin(9600);
}

void loop() {
  // Send a simple message to Arduino 2
  pinSerial.println("Hello from Arduino 1!");
  
  // Wait for a second before sending the next message
  delay(1000);
}
