#pragma once
#include "LeakedObjectDetector.h"

struct CommercialAeroplane
{
    bool landingGearDown {false};
    int numEngines {4};
    int numSeats {524};
    float maxAirSpeedMPH {576.43f};
    float speedRequiredForTakeOff {213.56f};
    double fuelTankCapacityInLitres {238840.04};
    double flightRangeInKM {14310.23};
    std::string flightNum {"BA1234"};
    CommercialAeroplane();
    ~CommercialAeroplane();

    struct Cockpit
    {
        float age;
        int numSeats;
        int numWindows;
        float proximityWarningThreshold;
        float altitude;
        bool hasBlackBox;
        bool ElectronicFlightInstrumentSystem;
        bool groundProximityalarmStateOn;
        bool autoPilotLightOn;
        Cockpit();
        ~Cockpit();
        
        void printProximityAlarm() const;
        float increaseAirSpeed(const float& deltaV, const float& currentAirSpeed) const;
        bool groundProximityWarningAlarm(const bool& nearGround, const float& proximityWarningThreshold);
        bool autopilotDisengagement(const bool& pilotAndCopilotChecklistComplete);
        void increaseAltitude(const float& requireAltitude);
    };

    void accelerateForTakeOff(const float& groundSpeed, const bool& armDoorsAndCrossCheck, const bool& runWayClear, const bool& airspaceClear);
    void increaseGroundSpeed(const float& windSpeed) const;
    void transportPeople(const int& totalPassengers, const int& totalCrew) const;
    void provideInflightEntertainment(const int& passengerSeatNumber, const std::string& mediaSelction) const;
    JUCE_LEAK_DETECTOR(CommercialAeroplane)
};
