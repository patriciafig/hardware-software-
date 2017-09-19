//Patricia Figueroa 
//Homework 5 
//Using Arduino EEPROM Memory to set a password 

#include <EEPROM.h>   // EEPROM.h library 

const int switchPin = 2;    //push button 
const int flagAddr = 0;     // first time 
const int notValue = 128;   // value used 
const int passAddr = 1;     

byte value ;                // first byte 
const int passLength = 4;   // 4 character password length  
