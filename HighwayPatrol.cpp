#include "HighwayPatrol.h"
#include <iostream>
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

HighwayPatrol::HighwayPatrol() : Vehicle("HighwayPatrol") { }

HighwayPatrol::~HighwayPatrol() = default;
HighwayPatrol::HighwayPatrol (const HighwayPatrol&) = default;
HighwayPatrol& HighwayPatrol::operator = (const HighwayPatrol&) = default;  

void HighwayPatrol::scanHighway(Highway* h)
{
    std::cout << name << ": scanning highway for speeders" << std::endl;

    for( size_t i = h->vehicles.size() - 1; static_cast<int>(i) >= 0; --i)
    {
        auto* v = h->vehicles[i];
        if( v->speed > h->speedLimit + 5 )
        {
            pullOver(v, v->speed > (h->speedLimit + 15), h );
            h->changeSpeed(50); //slow down for the highway patrol
        }
    }
}

void HighwayPatrol::pullOver( Vehicle* v, bool willArrest, Highway* h )
{
    std::cout << "\n\n";
    std::cout << name << ": vehicle is traveling " << v->speed - h->speedLimit << " miles per hour over the speed limit" << std::endl;
    if( willArrest )
    {
        //print the vehicle type in this std::cout between "THE [" and "] PULL". 
        std::string vehicleType;

        if(dynamic_cast<Car*>(v))
        {
            vehicleType = "Car";
        }       
        else if(dynamic_cast<Motorcycle*>(v))
        {
            vehicleType = "Motorcycle";
        }
        else if (dynamic_cast<SemiTruck*>(v))
        {
            vehicleType = "SemiTruck";
        } 

        std::cout << name << ": YOU IN THE [ " << vehicleType << " ] PULL OVER AND SHOW YOUR HANDS" << std::endl;
        std::cout << "EVERYONE ELSE, SLOW DOWN!! \n\n\n";
        h->removeVehicle(v);
    }
}
