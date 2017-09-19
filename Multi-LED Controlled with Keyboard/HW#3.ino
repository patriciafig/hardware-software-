/* Patricia Figueroa 
Homework #3
The goal of this assignment is to blink the built in LED on/off for 1 second each at startup and light up multiple LED's
If you enter a ‘+’ on the keyboard: blink twice a fast and if you enter a ‘-’ on the keyboard: blink twice as long */

                           //LED Pins
const int redLight = 5;    
const int yellowLight = 6;
const int whiteLight = 9;
const int blueLight = 10;
const int greenLight = 11;  

const int TotalLights = 5; 

      int blinkRate   = 1000;        // one second for initial blink rate 
const int maximumRate = 125;        // max blink rate
const int minimumRate = 4000;       // min blink rate 

int LightsArray [] = {redLight, yellowLight,whiteLight,blueLight,greenLight} ; 
char Receivebyte;

void setup() {
  Serial.begin(9600);           // set up serial link
  for (int i = 0 ; i < TotalLights ; i++){
         pinMode(LightsArray[i], OUTPUT); // set up the pin with the built in LED as an output pin  
    }
          Serial.println(blinkRate);
  }

void loop() {
  for (int i = 0 ; i < TotalLights ; i++){
   // Serial.println(LightsArray[i]);
    digitalWrite(LightsArray[i], HIGH);
 
    delay(blinkRate);   
    digitalWrite(LightsArray[i], LOW); 
 
    delay(blinkRate);                    // wait one second
 
  }
  
  if (Serial.available() > 0) 
  {
    Receivebyte = Serial.read(); 
    if (Receivebyte == '+' || '-') 
    {
      if (Receivebyte == '+') 
      {
          blinkRate  = blinkRate/2; 
            if (blinkRate  <= 125) 
            {
              blinkRate = 125;
              Serial.println("The Fastest Rate is : ");  
            }
            Serial.println(blinkRate);
      } 
      else {                             
        blinkRate  = blinkRate * 2; 
        if (blinkRate >= 4000) 
        {
          blinkRate = 4000; 
          Serial.println("The Slowest Rate is : ");
          }
          Serial.println(blinkRate);
        }
        
    }
    
  }

} 
 
 
  
