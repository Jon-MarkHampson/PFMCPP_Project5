#pragma once
struct CoffeeShop;
struct CommercialAeroplane;
struct Farm;
struct Town;
struct Airport;

struct CoffeeShopWrapper
{
    CoffeeShopWrapper(CoffeeShop* ptr);
    ~CoffeeShopWrapper();
    CoffeeShop* ptrToCoffeeShop = nullptr;
};

struct CommercialAeroplaneWrapper
{
    CommercialAeroplaneWrapper(CommercialAeroplane* ptr);
    ~CommercialAeroplaneWrapper();
    CommercialAeroplane* ptrToCommercialAeroplane = nullptr;
};

struct FarmWrapper
{
    FarmWrapper(Farm* ptr);
    ~FarmWrapper();
    Farm* ptrToFarm = nullptr;
};

struct TownWrapper
{
    TownWrapper(Town* ptr);
    ~TownWrapper();
    Town* ptrToTown = nullptr;
};

struct AirportWrapper
{
    AirportWrapper(Airport* ptr);
    ~AirportWrapper();
    Airport* ptrToAirport = nullptr;
};
