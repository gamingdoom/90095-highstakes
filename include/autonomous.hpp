#pragma once

#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "lemlib/api.hpp"
#include "rapidcsv.h"

namespace auton {

    struct recording_info{
        float left;
        float right;
        float intake;
        bool backWingsActive;
        float dt;
    };

    void autonomous_skills();
    void autonomous_far();
    void autonomous_awp();
    void pid();
    void turnAndMoveTo(float x, float y, int timeout);
    void move_for(int time, int voltage);
    void open_wings(bool back=true);
    void retract_wings(bool back=true);
    void begin_intake(int duration, bool async=false);
    void begin_outtake(int duration, bool async=false);
    void stop_intake();
    void skills_catapult();
    void release_intake();
    void record_position(std::string filepath, auton::recording_info recInfo);
    void play_position(std::string filepath);
    void save_doc();
    void init_doc(std::string filename);
    void autonomous_near_side();
    void autonomous_driver_start();



    void initialize_chassis();
    lemlib::Pose get_pose();
    
    //rapidcsv::Document doc(RECORD_FILENAME);
}

