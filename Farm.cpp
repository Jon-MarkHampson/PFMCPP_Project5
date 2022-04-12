#include<iostream>
#include "Farm.h"

Farm::Farm() : annualProfit(679000.78f), annualExpenses(0), cropYield (76543.21), farmLandAreaInHectare (84.3)
{
    std::cout << "\nFarm being constructed!" << std::endl;
}
Farm::~Farm()
{
    std::cout << "\nFarm being destructed!" << std::endl;
}

void Farm::printFarmExpenses() const
{
    std::cout << "The farm has spent £" << this->annualExpenses << " this year. It's remaining profit is £" << this->annualProfit <<  "." << std::endl;
}

float Farm::sellSheep(const float& priceOfSheep) const
{
    float sheepSale = priceOfSheep * numSheep;
    std::cout << "The farm made £" << sheepSale << " from the sale of " << numSheep << " sheep!" << std::endl;
    return sheepSale;
}

double Farm::harvestCrop(const bool& isCropMature, const int& numFarmHands, const bool& machinesFueled, const double& priceOfCrop)
{
    if (isCropMature && machinesFueled)
    {
        cropYield = farmLandAreaInHectare * numFarmHands;
        return priceOfCrop * cropYield;
    }
    return 0;
}

void Farm::constructNewBarn(const bool& needNewBarn, const float& newConstructionBudget)
{
    std::cout << "The farm has " << numSheep << " sheep, " << numCows << " cows, " << "and a crop yield of " << cropYield << "." << std::endl;
    if (needNewBarn)
    {
        annualExpenses = newConstructionBudget;
        annualProfit -= newConstructionBudget;
    }
}
void Farm::milkCows(const int& totalVolumeOfMilkNeeded, float volumeOfMilkAlreadyInTanks, const float& priceOfMilk) const
{
    while (volumeOfMilkAlreadyInTanks < totalVolumeOfMilkNeeded)
    {
        std::cout <<  "Milking in progress" << std::endl;
        volumeOfMilkAlreadyInTanks += 10;
    }
    std::cout << "Achieved total volume of milk needed: " << totalVolumeOfMilkNeeded << std::endl;
    std::cout << "Value of milk: £" << totalVolumeOfMilkNeeded * priceOfMilk << std::endl;
}
