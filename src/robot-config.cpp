// src/robot-config.cpp
#include "robot-config.h"
#include <iostream>
using namespace vex;
//Config for ports of all devices
vex::brain Brain;
vex::controller Controller(vex::controllerType::primary);
vex::motor LB(vex::PORT7, vex::gearSetting::ratio6_1, true); //Left Back Motor
vex::motor LM(vex::PORT10, vex::gearSetting::ratio6_1, true); //Left Middle Motor
vex::motor LF(vex::PORT5, vex::gearSetting::ratio6_1, true); //Left Front Motor
vex::motor RB(vex::PORT8, vex::gearSetting::ratio6_1, false); //Right Back Motor
vex::motor RM(vex::PORT2, vex::gearSetting::ratio6_1, false); //Right Middle Motor
vex::motor RF(vex::PORT3, vex::gearSetting::ratio6_1, false); //Right Front Motor

vex::motor_group LeftDrive(LF, LM, LB);
vex::motor_group RightDrive(RF, RM, RB);

vex::inertial InertialSensor(vex::PORT1);

vex::smartdrive Drivetrain = smartdrive(LeftDrive, RightDrive, InertialSensor, 279.5, 311.5, 254, mm, 0.6);

vex::motor high (vex::PORT17,vex::gearSetting::ratio6_1); //Intake low
vex::motor bigScore (vex::PORT21,vex::gearSetting::ratio6_1, true); //Intake high
vex::motor smallScore (vex::PORT9,vex::gearSetting::ratio6_1, false); //Intake high

vex::motor_group low(bigScore, smallScore);


vex::digital_out Loader (Brain.ThreeWirePort.A);

vex::digital_out Descore (Brain.ThreeWirePort.G);

// distance gap = distance(PORT2); // Change the port!

void vexcodeInit() {
  InertialSensor.calibrate();
  // DoubleActingPiston.set(false); // retracted
  // SingleActingPiston.set(false); // off
  while (InertialSensor.isCalibrating()) {
    vex::task::sleep(100);
    std::cout<<"Calibrate";
  }
}