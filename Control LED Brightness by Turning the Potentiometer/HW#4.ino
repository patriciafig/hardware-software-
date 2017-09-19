// Patricia Figueroa 
// Homework #4 

/*

Light all LED’s with an initial PWM duty cycle value of 255 (full on)•Read position of potentiometer (0 –1023)
Convert to new range of 0 –255 (desired PWM duty-cycle)•Blink the first LED (LED[0]) and illuminate with PWM value set by pot
When switch is pushed,store that duty cycle value for the flashing LED•Point to the next LED and flash using duty cycle determined by pot

*/
                       
                       //LED Pins .  //array for the LEDs 
const int redLight = 5;    
const int yellowLight = 6;
const int tealLight = 9;
const int blueLight = 10;
const int greenLight = 11;  

const int TotalLights = 5;   // for array 

      int blinkRate   = 50;        // 1/50 for initial blink rate 
const int maximumRate = 125;        // max blink rate
const int minimumRate = 4000;       // 4000 min blink rate 

int LightsArray [TotalLights] = {redLight, yellowLight,tealLight,blueLight,greenLight};  // 5 LED Lights 
char Receivebyte;

const int switchPin = 2; 
const int potPin = A6; 
      int potValue; 
      int pwdValue;
      int pwdLightValue[] = { 255, 255, 255, 255, 255 } ; // 
      int selectLight = 0;  

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(9600);           // set up serial link
  for (int i = 0 ; i < TotalLights ; i++){
         pinMode(LightsArray[i], OUTPUT); // set up the pin with the built in LED as an output pin  
    }
          Serial.println(blinkRate);
  }

void loop() {
   char Receivebyte;
   
   boolean beginSwitch = digitalRead(switchPin);  // if button is pressed 
if (!beginSwitch) {
  Serial.print ("LED:") ; 
  Serial.println( selectLight +1);
  selectLight++ ;  // move to the next light 
        if (selectLight >= 5) {
          selectLight = 0; //start again 
          
          } 
   }

 potValue = analogRead(potPin); 
 int LightLed = map(potValue, 0, 1023, 0, 255); 
 analogWrite (LightsArray[selectLight], LightLed);
 delay(blinkRate);   
 analogWrite(LightsArray[selectLight], LOW); 
 delay(blinkRate);                    // wait one second
 
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
 
 
  
