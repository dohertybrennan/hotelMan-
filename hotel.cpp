#include "hotel.h"
#include "room.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

//Converts a string to a float to be used in the base cost
float string_to_float( const std::string& s ){
   std::istringstream i(s);
   float x;

   //Checks to see if it is actually a float
   if (!(i >> x)) {
        return 0;
   }
   return x;
} 

//Strips any spaces on the ends of strings and returns it back
void stripSpaces(std::string& tempString) {
    while (tempString[0] == ' ') {
		tempString.erase(0, 1);
	}

	while (tempString.length() == ' ') {
		tempString.erase(tempString.length() - 1, tempString.length());
	}
}

//Initializes the static int mUID
int Hotel::mUID = 1;

Hotel::Hotel(std::string cfgFilePath) {
    std::ifstream cfgFile;
    std::string tempString;
    cfgFile.open(cfgFilePath);
    float baseCost = 0.00;
    int numKing = 0;
    int numDouble = 0;
    int numSuite = 0;
    
    //Checks to see if the file exists and can open
    if (!cfgFile.is_open()) {
        std::cerr << "Could not open " << cfgFilePath << std::endl;
        return; 
    } else {
        //Goes through each line of the config file and parses info
        while(!cfgFile.eof()){
            std::getline(cfgFile, tempString);
            stripSpaces(tempString);

            //Locates the colon seperator
            std::size_t pos = tempString.find(":");
            std::string param = tempString.substr(0,pos);
            std::cout << param <<std::endl;
            stripSpaces(param);
            std::cout << param <<std::endl;

            std::string arg = tempString.substr(pos + 1);
            std::cout << arg <<std::endl;
            stripSpaces(arg);
            std::cout << arg <<std::endl;

            //Looks for each paramater in the config file
            if (param == "name") {
                mName = arg;
            } else if (param == "cost") {
                baseCost = string_to_float(arg);
            } else if (param == "double") {
                numDouble = std::stoi(arg);
            } else if (param == "king") {
                numKing = std::stoi(arg);
            } else if (param == "suite") {
                numSuite = std::stoi(arg);
            }
        }
    }

    //Each of these loop through the number of times a room is present and adds them to the room list
    for(int i = 0; i < numKing; i++) {
        Room* r = new KingRoom(mUID, baseCost);
        mRooms.push_back(r);
        mUID++;
    }

    for(int i = 0; i < numDouble; i++) {
        Room* r = new DoubleRoom(mUID, baseCost);
        mRooms.push_back(r);
        mUID++;
    }

    for(int i = 0; i < numSuite; i++) {
        Room* r = new SuiteRoom(mUID, baseCost);
        mRooms.push_back(r);
        mUID++;
    }
       
}

std::string Hotel::getName() { return mName; }

std::list<Room*>& Hotel::getRoomList() { return mRooms; }

//Cleans the list of rooms
Hotel::~Hotel() {
    for(auto& r : mRooms) {
        delete r;
    }
}