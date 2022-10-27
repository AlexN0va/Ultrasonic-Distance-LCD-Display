#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel. Long data type
int distanceCm; // variable for the distance measurement in centemeters. Integer data type
int distanceIn; // variable for the distance measurement in Inches. Integer data type
int detectionVar; // variable to determine how far sensor will detect. integer data type


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
}

void loop() {

  // Turn on the display:
  lcd.display();
  delay(500);
  
  // Clears the trigPin condition for 2 seconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  
  distanceCm = duration * 0.034 / 2; // Speed of sound wave divided by 2 in CENTEMETERS (go and back)
  distanceIn = duration * 0.0133 / 2; //speed of sound wave divded by two in INCHES(go and back)

  if (distanceCm <= 40){
      // Displays the distance on the Serial Monitor
     lcd.clear();
     delay(500);

     lcd.print("distance: ");
     lcd.print(distanceCm);
     lcd.print("cm");

  }
  else{
    lcd.clear();
    delay(500);

    Serial.println("Not detected");
    lcd.print("Not detected");
    }
    delay(1000); //delay time for second
}
  
