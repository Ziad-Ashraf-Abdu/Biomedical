#include <LiquidCrystal.h>

#define rs 12
#define E 11
#define d4 5
#define d5 4
#define d6 3
#define d7 2

LiquidCrystal lcd(rs, E, d4, d5, d6, d7); //initiatlizing the pins for the LCD display

// defining pin numbers 
const int trigPin = 7;
const int echoPin = 8;

// defining variables
long duration;
float distanceOne=0, distanceTwo=0, distance=0;
float t1=0, t2=0;
double speed=0;

void setup() 
{
  Serial.begin(9600); 
  lcd.begin(16, 2); 
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}


void loop() 
{

// DISPLAYING DISTANCE ON SERIAL MONITOR AND LCD, RESPECTIVELY:
  
  distanceOne = ultrasonicRead(); 
  Serial.print("Distance = ");
  Serial.print(distanceOne);
  Serial.print(" cm ");
  lcd.setCursor(0,0);
  lcd.print("Distance=");
  lcd.print(distance);
  lcd.print("cm");
   
  _delay_ms(1000);
  
  t1 = millis();
   
  distanceTwo = ultrasonicRead();
  Serial.print("Distance = ");
  Serial.print(distanceTwo);
  Serial.print(" cm ");
  lcd.setCursor(0,0);
  lcd.print("Distance=");
  lcd.print(distance);
  lcd.print("cm");
  
  _delay_ms(1000);
  
  t2 = millis();
  
  //CALCULATING SPEED:
  
  if(abs(distanceTwo-distanceOne)<= 1)
  {
    speed = 0;
  }
  else 
  {
    speed = abs(distanceTwo - distanceOne)/((t2-t1)/1000);
  }
  
  //SPEACIAL THANKS FROM OUR TEAM
 if (distance <= 5){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Best Regards.");
    lcd.setCursor(0, 1);
    lcd.print("Team Shooky.");
    while(ultrasonicRead() <= 5);
  }

  //DISPLAYING SPEED ON SERIAL MONITOR AND LCD, RESPECTIVELY:
   
  Serial.print("Speed = "); 
  Serial.print(speed);
  Serial.print("cm/s");
  lcd.setCursor(0,1); 
  lcd.print("Speed=");
  lcd.print(speed); 
  lcd.print("cm/s");
  _delay_ms(1000);


}


float ultrasonicRead ()
{
  distance=0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  //CALCULATING DISTANCE:
  distance = (duration*0.0343)/2.0;
  return distance;
}