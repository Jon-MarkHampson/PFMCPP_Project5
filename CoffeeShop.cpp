#include <iostream>
#include "CoffeeShop.h"


CoffeeShop::CoffeeShop() : numChairs(54), numStaff(7), numToilets(2)
{
    std::cout << "\nCoffeeShop being constructed!" << std::endl;
}
CoffeeShop::~CoffeeShop()
{
    std::cout << "\nCoffeeShop being destructed!" << std::endl;
}

CoffeeShop::Employee::Employee() : employeeID(12345), fullyTrained(false), salary(30000.00f), deliveryDistTravelled(0.f), deliveryNumCustomers(0)
{
    std::cout << "\nEmployee being constructed!" << std::endl;
}
CoffeeShop::Employee::~Employee()
{
    std::cout << "\nEmployee being destructed!" << std::endl;
}

void CoffeeShop::Employee::printEmployeeDeliveries() const
{
    std::cout << this->firstName << " " << this->lastName << " made deliveries to " << this->deliveryNumCustomers << " customers over " << this->deliveryDistTravelled << " km" <<     std::endl;
}

void CoffeeShop::Employee::makeDeliveries(const float& distTravelled, const int& numCustomers)
{
    float aveDistancePerCustomer = distTravelled / numCustomers;
    std::cout << "Employee number: " << employeeID << " made some deliveries. Number of kilometers per customer: " << aveDistancePerCustomer << " km" << std::endl;
    deliveryDistTravelled = distTravelled;
    deliveryNumCustomers = numCustomers;
}

void CoffeeShop::Employee::takeHoliday(const int& startDate, const int& endDate) const
{
    int numDaysHolidayTaken = endDate - startDate;
    std::cout << numDaysHolidayTaken << " days holiday taken by " << firstName << " " << lastName << std::endl;
}

bool CoffeeShop::Employee::deservesPromotion()
{
    if (fullyTrained)
    {
        std::cout << firstName << " " << lastName << " deserves a promotion!" << std::endl;
        salary += 1000;
        return true;
    }
    return false;
}

void CoffeeShop::Employee::takeOutTrash(const int& bagsOfTrash, const int& numBagsEmployeeCanCarry) const
{
    int numOfTripsToDumpster = 0;
    for (int i = 0; i < bagsOfTrash/numBagsEmployeeCanCarry; ++i)
    {
        std::cout << firstName << " " << lastName << " took " << numBagsEmployeeCanCarry << " bags to the dumpster" << std::endl;
        ++numOfTripsToDumpster;
    }
    if (bagsOfTrash%numBagsEmployeeCanCarry != 0)
    {
        std::cout << firstName << " " << lastName << " took " << bagsOfTrash%numBagsEmployeeCanCarry << " bags to the dumpster" << std::endl;
        ++numOfTripsToDumpster;
    }
    std::cout << firstName << " " << lastName << " made a total of " << numOfTripsToDumpster << " trips to the dumpster" << std::endl;
}

void CoffeeShop::printIncomeFromArt() const
{
    std::cout << "This has added funds to the total annual profit, which is now £" << this->annualProfit  << std::endl;
}

float CoffeeShop::hostLocalArtistOnWalls(const float& percenatgeCommissionAgreed, const float& totalArtSales, const std::string& name) const
{
    float commissionTotal = percenatgeCommissionAgreed * totalArtSales;
    std::cout << name << " commission total: £" << commissionTotal << std::endl;
    return commissionTotal;
}

float CoffeeShop::chargeCustomer(const int& numberOfCoffees, const std::string& customerName) const
{
    float saleTotal = priceCoffee * numberOfCoffees;
    std::cout << customerName << " paid £" << saleTotal << std::endl;
    std::cout << "Each coffee from coffeeShop cost £" << this->priceCoffee << std::endl;
    return saleTotal;
}

bool CoffeeShop::trainStaff(const Employee& employee, const std::string& trainingRequired) const
{
    std::cout << employee.firstName << " " << employee.lastName << " has been trained on " << trainingRequired << std::endl;
    return true;
}

float CoffeeShop::addDailyTakingsToAnnualProfit(const int& numCoffeesSold, const float& totalFromAdditionalSales)
{
    float dailySalesTotal {0};
    for (int i = 0; i < numCoffeesSold; ++i)
    {
        dailySalesTotal += priceCoffee;
    }
    dailySalesTotal += totalFromAdditionalSales;
    annualSales += dailySalesTotal;
    std::cout << "Daily sales total is £" << dailySalesTotal << std::endl;
    std::cout << "New annual sales total is £" << annualSales << std::endl;
    return dailySalesTotal;
}
