#HW 9 – External Interrupt Service Routine

-------- 

- Using push-button switch connected to D2 (INT0)
- Create ISR (Interrupt Service Routing) called switchPushed()
- Have that ISR toggle a Boolean variable every time it executes
- Have main loop() routine continuously print (with a small delay) the value of the Boolean toggle variable
- Each time you press the switch, the Boolean variable should toggle
- Remove “switch bounce” by having a millis() driven routine reset a flag every 250ms and the interrupt routine will immediately exit if the flag is set
