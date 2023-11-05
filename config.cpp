#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::Motor frontRight(3);
pros::Motor backRight(4);
pros::Motor frontLeft(12);
pros::Motor backLeft(13);

std::shared_ptr<ChassisController> chassis =
      ChassisControllerBuilder()
        .withMotors({-2, -3}, {12, 13})
        // Blue gearset, 4 in in wheel diam, 31 cm in wheel track
        .withDimensions({AbstractMotor::gearset::blue, (84.0 / 36.0)}, {{4_in, 12.25_in}, imev5BlueTPR})
        .withSensors(
          RotationSensor{16, true}, // Left encoder in V5 port 16 (reversed, the rotation sensors are flipped)
          RotationSensor{6}  // Right encoder in V5 port 6
        )
    		.withOdometry({{4_in, 12.25_in}, quadEncoderTPR})
        .withGains(
            //0.002, 0, 0.0001
            //0.003, 0, 0.0002
            //0.002, 0, 0.0001
            {0.001, 0.0000001, 0.00001}, // Distance controller gains
            {0.0001, 0.005, 0.0001}, // Turn controller gains
            {0.001, 0.0000001, 0.00001}  // Angle controller gains (helps drive straight)
          )
        /*.withDerivativeFilters(
            std::make_unique<AverageFilter<3>>(), // Distance controller filter
            std::make_unique<AverageFilter<3>>(), // Turn controller filter
            std::make_unique<AverageFilter<3>>()  // Angle controller filter
          )*/
        .withLogger(
            std::make_shared<Logger>(
                TimeUtilFactory::createDefault().getTimer(), // It needs a Timer
                "/ser/sout", // Output to the PROS terminal
                Logger::LogLevel::debug // Most verbose log level
            )
          )
        //.withClosedLoopControllerTimeUtil(50, 5, 250_ms)
    		.buildOdometry();
