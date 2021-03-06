#pragma once 

#include "Highway.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

struct HighwayPatrol : Vehicle 
{
    
    HighwayPatrol();
    ~HighwayPatrol() override;

    HighwayPatrol(const HighwayPatrol&);
    HighwayPatrol& operator = (const HighwayPatrol&);
    
    void scanHighway(Highway* h);

    void pullOver( Vehicle* v, bool willArrest, Highway* h );
};
