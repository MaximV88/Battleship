/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of ComputerPlayer Class *
 ***********************************************************/

#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <limits>

#include "ComputerPlayer.h"
#include "Settings.h"
#include "Ship.h"
#include "Map.h"
#include "ActionMoveBy.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: actEasy                                                                       *
 * The Input: Map object (pointer)                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Performs a hit on the map with a guess, and returns true if the map   *
 *                        was changed, false otherwise.                                         *
 * *********************************************************************************************/

bool ComputerPlayer::actEasy(Map* cMap) {
    
    //This is simply guessing
    switch (cMap->hit(guess())) {
        case MapRepresentationHit:
            
            //Made a hit, meaning it was a successful play
            return true;
            
            break;
            
        case MapRepresentationMissed:
            
            //Still performed an action, and thats a successful play
            return true;
            
            break;
            
        case MapRepresentationOccupied:
            
            //It's not legal to make a move on that spot, so its not a success
            return false;
            
            break;
            
            //Shouldnt reach that
        default:
            
            return false;
            
            break;
            
    }
    
}

/************************************************************************************************
 * function name: actMedium                                                                     *
 * The Input: Map object (pointer)                                                              *
 * The output: none                                                                             *
 * The Function Opertion: If a hit was successful it stores the adjacent coordinates from that  *
 *                        hit into a stack. Then, on the next turn it checks if there are any   *
 *                        coordinates on the stack. If there are, it continues to try and hit   *
 *                        the map with them. On successful hit, adds the adjacent coordinates   *
 *                        of that hit. When the stack is empty, continue guessing. Returns true *
 *                        if made a change on the map, false otherwise.                         *
 * *********************************************************************************************/

bool ComputerPlayer::actMedium(Map* cMap) {
    
    /*
     * Try to guess until hitting something, then try to find the completed shape
     * using an algorithm similar to DFS. once hit, put all of the adjacent legal coordinates
     * into a stack, and try them one by one until the stack is empty. every time there is a
     * successful hit, put all of the hit's adjacent coordiantes into the stack. once the stack
     * is empty, guess.
     */
    
    
    //This will be used as the hitting position, the starting value is not considered
    Coordinate cHit = Coordinate(0,0);
    
    //if the stack is empty - guess
    if (m_vcCoordiantes.empty()) {
        
        //Calling the guess
        cHit = guess();
        
    }
    else {
        
        //The stack is not empty, and that requires to try every coordinate stored in it
        cHit = m_vcCoordiantes.top();
        
        //Pop the saved coordinate
        m_vcCoordiantes.pop();
        
    }
    
    //Make a hit with the coordinate given
    switch (cMap->hit(cHit)) {
        case MapRepresentationHit:
            
            //Made a successful hit, put the adjacent coordiantes into a stack
            addAdjacentIntoStack(cHit);
            
            //A successful play
            return true;
            
            break;
            
        case MapRepresentationMissed:
            
            //Its not a good hit, but still a successful play.
            return true;
            
        case MapRepresentationOccupied:
            
            //Its not a legal move, so its not a successful play
            return false;
            
            //Shouldnt reach that
        default: return false; break;
    }
    
}

/************************************************************************************************
 * function name: actHard                                                                       *
 * The Input: Map object (pointer)                                                              *
 * The output: none                                                                             *
 * The Function Opertion: If a hit was successful it stores the adjacent coordinates from that  *
 *                        hit into a stack. Then, on the next turn it checks if there are any   *
 *                        coordinates on the stack. If there are, it continues to try and hit   *
 *                        the map with them. On successful hit, adds the adjacent coordinates   *
 *                        of that hit. When the stack is empty, it tries to guess a location    *
 *                        that is in a chessboard configuration, that way a ship must be hit.   *
 *                        Returns true if made a change on the map, false otherwise.            *
 * *********************************************************************************************/

