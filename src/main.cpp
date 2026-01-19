/*    Module:       main.cpp                               */
/*    Author:       Vivaan Gupta                           */
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
competition Competition;

double batteryPercent(){
  return ("Battery Capacity: %0.0f%%", Brain.Battery.capacity(percentUnits::pct));
}

int readPort(){
    std::ifstream f("vex_project_settings.json");
    if (!f.is_open()) return -1;
    std::stringstream buffer;
    buffer << f.rdbuf();
    std::string json_str = buffer.str();
    picojson::value v;
    std::string err = picojson::parse(v, json_str);
    if (!err.empty()) return -1;
    picojson::object& root = v.get<picojson::object>();
    picojson::object& project = root["project"].get<picojson::object>();
    return (int)project["port"].get<double>();
}

void changeName(std::string new_name) {
    const std::string filename = "vex_project_settings.json";
    std::ifstream inFile(filename);
    if (!inFile.is_open()) { return;}
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string content = buffer.str();
    inFile.close(); // Close after reading
    picojson::value v;
    std::string err = picojson::parse(v, content);
    if (!err.empty()) return;
    if (v.is<picojson::object>()) {
        picojson::object& root = v.get<picojson::object>();
        if (root.count("project") && root["project"].is<picojson::object>()) {
            picojson::object& project = root["project"].get<picojson::object>();
            project["name"] = picojson::value(new_name);
        }
    }
  }
  
// Pre-Autonomous
void pre_auton(void) {
  low.setVelocity(600, rpm); 
  high.setVelocity(600, rpm);
  InertialSensor.calibrate();
  while (InertialSensor.isCalibrating()==true) {
    task::sleep(100);
    std::cout<<"Calibrating";
    Brain.Screen.print("Inertial Calibrating.."); 
    Controller.Screen.print("Inertial Calibrating.."); 
    wait(5, sec);
}  
Brain.Screen.clearLine();
Controller.Screen.clearLine();

Brain.Screen.print("Calibrated!"); 
Controller.Screen.print("Calibrated!"); 
}

void autonomous() {
  if (readPort()==1){
    std::cout<<"hi";
  }else if (readPort()==2){
    changeName("Low Goal");
    std::cout<<"bye";
  }
  Drivetrain.setStopping(hold);
  Descore.set(false);
  autonCodes(2);
}

int main(){
  pre_auton();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  while (true) {
    wait(100, msec);
  }
}