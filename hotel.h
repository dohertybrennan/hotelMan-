#pragma once

#include <string>
#include <list>

// abstract class that represents a hotel room
class Room {
public:
    Room(int uid) : mUID(uid) { }
    virtual ~Room() {}

    int getUID() {return mUID;}

    virtual std::string getDescription() = 0;
    virtual int getSleepCount() = 0;
    virtual float getCost() = 0;

private:
    int mUID;
};

// class that represents a hotel, which has a name
// and a list of rooms.
class Hotel {
public:
    Hotel(std::string cfgFilePath);
    ~Hotel();
    std::string getName();
    std::list<Room*>& getRoomList();

private:
    std::string mName;
    std::list<Room*> mRooms;
    static int mUID;
};