#include <iostream>
#include"Town.h"

Town::Town()
{
    std::cout << "\nTown being contructed!" << std::endl;
}
Town::~Town()
{
    std::cout << "\nTown being destructed!" << std::endl;
}

float Town::collectTaxes(const float& taxRate)
{
    float councilTaxIncome {0.0f};
    float coffeeShopTax = coffeeShop.annualProfit * taxRate;
    float farmTax = farm.annualProfit * taxRate;
    std::cout << "The Town council tax is being collected" << std::endl;
    std::cout << "The coffee shop income of £" << coffeeShop.annualProfit << " was taxed £" << coffeeShopTax << std::endl;
    std::cout << "The farm income of £" << farm.annualProfit << " was taxed £" << farmTax << std::endl;
    
    councilTaxIncome += coffeeShopTax + farmTax;
    
    std::cout << "The council tax collected a total of £" << councilTaxIncome << std::endl;
    coffeeShop.annualProfit *= 1 - taxRate;
    farm.annualProfit *= 1 - taxRate;
    std::cout << "The coffee shop's income after tax is £" << coffeeShop.annualProfit << std::endl;
    std::cout << "The farm's income after tax is £" << farm.annualProfit << std::endl;
    
    return councilTaxIncome;
}

void Town::controlAnimalDiseaseOutbreak(const std::string& diseaseName, const float& percenatgeInfected) const
{
    std::cout << "There has been an outbreak of " << diseaseName << ". The town authority needs to cull " << percenatgeInfected << "% of the farm's sheep & cows."<< std::endl;
    int numSheepToCull = int(farm.numSheep * percenatgeInfected / 100);
    int numCowsToCull = int(farm.numCows * percenatgeInfected / 100);
    std::cout << numSheepToCull << " sheep & " << numCowsToCull << " were culled." << std::endl;
}
