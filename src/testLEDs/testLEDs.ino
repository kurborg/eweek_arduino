// Pin Assignments
const int LED0 = 6; // COIN
const int LED1 = 4; // MUSHROOM
const int LED2 = 10; // FIREFLOWER
const int LED3 = 8; // ICEFLOWER
// const int IR_Sense = 2;

const int DELAY = 2000;

void setup() {
  // put your setup code here, to run once:
  // Configure GPIO Pins
  pinMode(LED0,     OUTPUT); // COIN
  pinMode(LED1,     OUTPUT); // MUSHROOM
  pinMode(LED2,     OUTPUT); // FIREFLOWER
  pinMode(LED3,     OUTPUT); // ICEFLOWER
  // pinMode(IR_Sense, INPUT);

  // Enable Serial Monitor at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.println("COIN");
    digitalWrite(LED0, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

    delay(DELAY); // Makes light stay ON for 5 seconds

    Serial.println("MUSHROOM");
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

    delay(DELAY); // Makes light stay ON for 5 seconds

    Serial.println("FIREFLOWER");
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);

    delay(DELAY); // Makes light stay ON for 5 seconds

    Serial.println("ICEFLOWER");
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);

    delay(DELAY); // Makes light stay ON for 5 seconds
}
