#include "vex.h"
#include "controls.h"
#include "autons.h"
#include "robot-config.h"
#include "functions.h"
#include "picojson.h"
#include <fstream>   
#include <sstream>   
#include <iostream>
#include <string>
#include <cmath> 
#include <iomanip>

using namespace vex;

double inchesToDegrees(double inches) {
 return (((inches)/(3.14 * 3.25)) * 360 * (5.0/3.0));
 //NOTE: 5/3 is the gear ratio
}

void setDTPosition(double inches) {
    double deg = inchesToDegrees(inches);
    LF.setPosition(deg, degrees);
    LM.setPosition(deg, degrees);
    LB.setPosition(deg, degrees);
    RF.setPosition(deg, degrees);
    RM.setPosition(deg, degrees);
    RB.setPosition(deg, degrees);
}

void stopDT() {
    LF.stop();
    LM.stop();
    LB.stop();
    RF.stop();
    RM.stop();
    RB.stop();
}

void spinRightDT(double velocity) {
    RF.spin(forward, velocity, percent);
    RM.spin(forward, velocity, percent);
    RB.spin(forward, velocity, percent);
}

void spinLeftDT(double velocity) {
    LF.spin(forward, velocity, percent);
    LM.spin(forward, velocity, percent);
    LB.spin(forward, velocity, percent);
}

void spinDT(double velocity) {
    spinRightDT(velocity);
    spinLeftDT(velocity);
}

void spinDTPosition(double velocity, double targetInches) {

    setDTPosition(0);

    double targetDegrees = inchesToDegrees(targetInches);

    LF.spinToPosition(targetDegrees, degrees, velocity, rpm, false);
    LM.spinToPosition(targetDegrees, degrees, velocity, rpm, false);
    LB.spinToPosition(targetDegrees, degrees, velocity, rpm, false);
    RF.spinToPosition(targetDegrees, degrees, velocity, rpm, false);
    RM.spinToPosition(targetDegrees, degrees, velocity, rpm, false);
    RB.spinToPosition(targetDegrees, degrees, velocity, rpm, true);
}

void turnForTime(double velocity, double time) {
    spinRightDT(velocity);
    spinLeftDT(velocity);
    wait(time, msec);
    stopDT();
}



double batteryPercent(){ return ("Battery Capacity: %0.0f%%", Brain.Battery.capacity(percentUnits::pct)); }

  

// double distance(){ return gap.objectDistance(inches); }

// void driveUntilTarget(double distance, double speed) {
//   double targetDistRaw=(gap.objectDistance(inches))-(distance); // this gives the og target 
//   double targetDist = std::round(targetDistRaw * 10.0) / 10.0; // this supposed to round so there no oscillation
//   double driveSpeed=speed; // for reducing speed??
//   Drivetrain.setDriveVelocity(speed, percent);

//   while (targetDist!=distance){ // this logic supposed to make it go to accurate number
//     // driveSpeed=driveSpeed-1;
//     // Drivetrain.setDriveVelocity(driveSpeed, percent); 
//     // THIS LOGIC-  supposed to reduce speed when its close, not done, so im not doing it yet

//     if (targetDist>distance){
//       Drivetrain.drive(forward);
//       targetDist=gap.objectDistance(inches)-(distance);
//   }else if(targetDist<distance){
//       Drivetrain.drive(reverse);
//       targetDist=gap.objectDistance(inches)-(distance);
//     }
//   }
//   Drivetrain.stop();
// }

// void driveToDist(double distance, double speed){
// double targetDistRaw=gap.objectDistance(inches); // this gives the og target 
//   double targetDist = std::round(targetDistRaw * 10.0) / 10.0; // this supposed to round so there no oscillation
//   double driveSpeed=speed; // for reducing speed??
//   double distR=std::round(distance * 10.0) / 10.0;
//   Drivetrain.setDriveVelocity(speed, percent);
  
//   while (targetDist!=distR){ // this logic supposed to make it go to accurate number
//     // driveSpeed=driveSpeed-1;
//     // Drivetrain.setDriveVelocity(driveSpeed, percent); 
//     // THIS LOGIC-  supposed to reduce speed when its close, not done, so im not doing it yet
//     if (targetDist>distR){
//       Drivetrain.drive(forward);
//       targetDist=gap.objectDistance(inches)-(distance);
//   }else if(targetDist<distR){
//       Drivetrain.drive(reverse);
//       targetDist=gap.objectDistance(inches)-(distance);
//     }
//   }
//   Drivetrain.stop();
//   }

// void turn(int deg, std::string dir){
//   if (dir == "left" or "l"){
//     Drivetrain.turnToHeading(deg,degrees);
//   }else if (dir == "right" or "r"){
//     Drivetrain.turnToHeading((0-deg),degrees);
//   }
// }
