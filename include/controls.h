#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "vex.h"

extern bool stateLoader;
extern bool stateDescore;

// Scoring
void reverseIntake();
void middleGoal();
void intake();
void longGoal();

// Loader
void loadOut();
void loadRest();
void load();

// Descore
void descoreOut();
void descoreIn();
void descore();

// Button Release 
void reverseIntakeRELEASED();
void middleGoalRELEASED();
void longGoalRELEASED();
void intakeRELEASED();

//User Controls
void usercontrol(void);

#endif // FUNCTIONS_H