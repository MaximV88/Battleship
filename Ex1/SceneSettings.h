/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of SceneSettings Class     *
 ***********************************************************/

#ifndef __Ex1__SceneSettings__
#define __Ex1__SceneSettings__

#include <stdio.h>

#include "Scene.h"
#include "Scanner.h"

typedef enum {
    
    SelectionSettingsNone = 0,
    SelectionSettingsMapSize = 1,
    SelectionSettingsMapOverlay = 2,
    SelectionSettingsPlayerNumberOfShips = 3,
    SelectionSettingsRepresentationOfShips = 4,
    SelectionSettingsOpponentMapHide = 5,
    SelectionSettingsWaitComputerVSComputer = 6,
    SelectionSettingsMainMenu = 7,
    SelectionSettingsTotalNumber = 8
    
} SelectionSettings;

typedef enum {
    
    SelectionSettingsMapRepresentationNone = 0,
    SelectionSettingsMapRepresentationOccupied = 1,
    SelectionSettingsMapRepresentationHit = 2,
    SelectionSettingsMapRepresentationMissed = 3,
    SelectionSettingsMapRepresentationTotalNumber = 4
    
} SelectionSettingsMapRepresentation;

/***********************************************************************************
 * Scene Class: This class represents the Settings scene. It is to be handled      *
 *              only by the SceneDirector.                                         *
 **********************************************************************************/

class SceneSettings : public Scene {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Reads the input from the user
    Scanner m_cScanner;
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: sceneEditMapSize                                                            *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: prints the relevant data for presentation.                          *
     * *******************************************************************************************/
    
    void sceneEditMapSize();
    
    /**********************************************************************************************
     * function name: sceneEditMapOverlay                                                         *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: prints the relevant data for presentation.                          *
     * *******************************************************************************************/
    
    void sceneEditMapOverlay();
    
    /**********************************************************************************************
     * function name: sceneEditPlayerNumberOfShips                                                *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: prints the relevant data for presentation.                          *
     * *******************************************************************************************/
    
    void sceneEditPlayerNumberOfShips();
    
    /**********************************************************************************************
     * function name: sceneEditOpponentMapHide                                                    *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: prints the relevant data for presentation.                          *
     * *******************************************************************************************/
    
    void sceneEditOpponentMapHide();
    
    /**********************************************************************************************
     * function name: sceneEditComputerWait                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: prints the relevant data for presentation.                          *
     * *******************************************************************************************/
    
    void sceneEditComputerWait();

    /**********************************************************************************************
     * function name: sceneEditRepresentationOfShips                                              *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: prints the relevant data for presentation.                          *
     * *******************************************************************************************/
    
    void sceneEditRepresentationOfShips();
    
    /**********************************************************************************************
     * function name: sceneEditRepresentationOfShipsOccupied                                      *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: prints the relevant data for presentation.                          *
     * *******************************************************************************************/
    
    void sceneEditRepresentationOfShipsOccupied();
    
    /**********************************************************************************************
     * function name: sceneEditRepresentationOfShipsHit                                           *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: prints the relevant data for presentation.                          *
     * *******************************************************************************************/
    
    void sceneEditRepresentationOfShipsHit();
    
    /**********************************************************************************************
     * function name: sceneEditRepresentationOfShipsMissed                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: prints the relevant data for presentation.                          *
     * *******************************************************************************************/
    
    void sceneEditRepresentationOfShipsMissed();
    
    /**********************************************************************************************
     * function name: sceneEditMapSize                                                            *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: prints the relevant data for presentation.                          *
     * *******************************************************************************************/
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: SceneSettings Constructor                                                     *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object                                                *
     * *********************************************************************************************/
    
    SceneSettings();
    
    /**********************************************************************************************
     * function name: SceneSettings Destructor                                                    *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~SceneSettings();
    
    /**********************************************************************************************
     * function name: show                                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: presents the scene.                                                 *
     * *******************************************************************************************/
    
    virtual void show();

};

#endif /* defined(__Ex1__SceneSettings__) */
