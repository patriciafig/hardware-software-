//HW # 2 Control Blinking LED with Keyboard
//Blink the built in LED on/off for 1 second each at startup
//If you enter a ‘+’ on the keyboard:
//Blink twice a fast (e.g. 500ms, 250ms...) to a max of 125ms
//Each time speed is changed, print new speed in mson monitor
//When you reach the max speed, print “max speed” followed by speed
//If you enter a ‘-’ on the keyboard:•Blink twice as long (e.g. 1000ms, 2000ms ...) to a max of 4000ms
//Each time speed is changed, print new speed in mson monitor•When you reach the slowest speed, print “lowest speed” followed by speed




      int blinkRate   = 1000;               // one second for initial blink rate 
const int maximumRate = 125;        // max blink rate
const int minimumRate = 4000;       // min blink rate 


void setup() {
  Serial.begin(9600);           // set up serial link
  pinMode(LED_BUILTIN, OUTPUT); // set up the pin with the built in LED as an output pin
  Serial.println(blinkRate);
}

void loop() {
  // put your main code here, to run repeatedly:
char Receivebyte; 
  digitalWrite(LED_BUILTIN, HIGH);        // light LED
  delay(blinkRate);                      // wait one second
  digitalWrite(LED_BUILTIN, LOW);       // turn off LED
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
      else {                               // - 
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
