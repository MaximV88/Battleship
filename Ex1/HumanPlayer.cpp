/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of HumanPlayer Class    *
 ***********************************************************/

#include <iostream>

#include "HumanPlayer.h"
#include "Ship.h"
#include "Map.h"

using namespace std;

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: getCoordinate                                                                 *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: It first prints to the Terminal a requeset for a row, takes the input,*
 *                        asks again for the Column. It then checks if the input has been       *
 *                        correctly input. If yes the function will return the input as a       *
 *                        Coordinate. If not, it will recursivly call the getCoordinate function*
 *                        until a valid input has been made and will return it.                 *
 * *********************************************************************************************/

Coordinate HumanPlayer::getCoordinate() const {
    
    //Now ask for the coordinates
    cout << "\nEnter the desired Row position (Letter): ";
    
    int iRowSelection =  m_cScanner.scanString(1, 1)[0] - 'A';
    
    cout << "Enter the desired Column position (Numbers): ";
    
    int iColumnSelection = m_cScanner.scanInt(-1, Settings::getInstance().getMapSize().getHeight());
    
    //Verify that the input is correct - start with Row
    if (iRowSelection < 0 || iRowSelection > Settings::getInstance().getMapSize().getWidth()) {
        
        cout << "The input for Row you have entered is incorrect. Please try again.\n";
        
        //Wrong - request coordiantes again
        return getCoordinate();
        
    }
    
    if (iColumnSelection < 0 || iColumnSelection > Settings::getInstance().getMapSize().getHeight()) {
        
        cout << "The input for Column you have entered is incorrect. Please try again.\n";
        
        //Wrong - request coordiantes again
        return getCoordinate();
        
    }
    
    //Otherwise we are clear and send back the coordiantes
    return Coordinate(iRowSelection, iColumnSelection);
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: HumanPlayer Constructor                                                       *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with a default "Player" name via the           *
 *                        superclass's Player constructor.                                      *
 * *********************************************************************************************/

HumanPlayer::HumanPlayer() : Player("Player") { }

/************************************************************************************************
 * function name: HumanPlayer Constructor                                                       *
 * The Input: const string object (reference)                                                   *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with the input string as name via the          *
 *                        superclass's Player constructor.                                      *
 * *********************************************************************************************/

HumanPlayer::HumanPlayer(const std::string& strName) : Player(strName) { }

/**********************************************************************************************
 * function name: act                                                                         *
 * The Input: Map object (pointer)                                                            *
 * The output: none                                                                           *
 * The Function Opertion: A while loop is executed, which is only broken with a valid action  *
 *                        on the Map object. during each cycle of the loop, it tries to hit   *
 *                        the map in the specified location (from the getCoordinate function) *
 *                        If the hit was successful (meaning that an action was performed,    *
 *                        the loop is broken. Otherwise it is continued until a valid action  *
 *                        has been performed.                                                 *
 * *******************************************************************************************/

void HumanPlayer::act(Map* cMap) {
    
    //The Human already sees the map, so no need to print it.
    //Instead, it prints the question to the terminal and gets input
    cout << "Select position to attack!";
    
    bool bLoopInvariant = true;
    
    while (bLoopInvariant) {
        
        //Choose a random position
        Coordinate cHitCoordinate = getCoordinate();
        
        switch (cMap->hit(cHitCoordinate)) {
            case MapRepresentationHit:

                //Made a hit, meaning it was a successful play
                bLoopInvariant = false;
                
                break;
                
            case MapRepresentationMissed:
                
                //Still performed an action, and thats a successful play
                bLoopInvariant = false;
                
                break;
                
            case MapRepresentationOccupied:
                
                //It's not legal to make a move on that spot, so its not a success
                //Keep the loop
                
                //Loop until successful position
                cout << "The position you have selected was already performed previously.\nPlease choose again.\n";
                
                
                break;
                
                //Shouldnt reach that
            default: break;
        }
        
    }

}

/**********************************************************************************************
 * function name: assign                                                                      *
 * The Input: Map object (pointer)                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Asks the player through a Terminal print what is the desired        *
 *                        ship to place (type), and afterwards it desired direction. it then  *
 *                        creates the specified ship and checks against the map if the        *
 *                        position is valid. If yes, it adds it to the map. Otherwise it      *
 *                        recursivly calls this function again until a valid input has been   *
 *                        entered.                                                            *
 * *******************************************************************************************/

void HumanPlayer::assign(Map* cMap) {
    
    
    //We use a place action - meaning that there is an input command that
    //takes the required coordinates, checks with the map and if valid assigns it.
    cout <<  "\n" << getName() << ", Enter the Ship type you want to place: \n";
    cout <<  "1. Type1x2 - Width: 2, Height: 1\n";
    cout <<  "2. Type1x3 - Width: 3, Height: 1\n";
    cout <<  "3. Type1x4 - Width: 4, Height: 1\n";
    cout <<  "4. Type2x2 - Width: 2, Height: 2\n";
    cout <<  "5. Type2x3 - Width: 3, Height: 2\n";
    
    cout << "\nWaiting for selection: ";
    
    ShipType eSelectedShipType;
    
    eSelectedShipType = ShipType(m_cScanner.scanInt(ShipTypeNone, ShipTypeTotalNumber));
    
    //Ask for a direction of the ship
    cout << "\nEnter a direction for the ship to face.\n";
    cout << "1. East:  Origin point in the lower left corner\n";
    cout << "2. North: Origin point in the lower right corner\n";
    cout << "3. South: Origin point in the upper left corner\n";
    cout << "4. West:  Origin point in the upper right corner\n";
    
    cout << "\nWaiting for selection: ";

    ShipDirection eSelectedShipDirection = ShipDirection(m_cScanner.scanInt(ShipDirectionNone, ShipDirectionTotalNumber));

    Coordinate cSelectedCoordiante = getCoordinate();
    
    //Create a new ship
    Ship *cAssignedShip = new Ship(eSelectedShipType, eSelectedShipDirection, cSelectedCoordiante);
    
    //Check to see if it's possible to add the ship
    if (cMap->isValid(*cAssignedShip)) {
        
        //OK to add
        cMap->addShip(*cAssignedShip);
        
        //Delete after addition
        delete cAssignedShip;
    }
    else {
        
        cout << "Cannot place a Ship in the requested position. Please try again. " << endl;
        
        //Delete before another try
        delete cAssignedShip;
        
        //Try again
        assign(cMap);
        
    }
    
}

