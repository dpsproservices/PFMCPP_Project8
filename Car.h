#pragma once

#include "Vehicle.h"

struct Car : public Vehicle
{
    Car(const std::string& s);

    ~Car() override;
    Car(const Car&);
    Car& operator = (const Car&);

    void closeWindows();

    void setSpeed(int s) override;

    void tryToEvade() override;
};
