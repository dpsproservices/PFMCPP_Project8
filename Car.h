#pragma once

#include "Vehicle.h"

struct Car : public Vehicle
{
    Car(const std::string& s);

    void closeWindows();

    void setSpeed(int s) override;

    void tryToEvade() override;
};
