#include "Wrappers.h"
#include "CoffeeShop.h"
#include "CommercialAeroplane.h"
#include "Farm.h"
#include "Town.h"
#include "Airport.h"

CoffeeShopWrapper::CoffeeShopWrapper(CoffeeShop* ptr) : ptrToCoffeeShop(ptr){}
CoffeeShopWrapper::~CoffeeShopWrapper()
{
    delete ptrToCoffeeShop; 
}

CommercialAeroplaneWrapper::CommercialAeroplaneWrapper(CommercialAeroplane* ptr) : ptrToCommercialAeroplane(ptr){}
CommercialAeroplaneWrapper::~CommercialAeroplaneWrapper()
{
    delete ptrToCommercialAeroplane;
}

FarmWrapper::FarmWrapper(Farm* ptr) : ptrToFarm(ptr){}
FarmWrapper::~FarmWrapper()
{
    delete ptrToFarm;
}
   
TownWrapper::TownWrapper(Town* ptr) : ptrToTown(ptr){}
TownWrapper::~TownWrapper()
{
    delete ptrToTown;
}

AirportWrapper::AirportWrapper(Airport* ptr) : ptrToAirport(ptr){}
AirportWrapper::~AirportWrapper()
{
    delete ptrToAirport;
}
