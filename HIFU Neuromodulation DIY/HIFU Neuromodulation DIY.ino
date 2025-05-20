#define TrigPin 2
#define EchoPin 3
#define photodiodePin A0


void setup() {
  pinMode(photodiodePin, INPUT);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(9600); // Initialize serial communication
}


void loop() {
  // Read analog value from photodiode
  int sensorValue = analogRead(photodiodePin);
  
  int frequency = analogRead(TrigPin);


  PORTD &= B11111011;     // Clear D2 (low)
  Anas(sensorValue);  // Custom assembly delay function with sensor value
  PORTD |= B00000100;     // Set D2 (high)
  Anas(sensorValue);  // Custom assembly delay function with senor value


  Serial.print("Sensor: ");
  Serial.println(sensorValue);
  Serial.print("Delay: ");
  Serial.println(sensorValue);
  Serial.print("Frequency: ");
  Serial.println(frequency);

delay(1000);
}

void Anas(int sensorValue) {
  // Customized assembly code for delay
  asm volatile(
    "1:  dec %0        \n"  // Decrement delayValue
    "    brne 1b       \n"  // Branch back if delayValue is not zero
    : "+r"(sensorValue)      // Output operand (delayValue), "+" indicates that it's read and written
  );
}
