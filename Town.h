#pragma once
#include "LeakedObjectDetector.h"
#include "CoffeeShop.h"
#include "Farm.h"

struct Town
{
    CoffeeShop coffeeShop;
    Farm farm;
    Town();
    ~Town();

    float collectTaxes(const float& taxRate);
    void controlAnimalDiseaseOutbreak(const std::string& diseaseName, const float& percenatgeInfected) const;
    JUCE_LEAK_DETECTOR(Town)
};
