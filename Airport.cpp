#include <iostream>
#include"Airport.h"

Airport::Airport()
{
    std::cout << "\nAirport being constructed!" << std::endl;
}
Airport::~Airport()
{
    std::cout << "\nAirport being destructed!" << std::endl;
}

int Airport::collectGroundRent()
{
    int groundRent {1500};
    coffeeShop.annualProfit -= groundRent;
    return groundRent;
}

void Airport::guideAeroplaneToGate(const int& gateNumber, const bool& followMeCar) const
{
    if (followMeCar)
    {
        std::cout << "Follow me car dispatched" << std::endl;
        std::cout << commercialAeroplane.flightNum << " follow the car to gate " << gateNumber << std::endl;
    }
    else
    {
        std::cout << commercialAeroplane.flightNum << " head to gate " << gateNumber << std::endl;
    }
}
