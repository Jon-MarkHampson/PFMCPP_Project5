#pragma once
#include "LeakedObjectDetector.h"

struct Farm
{
    int numSheep {1234};
    int numCows {321};
    int numFarmers {6};
    float annualProfit;
    float annualExpenses;
    double cropYield;
    double farmLandAreaInHectare;
    Farm();
    ~Farm();
    
    void printFarmExpenses() const;
    float sellSheep(const float& priceOfSheep) const;
    double harvestCrop(const bool& isCropMature, const int& numFarmHands, const bool& machinesFueled, const double& priceOfCrop);
    void constructNewBarn(const bool& needNewBarn, const float& newConstructionBudget);
    void milkCows(const int& totalVolumeOfMilkNeeded, float volumeOfMilkAlreadyInTanks, const float& priceOfMilk) const;
    JUCE_LEAK_DETECTOR(Farm)
};
