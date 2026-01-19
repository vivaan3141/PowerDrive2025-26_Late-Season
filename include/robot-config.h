#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H
#include "vex.h" //definitions depend on definitions in vex.h
extern vex::brain Brain;
extern vex::controller Controller;
extern vex::competition Competition;
// Drivetrain
extern vex::motor LB;
extern vex::motor LM;
extern vex::motor LF;
extern vex::motor RB;
extern vex::motor RM;
extern vex::motor RF;
extern vex::motor_group LeftDrive;
extern vex::motor_group RightDrive;
extern vex::smartdrive Drivetrain;
// Scoring
extern vex::motor high;
extern vex::motor bigScore;
extern vex::motor smallScore;
extern vex::motor_group low;
//sensors
extern vex::inertial InertialSensor;
// extern vex::distance gap;
//pneumatics
extern vex::digital_out Loader;
extern vex::digital_out Descore;
#endif