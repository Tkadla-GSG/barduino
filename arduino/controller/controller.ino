#include <Arduino.h>

#include "SerialCommand.h"
#include "AccelStepper.h"

#define COMMAND_BREW              "brew_"
#define COMMAND_MOTOR_OFF         "off_"
#define COMMAND_MOTOR_ON_LOAD     "load_"
#define COMMAND_MOTOR_ON_UNLOAD   "unload_"

#define BREW_1            COMMAND_BREW "1"
#define BREW_2            COMMAND_BREW "2"
#define BREW_3            COMMAND_BREW "3"
#define BREW_4            COMMAND_BREW "4"
#define BREW_5            COMMAND_BREW "5"
#define BREW_6            COMMAND_BREW "6"

#define MOTOR_1_OFF       COMMAND_MOTOR_OFF "1"
#define MOTOR_2_OFF       COMMAND_MOTOR_OFF "2"
#define MOTOR_3_OFF       COMMAND_MOTOR_OFF "3"
#define MOTOR_4_OFF       COMMAND_MOTOR_OFF "4"
#define MOTOR_5_OFF       COMMAND_MOTOR_OFF "5"
#define MOTOR_6_OFF       COMMAND_MOTOR_OFF "6"

#define MOTOR_1_ON_LOAD   COMMAND_MOTOR_ON_LOAD "1"
#define MOTOR_2_ON_LOAD   COMMAND_MOTOR_ON_LOAD "2"
#define MOTOR_3_ON_LOAD   COMMAND_MOTOR_ON_LOAD "3"
#define MOTOR_4_ON_LOAD   COMMAND_MOTOR_ON_LOAD "4"
#define MOTOR_5_ON_LOAD   COMMAND_MOTOR_ON_LOAD "5"
#define MOTOR_6_ON_LOAD   COMMAND_MOTOR_ON_LOAD "6"

#define MOTOR_1_ON_UNLOAD  COMMAND_MOTOR_ON_UNLOAD "1"
#define MOTOR_2_ON_UNLOAD  COMMAND_MOTOR_ON_UNLOAD "2"
#define MOTOR_3_ON_UNLOAD  COMMAND_MOTOR_ON_UNLOAD "3"
#define MOTOR_4_ON_UNLOAD  COMMAND_MOTOR_ON_UNLOAD "4"
#define MOTOR_5_ON_UNLOAD  COMMAND_MOTOR_ON_UNLOAD "5"
#define MOTOR_6_ON_UNLOAD  COMMAND_MOTOR_ON_UNLOAD "6"

#define MOTOR_1_DIR_PIN           2
#define MOTOR_1_STEP_PIN          3
#define MOTOR_2_DIR_PIN           4
#define MOTOR_2_STEP_PIN          5
#define MOTOR_3_DIR_PIN           6
#define MOTOR_3_STEP_PIN          7
#define MOTOR_4_DIR_PIN           8
#define MOTOR_4_STEP_PIN          9
#define MOTOR_5_DIR_PIN           10
#define MOTOR_5_STEP_PIN          11
#define MOTOR_6_DIR_PIN           12
#define MOTOR_6_STEP_PIN          13

#define MOTOR_SPEED               1000
#define MOTOR_ACCELERATION        1000

AccelStepper motor1(AccelStepper::FULL2WIRE, MOTOR_1_STEP_PIN, MOTOR_1_DIR_PIN);
AccelStepper motor2(AccelStepper::FULL2WIRE, MOTOR_2_STEP_PIN, MOTOR_2_DIR_PIN);
AccelStepper motor3(AccelStepper::FULL2WIRE, MOTOR_3_STEP_PIN, MOTOR_3_DIR_PIN);
AccelStepper motor4(AccelStepper::FULL2WIRE, MOTOR_4_STEP_PIN, MOTOR_4_DIR_PIN);
AccelStepper motor5(AccelStepper::FULL2WIRE, MOTOR_5_STEP_PIN, MOTOR_5_DIR_PIN);
AccelStepper motor6(AccelStepper::FULL2WIRE, MOTOR_6_STEP_PIN, MOTOR_6_DIR_PIN);

SerialCommand sCmd;

void unrecognizedCommand(const char *command) {
  Serial.println("command no recognized");
  Serial.println(command);
}
void motor1Load() {
  Serial.println("load");
  motor1.moveTo(100000000);
}
void motor1Unload() {
  Serial.println("unload");
  motor1.moveTo(-100000000);
}
void motor1Off() {
  Serial.println("off");
  motor1.stop();
}
 
void setup() {
  // setup hardware
  Serial.begin(115200);
  motor1.setMaxSpeed(MOTOR_SPEED);
  motor1.setAcceleration(MOTOR_ACCELERATION);
  motor2.setMaxSpeed(MOTOR_SPEED);
  motor2.setAcceleration(MOTOR_ACCELERATION);
  motor3.setMaxSpeed(MOTOR_SPEED);
  motor3.setAcceleration(MOTOR_ACCELERATION);
  motor4.setMaxSpeed(MOTOR_SPEED);
  motor4.setAcceleration(MOTOR_ACCELERATION);
  motor5.setMaxSpeed(MOTOR_SPEED);
  motor5.setAcceleration(MOTOR_ACCELERATION);
  motor6.setMaxSpeed(MOTOR_SPEED);
  motor6.setAcceleration(MOTOR_ACCELERATION);

  sCmd.addCommand(MOTOR_1_ON_LOAD, motor1Load);
  sCmd.addCommand(MOTOR_1_ON_UNLOAD, motor1Unload);
  sCmd.addCommand(MOTOR_1_OFF, motor1Off);
  sCmd.setDefaultHandler(unrecognizedCommand);
}
void loop() {
  sCmd.readSerial();

  motor1.run();
  motor2.run();
  motor3.run();
  motor4.run();
  motor5.run();
  motor6.run();
}
