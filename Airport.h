#pragma once
#include "LeakedObjectDetector.h"
#include "CoffeeShop.h"
#include "CommercialAeroplane.h"

struct Airport
{
    CoffeeShop coffeeShop;
    CommercialAeroplane commercialAeroplane;
    Airport();
    ~Airport();
    int collectGroundRent();
    void guideAeroplaneToGate(const int& gateNumber, const bool& followMeCar) const;
    JUCE_LEAK_DETECTOR(Airport)
};
