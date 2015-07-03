/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of SceneMainMenu Class  *
 ***********************************************************/

#include <iostream>

#include "SceneMainMenu.h"
#include "SceneDirector.h"

#include "SceneSettings.h"
#include "SceneGameMatch.h"

using namespace std;

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: SceneMainMenu Constructor                                                     *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with "Main Menu" as name                       *
 * *********************************************************************************************/

SceneMainMenu::SceneMainMenu() : Scene("Main Menu") { }

/**********************************************************************************************
 * function name: SceneMainMenu Destructor                                                    *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

SceneMainMenu::~SceneMainMenu() { }

/**********************************************************************************************
 * function name: show                                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Shows the selections possible to proceed. on every choice, goes to  *
 *                        the required scene.                                                 *
 * *******************************************************************************************/

void SceneMainMenu::show() {
    
    //Print out the selection - we dont have any other way of drawing text to screen using drawer
    cout << "Please enter the number for your selection:\n" << endl;
    
    //Make it in order for easier changing of text - ordered by enum values
    cout << "1. Game Settings" << endl;
    cout << "2. Play" << endl;
    cout << "3. Quit" << endl;
    
    cout << "\nWaiting for selection: ";
    
    switch (m_cScanner.scanInt(SelectionMainMenuNone, SelectionMainMenuTotalNumber)) {
            
        case SelectionMainMenuSettings:
            
            SceneDirector::getInstance().present(new SceneSettings());
            
            break;
            
        case SelectionMainMenuGameMatch:
            
            SceneDirector::getInstance().present(new SceneGameMatch());
            
            break;
            
        case SelectionMainMenuQuit:
            
            return;
            
        //Shouldnt reach that
        default: break;
            
    }
    
}
