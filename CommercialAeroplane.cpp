#include <iostream>
#include "CommercialAeroplane.h"

CommercialAeroplane::CommercialAeroplane()
{
    std::cout << "\nCommercialAeroplane being constructed!" << std::endl;
}
CommercialAeroplane::~CommercialAeroplane()
{
    std::cout << "\nCommercialAeroplane being destructed!" << std::endl;
}

CommercialAeroplane::Cockpit::Cockpit() : age(1.35f), numSeats(5), numWindows(4), proximityWarningThreshold(1200.00f), altitude(10000.00f), hasBlackBox(true), ElectronicFlightInstrumentSystem(true), groundProximityalarmStateOn(false), autoPilotLightOn(true)
{
    std::cout << "\nCockpit being constructed!" << std::endl;
}
CommercialAeroplane::Cockpit::~Cockpit()
{
    std::cout << "\nCockpit being destructed!" << std::endl;
}

void CommercialAeroplane::Cockpit::printProximityAlarm() const
{
    std::cout << "You are within " << this->proximityWarningThreshold << " metres of the ground!" << std::endl;
}

float CommercialAeroplane::Cockpit::increaseAirSpeed(const float& deltaV, const float& currentAirSpeed) const
{
    return deltaV + currentAirSpeed;
}

bool CommercialAeroplane::Cockpit::groundProximityWarningAlarm(const bool& nearGround, const float& distFromGround)
{
    if(nearGround == true && distFromGround < proximityWarningThreshold)
    {
        groundProximityalarmStateOn = true;
        std::cout << "Warning! Pull Up! Warning! Pull Up!" << std::endl;
    }
    else
    {
        groundProximityalarmStateOn = false;
    }
    return groundProximityalarmStateOn;
}

bool CommercialAeroplane::Cockpit::autopilotDisengagement(const bool& pilotAndCopilotChecklistComplete)
{
    std::cout << "Autopilot currently engaged?: " << autoPilotLightOn << std::endl;
    if (pilotAndCopilotChecklistComplete)
    {
        autoPilotLightOn = false;
        std::cout << "Pilot and copilot checklist complete" << std::endl;
        std::cout << "Autopilot disengaged" << std::endl;
    }
    else
    {
        autoPilotLightOn = true;
        std::cout << "Autopilot engaged" << std::endl;
    }
    return autoPilotLightOn;
}

void CommercialAeroplane::Cockpit::increaseAltitude(const float& requireAltitude)
{
    while (altitude < requireAltitude)
    {
        altitude += 100;
    }
    std::cout << "New altitude of " << altitude << "ft achieved" << std::endl;
}

void CommercialAeroplane::accelerateForTakeOff(const float& groundSpeed, const bool& armDoorsAndCrossCheck, const bool& runWayClear, const bool& airspaceClear)
{
    if (runWayClear && armDoorsAndCrossCheck && airspaceClear)
    {
        std::cout << "Clear for take off" << std::endl;
    
        if (groundSpeed > speedRequiredForTakeOff)
        {
            landingGearDown = false;
        }
    }
}

void CommercialAeroplane::increaseGroundSpeed(const float& windSpeed) const
{
    float currentGroundSpeed {0.0f};
    while (currentGroundSpeed < speedRequiredForTakeOff - windSpeed)
    {
        currentGroundSpeed += 15;
    }
    std::cout << "Speed for take off achieved... Take Off" << std::endl;
}

void CommercialAeroplane::transportPeople(const int& totalPassengers, const int& totalCrew) const
{
    std::cout << "Total number on board: " << totalPassengers + totalCrew << std::endl;
}

void CommercialAeroplane::provideInflightEntertainment(const int& passengerSeatNumber, const std::string& mediaSelction) const
{
    std::cout << "Passenger " << passengerSeatNumber << " selected " << mediaSelction << std::endl;
}
