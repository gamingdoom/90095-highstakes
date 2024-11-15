#!/usr/bin/python3

# Build all the modes
import json
import os
import subprocess
import sys

if len(sys.argv) <= 1:
    print("Usage: python3 build.py <team letter>")
    sys.exit(1)

team = sys.argv[1]

if team not in ("g", "b", "G", "B"):
    print("Invalid team letter: " + team)
    sys.exit(1)

team = team.upper()

print("Building for team: 90095" + team)

modes = {
    # "Competition": {},
    # "Auton Recording Skills": {"Record": True },
    # "Auton Playback Skills": {"Playback": True, "autonTest": True},
    # "Auton Test": {"autonTest": True},
    "Driver": {"driver": True},
    # "Driver Skills": {"driverSkills": True}
}

recorder_filename = "/usd/skills.csv"

slot = 1

for modeName, modeInfo in modes.items():
    with open("project.pros", "r") as f:
        protoPros = json.load(f)

    protoPros["py/state"]["project_name"] = modeName
    protoPros["py/state"]["upload_options"]["slot"] = slot

    cxxflags = []

    # Define team
    cxxflags.append(f"-DTEAM_90095{team}")
    
    if "autonTest" in modeInfo:
        cxxflags.append("-DAUTON_TEST=true")

    if "Record" in modeInfo:
        cxxflags.append("-DRECORD_MODE=true")
        cxxflags.append("-DRECORD_FILENAME=\\\"" + recorder_filename + "\\\"")

    if "driver" in modeInfo:
        cxxflags.append("-DDRIVER=true")

    if "Playback" in modeInfo:
        cxxflags.append("-DPLAYBACK_MODE=true")
        cxxflags.append("-DPLAYBACK_FILE=\\\"" + recorder_filename + "\\\"")

    if "driverSkills" in modeInfo:
        cxxflags.append("-DDRIVE_SKILLS=true")

    with open("project.pros", "w") as f:
        json.dump(protoPros, f)

    print("CXX Flags: " + " ".join(cxxflags))
    
    os.system(f"make -j -B EXTRA_CXXFLAGS='{' '.join(cxxflags)}'")
    
    os.system("pros upload")
    
    slot += 1