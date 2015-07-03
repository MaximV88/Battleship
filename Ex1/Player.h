/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Player Class            *
 ***********************************************************/

#ifndef __Ex1__Player__
#define __Ex1__Player__

#include <stdio.h>
#include <string>

#include "Nameable.h"

typedef enum {
    PlayerDifficultyNone = 0,
    PlayerDifficultyEasy,
    PlayerDifficultyMedium,
    PlayerDifficultyHard,
    PlayerDifficultyTotalNumber
} PlayerDifficulty;

class Action;
class Map;

/*************************************************************************************
 * Player Class: Represents the player. The player performs actions on a Map         *
 *               object. The player class has it's actions implemented by subclasses.*
 ************************************************************************************/

class Player : public Nameable {
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Player Constructor                                                            *
     * The Input: const string object (reference)                                                   *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input string as name                      *
     * *********************************************************************************************/
    
    Player(const std::string& strName);
    
    /**********************************************************************************************
     * function name: Player Destructor                                                           *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~Player();
    
    /**********************************************************************************************
     * function name: act                                                                         *
     * The Input: Map object (pointer)                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Makes a turn on the input map.                                      *
     * *******************************************************************************************/
    
    virtual void act(Map* cMap) = 0;
    
    /**********************************************************************************************
     * function name: assign                                                                      *
     * The Input: Map object (pointer)                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Assignes a ship on the input Map.                                   *
     * *******************************************************************************************/
    
    virtual void assign(Map* cMap) = 0;
    
};

#endif  
