/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of SceneSettings Class  *
 ***********************************************************/

#include <iostream>

#include "SceneDirector.h"
#include "SceneSettings.h"
#include "SceneMainMenu.h"
#include "Settings.h"

using namespace std;

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: sceneEditMapSize                                                            *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Prints instructions, reads the input and presents the SettingsScene *
 *                        from the start.                                                     *
 * *******************************************************************************************/

void SceneSettings::sceneEditMapSize() {
    
    cout << "Please enter your desired map width (from 8 up to 20): ";
    
    unsigned int uiMapWidth = m_cScanner.scanInt(7, 21);
    
    cout << "Please enter your desired map height (from 8 up to 20): ";

    unsigned int uiMapHeight = m_cScanner.scanInt(7, 21);
    
    Settings::getInstance().setMapSize(Oblong(uiMapWidth, uiMapHeight));
    
    //Clear the screen and present the scene again
    SceneDirector::getInstance().present(new SceneSettings());
    
}

/**********************************************************************************************
 * function name: sceneEditMapOverlay                                                         *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Prints instructions, reads the input and presents the SettingsScene *
 *                        from the start.                                                     *
 * *******************************************************************************************/

void SceneSettings::sceneEditMapOverlay() {
    
    cout << "Please enter your desired configuration.\nCurrent configuration: " ;
    
    switch (Settings::getInstance().getMapOverlay()) {
        case MapOverlaySideBySide:      cout << "Side by side\n" << endl;     break;
        case MapOverlayTopAndBottom:    cout << "Top and bottom\n" << endl;   break;
            
        //Shouldnt be called
        default: break;
            
    }
    
    //Make it in order for easier changing of text - ordered by enum values
    cout << "1. Side by Side" << endl;
    cout << "2. Top and bottom" << endl;
    
    cout << "\nWaiting for selection: ";
    
    Settings::getInstance().setMapOverlay(MapOverlay(m_cScanner.scanInt(MapOverlayNone, MapOverlayTotalNumber)));
    
    //Clear the screen and present the scene again
    SceneDirector::getInstance().present(new SceneSettings());
    
}

/**********************************************************************************************
 * function name: sceneEditPlayerNumberOfShips                                                *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Prints instructions, reads the input and presents the SettingsScene *
 *                        from the start.                                                     *
 * *******************************************************************************************/

void SceneSettings::sceneEditPlayerNumberOfShips() {
    
    cout << "Please enter your desired number of ships (from 1 to 7): ";
    
    unsigned int uiNumberOfShips = m_cScanner.scanInt(0, 8);
    
    Settings::getInstance().setPlayerNumberOfShips(uiNumberOfShips);
    
    //Clear the screen and present the scene again
    SceneDirector::getInstance().present(new SceneSettings());
    
}

/**********************************************************************************************
 * function name: sceneEditComputerWait                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Prints instructions, reads the input and presents the SettingsScene *
 *                        from the start.                                                     *
 * *******************************************************************************************/

void SceneSettings::sceneEditComputerWait() {
    
    cout << "Please enter your desired configuration.\nCurrent configuration: " ;
    
    switch (Settings::getInstance().getComputerWait()) {
        case VsCWaitYES:      cout << "Waiting at each turn\n" << endl;     break;
        case VsCWaitNO:    cout << "Doesnt wait at each turn\n" << endl;   break;
            
            //Shouldnt be called
        default: break;
            
    }
    
    //Make it in order for easier changing of text - ordered by enum values
    cout << "1. Wait at each turn" << endl;
    cout << "2. Dont wait at each turn" << endl;
    
    cout << "\nWaiting for selection: ";
    
    Settings::getInstance().setComputerWait(VsCWait(m_cScanner.scanInt(VsCWaitNone, VsCWaitTotalNumber)));
    
    //Clear the screen and present the scene again
    SceneDirector::getInstance().present(new SceneSettings());
    
}

/**********************************************************************************************
 * function name: sceneEditRepresentationOfShips                                              *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Prints instructions, reads the input and presents the SettingsScene *
 *                        from the start.                                                     *
 * *******************************************************************************************/

void SceneSettings::sceneEditRepresentationOfShips() {
    
    cout << "Please enter your desired representation to change. Current representations: " << endl;
    
    cout << "Occupied: " << Settings::getInstance().getRepresentationForType(MapRepresentationOccupied) << endl;
    cout << "Hit:      " << Settings::getInstance().getRepresentationForType(MapRepresentationHit) << endl;
    cout << "Missed:   " << Settings::getInstance().getRepresentationForType(MapRepresentationMissed) << endl;
    
    
    //Make it in order for easier changing of text - ordered by enum values
    cout << "\n1. Change Representation for 'Occupied'" << endl;
    cout << "2. Change Representation for 'Hit'" << endl;
    cout << "3. Change Representation for 'Missed'" << endl;

    
    cout << "Waiting for selection: ";

    switch (m_cScanner.scanInt(SelectionSettingsMapRepresentationNone, SelectionSettingsMapRepresentationTotalNumber)) {
            
        case SelectionSettingsMapRepresentationOccupied: sceneEditRepresentationOfShipsOccupied(); break;
        case SelectionSettingsMapRepresentationHit: sceneEditRepresentationOfShipsHit(); break;
        case SelectionSettingsMapRepresentationMissed: sceneEditRepresentationOfShipsMissed(); break;
        
        //Shouldnt reach that
        default: break;
    }
    
    //Clear the screen and present the scene again
    SceneDirector::getInstance().present(new SceneSettings());
    
}

