#include <Arduino.h>

#include "SerialCommand.h"
#include "AccelStepper.h"

#define STATUS_BREWING            "brewing"
#define STATUS_IDLE               "idle"

#define COMMAND_BREW              "brew_"
#define COMMAND_MOTOR_OFF         "off_"
#define COMMAND_MOTOR_ON_LOAD     "load_"
#define COMMAND_MOTOR_ON_UNLOAD   "unload_"
#define COMMAND_MOTOR_ALL_OFF     "off_all"

#define MOTOR_ID_1        "1"
#define MOTOR_ID_2        "2"
#define MOTOR_ID_3        "3"
#define MOTOR_ID_4        "4"
#define MOTOR_ID_5        "5"
#define MOTOR_ID_6        "6"

#define BREW_1            COMMAND_BREW "1"
#define BREW_2            COMMAND_BREW "2"
#define BREW_3            COMMAND_BREW "3"
#define BREW_4            COMMAND_BREW "4"
#define BREW_5            COMMAND_BREW "5"
#define BREW_6            COMMAND_BREW "6"

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

#define MOTOR_SPEED               2000
#define MOTOR_ACCELERATION        2000

#define LOAD_DISTANCE             100000000
#define UNLOAD_DISTANCE           -100000000

bool isBrewing = false; 

AccelStepper motor1(AccelStepper::FULL2WIRE, MOTOR_1_STEP_PIN, MOTOR_1_DIR_PIN);
AccelStepper motor2(AccelStepper::FULL2WIRE, MOTOR_2_STEP_PIN, MOTOR_2_DIR_PIN);
AccelStepper motor3(AccelStepper::FULL2WIRE, MOTOR_3_STEP_PIN, MOTOR_3_DIR_PIN);
AccelStepper motor4(AccelStepper::FULL2WIRE, MOTOR_4_STEP_PIN, MOTOR_4_DIR_PIN);
AccelStepper motor5(AccelStepper::FULL2WIRE, MOTOR_5_STEP_PIN, MOTOR_5_DIR_PIN);
AccelStepper motor6(AccelStepper::FULL2WIRE, MOTOR_6_STEP_PIN, MOTOR_6_DIR_PIN);

SerialCommand sCmd;

void setupMotor(AccelStepper motor) {
  motor.setMaxSpeed(MOTOR_SPEED);
  motor.setAcceleration(MOTOR_ACCELERATION);
}

void setupMotorCommand(const char* motorId, void* load, void* unload, void* off) {
  sCmd.addCommand(strcat(COMMAND_MOTOR_ON_LOAD, motorId), load);
  sCmd.addCommand(strcat(COMMAND_MOTOR_ON_UNLOAD, motorId), unload);
  sCmd.addCommand(strcat(COMMAND_MOTOR_OFF, motorId), off);
}

void load1() { motor1.moveTo(LOAD_DISTANCE); };
void unload1() { motor1.moveTo(UNLOAD_DISTANCE); };
void off1() { motor1.stop(); };

void load2() { motor2.moveTo(LOAD_DISTANCE); };
void unload2() { motor2.moveTo(UNLOAD_DISTANCE); };
void off2() { motor2.stop(); };

void load3() { motor3.moveTo(LOAD_DISTANCE); };
void unload3() { motor3.moveTo(UNLOAD_DISTANCE); };
void off3() { motor3.stop(); };

void load4() { motor4.moveTo(LOAD_DISTANCE); };
void unload4() { motor4.moveTo(UNLOAD_DISTANCE); };
void off4() { motor4.stop(); };

void load5() { motor5.moveTo(LOAD_DISTANCE); };
void unload5() { motor5.moveTo(UNLOAD_DISTANCE); };
void off5() { motor5.stop(); };

void load6() { motor6.moveTo(LOAD_DISTANCE); };
void unload6() { motor6.moveTo(UNLOAD_DISTANCE); };
void off6() { motor6.stop(); };

void offAll() {
  motor1.stop();
  motor2.stop();
  motor3.stop();
  motor4.stop();
  motor5.stop();
  motor6.stop();
}

void brew1() {
  motor1.moveTo(100);
  motor2.moveTo(200);
}

void brew2() {
}

void brew3() {
}

void brew4() {
}

void brew5() {
}

void brew6() {
}

void unrecognizedCommand(const char *command) {
}

bool anyIsRunning() {
  return
    motor1.isRunning() ||
    motor2.isRunning() ||
    motor3.isRunning() ||
    motor4.isRunning() ||
    motor5.isRunning() ||
    motor6.isRunning();
}
 
void setup() {
  // setup hardware
  Serial.begin(115200);
  setupMotor(motor1);
  setupMotor(motor2);
  setupMotor(motor3);
  setupMotor(motor4);
  setupMotor(motor5);
  setupMotor(motor6);

  setupMotorCommand((const char*)MOTOR_ID_1, load1, unload1, off1);
  setupMotorCommand((const char*)MOTOR_ID_2, load2, unload2, off2);
  setupMotorCommand((const char*)MOTOR_ID_3, load3, unload3, off3);
  setupMotorCommand((const char*)MOTOR_ID_4, load4, unload4, off4);
  setupMotorCommand((const char*)MOTOR_ID_5, load5, unload5, off5);
  setupMotorCommand((const char*)MOTOR_ID_6, load6, unload6, off6);

  sCmd.addCommand(BREW_1, brew1);
  sCmd.addCommand(BREW_2, brew2);
  sCmd.addCommand(BREW_3, brew3);
  sCmd.addCommand(BREW_4, brew4);
  sCmd.addCommand(BREW_5, brew5);
  sCmd.addCommand(BREW_6, brew6);

  sCmd.addCommand(COMMAND_MOTOR_ALL_OFF, offAll);

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

  bool motorsRunning = anyIsRunning();
  if (motorsRunning != isBrewing) {
    isBrewing = motorsRunning;
    Serial.println(isBrewing ? STATUS_BREWING : STATUS_IDLE);
  }
}
