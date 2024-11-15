#include "main.h"
#include "autonomous.hpp"

#include "pros/misc.h"
#include "pros/motors.h"
#include "lemlib/api.hpp"
#include "pros/rtos.hpp"
#include "rapidcsv.h"
#include "pros/llemu.hpp"

#include <cstdio>
#include <stdbool.h>

// #include "autoSelect/selection.h"

using namespace pros;
using namespace pros::c;

Controller master (E_CONTROLLER_MASTER);

int map(int inMin, int inMax, int outMin, int outMax, int input);

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() { }

void screen_pose() {
    Imu inertial_sensor(INERTIAL_PORT);
	// loop forever
    while (true) {
        lemlib::Pose pose = auton::get_pose(); // get the current position of the robot
        pros::lcd::print(0, "x: %f", pose.x); // print the x position
        pros::lcd::print(1, "y: %f", pose.y); // print the y position
        pros::lcd::print(2, "heading: %f", pose.theta); // print the heading
        pros::lcd::print(3, "deg: %f", inertial_sensor.get_yaw()); // print the heading
        pros::lcd::print(4, "deg: %f", inertial_sensor.get_pitch()); // print the heading
        pros::delay(10);
    }
}

void auton_selector() {

}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	if (DRIVER) return;

	lcd::initialize();
	// selector::init();

	auton::initialize_chassis();

	if (AUTON_TEST){
		autonomous();
	}

	if (RECORD_MODE){
		// //std::filesystem::remove(RECORD_FILENAME);
		// std::fstream fs;
		// fs.open(RECORD_FILENAME, std::ios::out);
		// fs.close();
		// printf("Cleaned Recording!\n");
		// FILE *fp = fopen(RECORD_FILENAME, "w");
		// if (fp){
		// 	fclose(fp);
		// } else {
		// 	printf("%s\n", strerror(errno));
		// }
		// printf("Emptied File\n");
		remove(RECORD_FILENAME);
		auton::init_doc(RECORD_FILENAME);
	}

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	pros::lcd::initialize();

	pros::lcd::register_btn1_cb(on_center_button);

}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	// if (AUTON_TEST) {
	// 	// auton::autonomous_far();
	// 	// auton::autonomous_near_side();
	// 	auton::autonomous_skills();
	// 	return;
	// }

	// if (PLAYBACK_MODE){
	// 	auton::init_doc(RECORD_FILENAME);
	// 	auton::play_position(PLAYBACK_FILE);
	// 	return;
	// }

	// if (selector::auton == 0) {
	// 	auton::autonomous_skills();
	// }

	// if (selector::auton == 1 || selector::auton == -1) {
	// 	auton::autonomous_far();
	// }

	// if (selector::auton == 2 || selector::auton == -2) {
	// 	auton::autonomous_near_side();
	// }
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	// auto backWings = ADIDigitalOut(BACK_WINGS);
	// auto frontWings = ADIDigitalOut(FRONT_WINGS);
	// auto hang = ADIDigitalOut(HANG_PNEUMATICS);
	auto mogoal = ADIDigitalOut(MOGOAL_PISTON);

	float currLeftSpeed = 0;
	float currRightSpeed = 0;

	// drive motor has blue gear
	motor_set_gearing(FRONT_LEFT_WHEELS_PORT, E_MOTOR_GEAR_BLUE);
	motor_set_gearing(FRONT_RIGHT_WHEELS_PORT, E_MOTOR_GEAR_BLUE);
	motor_set_gearing(MID_LEFT_WHEELS_PORT, E_MOTOR_GEAR_BLUE);
	motor_set_gearing(MID_RIGHT_WHEELS_PORT, E_MOTOR_GEAR_BLUE);
	motor_set_gearing(BACK_LEFT_WHEELS_PORT, E_MOTOR_GEAR_BLUE);
	motor_set_gearing(BACK_RIGHT_WHEELS_PORT, E_MOTOR_GEAR_BLUE);

	motor_set_gearing(INTAKE_PORT, E_MOTOR_GEAR_GREEN);
	motor_set_gearing(CATAPULT_PORT_1, E_MOTOR_GEAR_GREEN);
	motor_set_gearing(CATAPULT_PORT_2, E_MOTOR_GEAR_GREEN);

	if (SHOULD_PRINT) controller_clear(CONTROLLER_MASTER);

	int slowmodeIndex = 2;
	float slowmode = 1.0f;

	bool cataActive = false;

	// bool backWingsActive = false;
	// bool frontWingsActive = false;
	// bool hangActive = false;
	bool mogoal_active = false;

	bool intakeFoward = false;
	bool intakeOn = false;
	bool intakeDirection = false;
	

	int voltage = -12000;

	float oldTime = pros::millis();

	if (DRIVE_SKILLS) {
		auton::autonomous_driver_start();
	}

	while (true) {
		if (controller_get_digital_new_press(CONTROLLER_MASTER, DIGITAL_DOWN)) {
			slowmodeIndex++;

			if (slowmodeIndex > 2) slowmodeIndex = 0;

			if (slowmodeIndex == 2) {
				slowmode = 1.f;
			} else if (slowmodeIndex == 1) {
				slowmode = 0.9f;
			} else {
				slowmode = 0.8f;
			}
		}

		if (controller_get_digital_new_press(CONTROLLER_MASTER, DIGITAL_R1)) {
			intakeFoward = !intakeFoward;
		}

		bool out = master.get_digital(DIGITAL_R2);

		if (intakeFoward){
			motor_move_voltage(INTAKE_PORT, INTAKE_CONSTANT * 12000);
		} 
		
		if (out) {
			intakeFoward = false;
			motor_move_voltage(INTAKE_PORT, INTAKE_CONSTANT * -12000);
		}
		
		if (!intakeFoward && !out) {
			motor_move_velocity(INTAKE_PORT, 0);
		}

		// if (controller_get_digital_new_press(CONTROLLER_MASTER, DIGITAL_L1)) {
		// 	frontWingsActive = !frontWingsActive;
		// 	frontWings.set_value(frontWingsActive);
		// }
		
		// if (controller_get_digital_new_press(CONTROLLER_MASTER, DIGITAL_L2)) {
		// 	backWingsActive = !backWingsActive;
		// 	backWings.set_value(backWingsActive);
		// }

		// if (controller_get_digital_new_press(CONTROLLER_MASTER, DIGITAL_Y)) {
		// 	hangActive = !hangActive;
		// 	hang.set_value(hangActive);
		// }

		if (controller_get_digital_new_press(CONTROLLER_MASTER, DIGITAL_L1)) {
			mogoal_active = !mogoal_active;
			mogoal.set_value(mogoal_active);
		}
		
		if (controller_get_digital_new_press(CONTROLLER_MASTER, DIGITAL_A)) {
			cataActive = !cataActive;

			if (!cataActive) {
				motor_move_voltage(CATAPULT_PORT_1, 0);
				motor_move_voltage(CATAPULT_PORT_2, 0);
			}
		}

		if (cataActive) {
			motor_move_voltage(CATAPULT_PORT_1, voltage);
			motor_move_voltage(CATAPULT_PORT_2, -voltage);
		}

		if (controller_get_digital_new_press(CONTROLLER_MASTER, DIGITAL_B)) {
			motor_move_relative(CATAPULT_PORT_1, -1000, 100);
		}

		if (controller_get_digital_new_press(CONTROLLER_MASTER, DIGITAL_X)) {
			voltage -= 1000;
		}

		if (RECORD_MODE && controller_get_digital_new_press(E_CONTROLLER_MASTER, DIGITAL_UP)){
			auton::save_doc();
		}

		// HANG KEYS: RIGHT ARROW GOES UP, Y GOES DOWN

		// if (controller_get_digital_new_press(CONTROLLER_MASTER, DIGITAL_B)) {
		// 	voltage -= 1000;
		// }

		//int strafeLeft = controller_get_digital(CONTROLLER_MASTER, DIGITAL_L1);
		//int strafeRight = controller_get_digital(CONTROLLER_MASTER, DIGITAL_R1);
		//int strafe = map(-1, 1, -127, 127, strafeRight) - map(-1, 1, -127, 127, strafeLeft);

		// Split Drive
		// int pow = controller_get_analog(CONTROLLER_MASTER, ANALOG_RIGHT_X);
		// int tur = controller_get_analog(CONTROLLER_MASTER, ANALOG_LEFT_Y);
		// int left = pow + tur;
		// int right = pow - tur;
		int right;
		int left;

		if (TANK_DRIVE) {
			right = -1 * controller_get_analog(CONTROLLER_MASTER, ANALOG_RIGHT_Y);
			left = controller_get_analog(CONTROLLER_MASTER, ANALOG_LEFT_Y);	
		} else {
			// Left Stick Throttle
			right = controller_get_analog(CONTROLLER_MASTER, ANALOG_RIGHT_X);
			left = controller_get_analog(CONTROLLER_MASTER, ANALOG_RIGHT_X);

			// Right Stick Turn
			right -= controller_get_analog(CONTROLLER_MASTER, ANALOG_LEFT_Y);
			left += controller_get_analog(CONTROLLER_MASTER, ANALOG_LEFT_Y);
		}


		if (DEADZONE_ENABLE){
			if (abs(left) < LEFT_Y_DEADZONE){
				left = 0;
			}

			if (abs(right) < RIGHT_Y_DEADZONE){
				right = 0;
			}
		}


		// Tank Drive
		//power *= -1;
		//int left = power + turn;
    	//int right = power - turn;

		// Smooth inputs when accelerating 
		if (SMOOTHING_ENABLE){
			if ((float)left != currLeftSpeed){
				if (left > 0){
					if (left > currLeftSpeed){
						currLeftSpeed += SMOOTHING_SPEED;
					} else if (currLeftSpeed > left){
						currLeftSpeed = left;
					}
				} else if (left < 0) {
					if (left < currLeftSpeed){
						currLeftSpeed -= SMOOTHING_SPEED;
					} else if (currLeftSpeed < left){
						currLeftSpeed = left;
					}
				} else if (left == 0){
					currLeftSpeed = 0;
				}
			}
			if ((float)right != currRightSpeed){
				if (right > 0){
					if (right > currRightSpeed){
						currRightSpeed += SMOOTHING_SPEED;
					} else if (currRightSpeed > right){
						currRightSpeed = right;
					}
				} else if (right < 0) {
					if (right < currRightSpeed){
						currRightSpeed -= SMOOTHING_SPEED;
					} else if (currRightSpeed < right){
						currRightSpeed = right;
					}
				} else if (right == 0){
					currRightSpeed = 0;
				}
			}
		}

		motor_move(FRONT_LEFT_WHEELS_PORT, slowmode * (FL_CONSTANT * (left)));
		motor_move(FRONT_RIGHT_WHEELS_PORT, -slowmode * (FR_CONSTANT * (right)));
		motor_move(MID_LEFT_WHEELS_PORT, slowmode * (ML_CONSTANT * (left)));
		motor_move(MID_RIGHT_WHEELS_PORT, -slowmode * (MR_CONSTANT * (right)));
		motor_move(BACK_LEFT_WHEELS_PORT, slowmode * (RL_CONSTANT * (left)));
		motor_move(BACK_RIGHT_WHEELS_PORT, -slowmode * (RR_CONSTANT * (right)));

		// Controller prints
		double battery = battery_get_capacity();

		auto drivetrainMotors = {FRONT_LEFT_WHEELS_PORT, FRONT_RIGHT_WHEELS_PORT, MID_LEFT_WHEELS_PORT, MID_RIGHT_WHEELS_PORT, BACK_LEFT_WHEELS_PORT, BACK_RIGHT_WHEELS_PORT};

		double temperatureSum = 0.0;
		double hotspot = 0.0;
		int hotspotPort = 0;

		for (int port : drivetrainMotors) {
			double currentTemp = motor_get_temperature(port);

			temperatureSum += currentTemp;
			
			if (hotspot < currentTemp) {
				hotspot = currentTemp;
				hotspotPort = port;
			}
		}

		double averageTemperature = temperatureSum / drivetrainMotors.size();

		temperatureSum = 0.0;

		temperatureSum += motor_get_temperature(CATAPULT_PORT_1);
		temperatureSum += motor_get_temperature(CATAPULT_PORT_2);

		master.print(0, 0, "Battery: %.0f%c", battery, 37);
		delay(1);
		master.print(1, 0, "Temps: %.0f°F, %.0f°F", celsiusToFahrenheit(averageTemperature), celsiusToFahrenheit(temperatureSum / 2));
		delay(1);
		master.print(2, 0, "Speeds: %.0f%c, %.0f%c", (abs(voltage / 1000.0f) / 12.0f) * 100.0f, 37, slowmode * 100.0f, 37);

		if (RECORD_MODE){
			float intake;
			if (intakeFoward){
				intake = INTAKE_CONSTANT * 12000;
			} else if (out) {
				intake = INTAKE_CONSTANT * -12000;
			} else {
				intake = 0;
			}
			auton::recording_info recInfo;
			recInfo.left = slowmode * (left);
			recInfo.right = slowmode * (right);
			recInfo.intake = intake;
			// recInfo.backWingsActive = backWingsActive;
			recInfo.dt = pros::millis() - oldTime;
			oldTime = pros::millis();
			auton::record_position(RECORD_FILENAME, recInfo);
		}

		delay(1);
	}
}

// This is how arduino implements the map function
int map(int inMin, int inMax, int outMin, int outMax, int input){
	return (input - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}