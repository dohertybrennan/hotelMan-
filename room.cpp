#include "room.h"
#include "hotel.h"
#include <fstream>
#include <iostream>

//// Function Definitions ////
/* ::getDescription() - Gets the desription of each room and returns it to the user.
/* ::getSleepCount() - Returns the num of people that can sleep in a room.
/* ::getCost() - Returns a float to the user on the cost of the room
*/


////King Room Subclass////
std::string KingRoom::getDescription() { return "1 King Bed, Standard Room"; }
int KingRoom::getSleepCount() { return 2;}
float KingRoom::getCost() { return mBaseCost * 1.2; }
KingRoom::~KingRoom() {}


////Double Room Subclass////
std::string DoubleRoom::getDescription() { return  "2 Double Beds, Standard Room"; }
int DoubleRoom::getSleepCount() { return 4; }
float DoubleRoom::getCost() { return mBaseCost; }
DoubleRoom::~DoubleRoom() {}


////Suite Room Subclass////
std::string SuiteRoom::getDescription() { return "1 King Bed in Bedroom and 1 Sleeper Sofa in Living Room"; }
int SuiteRoom::getSleepCount() { return 4; }
float SuiteRoom::getCost() { return mBaseCost * 1.6; }
SuiteRoom::~SuiteRoom() {}