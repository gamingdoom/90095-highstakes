/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * \copyright Copyright (c) 2017-2023, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convenient for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "api.h"

/**
 * You should add more #includes here
 */
//#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
// using namespace pros;
// using namespace pros::literals;
// using namespace okapi;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_

#if !defined(TEAM_90095G) && !defined(TEAM_90095B)
#define TEAM_90095G
#endif

#if defined(TEAM_90095G)
#define TANK_DRIVE false

#define FRONT_LEFT_WHEELS_PORT 2
#define FRONT_RIGHT_WHEELS_PORT 3

// middle motor
#define MID_RIGHT_WHEELS_PORT 5
#define MID_LEFT_WHEELS_PORT 4

// bottom motor
#define BACK_RIGHT_WHEELS_PORT 6
#define BACK_LEFT_WHEELS_PORT 7

#define INTAKE_PORT 10
#define CATAPULT_PORT_1 21
#define CATAPULT_PORT_2 21
#define INERTIAL_PORT 21

#define SMOOTHING_ENABLE true
#define SMOOTHING_SPEED 1

#define DEADZONE_ENABLE true
#define LEFT_X_DEADZONE 5
#define LEFT_Y_DEADZONE 5
#define RIGHT_X_DEADZONE 5
#define RIGHT_Y_DEADZONE 5

#define FR_CONSTANT 1
#define FL_CONSTANT -1
#define MR_CONSTANT 1
#define ML_CONSTANT -1
#define RR_CONSTANT 1
#define RL_CONSTANT -1

#define SLOWMODE_CONSTANT 0.5
#define SLOWMODE_ENABLE true

#define SHOULD_PRINT true

// #define BACK_WINGS 1
// #define HANG_PNEUMATICS 3
// #define FRONT_WINGS 4
#define MOGOAL_PISTON 1
#define INTAKE_CONSTANT 1
#elif defined(TEAM_90095B)
#define TANK_DRIVE false

#define FRONT_LEFT_WHEELS_PORT 3
#define FRONT_RIGHT_WHEELS_PORT 8

// top motor
#define MID_RIGHT_WHEELS_PORT 9
#define MID_LEFT_WHEELS_PORT 2

// bottom motor
#define BACK_RIGHT_WHEELS_PORT 10
#define BACK_LEFT_WHEELS_PORT 1

#define INTAKE_PORT 21
#define CATAPULT_PORT_1 21
#define CATAPULT_PORT_2 21
#define INERTIAL_PORT 21

#define SMOOTHING_ENABLE true
#define SMOOTHING_SPEED 1

#define DEADZONE_ENABLE true
#define LEFT_X_DEADZONE 5
#define LEFT_Y_DEADZONE 5
#define RIGHT_X_DEADZONE 5
#define RIGHT_Y_DEADZONE 5

#define FR_CONSTANT -1
#define FL_CONSTANT -1
#define MR_CONSTANT -1
#define ML_CONSTANT -1
#define RR_CONSTANT -1
#define RL_CONSTANT -1

#define SLOWMODE_CONSTANT 0.5
#define SLOWMODE_ENABLE true

#define SHOULD_PRINT true

// #define BACK_WINGS 21
// #define HANG_PNEUMATICS 21
// #define FRONT_WINGS 21
#define MOGOAL_PISTON 21
#define INTAKE_CONSTANT -1
#endif

// To Be set by build.py
#ifndef AUTON_TEST
#define AUTON_TEST false
#endif

#ifndef DRIVER
#define DRIVER false
#endif

#ifndef RECORD_MODE
#define RECORD_MODE false
#endif

#ifndef PLAYBACK_MODE
#define PLAYBACK_MODE false
#endif

#ifndef PLAYBACK_FILE
#define PLAYBACK_FILE "/usd/skills.csv"
#endif

#ifndef RECORD_FILENAME
#define RECORD_FILENAME  "/usd/skills.csv"
#endif

#ifndef DRIVE_SKILLS
#define DRIVE_SKILLS false
#endif