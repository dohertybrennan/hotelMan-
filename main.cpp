#include "hotel.h"
#include <iostream>

// Print information about all rooms in a list
void printRoomList(Hotel& hotel) {
    std::cout << hotel.getName() << " Room List:\n";
    for (auto& r : hotel.getRoomList()) {
        std::cout << r->getUID() << "; " << r->getCost() << "; " << 
            r->getDescription() << "; " << r->getSleepCount() << "; " << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Create 3 different hotel objects and print all rooms
    // from each hotel.  The room configuration for each hotel
    // is defined in the config file passed into Hotel constructor.

    Hotel hotel1("hotel1.cfg");
    printRoomList(hotel1);

    Hotel hotel2("hotel2.cfg");
    printRoomList(hotel2);

    Hotel hotel3("hotel3.cfg");
    printRoomList(hotel3);

    return 0;
}