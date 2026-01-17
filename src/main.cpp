/*    Module:       main.cpp                               */
/*    Author:       Vivaan Gupta                           */
/*    Created:      5/27/2025, 10:30:19 PM                 */
// January 10. Autonomous change for Jan 10
#include "vex.h"
#include "robot-config.h"
#include "functions.h"

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace vex;
competition Competition;


// void setSpeedAuton(){
//     Loader.set(false);
//     Descore.set(false);
//     low.setVelocity(150, rpm);
//     high.setVelocity(200, rpm);
// }

void loadLoop(int loop, double dist, double time){
  for (int i=0; i<loop; i++){
    Drivetrain.driveFor(dist,inches);
    wait(time, sec);
    Drivetrain.driveFor((0-dist),inches);
  }
}
  
void autonCodes(int x) {
  if (x==1){
  Brain.Screen.print(" - V23");
  Drivetrain.setStopping(hold);
  low.setVelocity(75, percent);
  high.setVelocity(75, percent);
  Drivetrain.setTurnVelocity(8, percent);
  Drivetrain.setTurnConstant(0.6);
  Drivetrain.setTurnThreshold(1);

  Drivetrain.driveFor(8,inches);
  Drivetrain.turnToHeading(90,degrees);
  low.spin(reverse);
   //Make turns
   Drivetrain.setDriveVelocity(10, percent);
   Drivetrain.driveFor(31.5,inches);
   Drivetrain.turnToHeading(90,degrees);
  // Drivetrain.driveFor(-1,inches);

  low.stop();
  low.setVelocity(100, percent);
  high.setVelocity(100, percent);
  Drivetrain.turnToHeading(-45,degrees);
  wait(1, sec);
  Drivetrain.setDriveVelocity(10, percent);
  
   Drivetrain.driveFor(-14.5,inches);
   wait(0.5, sec);
  
   high.spin(reverse);
   low.spin(reverse);
   wait(5, sec);
   high.stop();
   low.stop();

}if (x==2){
// Low Goal Match
    Brain.Screen.print(" - V25");
  Controller.Screen.print(" - V25");

  Drivetrain.setStopping(hold);
  low.setVelocity(75, percent);
  high.setVelocity(75, percent);
  Drivetrain.setTurnVelocity(8, percent);
  Drivetrain.setTurnConstant(0.6);
  Drivetrain.setTurnThreshold(1);

  Drivetrain.driveFor(8,inches);
  Drivetrain.turnToHeading(-90,degrees);
  low.spin(reverse);
   //Make turns
   Drivetrain.setDriveVelocity(10, percent);
   Drivetrain.driveFor(31.5,inches);
   Drivetrain.turnToHeading(-135,degrees);
  // Drivetrain.driveFor(-1,inches);
  low.stop();
    Drivetrain.driveFor(12.5,inches);
        wait(0.5, sec);
  
  low.setVelocity(100, percent);
  high.setVelocity(100, percent);

    low.spin(forward);
    wait(3, sec);
    high.stop();
    low.stop();

}if (x==3){
    // Scores 4 block on long goal
  Brain.Screen.print(" - V26");
  Controller.Screen.print(" - V26");

  Drivetrain.setStopping(hold);
  low.setVelocity(75, percent);
  high.setVelocity(75, percent);
  Drivetrain.setTurnVelocity(8, percent);
  Drivetrain.setTurnConstant(0.6);
  Drivetrain.setTurnThreshold(1);

  Drivetrain.driveFor(8,inches);
  Drivetrain.turnToHeading(-90,degrees);
  low.spin(reverse);
   //Make turns
   Drivetrain.setDriveVelocity(10, percent);
   Drivetrain.driveFor(31.5,inches);
   Drivetrain.turnToHeading(-135,degrees);
  // Drivetrain.driveFor(-1,inches);
  low.stop();
    Drivetrain.driveFor(-40.8,inches);
    wait(0.5, sec);
    Drivetrain.turnToHeading(90,degrees);

  low.setVelocity(100, percent);
  high.setVelocity(100, percent);

    Drivetrain.driveFor(-10.5,inches);
    Drivetrain.turnToHeading(90,degrees);
        Drivetrain.driveFor(-7.5,inches);

    wait(0.75, sec);
    Drivetrain.turnToHeading(90,degrees);

    high.spin(forward);
    low.spin(reverse);
    wait(3, sec);
    high.stop();
    low.stop();
}if (x==4){
  low.setVelocity(200, rpm);
  high.setVelocity(200, rpm);
  Drivetrain.setTurnVelocity(8, percent);
  Drivetrain.setTurnConstant(0.6);
  
  Drivetrain.driveFor(8,inches);
  Drivetrain.turnToHeading(90,degrees);
  low.spin(forward);
   //Make turns
   Drivetrain.setDriveVelocity(10, percent);
   Drivetrain.driveFor(31,inches);
   Drivetrain.turnToHeading(130,degrees);
   wait(1, sec);
   Drivetrain.setDriveVelocity(10, percent);
  
   Drivetrain.driveFor(17.7,inches);
   wait(0.5, sec);
  
   high.spin(reverse);
   low.spin(forward);
   wait(5, sec);
   high.stop();
   low.stop();
}if (x==5){
    Brain.Screen.print(" - V23");
  Drivetrain.setStopping(hold);
  low.setVelocity(75, percent);
  high.setVelocity(75, percent);
  Drivetrain.setTurnVelocity(8, percent);
  Drivetrain.setTurnConstant(0.6);
  Drivetrain.setTurnThreshold(1);

  Drivetrain.driveFor(8,inches);
  Drivetrain.turnToHeading(90,degrees);
  low.spin(reverse);
   //Make turns
   Drivetrain.setDriveVelocity(10, percent);
   Drivetrain.driveFor(31.5,inches);
   Drivetrain.turnToHeading(90,degrees);
  // Drivetrain.driveFor(-1,inches);

  low.stop();
  low.setVelocity(100, percent);
  high.setVelocity(100, percent);
  Drivetrain.turnToHeading(-45,degrees);
  wait(1, sec);
  Drivetrain.setDriveVelocity(10, percent);
  
   Drivetrain.driveFor(-14.5,inches);
   wait(0.5, sec);
  
   high.spin(reverse);
   low.spin(reverse);
   wait(8, sec);
   high.stop();
   low.stop();
    
  Drivetrain.driveFor(14.5,inches);

  Drivetrain.turnToHeading(90,degrees);

  Drivetrain.driveFor(-15,inches);

  Drivetrain.turnToHeading(0,degrees);

  Drivetrain.driveFor(-16,inches);

  Drivetrain.turnToHeading(90,degrees);

  Drivetrain.driveFor(-30,inches);

}
}

