#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) {}

SemiTruck::~SemiTruck() = default;
SemiTruck::SemiTruck(const SemiTruck&) = default;
SemiTruck& SemiTruck::operator = (const SemiTruck&) = default;

/*
    5) Add a Truck type
    semi-trucks don't evade when they're pulled over, unlike cars and motorcycles. 
*/
void SemiTruck::pullOver()
{
    setSpeed(0);
    std::cout << name << ": hello officer, what seems to be the problem?" << std::endl;
}

void SemiTruck::cruiseInRightLane()
{
    setSpeed(55);
    std::cout << name << ": gonna set cruise control and listen to some tunes." << std::endl;
}
