/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */
#include <iostream>
/*
 copied UDT 1:
 */
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

        void makeDeliveries(float distTravelled, int numCustomers);
        void takeHoliday(int startDate, int endDate);
        bool deservesPromotion();
        void takeOutTrash(int bagsOfTrash, int numBagsEmployeeCanCarry);
    };

    float hostLocalArtistOnWalls(float percenatgeCommissionAgreed, float totalArtSales, std::string name);
    float chargeCustomer(int numberOfCoffees, std::string customerName);
    bool trainStaff(Employee employee, std::string trainingRequired);
    float addDailyTakingsToAnnualProfit(int numCoffeesSold, float totalFromAdditionalSales);

};

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

void CoffeeShop::Employee::makeDeliveries(float distTravelled, int numCustomers)
{
    float aveDistancePerCustomer = distTravelled / numCustomers;
    std::cout << "Employee number: " << employeeID << " made some deliveries. Number of kilometers per customer: " << aveDistancePerCustomer << " km" << std::endl;
    deliveryDistTravelled = distTravelled;
    deliveryNumCustomers = numCustomers;
}

void CoffeeShop::Employee::takeHoliday(int startDate, int endDate)
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

void CoffeeShop::Employee::takeOutTrash(int bagsOfTrash, int numBagsEmployeeCanCarry)
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

float CoffeeShop::hostLocalArtistOnWalls(float percenatgeCommissionAgreed, float totalArtSales, std::string name)
{
    float commissionTotal = percenatgeCommissionAgreed * totalArtSales;
    std::cout << name << " commission total: £" << commissionTotal << std::endl; 
    return commissionTotal;
}

float CoffeeShop::chargeCustomer(int numberOfCoffees, std::string customerName)
{
    float saleTotal = priceCoffee * numberOfCoffees;
    std::cout << customerName << " paid £" << saleTotal << std::endl;
    return saleTotal;
}

bool CoffeeShop::trainStaff(Employee employee, std::string trainingRequired)
{
    std::cout << employee.firstName << " " << employee.lastName << " has been trained on " << trainingRequired << std::endl;
    return true;
}

float CoffeeShop::addDailyTakingsToAnnualProfit(int numCoffeesSold, float totalFromAdditionalSales)
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
/*
 copied UDT 2:
 */
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

        float increaseAirSpeed(float deltaV, float currentAirSpeed);
        bool groundProximityWarningAlarm(bool nearGround, float proximityWarningThreshold);
        bool autopilotDisengagement(bool pilotAndCopilotChecklistComplete);
        void increaseAltitude(float requireAltitude);
    };

    void accelerateForTakeOff(float groundSpeed, bool armDoorsAndCrossCheck, bool runWayClear, bool airspaceClear);
    void increaseGroundSpeed(float windSpeed);
    void transportPeople(int totalPassengers, int totalCrew);
    void provideInflightEntertainment(int passengerSeatNumber, std::string mediaSelction);  
};

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

float CommercialAeroplane::Cockpit::increaseAirSpeed(float deltaV, float currentAirSpeed)
{
    return deltaV + currentAirSpeed;
}

bool CommercialAeroplane::Cockpit::groundProximityWarningAlarm(bool nearGround, float distFromGround)
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

bool CommercialAeroplane::Cockpit::autopilotDisengagement(bool pilotAndCopilotChecklistComplete)
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

void CommercialAeroplane::Cockpit::increaseAltitude(float requireAltitude)
{
    while (altitude < requireAltitude)
    {
        altitude += 100;
    }
    std::cout << "New altitude of " << altitude << "ft achieved" << std::endl;
}

void CommercialAeroplane::accelerateForTakeOff(float groundSpeed, bool armDoorsAndCrossCheck, bool runWayClear, bool airspaceClear)
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

void CommercialAeroplane::increaseGroundSpeed(float windSpeed)
{
    float currentGroundSpeed {0.0f};
    while (currentGroundSpeed < speedRequiredForTakeOff - windSpeed)
    {
        currentGroundSpeed += 15;
    }
    std::cout << "Speed for take off achieved... Take Off" << std::endl;
}

void CommercialAeroplane::transportPeople(int totalPassengers, int totalCrew)
{
    std::cout << "Total number on board: " << totalPassengers + totalCrew << std::endl;
}

void CommercialAeroplane::provideInflightEntertainment(int passengerSeatNumber, std::string mediaSelction)
{
    std::cout << "Passenger " << passengerSeatNumber << " selected " << mediaSelction << std::endl;
}
/*
 copied UDT 3:
 */
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

    float sellSheep(float priceOfSheep);
    double harvestCrop(bool isCropMature, int numFarmHands, bool machinesFueled, double priceOfCrop);
    void constructNewBarn(bool needNewBarn, float newConstructionBudget);
    void milkCows(int totalVolumeOfMilkNeeded, float volumeOfMilkAlreadyInTanks, float priceOfMilk);
};

Farm::Farm() : annualProfit(679000.78f), annualExpenses(0), cropYield (76543.21), farmLandAreaInHectare (84.3)
{
   std::cout << "\nFarm being constructed!" << std::endl;
}
Farm::~Farm()
{
   std::cout << "\nFarm being destructed!" << std::endl;
}

float Farm::sellSheep(float priceOfSheep)
{
    float sheepSale = priceOfSheep * numSheep;
    std::cout << "The farm made £" << sheepSale << " from the sale of " << numSheep << " sheep!" << std::endl;
    return sheepSale;
}

