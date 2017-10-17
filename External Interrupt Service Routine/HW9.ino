
// Patricia Figueroa 
// HW #9: External Interrupt Service  
// Oct. 14, 2017


#define INTERRUPT true;

const    int     pushButtonSwitch = 2;                          // switch is on pin D2, declare as constant

unsigned long lastTime = millis();
unsigned debounceTime = 250;
bool enableIntFlag = true;
volatile bool toggleFlag = false;

//  ------------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pushButtonSwitch, INPUT_PULLUP);                                      // D2 INPUT mode and attach a PULLUP resistor
  
#ifdef INTERRUPT
    attachInterrupt(digitalPinToInterrupt(pushButtonSwitch), switchPushed, FALLING);  // attach an interrupt on int0 and call switchPushed() when triggered
    Serial.println("Interrupts enabled");
#else
    Serial.println("Interrupts are NOT ENABLED");
#endif
  
  Serial.print("Digital pin 2 maps to interrupt number: ");     Serial.println(digitalPinToInterrupt(pushButtonSwitch));
  Serial.print("Digital pin 3 maps to interrupt number: ");     Serial.println(digitalPinToInterrupt(3));
  delay(1000);
}

//  ------------------------------------------------------------------------------------
void loop() {
  debounce();
 #ifndef INTERRUPT
    if(!digitalRead(pushButtonSwitch) && enableIntFlag) {
      toggleFlag = !toggleFlag;
    }
#endif
// Serial.print("loop: printing toggleFlag: "); Serial.println(toggleFlag);
// delay(5000);

}

// ---------------------------------------------------------------------------
void switchPushed() {   // ISR
  if(!enableIntFlag){
 //   Serial.println("switchPushed but enableIntFlag not set");
    return;
  }
  else {
//    Serial.println("switchPushed and enableIntFlag IS SET");
    toggleFlag = !toggleFlag;
    Serial.println(toggleFlag);
    digitalWrite(LED_BUILTIN, toggleFlag);
    lastTime = millis();
    enableIntFlag = false;
  }
}
// ---------------------------------------------------------------------------
void debounce() {
  if(millis() - lastTime > debounceTime) {
     enableIntFlag = true;
     lastTime = millis();
  }
}
 


}

void loop() {
  // put your main code here, to run repeatedly:
  debounce(); 
#ifndef INTERRUPT 


}
