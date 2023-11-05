#include "main.h"

void driveControl(){
    // drive train control code (for driver control)
    int forward = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + float(partner.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y))*0.25;
    int lateral = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) + float(partner.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X))*0.25;
    int left = forward + lateral;
    int right = forward - lateral;
    
    frontLeft = left;
	backLeft = left;
	frontRight = right;
	backRight = right;
}