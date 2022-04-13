/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.



  MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

  Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
  
  If you didn't already:
     Make a pull request after you make your first commit
     pin the pull request link and this repl.it link to our DM thread in a single message.

  send me a DM to review your pull request when the project is ready for review.

  Wait for my code review.
  */

#include <iostream>
#include "LeakedObjectDetector.h"
#include "Wrappers.h"
#include "Airport.h"
#include "CoffeeShop.h"
#include "CommercialAeroplane.h"
#include "Farm.h"
#include "Town.h"

int main()
{
    std::cout << "good to go!" << std::endl;
    
    CoffeeShopWrapper coffeeShop ( new CoffeeShop() );
    coffeeShop.ptrToCoffeeShop->chargeCustomer(3, "Jennifer Aniston");
    std::cout << "Each coffee cost £" << coffeeShop.ptrToCoffeeShop->priceCoffee << std::endl;
    
    coffeeShop.ptrToCoffeeShop->annualProfit += coffeeShop.ptrToCoffeeShop->hostLocalArtistOnWalls(0.1f, 3214.51f, "Banksy");
    std::cout << "This has added funds to the total annual profit, which is now £" << coffeeShop.ptrToCoffeeShop->annualProfit  << std::endl;
    coffeeShop.ptrToCoffeeShop->printIncomeFromArt();
    coffeeShop.ptrToCoffeeShop->addDailyTakingsToAnnualProfit(345, 789.99f);
    
    CoffeeShop::Employee employee;
    employee.fullyTrained = coffeeShop.ptrToCoffeeShop->trainStaff(employee, "Milk frothing");
    std::cout << "Is employee number: " << employee.employeeID << " " << employee.firstName << " " << employee.lastName << " fully trained? " << (employee.fullyTrained == false ? "No" : "Yes") << std::endl;
    
    employee.deservesPromotion();
    employee.takeHoliday(156, 167);
    employee.makeDeliveries(13, 12);
    std::cout << employee.firstName << " " << employee.lastName << " made deliveries to " << employee.deliveryNumCustomers << " customers over " << employee.deliveryDistTravelled << " km" << std::endl;
    employee.printEmployeeDeliveries();
    employee.takeOutTrash(11, 3);
    
    FarmWrapper farm ( new Farm() );
    farm.ptrToFarm->sellSheep(12.11f);
    std::cout << "The farm made income of £" << farm.ptrToFarm->harvestCrop(true, 4, true, 1.30) << " from this years harvest." << std::endl;
    farm.ptrToFarm->constructNewBarn(true, 12345.45f);
    std::cout << "The farm has spent £" << farm.ptrToFarm->annualExpenses << " this year. It's remaining profit is £" << farm.ptrToFarm->annualProfit <<  "." << std::endl;
    farm.ptrToFarm->printFarmExpenses();
    farm.ptrToFarm->milkCows(120.0f, 35.0f, 3.50f);
    
    CommercialAeroplaneWrapper commercialAeroplane ( new CommercialAeroplane() );
    commercialAeroplane.ptrToCommercialAeroplane->accelerateForTakeOff(278, true, true, true);
    commercialAeroplane.ptrToCommercialAeroplane->provideInflightEntertainment(234, "Love Actually");
    commercialAeroplane.ptrToCommercialAeroplane->transportPeople(156, 7);
    commercialAeroplane.ptrToCommercialAeroplane->increaseGroundSpeed(26.8f);
    
    CommercialAeroplane::Cockpit cockpit;
    cockpit.autopilotDisengagement(true);
    cockpit.groundProximityWarningAlarm(true, 200);
    std::cout << "You are within " << cockpit.proximityWarningThreshold << " metres of the ground!" << std::endl;
    cockpit.printProximityAlarm();
    std::cout << "New airspeed is " << cockpit.increaseAirSpeed(122.1f, 345.f) << " mph" << std::endl;
    cockpit.increaseAltitude(20000.0f);
    
    TownWrapper town ( new Town() );
    town.ptrToTown->collectTaxes(0.1f);
    town.ptrToTown->controlAnimalDiseaseOutbreak("Foot and mouth", 70);
    
    AirportWrapper airport ( new Airport() );
    std::cout << "The airport collected £" << airport.ptrToAirport->collectGroundRent() << " in ground rent from the coffee shop." << std::endl;
    airport.ptrToAirport->guideAeroplaneToGate(23, true);
}
