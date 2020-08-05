#pragma once 

#include "Highway.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

struct HighwayPatrol : Vehicle 
{
    
    HighwayPatrol();
    void scanHighway(Highway* h);

    void pullOver( Vehicle* v, bool willArrest, Highway* h );
};
