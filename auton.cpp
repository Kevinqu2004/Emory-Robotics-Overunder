#include "main.h"

void auton(){
    // autonomous code
    chassis->moveDistance(2_ft);
    intake();
    chassis->moveDistance(-36_in);
    chassis->turnAngle(90_deg);
    chassis->moveDistance(60_in);
    chassis->turnAngle(90_deg);
    chassis->moveDistance(12_in);
    score();
}