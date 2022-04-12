#pragma once
#include "LeakedObjectDetector.h"

struct CoffeeShop
{
    int numChairs;
    int numStaff;
    int numToilets;
    float annualProfit {45362.78f};
    float annualSales {345678.9f};
    float priceCoffee {3.40f};
    CoffeeShop();
    ~CoffeeShop();

    struct Employee
    {
        std::string firstName {"Magnus"};
        std::string lastName {"Magnusson"};
        int employeeID = 12345;
        bool fullyTrained = false;
        float salary = 30000.00f;
        float deliveryDistTravelled;
        int deliveryNumCustomers;
        Employee();
        ~Employee();
        
        void printEmployeeDeliveries() const;
        void makeDeliveries(const float& distTravelled, const int& numCustomers);
        void takeHoliday(const int& startDate,const int& endDate) const;
        bool deservesPromotion();
        void takeOutTrash(const int& bagsOfTrash, const int& numBagsEmployeeCanCarry) const;
    };

    void printIncomeFromArt() const;
    float hostLocalArtistOnWalls(const float& percenatgeCommissionAgreed, const float& totalArtSales, const std::string& name) const;
    float chargeCustomer(const int& numberOfCoffees, const std::string& customerName) const;
    bool trainStaff(const Employee& employee, const std::string& trainingRequired) const;
    float addDailyTakingsToAnnualProfit(const int& numCoffeesSold, const float& totalFromAdditionalSales);
    JUCE_LEAK_DETECTOR(CoffeeShop)
 };
