/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of SceneMainMenu Class     *
 ***********************************************************/

#ifndef __Ex1__SceneMainMenu__
#define __Ex1__SceneMainMenu__

#include <stdio.h>

#include "Scene.h"
#include "Scanner.h"

typedef enum {
    
    SelectionMainMenuNone = 0,
    SelectionMainMenuSettings = 1,
    SelectionMainMenuGameMatch = 2,
    SelectionMainMenuQuit = 3,
    SelectionMainMenuTotalNumber = 4
    
} SelectionMainMenu;

/***********************************************************************************
 * Scene Class: This class represents the main menu scene. It is to be handled     *
 *              only by the SceneDirector.                                         *
 **********************************************************************************/

class SceneMainMenu : public Scene {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    Scanner m_cScanner;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: SceneMainMenu Constructor                                                     *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object                                                *
     * *********************************************************************************************/
    
    SceneMainMenu();
    
    /**********************************************************************************************
     * function name: SceneMainMenu Destructor                                                    *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~SceneMainMenu();
    
    /**********************************************************************************************
     * function name: show                                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: presents the scene.                                                 *
     * *******************************************************************************************/

    virtual void show();

};

#endif /* defined(__Ex1__SceneMainMenu__) */
