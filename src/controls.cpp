
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

bool stateLoader=false;
bool stateDescore=true;
 

using namespace vex;


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