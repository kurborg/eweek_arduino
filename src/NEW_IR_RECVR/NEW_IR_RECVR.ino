// Define the IR receiver sensor pin
const int irReceiverPin = 2;  // Replace with your actual pin

// Define the LED pins for each frequency
const int led20HzPin = 6; // COIN
const int led40HzPin = 4; // MUSHROOM
const int led60HzPin = 10; // FIREFLOWER
const int led80HzPin = 9; // ICEFLOWER

// Define the tolerance for each frequency
const int tolerance = 5;

void setup() {
  // Initialize the IR receiver sensor pin as an input
  pinMode(irReceiverPin, INPUT);

  // Initialize the LED pins as outputs
  pinMode(led20HzPin, OUTPUT);
  pinMode(led40HzPin, OUTPUT);
  pinMode(led60HzPin, OUTPUT);
  pinMode(led80HzPin, OUTPUT);
}

void loop() {
  // Read the IR receiver sensor value
  int irValue = pulseIn(irReceiverPin, HIGH); // TODO may need to use LOW here
  // int irValue = pulseIn(irReceiverPin, LOW);

  // Convert the IR value to frequency
  int frequency = 1000000 / irValue;  // Calculate the frequency in Hz

  // Create conditionals based on the frequency reading
  if (isWithinTolerance(frequency, 20, tolerance)) {
    digitalWrite(led20HzPin, HIGH);  // Turn on the 20Hz LED
    digitalWrite(led40HzPin, LOW);
    digitalWrite(led60HzPin, LOW);
    digitalWrite(led80HzPin, LOW);
  } else if (isWithinTolerance(frequency, 40, tolerance)) {
    digitalWrite(led20HzPin, LOW);
    digitalWrite(led40HzPin, HIGH);  // Turn on the 40Hz LED
    digitalWrite(led60HzPin, LOW);
    digitalWrite(led80HzPin, LOW);
  } else if (isWithinTolerance(frequency, 60, tolerance)) {
    digitalWrite(led20HzPin, LOW);
    digitalWrite(led40HzPin, LOW);
    digitalWrite(led60HzPin, HIGH);  // Turn on the 60Hz LED
    digitalWrite(led80HzPin, LOW);
  } else if (isWithinTolerance(frequency, 80, tolerance)) {
    digitalWrite(led20HzPin, LOW);
    digitalWrite(led40HzPin, LOW);
    digitalWrite(led60HzPin, LOW);
    digitalWrite(led80HzPin, HIGH);  // Turn on the 80Hz LED
  }

  delay(50);  // Add a small delay to avoid flickering
}

// Function to check if a value is within a tolerance range
bool isWithinTolerance(int value, int target, int tolerance) {
  return (value >= target - tolerance && value <= target + tolerance);
}
