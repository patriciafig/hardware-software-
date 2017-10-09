
// Patricia Figueroa 
// HW #7: Ultrasonic and LCD 
// Oct. 07, 2017

#include <LiquidCrystal_I2C.h>  

#define trigPin A1 
#define echoPin A2 

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

void setup() {
  // put your setup code here, to run once:
  // initialize serial communication:
  Serial.begin(9600); 
  pinMode (trigPin, OUTPUT);  // configure analog pin 1 as digital output 
  pinMode (echoPin, INPUT);   // configure analog pin 2 as digital input 

  digitalWrite (A1, LOW);  
  lcd.begin(16,2); 
  lcd.backlight(); 

  lcd.setCursor(8,0) // start at character 4 on line 0 
  lcd.print (" Inches "); 

  lcd.setCursor (8,1) 
  lcd.print(" cm ")
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(20); 
  digitalWrite(trigPin, LOW); 


  duration = pulseIn(echoPin, HIGH); 
  distance = (duration * .0066929); 
  lcd.setCursor(0,0);   lcd.print ("     ");  lcd.setCursor(0,0); lcd.print(distance); Serial.println(distance); 

  distance = (duration * .017); 
  lcd.setCursor(0,0);   lcd.print ("     ");  lcd.setCursor(0,0); lcd.print(distance); Serial.println(distance); 
  

  delay (500); 

}










