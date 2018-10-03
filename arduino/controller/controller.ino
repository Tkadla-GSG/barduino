#include <../constants.h>

#define ON      49
#define OFF     50
 
// Connections to A4988
const int dirPin = 2;  // Direction
const int stepPin = 3; // Step
 
// Motor steps per rotation
const int STEPS_PER_REV = 200;

String incommingCommand;
 
void setup() {
  // setup hardware
  Serial.begin(115200);

  // Setup the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  while(Serial.available()) {
      // read the incoming byte:
      incommingCommand = Serial.readStringUtil(COMMAND_SEPARATOR);

      // say what you got:
      Serial.print("I received: ");
      Serial.println(incommingCommand);
  }
  
  // Set motor direction clockwise
  //digitalWrite(dirPin,HIGH); 
  
  // Spin motor one rotation slowly
  /*for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2000); 
  }
  
  // Pause for one second
  delay(1000); 
  */
  if (incomingByte == ON) {
    // Set motor direction counterclockwise
    digitalWrite(dirPin,LOW);
    
    // Spin motor two rotations quickly
    for(int x = 0; x < (STEPS_PER_REV * 4); x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(1000);
    }
  }
  
  // Pause for one second
  delay(100);
}
