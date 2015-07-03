/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Game Class           *
 ***********************************************************/

#include <iostream>

#include "Game.h"
#include "SceneDirector.h"
#include "SceneMainMenu.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Game Constructor                                                              *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object                                                *
 * *********************************************************************************************/

Game::Game()  {
    
}

/**********************************************************************************************
 * function name: Game Destructor                                                             *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

Game::~Game() {
    
}

/**********************************************************************************************
 * function name: start                                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Prints a starting message, and after input clears the screen.       *
 *                        Calls the MainMenu scene from the SceneDirector.                    *
 * *******************************************************************************************/

void Game::start() {

    //Greeting messege
    std::cout << "Welcome to SinkTheShip (TM)!\nCoded by Maxim Vainshtein." << std::endl;
    
    std::cout << "\nPress Enter to continue.";
    
    std::cin.get();
    
    //Load the main menu scene
    SceneDirector::getInstance().present(new SceneMainMenu());
    
}
