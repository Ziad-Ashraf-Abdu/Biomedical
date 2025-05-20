#include <LiquidCrystal.h>

// Initialize the LCD connected to pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define the LED and photodiode pin
const int ledPin = 9;          
const int photoDiodePin = A0;  

/*// Function to calculate glucose concentration from sensor voltage
float calculateGlucoseConcentration(float sensorVoltage) {
  float glucoseConcentration = (sensorVoltage/ 1023);
  // Ensure the concentration is within the expected range
  return glucoseConcentration;
}*/

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Turn on the LED to the maximum safe brightness
  analogWrite(ledPin, 255);

  // Start the serial communication
  Serial.begin(9600);
}

void loop() {


  // Read the sensor voltage
  float sensorVoltage = analogRead(photoDiodePin);

  // Calculate the glucose concentration
  float glucoseConcentration = sensorVoltage;

  // Determine the patient status based on glucose concentration
  String status;
  if (glucoseConcentration >= 49) {
    status = "No sample";
    //lcd.setRGB(0, 255, 0); // Set LCD color to green for normal status
  } else if (glucoseConcentration >= 36.667 && glucoseConcentration < 49) {
    status = "prediabetes";
    //lcd.setRGB(255, 255, 0); // Set LCD color to yellow for prediabetes status
  } else if (glucoseConcentration > 36.667 && glucoseConcentration <= 10) {
    status = "Diabetic";
    //lcd.setRGB(255, 165, 0); // Set LCD color to orange for diabetic status
  } else if (glucoseConcentration < 10) {
    status = "Severe Diabetes";
    //lcd.setRGB(255, 0, 0); // Set LCD color to red for severe diabetes status
  }

lcd.clear();

  // Display the glucose level on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Glucose Conc.:");
  lcd.print(glucoseConcentration); // Print glucose concentration with one decimal point
  lcd.print(" %");

  // Display the status on the LCD
  lcd.setCursor(0, 1);
  lcd.print(status);

  Serial.println(sensorVoltage);
  Serial.println(glucoseConcentration);
  Serial.println(status);

  // Wait for a bit before taking the next reading
  delay(2000);
}