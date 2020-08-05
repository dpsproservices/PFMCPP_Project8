#pragma once

#include "Vehicle.h"

struct SemiTruck : public Vehicle
{
    SemiTruck(const std::string& n);

    void setSpeed(int s) override;

    void tryToEvade() override;
};
