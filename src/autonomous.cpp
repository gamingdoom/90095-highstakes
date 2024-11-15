#include "autonomous.hpp"
#include "lemlib/pose.hpp"
#include "main.h"

#include "pros/motors.h"
#include "pros/rtos.h"
#include "rapidcsv.h"

#include <cstddef>
#include <cstdio>
#include <math.h>
#include <vector>

using namespace auton;
using namespace pros;

constexpr int SPEED = 127 * 2/3;
constexpr int SEMI_ACCURATE_SPEED = 60 * 2/3;
constexpr int ACCURATE_SPEED = 40 * 2/3;

// MotorGroup left({Motor(FRONT_LEFT_WHEELS_PORT, E_MOTOR_GEARSET_06, true),  Motor(MID_LEFT_WHEELS_PORT, E_MOTOR_GEARSET_06, true), Motor(BACK_LEFT_WHEELS_PORT, E_MOTOR_GEARSET_06, true)});
// MotorGroup right({Motor(FRONT_RIGHT_WHEELS_PORT, E_MOTOR_GEARSET_06, false),  Motor(MID_RIGHT_WHEELS_PORT, E_MOTOR_GEARSET_06, false), Motor(BACK_RIGHT_WHEELS_PORT, E_MOTOR_GEARSET_06, false)});

// lemlib::Drivetrain drivetrain {
//     &left, // left drivetrain motors
//     &right, // right drivetrain motors
//     11, // track width
//     3.25, // wheel diameter
//     450, // wheel rpm
//     5 // chasepower
// };

// Imu inertial_sensor(INERTIAL_PORT);

// lemlib::OdomSensors sensors {
//     nullptr, // vertical tracking wheel 1
//     nullptr, // vertical tracking wheel 2
//     nullptr, // horizontal tracking wheel 1
//     nullptr, // we don't have a second tracking wheel, so we set it to nullptr
//     &inertial_sensor // inertial sensor
// };

// lemlib::ControllerSettings lateralController {
//     8, // kP
//     0, // kI
//     40, // kD
//     3, // anti windup
//     1, // small error range, in inches
//     100, // small error range timeout, in milliseconds
//     3, // large error range, in inches
//     500, // large error range timeout, in milliseconds
//     40 // maximum acceleration (slew)
// };
 
// // turning PID
// lemlib::ControllerSettings angularController {
//     2, // kP
//     0, // kI
//     15, // kD
//     3, // anti windup
//     1, // small error range, in inches
//     100, // small error range timeout, in milliseconds
//     3, // large error range, in inches
//     500, // large error range timeout, in milliseconds
//     20 // maximum acceleration (slew)
// };

// lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

// function for pid tuning
void auton::pid() {
    // chassis.setPose(0, 0, 0);   

    // chassis.turnTo(0, -30, 5000, true, 127, false);
}

// ADIDigitalOut backWings(BACK_WINGS);
// ADIDigitalOut frontWings(FRONT_WINGS);
// ADIDigitalOut hang(HANG_PNEUMATICS);

// Motor intake(INTAKE_PORT);
// Motor catapult_1(CATAPULT_PORT_1, E_MOTOR_GEAR_GREEN);
// Motor catapult_2(CATAPULT_PORT_2, E_MOTOR_GEAR_GREEN);

rapidcsv::Document doc;

float getHeading() {
    // return chassis.getPose().theta;
    return 0.0;
}

void auton::autonomous_driver_start() {
    // release_intake();

    // delay(500);

    // chassis.setPose(-39, -58, 110);

    // chassis.moveToPose(-60, -23, 180, 2000, {false, 17}, false);

    // move_for(100, 100);

    // chassis.moveToPoint(-48, -40, 5000, true, SPEED, false);
    // chassis.turnTo(47, -25, 1500, true, ACCURATE_SPEED, false);

    // move_for(1400, -20);
}

