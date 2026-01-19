
#include "vex.h"
#include "robot-config.h"
#include "functions.h"

#include <fstream>   
#include <sstream>   

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

#include "picojson.h"
using namespace vex;


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
   Drivetrain.driveFor(30,inches);
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
  //Make turns
  Drivetrain.turnToHeading(-90,degrees);
  low.spin(reverse);
   Drivetrain.setDriveVelocity(10, percent);
   Drivetrain.driveFor(31.5,inches);
   Drivetrain.turnToHeading(-135,degrees);

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
   Drivetrain.setDriveVelocity(29, percent);
   Drivetrain.driveFor(32,inches);
  Drivetrain.driveFor(-1,inches);
   Drivetrain.turnToHeading(-135,degrees);
  // Drivetrain.driveFor(-1,inches);
  low.stop();
    Drivetrain.driveFor(-40.5,inches);
    wait(0.5, sec);
    Drivetrain.turnToHeading(90,degrees);

  low.setVelocity(100, percent);
  high.setVelocity(100, percent);
   Drivetrain.setDriveVelocity(25, percent);

    Drivetrain.driveFor(-10.5,inches);
    Drivetrain.turnToHeading(90,degrees);
        Drivetrain.driveFor(-7.2,inches);

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
    Drivetrain.turnToHeading(130,degrees);
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
        Controller.Screen.print(" Stage 2");
  Drivetrain.driveFor(14.5,inches);

  Drivetrain.turnToHeading(90,degrees);

  Drivetrain.driveFor(-15,inches);
    Drivetrain.turnToHeading(90,degrees);


  Drivetrain.turnToHeading(0,degrees);

  Drivetrain.driveFor(-4,inches); ///2

  Drivetrain.turnToHeading(45,degrees);

   Drivetrain.setDriveVelocity (40, percent);

    Drivetrain.driveFor(-30,inches);
  wait(1, seconds);
    Drivetrain.turnToHeading(90,degrees);

    Drivetrain.setDriveVelocity(20, percent);

  Drivetrain.driveFor(-10,inches);

} if (x==6){
  // Park Go
  Drivetrain.setDriveVelocity(30, percent);

   Drivetrain.driveFor(5,inches);
   Drivetrain.setDriveVelocity(25, percent);

   wait(1, sec);
   Drivetrain.driveFor(-22,inches);
   wait(1, sec);
   Drivetrain.driveFor(-15,inches);

    Drivetrain.turnToHeading(-45,degrees);
   Drivetrain.driveFor(-1,inches);


} if (x==7){
  // MiniGo
  Drivetrain.driveFor(6,inches);
}
}