/*
  Stepper Motor Demonstration 4
  Stepper-Demo4.ino
  Demonstrates NEMA 17 Bipolar Stepper with A4988 Driver
 
  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/
 
// Define Constants

#define ON      49
#define OFF     50
 
// Connections to A4988
const int dirPin = 2;  // Direction
const int stepPin = 3; // Step
 
// Motor steps per rotation
const int STEPS_PER_REV = 200;

// for incoming serial data
int incomingByte = 0;
 
void setup() {
  // setup hardware
  Serial.begin(115200);

  // Setup the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
      // read the incoming byte:
      incomingByte = Serial.read();

      // say what you got:
      Serial.print("I received: ");
      Serial.println(incomingByte, DEC);
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
  delay(1000);
}
