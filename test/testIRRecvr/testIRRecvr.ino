#include <IRremote.h>

const int RECV_PIN = 2;
const int IR_Sense = 2;


void setup(){

  // IRrecv irrecv(RECV_PIN);
  pinMode(IR_Sense, INPUT);

  // decode_results results;
  Serial.begin(9600);
  // irrecv.enableIRIn();
  // irrecv.blink13(true);
}

void loop(){
  Serial.println(digitalRead(IR_Sense));

  delay(1000);

  // if (irrecv.decode(&results)){
  //       Serial.println(results.value, HEX);
  //       irrecv.resume();
  // }
}