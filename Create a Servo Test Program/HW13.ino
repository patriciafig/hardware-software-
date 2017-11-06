
// Patricia Figueroa 
// HW#13: Create a Servo Test Program
// October 30, 2017 

#include <Servo.h>  // servo library 

int SERVO_PIN = 9; // Pin D9 

Servo servo;  
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  servo.attach(SERVO_PIN); 
} 
 
void loop() 
{ 
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  } 
} 
