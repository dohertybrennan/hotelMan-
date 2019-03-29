#pragma once
#include <fstream>
#include "hotel.h"

class KingRoom : public Room {
public:
    KingRoom(int uid, float baseCost)
    : Room(uid){mBaseCost = baseCost;};

    std::string getDescription();
    int getSleepCount();
    float getCost();
    ~KingRoom();

private:
    float mBaseCost;
};

class DoubleRoom : public Room {
public:
    DoubleRoom(int uid, float baseCost)
    : Room(uid){mBaseCost = baseCost;};

    std::string getDescription();
    int getSleepCount();
    float getCost();
    ~DoubleRoom();

private:
    float mBaseCost;
};

class SuiteRoom : public Room {
public:
    SuiteRoom(int uid, float baseCost)
    : Room(uid) {mBaseCost = baseCost;}

    std::string getDescription();
    int getSleepCount();
    float getCost();
    ~SuiteRoom();

private:
    float mBaseCost;
};