bool ComputerPlayer::actHard(Map* cMap) {
    
    /*
     * Instead of guessing, move across the board with a pattern, then try to find the completed shape
     * using an algorithm similar to DFS. once hit, put all of the adjacent legal coordinates
     * into a stack, and try them one by one until the stack is empty. every time there is a
     * successful hit, put all of the hit's adjacent coordiantes into the stack. once the stack
     * is empty, continue with the pattern.
     */
    
    //This will be used as the hitting position, the starting value is not considered
    Coordinate cHit = Coordinate(0,0);
    
    //if the stack is empty - guess
    if (m_vcCoordiantes.empty()) {
        
        /*
         * Make an iterative walk using a 'chessboard' like steps:
         * the remainder of the total steps divided by the map's width
         * will be used as height, and the modulo of the total steps
         * by the map width will be used as width
         */
        
        //Make a guess and check if its in the chessboard configuration, continue guessing until finding a correct guess
        bool bLoopInvariant = true;
        
        while (bLoopInvariant) {
            
            //Make a guess
            cHit = guess();
            
            //Checks if its in a chessboard position
            if (((cHit.getX() % 2 == 0) && (cHit.getY() % 2 != 0)) ||
                ((cHit.getX() % 2 != 0) && (cHit.getY() % 2 == 0)))
                bLoopInvariant = false;
            
            //Otherwise continue guessing
            
        }
        
    }
    else {
        
        //The stack is not empty, and that requires to try every coordinate stored in it
        cHit = m_vcCoordiantes.top();
        
        //Pop the saved coordinate
        m_vcCoordiantes.pop();
        
    }
    
    //Make a hit with the coordinate given
    switch (cMap->hit(cHit)) {
        case MapRepresentationHit:
            
            //Made a successful hit, put the adjacent coordiantes into a stack
            addAdjacentIntoStack(cHit);
            
            //A successful play
            return true;
            
            break;
            
        case MapRepresentationMissed:
            
            //Its not a good hit, but still a successful play.
            return true;
            
        case MapRepresentationOccupied:
            
            //Its not a legal move, so its not a successful play
            return false;
            
            //Shouldnt reach that
        default: return false; break;
    }
    
}

/************************************************************************************************
 * function name: guess                                                                         *
 * The Input: none                                                                              *
 * The output: Coordinate object                                                                *
 * The Function Opertion: Creates two random integers, creates a coordinate with them           *
 *                        and returns the coordinate.                                           *
 * *********************************************************************************************/

Coordinate ComputerPlayer::guess() const {
    
    //Choose a random position
    unsigned int uiPositionX = int(rand() % Settings::getInstance().getMapSize().getWidth());
    unsigned int uiPositionY = int(rand() % Settings::getInstance().getMapSize().getHeight());
    
    //Return the result
    return Coordinate(uiPositionX, uiPositionY);
    
}

/************************************************************************************************
 * function name: addAdjacentIntoStack                                                          *
 * The Input: const Coordinate object (reference)                                               *
 * The output: none                                                                             *
 * The Function Opertion: Checks every adjacent valid configuration of coordinates based on the *
 *                        input, and adds those who are valid to the coordinate stack.          *
 * *********************************************************************************************/

