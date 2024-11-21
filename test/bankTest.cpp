// Include the string library
#include <string>
#include <iostream>
#include <chrono>
#include <unistd.h>

const int numDigits = 8; // TODO: Change to 2 when running bank tests
const int numPossibleValues = 10;
// const int bankDelay = 300; // TODO: Change to correct bank delay (number of milliseconds to pause)


int main()
{
    
    // Get the current time before your code executes
    auto startTime = std::chrono::high_resolution_clock::now();


    // std::string bankCode = "00000000";
    std::string bankCode = "45891736";
    
    // std::cout<<"Banke Code: " << bankCode<<" \n";

  int password[numDigits];
  for (int i = 0; i < numDigits; i++) {
  password[i] = 0;
    }
  int correctDigits = 0;
  int tries = 0;

  for (int i = 0; i < numDigits; i++) {
    for (int j = 0; j < numPossibleValues; j++) {
      password[i] = j;
    //   std::cout<<"Password: " << "\n";

        // for (int l = 0; l < numDigits; l++) {
        //       std::cout<< password[l];
        // }
      std::string passwordStr = "";
      for (int k = 0; k < numDigits; k++) {
        passwordStr += std::to_string(password[k]);
      }
      passwordStr += "\n";
    //   std::cout<<"\nPassword String: " << passwordStr << "\n";
      tries += 1;
      sleep(1); // sleep 1 second
      //Serial.println(passwordStr); // TODO: maybe need to change how the bank is reading our input
    //   delay(bankDelay); // wait for the Bank to respond
      if (passwordStr[i] == bankCode[i]) {
        std::cout<<"Correct Digit. Tries = " << tries << "\n";
        correctDigits += 1;
        break; // move on to the next digit
      }
      //int response = Serial.parseInt();
    //   if (response > correctDigits) {
    //     std::cout<<"Tries = " << tries;
    //     correctDigits = response;
    //     break; // move on to the next digit
    //   }
        // std::cout<<passwordStr<<"=="<<bankCode<<" ?,\n";

      // password is correct!
      if (passwordStr == bankCode) {
          std::cout<<"\nPassword is correct!";
          std::cout<<"\nTotal Tries = " << tries << "\n";
      }
    }
  }
  
      // Get the current time after your code executes
    auto endTime = std::chrono::high_resolution_clock::now();

    // Calculate the time taken by your code
    auto timeTaken = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();

    // Print the time taken by your code
    printf("Time taken: %ld seconds\n", timeTaken);


  
  return 0;
}