/**********************************************************************************************
 * function name: sceneEditRepresentationOfShipsOccupied                                      *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Prints instructions, reads the input and presents the SettingsScene *
 *                        from the start.                                                     *
 * *******************************************************************************************/

void SceneSettings::sceneEditRepresentationOfShipsOccupied() {
    
    cout << "Please enter your desired character for 'Occupied': " ;

    Settings::getInstance().setRepresentationForType(MapRepresentationOccupied, m_cScanner.scanString(1, 1)[0]);
    
}

/**********************************************************************************************
 * function name: sceneEditRepresentationOfShipsHit                                           *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Prints instructions, reads the input and presents the SettingsScene *
 *                        from the start.                                                     *
 * *******************************************************************************************/

void SceneSettings::sceneEditRepresentationOfShipsHit() {
    
    cout << "Please enter your desired character for 'Hit': " ;
    
    Settings::getInstance().setRepresentationForType(MapRepresentationHit, m_cScanner.scanString(1, 1)[0]);
    
}

/**********************************************************************************************
 * function name: sceneEditRepresentationOfShipsMissed                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Prints instructions, reads the input and presents the SettingsScene *
 *                        from the start.                                                     *
 * *******************************************************************************************/

void SceneSettings::sceneEditRepresentationOfShipsMissed() {
    
    cout << "Please enter your desired character for 'Missed': " ;
    
    Settings::getInstance().setRepresentationForType(MapRepresentationMissed, m_cScanner.scanString(1, 1)[0]);
    
}

/**********************************************************************************************
 * function name: sceneEditOpponentMapHide                                                    *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Prints instructions, reads the input and presents the SettingsScene *
 *                        from the start.                                                     *
 * *******************************************************************************************/

void SceneSettings::sceneEditOpponentMapHide() {
    
    cout << "Please enter your desired configuration.\nCurrent configuration: " ;
    
    switch (Settings::getInstance().getOpponentMap()) {
        case OpponentMapHide:      cout << "Hidden\n" << endl;     break;
        case OpponentMapDontHide:  cout << "Not hidden\n" << endl;   break;
            
            //Shouldnt be called
        default: break;
            
    }
    
    //Make it in order for easier changing of text - ordered by enum values
    cout << "1. Hide opponent's map" << endl;
    cout << "2. Don't hide the opponent's map" << endl;
    
    cout << "\nWaiting for selection: ";
    
    Settings::getInstance().setOpponentMap(OpponentMap(m_cScanner.scanInt(OpponentMapNone, OpponentMapTotalNumber)));
    
    //Clear the screen and present the scene again
    SceneDirector::getInstance().present(new SceneSettings());
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: SceneSettings Constructor                                                     *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object                                                *
 * *********************************************************************************************/

SceneSettings::SceneSettings() : Scene("Settings") { }

/**********************************************************************************************
 * function name: SceneSettings Destructor                                                    *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

SceneSettings::~SceneSettings() { }

/**********************************************************************************************
 * function name: show                                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: presents the scene with the required choices.                       *
 * *******************************************************************************************/

void SceneSettings::show() {
    
    //This will present the map size
    Oblong cMapSize = Settings::getInstance().getMapSize();
    
    cout << "Please enter the number for your selection:\n" << endl;
    
    //Make it in order for easier changing of text - ordered by enum values
    cout << "1. Edit Map size (Currently at " << cMapSize.getWidth() << " width and " << cMapSize.getHeight() << " height)" << endl;
    cout << "2. Change Maps overlay" << endl;
    cout << "3. Change number of Ships per Player (Currently at " << Settings::getInstance().getPlayerNumberOfShips() << ")" << endl;
    cout << "4. Edit representation of Ships" << endl;
    cout << "5. Hide opponent's Map" << endl;
    cout << "6. Wait at turns at VS Computer" << endl;
    cout << "7. Return to Main Menu" << endl;

    
    cout << "\nWaiting for selection: ";
    
    //Performs the selection given
    switch (SelectionSettings(m_cScanner.scanInt(SelectionSettingsNone, SelectionSettingsTotalNumber))) {
            
        case SelectionSettingsMapSize:
            
            sceneEditMapSize();
            
            break;
        case SelectionSettingsMapOverlay:
            
            sceneEditMapOverlay();
            
            break;
        case SelectionSettingsPlayerNumberOfShips:
            
            sceneEditPlayerNumberOfShips();
            
            break;
        case SelectionSettingsRepresentationOfShips:
            
            sceneEditRepresentationOfShips();
            
            break;
        case SelectionSettingsOpponentMapHide:
            
            sceneEditOpponentMapHide();
            
            break;
        case SelectionSettingsWaitComputerVSComputer:
            
            sceneEditComputerWait();
            
            break;
        case SelectionSettingsMainMenu:
            
            SceneDirector::getInstance().present(new SceneMainMenu());
            
            break;
            
        //Shouldnt reach that
        default: break;
    }
    
}