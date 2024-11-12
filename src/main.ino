// Room #2: "Mario Party Item Finder"

// Room Task:
// The robot shall navigate the course to reach each item box to decode the item within it, within the time limit
// The robot shall output which item is located within each box as follows (Pulse Widths identified in red):
// Coin (20 ms Pulse Width)
// Mushroom (40 ms Pulse Width)
// Fire Flower (60 ms Pulse Width)
// Ice Flower (80 ms Pulse Width)

// The robot shall complete 3 "loops" around the nearest pipe before continuing to the next box
// The robot shall complete the course as previously state, denote each item, and go to the end location to receive the maximum allowable points of 100
// If the robot is unable to reach the next item without looping around the pipe, 5 points will be deducted for each loop missed
// Challenge Team: Circuit Troubleshooting
// The challenge team shall utilize a multimeter and basic circuit knowledge to troubleshoot an LED breadboard circuit
// The challenge team shall detect the missing or faulty component and complete the circuit to light up the LED
// Points shall be awarded for solving problems of increasing difficulty

const NUM_OBJECTS = 4;

enum OBJECT_TYPE
{
  COIN,     // ID =  0
  MUSHROOM,   //       1
  FIREFLOWER,    //       2
  ICEFLOWER     //       3
};

//  Object Strings
char * names[NUM_OBJECTS] = 
{
  "COIN",
  "MUSHROOM",
  "FIREFLOWER",
  "ICEFLOWER"
};

// IR Pulse Widths of each Object
const int pw[NUM_OBJECTS] =
  {20,40,60,80};

// Pin Assignments
const int LED0 = 6;
const int LED1 = 1;
const int LED2 = 3;
const int LED3 = 4;
const int IR_Sense = 2;

// Helper Variables
volatile unsigned long time_low = 0;
volatile unsigned long time_high = 0;
double duration_ms = 0;

// Detection Tolerance
const int tol = 4;  // 4 millisecond tolerance for detected pulse widths

// ------------------------------------------------------------------------------
// Setup: Arduino code main entry point, runs once on startup.
// ------------------------------------------------------------------------------
void setup()
{
  // Configure GPIO Pins
  pinMode(LED0,     OUTPUT);
  pinMode(LED1,     OUTPUT);
  pinMode(LED2,     OUTPUT);
  pinMode(LED3,     OUTPUT);
  pinMode(IR_Sense, INPUT);

  // Attach interrupt to IR sensor output pin
  attachInterrupt(digitalPinToInterrupt(IR_Sense), getPulseWidth, CHANGE);

  // Enable Serial Monitor at 9600 baud rate
  Serial.begin(9600);
}

// ------------------------------------------------------------------------------
// Arduino code loop, runs infinitely after setup function completes.
// ------------------------------------------------------------------------------
void loop()
{
  // Check if a new pulse has been received
  if((time_low != 0) && (time_high != 0) && (time_high > time_low))
  {
    // Calculate duration of pulse, and reset pulse flags
    duration_ms = time_high - time_low;
    time_low = 0;
    time_high = 0;
  }

  // 1 - COIN
  if((duration_ms >= (pw[COIN] - tol)) && (duration_ms <= (pw[COIN] + tol)))
  {
    Serial.println("COIN - 10ms");
    digitalWrite(LED0, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }

  // 2 - MUSHROOM
  if((duration_ms >= (pw[MUSHROOM] - tol)) && (duration_ms <= (pw[MUSHROOM] + tol)))
  {
    Serial.println("MUSHROOM - 20ms");
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }

  // 3 - FIREFLOWER
  if((duration_ms >= (pw[FIREFLOWER] - tol)) && (duration_ms <= (pw[FIREFLOWER] + tol)))
  {
    Serial.println("FIREFLOWER - 30ms");
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
  }

  // 4 - ICEFLOWER
  if((duration_ms >= (pw[ICEFLOWER] - tol)) && (duration_ms <= (pw[ICEFLOWER] + tol)))
  {
    Serial.println("ICEFLOWER - 40ms");
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
  }
}

// ------------------------------------------------------------------------------
// getPulseWidth: Interrupt function called when IR Sensor Output signal changes
// ------------------------------------------------------------------------------
void getPulseWidth()
{
  if(digitalRead(IR_Sense))  // IR Sensor Signal is high
  {
    // Capture rise time of IR Sensor Output
    time_high = millis();
  }
  else  // IR Sensor signal is low
  {
    // Capture fall time of IR Sensor Output
    time_low = millis();
  }
}