double Farm::harvestCrop(bool isCropMature, int numFarmHands, bool machinesFueled, double priceOfCrop)
{
    if (isCropMature && machinesFueled)
    {
        cropYield = farmLandAreaInHectare * numFarmHands;
        return priceOfCrop * cropYield; 
    }
    return 0;
}

void Farm::constructNewBarn(bool needNewBarn, float newConstructionBudget)
{
    std::cout << "The farm has " << numSheep << " sheep, " << numCows << " cows, " << "and a crop yield of " << cropYield << "." << std::endl;
    if (needNewBarn)
    {
        annualExpenses = newConstructionBudget;
        annualProfit -= newConstructionBudget;
    }
    
}
void Farm::milkCows(int totalVolumeOfMilkNeeded, float volumeOfMilkAlreadyInTanks, float priceOfMilk)
{
    while (volumeOfMilkAlreadyInTanks < totalVolumeOfMilkNeeded)
    {
        std::cout <<  "Milking in progress" << std::endl;
        volumeOfMilkAlreadyInTanks += 10;
    }
    std::cout << "Achieved total volume of milk needed: " << totalVolumeOfMilkNeeded << std::endl;
    std::cout << "Value of milk: £" << totalVolumeOfMilkNeeded * priceOfMilk << std::endl;
}
/*
 new UDT 4:
 with 2 member functions
 */
struct Town
{
    CoffeeShop coffeeShop;
    Farm farm;
    Town();
    ~Town();
    float collectTaxes(float taxRate);
    void controlAnimalDiseaseOutbreak(std::string diseaseName, float percenatgeInfected);

};

Town::Town()
{
   std::cout << "\nTown being contructed!" << std::endl;
}
Town::~Town()
{
   std::cout << "\nTown being destructed!" << std::endl;
}

float Town::collectTaxes(float taxRate)
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

void Town::controlAnimalDiseaseOutbreak(std::string diseaseName, float percenatgeInfected)
{
    std::cout << "There has been an outbreak of " << diseaseName << ". The town authority needs to cull " << percenatgeInfected << "% of the farm's sheep & cows."<< std::endl;
    int numSheepToCull = int(farm.numSheep * percenatgeInfected / 100);
    int numCowsToCull = int(farm.numCows * percenatgeInfected / 100);
    std::cout << numSheepToCull << " sheep & " << numCowsToCull << " were culled." << std::endl;
}

/*
 new UDT 5:
 with 2 member functions
 */
struct Airport
{
    CoffeeShop coffeeShop;
    CommercialAeroplane commercialAeroplane;
    Airport();
    ~Airport();
    int collectGroundRent();
    void guideAeroplaneToGate(int gateNumber, bool followMeCar);
};

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

void Airport::guideAeroplaneToGate(int gateNumber, bool followMeCar)
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

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    std::cout << "good to go!" << std::endl;

    CoffeeShop coffeeShop;
    coffeeShop.chargeCustomer(3, "Jennifer Aniston");
    std::cout << "Each coffee cost £" << coffeeShop.priceCoffee << std::endl;

    coffeeShop.annualProfit += coffeeShop.hostLocalArtistOnWalls(0.1f, 3214.51f, "Banksy");
    std::cout << "This has added funds to the total annual profit, which is now £" << coffeeShop.annualProfit  << std::endl;
    coffeeShop.addDailyTakingsToAnnualProfit(345, 789.99f);

    CoffeeShop::Employee employee;
    employee.fullyTrained = coffeeShop.trainStaff(employee, "Milk frothing");
    std::cout << "Is employee number: " << employee.employeeID << " " << employee.firstName << " " << employee.lastName << " fully trained? " << (employee.fullyTrained == 0 ? "No" : "Yes") << std::endl;

    employee.deservesPromotion();
    employee.takeHoliday(156, 167);
    employee.makeDeliveries(13, 12);
    std::cout << employee.firstName << " " << employee.lastName << " made deliveries to " << employee.deliveryNumCustomers << " customers over " << employee.deliveryDistTravelled << " km" << std::endl;
    employee.takeOutTrash(11, 3);

    Farm farm;
    farm.sellSheep(12.11f);

    std::cout << "The farm made income of £" << farm.harvestCrop(true, 4, true, 1.30) << " from this years harvest." << std::endl; 
    farm.constructNewBarn(true, 12345.45f);
    std::cout << "The farm has spent £" << farm.annualExpenses << " this year. It's remaining profit is £" << farm.annualProfit <<  "." << std::endl;
    farm.milkCows(120.0f, 35.0f, 3.50f);

    CommercialAeroplane commercialAeroplane;
    commercialAeroplane.accelerateForTakeOff(278, true, true, true);
    commercialAeroplane.provideInflightEntertainment(234, "Love Actually");
    commercialAeroplane.transportPeople(156, 7);
    commercialAeroplane.increaseGroundSpeed(26.8f);

    CommercialAeroplane::Cockpit cockpit;
    cockpit.autopilotDisengagement(true);
    cockpit.groundProximityWarningAlarm(true, 200);
    std::cout << "You are within " << cockpit.proximityWarningThreshold << " metres of the ground!" << std::endl;
    std::cout << "New airspeed is " << cockpit.increaseAirSpeed(122.1f, 345.f) << " mph" << std::endl;
    cockpit.increaseAltitude(20000.0f);

    Town town;
    town.collectTaxes(0.1f);
    town.controlAnimalDiseaseOutbreak("Foot and mouth", 70);

    Airport airport;
    std::cout << "The airport collected £" << airport.collectGroundRent() << " in ground rent from the coffee shop." << std::endl;
    airport.guideAeroplaneToGate(23, true);
}
