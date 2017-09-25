//Patricia Figueroa 
//Homework 5 
//Using Arduino EEPROM Memory to set a password 


#include <EEPROM.h>

const int switchPin = 2;                            // pin used for the switch    D2
const int addr = 0;                         // start reading from the first byte (address 0) of the EEPROM
const int pass_length = 4;                       // Password Length

String savedPassword = "0000";
String enteredPassword = "0000";
String userAttempt;                                  // User password attempts 
String pwdSaved;                                    // We are going to use this to extract a pwd from the EPROM.
byte value;                                         // Used to check if this is this first time powering up



String get_password(String pwd){
  int index = 0;                                    // used to store the values to our character array
  bool flag = false;                                // used to exit the do while loop
  do{
      if(Serial.available() > 0){                   //  character is available from console?
          pwd[index] = Serial.read();               
          index++;                                 
         }
       if(index >= pass_length){                 
            index = 0;                              // Reset index
            flag = true;                            // Exit loop
              Serial.print("You Entered: ");        
              Serial.println(pwd);
        }
      }
      while (flag == false);
      return pwd;
  }


  void store_pass(String pwd){
    for (int i = addr; i < pass_length; i++){
        EEPROM.write(i, pwd[i]); 
      }
    }
    

//reset 
   void reset_pass(){
        for (int i = addr; i < pass_length; i++){
          EEPROM.write(i, 0);
          Serial.println("Password reset.");
        }
    }
    

    String get_addr(){
          String pwd;                                         
          for(int i = addr; i < pass_length; i++){            
                pwd += ((char)EEPROM.read(i));                

            }
            return pwd;                                       // send back the string
      }


void setup() {
  pinMode(switchPin, INPUT_PULLUP);                           // Switch pin connected to A2
  bool flag = false;                                          // Used to flag exit for the do while loop below 
  
  if (digitalRead(switchPin) == false){                       // if the switch is pressed/held down at start up reset the password
        reset_pass();
    }
    
   Serial.begin(9600);                                        // initialize serial and wait for port to open:
   value = EEPROM.read(addr);                         // Reading the value at our initial Address of 0

  if (value == 0){                                            // If the value read from EEPROM at address 0 is 0 then this is the first power up
    Serial.println("This is the first power up.");
    Serial.println("Hi.Please enter a 4 digit password.");   

    pwdSaved = get_password(enteredPassword);                  // Call function to get password 
    store_pass(pwdSaved);                                   // Save the password to EEPROM
  }     
  do {
        Serial.print("Enter your password..");               // Ask for password               
        
        userAttempt = get_password(savedPassword);                  
        pwdSaved = get_addr();                            

        if ( userAttempt == pwdSaved ){                            // If the two strings we just got are the same End program
            Serial.println("Valid Pasword!");
            flag = true;
          }
          else{
              Serial.println("Wrong answer please try again....");
            }
      
      }while(flag == false);

          Serial.println("Hello There!.");      
         
   }

void loop() {

}