void ComputerPlayer::addAdjacentIntoStack(const Coordinate &cCoordinate) {
    
    /*
     * As long as the adjacent coordiantes are in a legal (not outside the map)
     * position, add them into the stack. there are 4 possibilities so its done
     * with manual checking. The assumption is that the input coordinate is in legal position.
     */
    
    /* the '+' represents the given coordiante:
     *
     *     *
     *    *+*
     *     *
     *
     */
    
    //Check top coordinate
    if (cCoordinate.getY() + 1 <= Settings::getInstance().getMapSize().getHeight()) {
        
        //Create a Coordinate with height larger by 1, and stack it
        Coordinate cTop = Coordinate(cCoordinate.getX(), cCoordinate.getY() + 1);
        
        //Push the coordinate
        m_vcCoordiantes.push(cTop);
        
    }
    
    //Check the bottom coordiante
    if (cCoordinate.getY() - 1 >= 0) {
        
        //Create a Coordinate with height smaller by 1, and stack it
        Coordinate cBottom = Coordinate(cCoordinate.getX(), cCoordinate.getY() - 1);
        
        //Push the coordinate
        m_vcCoordiantes.push(cBottom);
        
    }
    
    //Check right coordinate
    if (cCoordinate.getX() + 1 <= Settings::getInstance().getMapSize().getWidth()) {
        
        //Create a Coordinate with X larger by 1, and stack it
        Coordinate cRight = Coordinate(cCoordinate.getX() + 1, cCoordinate.getY());
        
        //Push the coordinate
        m_vcCoordiantes.push(cRight);
        
    }
    
    //Check the left coordiante
    if (cCoordinate.getX() - 1 >= 0) {
        
        //Create a Coordinate with X smaller by 1, and stack it
        Coordinate cLeft = Coordinate(cCoordinate.getX() - 1, cCoordinate.getY());
        
        //Push the coordinate
        m_vcCoordiantes.push(cLeft);
        
    }
    
}

/************************************************************************************************
 * function name: checkExtendedArea                                                             *
 * The Input: Ship object (pointer), Map object (pointer)                                       *
 * The output: bool                                                                             *
 * The Function Opertion: Moves the input ship by 1 block in every adjacent direction and checks*
 *                        if its a valid location. It continues to do so for every one of the   *
 *                        4 possible directions. If any of them is false (not valid), returns   *
 *                        false. Otherwise returns true.                                        *
 * *********************************************************************************************/

