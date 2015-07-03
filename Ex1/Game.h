/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Game Class              *
 ***********************************************************/
#ifndef __Ex1__Game__
#define __Ex1__Game__

#include <stdio.h>
#include <vector>
#include "Drawer.h"
#include "Settings.h"

/***********************************************************************************
 * Scene Class: Used only as a starting point to call the SceneDirector with the   *
 *              MainMenu scene.                                                    *
 **********************************************************************************/

class Game {
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: Game Constructor                                                              *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object                                                *
     * *********************************************************************************************/
    
    Game();
    
    /**********************************************************************************************
     * function name: Game Destructor                                                             *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~Game();
    
    /**********************************************************************************************
     * function name: start                                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Starts the game.                                                    *
     * *******************************************************************************************/
    
    void start();
    
};

#endif /* defined(__Ex1__Game__) */
