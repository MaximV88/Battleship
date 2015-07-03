/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of HumanPlayer Class       *
 ***********************************************************/

#ifndef __Ex1__HumanPlayer__
#define __Ex1__HumanPlayer__

#include <stdio.h>
#include "Player.h"
#include "Scanner.h"
#include "Coordinate.h"

/***************************************************************************************
 * HumanPlayer Class: Represents the Human player. When presented with a possible      *
 *                    action, it waits for a valid input from the Terminal to continue.*
 **************************************************************************************/

class HumanPlayer : public Player {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Used to read the input from the user
    Scanner m_cScanner;
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: getCoordinate                                                                 *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Used to get valid Coordinate input from the user (Terminal)           *
     * *********************************************************************************************/
    
    Coordinate getCoordinate() const;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: HumanPlayer Constructor                                                       *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with a default "Player" name                   *
     * *********************************************************************************************/
    
    HumanPlayer();
    
    /************************************************************************************************
     * function name: HumanPlayer Constructor                                                       *
     * The Input: const string object (reference)                                                   *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with the input string as name                  *
     * *********************************************************************************************/
    
    HumanPlayer(const std::string& strName);
    
    /**********************************************************************************************
     * function name: act                                                                         *
     * The Input: Map object (pointer)                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Makes a turn on the input map.                                      *
     * *******************************************************************************************/
    
    virtual void act(Map* cMap);
    
    /**********************************************************************************************
     * function name: assign                                                                      *
     * The Input: Map object (pointer)                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Assignes a ship on the input Map.                                   *
     * *******************************************************************************************/
    
    virtual void assign(Map* cMap);
    
};

#endif /* defined(__Ex1__HumanPlayer__) */