bool ComputerPlayer::checkExtendedArea(Ship* cShip, Map* cMap) {
    
    //First check the original
    if (!cMap->isValid(*cShip))
        return false;
    
    //Move the ship to the right
    ActionMoveBy(cShip, 1, 0).apply();
    if (!cMap->isValid(*cShip))
        return false;
    
    
    //Move the ship to the left
    ActionMoveBy(cShip, -2, 0).apply();
    if (!cMap->isValid(*cShip))
        return false;
    
    //Move the ship to the top
    ActionMoveBy(cShip, 1, 0).apply();
    ActionMoveBy(cShip, 0, 1).apply();
    if (!cMap->isValid(*cShip))
        return false;
    
    //Move the ship to the bottom
    ActionMoveBy(cShip, 0, -2).apply();
    if (!cMap->isValid(*cShip))
        return false;
    
    
    //Move it to the original position
    ActionMoveBy(cShip, 0, 1).apply();
    
    //Everything is ok
    return true;
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: ComputerPlayer Constructor                                                    *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the player with easy difficulty and a random name         *
 * *********************************************************************************************/

ComputerPlayer::ComputerPlayer() : Player("CPU") {
    
    m_ePlayerDifficulty = PlayerDifficultyEasy;
    
    //Just for the fun of it - create a random name
    switch (rand()%10) {
            
        case 0: changeName("Walter White"); break;
        case 1: changeName("Jesse Pinkman"); break;
        case 2: changeName("Gustavo Fring"); break;
        case 3: changeName("Hector Salamanca"); break;
        case 4: changeName("Daryl Dixon"); break;
        case 5: changeName("Rick Grimes"); break;
        case 6: changeName("Darth Vader"); break;
        case 7: changeName("Francis Underwood"); break;
        case 8: changeName("Hank Schrader"); break;
        case 9: changeName("Saul Goodman"); break;

    }

}

/**********************************************************************************************
 * function name: act                                                                         *
 * The Input: Map object (pointer)                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Calls to the appropriate function based on the difficulty of the    *
 *                        player (it is stored in a member variable).                         *
 * *******************************************************************************************/

void ComputerPlayer::act(Map* cMap) {
    
    bool bLoopInvariant = true;
    
    while (bLoopInvariant) {
        
        switch (m_ePlayerDifficulty) {
            case PlayerDifficultyEasy:
                
                if(actEasy(cMap))
                    bLoopInvariant = false;
                
                break;
                
            case PlayerDifficultyMedium:
                
                if (actMedium(cMap))
                    bLoopInvariant = false;
                
                break;
            case PlayerDifficultyHard:
                
                if (actHard(cMap))
                    bLoopInvariant = false;
                
                break;
                
                //Shouldnt be called
            default: break;
        }
        
    }
    
    //Perform the waiting setting  
    switch (Settings::getInstance().getComputerWait()) {
        case VsCWaitYES:
            
            //Wait
            std::cout << "Press ENTER to continue..";
            
            
            if (std::cin.rdbuf()->sungetc() != std::cin.eof() && std::cin.get() != std::cin.widen ( '\n' ) )
                std::cin.ignore ( std::numeric_limits<std::streamsize>::max(), std::cin.widen ( '\n' ) );
            
            std::cout.clear();
            std::cin.ignore();
            
            break;
            
        case VsCWaitNO:
            
            //Shouldnt do anything here, just pass on
            
            break;
            
            //Shouldnt reach here
        default:  break;
    }
    
    
}

/**********************************************************************************************
 * function name: assign                                                                      *
 * The Input: Map object (pointer)                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Creates a random ship. Then, according to the player's difficulty   *
 *                        checks if its in a valid position (for easy and medium difficulties *
 *                        the ships can be adjacent, for hard it musnt be adjacent). The hard *
 *                        difficulty checks against a function is the adjacent blocks are free*
 *                        and if so it places the ship in the map. Otherwise, the while loop  *
 *                        will continue to be excecuted until a valid placement has been made.*
 * *******************************************************************************************/

void ComputerPlayer::assign(Map *cMap) {
    
    bool bLoopInvariant = true;
    
    //This will hold the added ship
    Ship *cAssignedShip = NULL;
    
    
    //Iterate the loop until a valid ship has been found
    while (bLoopInvariant) {
        
        //Just randomly place the ships until something works out
        
        //Choose a random ship type
        ShipType eShipType = ShipType((rand() % (ShipTypeTotalNumber-1)) + 1);
        
        //Choose a random direction
        ShipDirection eShipDirection = ShipDirection((rand() % (ShipDirectionTotalNumber-1)) + 1);
        
        //Create a ship at a guessed position
        cAssignedShip = new Ship(eShipType, eShipDirection, guess());
        
        //Iterate the loop until a valid ship has been found
        switch (m_ePlayerDifficulty) {
            case PlayerDifficultyEasy:
            case PlayerDifficultyMedium:
                
                //If the ship is in a valid position - its enough
                if (cMap->isValid(*cAssignedShip)) {
                    
                    bLoopInvariant = false;
                    
                }
                else {
                    
                    //Make another try
                    delete cAssignedShip;
                    
                }
                
                break;
                
            case PlayerDifficultyHard:
                
                //Needs to check that the ship is in valid position across an extended area
                if (checkExtendedArea(cAssignedShip, cMap)) {
                    
                    bLoopInvariant = false;
                    
                }
                else {
                    
                    //Make another try
                    delete cAssignedShip;
                    
                }
                
                break;
                
            default:
                break;
        }
        

        
    }
    
    //Add the ship to the map
    cMap->addShip(*cAssignedShip);
    
    //Delete after assignment
    delete cAssignedShip;
    
}

/**********************************************************************************************
 * function name: setPlayerDifficulty                                                         *
 * The Input: PlayerDifficulty (enum)                                                         *
 * The output: none                                                                           *
 * The Function Opertion: Sets the difficulty of the ComputerPlayer                           *
 * *******************************************************************************************/

void ComputerPlayer::setPlayerDifficulty(PlayerDifficulty eDifficulty) {
    
    m_ePlayerDifficulty = eDifficulty;
    
}
