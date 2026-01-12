#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

#include "vex.h" //definitions depend on definitions in vex.h

//extern: there is a variable, no need to make another variable to reference it
extern vex::brain Brain;
extern vex::controller Controller;
extern vex::competition Competition;

//TODO: group into drivetrain

extern vex::motor LB;
extern vex::motor LM;
extern vex::motor LF;
extern vex::motor RB;
extern vex::motor RM;
extern vex::motor RF;

extern vex::motor_group LeftDrive;
extern vex::motor_group RightDrive;

extern vex::smartdrive Drivetrain;

extern vex::motor low;
extern vex::motor bigbig;
extern vex::motor smallsmall;
extern vex::motor_group high;

extern vex::inertial InertialSensor;


extern vex::distance gap;


extern vex::digital_out Loader;

extern vex::digital_out Descore;


void vexcodeInit();

#endif