// Pre-Autonomous
void pre_auton(void) {
  vexcodeInit();
  InertialSensor.calibrate();  // Start calibration. Print that the Inertial Sensor is calibrating
  low.setVelocity(600, rpm); 
  high.setVelocity(600, rpm);
  while(InertialSensor.isCalibrating()){
    Brain.Screen.print("Inertial Calibrating"); wait(5, sec);
  }
  Brain.Screen.print("Inertial Calibrated!"); wait(5, sec);
}
// USER CONTROLS

void autonomous() {
  Drivetrain.setStopping(hold);
    Descore.set(true);
  autonCodes(5);
}
 
bool stateLoader=false;
bool stateDescore=true;
 
void reverseIntake(){
  low.spin(forward);
  high.stop();
}

void middleGoal(){
  low.spin(reverse);
  high.spin(reverse);
  Controller.Screen.print("Middle Goal");
}

void intake(){
  low.spin(reverse);
  high.stop();
  Controller.Screen.print("Intake");
}

void longGoal(){
  Controller.Screen.clearLine();
  high.spin(forward); // Score long, moves all stages
  low.spin(reverse);
  Controller.Screen.print("LONG GOAL");
}
void loadOut(){
  Controller.Screen.clearLine();

  Controller.Screen.print("Loading"); 
  Loader.set(true);
}

void loadRest(){
  Controller.Screen.clearLine();
  Loader.set(false);
}

void descoreOut(){
  Controller.Screen.clearLine();
  Descore.set(true);
}

void descoreIn(){
  Controller.Screen.clearLine();
  Descore.set(false);
}
void reverseIntakeRELEASED(){
  Controller.Screen.clearLine();

  low.stop();
  high.stop();
}

void middleGoalRELEASED(){
  Controller.Screen.clearLine();
  low.stop();
  high.stop();
}

void longGoalRELEASED(){
  Controller.Screen.clearLine();

  high.stop();
  low.stop();
}

void intakeRELEASED(){
  Controller.Screen.clearLine();

  high.stop();
  low.stop();
}


void load(){
  if (stateLoader==true){
    loadOut();
    stateLoader=false; // Happy :)
  }else {
    loadRest();
    stateLoader=true;
  }
}

void descore(){
  if (stateDescore==true){
    descoreOut();
    stateDescore=false; // Happy :)
  }else {
    descoreIn();
    stateDescore=true;
  }
}

void descoreTest(){
  Descore.set(true);
  wait(1,sec);
    Descore.set(false);
}


void usercontrol(void) {
  high.setVelocity(600, rpm);
  low.setVelocity(600, rpm);


  Controller.ButtonR1.pressed(middleGoal);
  Controller.ButtonR1.released(middleGoalRELEASED);

  Controller.ButtonR2.pressed(longGoal);
  Controller.ButtonR2.released(longGoalRELEASED);

  Controller.ButtonL2.pressed(intake);
  Controller.ButtonL2.released(intakeRELEASED);

  Controller.ButtonA.pressed(reverseIntake);
  Controller.ButtonA.released(reverseIntakeRELEASED);
  // Pneumatics
  // Controller.ButtonUp.pressed(load);
  Controller.ButtonY.pressed(descore);

  while (true) {
    // ========== DRIVE CONTROL ========== //
    Drivetrain.setStopping(coast);

    double fwd = Controller.Axis3.position();
    double turn = Controller.Axis1.position();

    double leftPower  = fwd + turn;
    double rightPower = fwd - turn;

    spinLeftDT(leftPower * 1);
    spinRightDT(rightPower * 1);
  
    wait(20, msec);
  }

}
int main(){
  pre_auton();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  while (true) {
    wait(100, msec);
  }
}
