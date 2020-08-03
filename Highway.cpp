#include "Highway.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"
#include "HighwayPatrol.h"
//#include <cassert>

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    //assert(false);

    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    */
    if( auto* car = dynamic_cast<Car*>(v))
    {
        car->setSpeed(speedLimit);
    }
    else if( auto* motorcycle = dynamic_cast<Motorcycle*>(v) )
    {
        motorcycle->setSpeed(speedLimit);
    }
    else if( auto* semitruck = dynamic_cast<SemiTruck*>(v) )
    {
        semitruck->setSpeed(speedLimit);
    }
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    //assert(false);

    /*
    depending on the derived type, call the member function that tries to evade the cops. 

    trucks pull over, but cars and bikes try to evade!!
    */
    if( auto* car = dynamic_cast<Car*>(v))
    {
        car->tryToEvade();
    }
    else if( auto* motorcycle = dynamic_cast<Motorcycle*>(v) )
    {
        motorcycle->tryToEvade();
    }
    else if( auto* semitruck = dynamic_cast<SemiTruck*>(v) )
    {
        //highwayPatrol->pullOver( semitruck, true, this )
    }    
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}
