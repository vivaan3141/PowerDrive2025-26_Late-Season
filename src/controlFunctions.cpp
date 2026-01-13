#include "vex.h"
#include "robot-config.h"
#include "functions.h"


using namespace vex;

bool stateLoader=false;
bool stateDescore=false;
 
void reverseIntake(){
  low.spin(reverse);
  high.spin(reverse);
}

void middleGoal(){
  low.spin(forward);
  high.spin(reverse);
  Controller.Screen.print("Middle Goal");
}

void intake(){
  low.spin(forward);
  Controller.Screen.print("Intake");
}

void longGoal(){
  Controller.Screen.clearLine();

  high.spin(forward); // Score long, moves all stages
  low.spin(forward);

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
