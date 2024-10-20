#include <QTRSensors.h>

#include <Arduino.h>


// create an object for four QTR-xRC sensors on digital pins 0 and 9, and on analog
// inputs 1 and 3 (which are being used as digital inputs 15 and 17 in this case)
QTRSensorsRC qtrrc((unsigned char[]) {0, 9, 15, 17}, 4);

const int sensorPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

enum Position {
  LEFT,
  RIGHT,
  CENTER
};

enum Speed {
  SLOW,
  MEDIUM, 
  FAST
};

void setLeftMotorSpeed(Speed speed) {
  // Implement your logic to control the left motor's speed
}
void setRightMotorSpeed(Speed speed) {
  // Implement your logic to control the right motor's speed
}

Position determinePosition(int sensorValues) {
  // Implement your logic here to determine the position based on the sensor values
  // For example, you might check if the leftmost or rightmost sensors are activated
  // to determine if the robot is too far left or too far right.
}

int readSensors() {
  int sensorValues = 0;
  for (int i = 0; i < 8; i++) {
    sensorValues |= digitalRead(sensorPins[i]) << i;
  }
  return sensorValues;
}

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(sensorPins[i], INPUT);
  }
}

void loop() {
  int sensorValues = readSensors();
  int position = determinePosition(sensorValues);

  // Adjust motor speeds based on the position
  if (position == LEFT) {
    setLeftMotorSpeed(SLOW);
    setRightMotorSpeed(FAST);
  } else if (position == RIGHT) {
    setLeftMotorSpeed(FAST);
    setRightMotorSpeed(SLOW);
  } else {
    setLeftMotorSpeed(MEDIUM);
    setRightMotorSpeed(MEDIUM);
  }
}

//////////////////////////////////////////////////////////////////

// PSEUDO CODE for basic PID implementation

// double Kp = 0.5; 
// double Ki = 0.1;
// double Kd = 0.2;

// double error = 0;
// double previousError = 0;
// double integral = 0;
// double derivative = 0;
// double pidOutput = 0;

// void loop() {
//   // ... (rest of your code)

//   // Calculate PID output
//   error = desiredPosition - position;
//   integral += error;
//   derivative = (error - previousError);
//   pidOutput = Kp * error + Ki * integral + Kd * derivative;

//   // Adjust motor speeds
//   setLeftMotorSpeed(baseSpeed + pidOutput);
//   setRightMotorSpeed(baseSpeed - pidOutput);

//   // Update previous error
//   previousError = error;
// }