void auton::autonomous_skills() {
    // release_intake();

    // delay(500);

    // chassis.setPose(-39, -58, 110);

    // chassis.moveToPose(-60, -23, 180, 2000, {false, 0, 0.6, 127, 80, 0}, false);

    // move_for(100, 100);

    // chassis.moveToPoint(-50, -45, 5000, true, SPEED, false);
    // chassis.turnTo(47, -8, 2000, true, ACCURATE_SPEED, false);

    // move_for(1400, -20);

    // skills_catapult();

    // chassis.moveToPose(-32, -62, 90, 2000, {true, 9}, false);
    // chassis.moveToPose(35, -62, 90, 4000, {true, 0, 0.6, 127, 90, 0}, false);

    // auton::open_wings(false);

    // chassis.moveToPose(60, -20, 0, 2000, {true, 12, 0.6, 80, 127, 0}, false);

    // auton::retract_wings(false);

    // move_for(400, -80);
    // move_for(600, 127);
    // move_for(200, -80);

    // chassis.turnTo(12, -30, 2000, true, 80, false);

    // chassis.moveToPoint(18, -30, 3000, true, 90, false);

    // auton::open_wings(false);

    // chassis.moveToPose(46, -10, 70, 1500, {true, 20, 0.6, 127, 127, 0}, false);  

    // move_for(400, 127);
    // move_for(500, -50);
    // move_for(400, 127);

    // auton::retract_wings(false);

    // chassis.moveToPose(13, 0, 270, 3000, {false}, false);

    // auton::open_wings(true);

    // chassis.moveToPoint(46, 0, 1500, false, 127, false); 

    // move_for(200, 100);
    // move_for(400, -127);
    // move_for(200, 100);

    // auton::retract_wings(true);

    // chassis.moveToPose(17, 27, 300, 2000, {true}, false);

    // auton::open_wings(true);

    // chassis.moveToPose(46, 8, 70, 1500, {false, 20, 0.6, 127, 127, 0}, false); 

    // move_for(200, 100);
    // move_for(400, -127);
    // move_for(200, 100);

    // auton::retract_wings(true);

    // chassis.moveToPose(45, 45, 330, 4000, {true, 20, 0.6, 60, 127, 0}, false); 

    // chassis.moveToPose(63, 20, 0, 2000, {false, 12, 0.6, 80, 127, 0}, false);

    // move_for(150, 127);
    // move_for(300, -127);
    // move_for(200, 80);

    // auton::retract_wings(false);

    // chassis.moveToPose(35, 60, 270, 2000, {true, 12, 0.6, 60, 127, 0}, false);

    // hang.set_value(true);

    // chassis.moveToPoint(-8, 60, 2000, true, 100, false);

    // hang.set_value(false);

    // return;
}

void auton::autonomous_near_side(){
    // release_intake();

    // delay(500);

    // chassis.setPose(-41, -56, 0);

    // auton::open_wings(false);

    // chassis.moveToPose(-48, -48, 315, 5000, {true, 5}, false);
    
    // move_for(300, 50);

    // chassis.turnTo(-30, 58, 2000, true, 80, false);

    // auton::retract_wings(false);

    // pros::delay(1000);

    // chassis.moveToPose(-30, -58, 270, 4000, {false, 8}, false);

    // chassis.moveToPoint(-15, -58, 4000, false, 60, false);
    // move_for(2000, -20);
}

void auton::autonomous_far(){
    // release_intake();

    // delay(500);

    // chassis.setPose(-23, 60, 90);

    // auton::begin_intake(-1, true);
    // chassis.moveToPoint(-10, 60, 2000, true, SEMI_ACCURATE_SPEED, false);

    // chassis.moveToPoint(-40, 60, 2000, false, SPEED, false);

    // chassis.moveToPose(-60, 45, 60, 1000, {false, 6}, false);
    // chassis.turnTo(-62, 20, 400, false, SPEED, false);
    
    // move_for(500, -100);
    // move_for(500, 50);

    // chassis.turnTo(-60, 20, 700, true, SPEED, false);

    // auton::begin_outtake(300, false);

    // move_for(500, 75);
    // move_for(500, -50);

    // chassis.turnTo(-4, 23, 300, true, SPEED, false);

    // auton::begin_intake(-1, true);

    // chassis.moveToPoint(-4, 23, 1800, true, 80, false);

    // move_for(250, -100);

    // chassis.turnTo(-50, 15, 800, true, SPEED, false);

    // auton::begin_outtake(300, false);

    // auton::begin_intake(-1, true);

    // chassis.moveToPose(-6, 4, 270, 4000, {true, 12}, false);
    // chassis.turnTo(-50, 0, 500, true, SPEED, false);

    // auton::stop_intake();

    // auton::open_wings(false);

    // move_for(700, 127);
    // move_for(300, -127);

    // auton::retract_wings(false);
}

void auton::autonomous_awp() {
    // release_intake();

    // delay(500);

    // chassis.setPose(-40, -56, 0);    

    // auton::open_wings();

    // delay(500);

    // chassis.turnTo(0, -63, 3000, false, SEMI_ACCURATE_SPEED, false);

    // auton::retract_wings();

    // chassis.moveToPose(-7.5, -63, 270, 2000, {false, 5}, false);
}

void auton::move_for(int duration, int voltage) {
    // left.move(voltage);
    // right.move(voltage);

    // delay(duration);

    // left.move(0);
    // right.move(0);
}

void auton::skills_catapult() {
    // int goal = -1800 * 44; 
    // catapult_1.move_voltage(-12000);
    // catapult_2.move_voltage(12000);

    // right.move(-10);

    // pros::delay(24000*2);

    // right.move(0);

    // catapult_1.move_voltage(0);
    // catapult_2.move_voltage(0);
}

void auton::release_intake() {
    // intake.move_velocity(20);

    // delay(1000);

    // intake.move_velocity(0);
}

void auton::begin_intake(int duration, bool async)
 {
    // if (async) {
    //     pros::Task intake_task([=]() {
    //         auton::begin_intake(duration, false);
    //     });
    //     return;
    // }

    // intake.move_velocity(INTAKE_CONSTANT * 600);

    // if (duration == -1) return;

    // delay(duration);

    // intake.move_velocity(0);
}

void auton::begin_outtake(int duration, bool async) {
    // if (async) {
    //     pros::Task outtake_task([=]() {
    //         auton::begin_outtake(duration, false);
    //     });
    //     return;
    // }

    // intake.move_velocity(INTAKE_CONSTANT * -600);

    // if (duration == -1) return;

    // delay(duration);

    // intake.move_velocity(0);
}

void auton::stop_intake() {
    // intake.move_velocity(0);
}

void auton::open_wings(bool back) {
    // if (back) backWings.set_value(true);
    // else frontWings.set_value(true);
}

void auton::retract_wings(bool back) {
    // if (back) backWings.set_value(false);  
    // else frontWings.set_value(false);
}
void auton::turnAndMoveTo(float x, float y, int timeout){
    // chassis.turnTo(x, y, timeout, false, ACCURATE_SPEED);
    // chassis.moveToPose(x, y, timeout, ACCURATE_SPEED);
}

void auton::initialize_chassis() {
    // chassis.calibrate();
}

void auton::record_position(std::string filepath, auton::recording_info recInfo){
    // std::vector<float> posVec = {recInfo.left, recInfo.right, (float)(int)recInfo.backWingsActive, recInfo.intake, recInfo.dt};

    // doc.InsertRow(doc.GetRowCount(), posVec);

    // //printf("Recored %f %f\n", pos.x, pos.y);
}

void auton::play_position(std::string filepath){
    // //rapidcsv::Document doc(filepath);

    // for (size_t i = 0; i < doc.GetRowCount(); i++){
    //     std::vector<float> pos = doc.GetRow<float>(i);
        
    //     pros::delay(pos[4]);

    //     intake.move_velocity(pos[3]);

    //     backWings.set_value((int)pos[2]);

    //     left.move_velocity(pos[0]);
    //     right.move_velocity(pos[1]);
        
    //     printf("Left Velocity: %f Right Velocity: %f\n", pos[0], pos[1]);
    // }
}

void auton::init_doc(std::string filename){
    // doc = rapidcsv::Document(filename);
}

void auton::save_doc(){
    // printf("Saving document\n");
    // doc.Save();
}

lemlib::Pose get_pose() {
    // return chassis.getPose();
    return lemlib::Pose(0, 0, 0);
}