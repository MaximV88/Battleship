/*******************************************************
 * Student Name:     Maxim Vainshtein                  *
 * Exercise Name:    Ex4                               *
 * File description: Declaration of Settings Class     *
 ******************************************************/

#ifndef __Ex1__Settings__
#define __Ex1__Settings__

#include <stdio.h>

#include "Oblong.h"
#include "Player.h"

/********************************************************************************
 * Settings Class: It is a singelton that holds all of the game settings,       *
 *                 such as Map's overlay, number of Ships per Player, Size of   *
 *                 the map, etc. it also calculates the adjusted size of the    *
 *                 drawer (responsible for drawing the game elements) from the  *
 *                 selected size of the map.                                    *
 *******************************************************************************/

typedef enum {
    
    MapOverlayNone = 0,
    MapOverlaySideBySide = 1,
    MapOverlayTopAndBottom = 2,
    MapOverlayTotalNumber = 3
    
} MapOverlay;

typedef enum {
    
    MapRepresentationNone = 0,
    MapRepresentationClear = 1,
    MapRepresentationOccupied = 2,
    MapRepresentationMissed = 3,
    MapRepresentationHit = 4,
    MapRepresentationTotalNumber = 5
    
} MapRepresentation;

typedef enum {
    OpponentMapNone = 0,
    OpponentMapHide = 1,
    OpponentMapDontHide = 2,
    OpponentMapTotalNumber =3
} OpponentMap;

typedef enum {
    VsCWaitNone = 0,
    VsCWaitYES = 1,
    VsCWaitNO = 2,
    VsCWaitTotalNumber =3
} VsCWait;

class Settings {
    
private:
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /**********************************************************************************************
     * function name: Settings Constructor                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Since the Settings class is a singelton, from the pattern design    *
     *                        it needs to have it's constructor as private to avoid any other     *
     *                        class other than the Settings class from initializing it.           *
     * *******************************************************************************************/
    
    Settings();

    /**********************************************************************************************
     * function name: Copy Constructor                                                            *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Since the Settings class is a singelton, from the pattern design    *
     *                        duplicating is unwanted because there should only be one singelton. *
     * *******************************************************************************************/
    
    Settings(Settings const& cSettings);
    
    /**********************************************************************************************
     * function name: operator=                                                                   *
     * The Input: const Settings object (reference)                                               *
     * The output: none                                                                           *
     * The Function Opertion: Copies the content of the input Settings object to the current      *
     *                        object. Since the singelton is only one, there should not be a copy *
     *                        to perform this operator from, and because this operator is private *
     *                        it will never be called.                                            *
     * *******************************************************************************************/
    
    void operator=(Settings const& cSettings);
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the structure of the map (drawing style)
    MapOverlay m_eMapOverlay;
    
    //Stores the size of the map
    Oblong m_cMapSize;
    
    //Stores settings regarding hiding of computer opponent map
    OpponentMap m_eOpponentMap;
    
    //Stores settings regarding should wait at end of each turn when playing vs computer
    VsCWait m_eIsWaitingComputerVSComputer;

    //Stores the maximum length of a player name
    unsigned int m_uiPlayerNameMaxLength;
    
    //Stores the minimal length of a player name
    unsigned int m_uiPlayerNameMinLength;
    
    //Stores the number of ships permitted per player
    unsigned int m_uiPlayerNumberOfShips;
    
    //Stores the char representation of every Map tile type
    char m_chMapRepresentations[MapRepresentationTotalNumber];
    
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /**********************************************************************************************
     * function name: getInstance                                                                 *
     * The Input: none                                                                            *
     * The output: Settings object (reference)                                                    *
     * The Function Opertion: Since the singleton has only one copy, a class function is made to  *
     *                        to access it. Calling this function will return the only copy of    *
     *                        the Settings class.                                                 *
     * *******************************************************************************************/
    
    static Settings& getInstance();
    
    /**********************************************************************************************
     * function name: setMapOverlay                                                               *
     * The Input: MapOverlay object (enum)                                                        *
     * The output: none                                                                           *
     * The Function Opertion: Sets the desired Map drawing style.                                 *
     * *******************************************************************************************/
    
    void setMapOverlay(MapOverlay eMapOverlay);
    
    /**********************************************************************************************
     * function name: getMapOverlay                                                               *
     * The Input: none                                                                            *
     * The output: MapOverlay object (enum)                                                       *
     * The Function Opertion: Returns the desired Map drawing style.                              *
     * *******************************************************************************************/
    
    MapOverlay getMapOverlay() const;
    
    /**********************************************************************************************
     * function name: setMapSize                                                                  *
     * The Input: const Oblong object (reference)                                                 *
     * The output: none                                                                           *
     * The Function Opertion: Sets the desired Map size.                                          *
     * *******************************************************************************************/
    
    void setMapSize(const Oblong& cOblong);
    
    /**********************************************************************************************
     * function name: getMapSize                                                                  *
     * The Input: none                                                                            *
     * The output: Oblong object                                                                  *
     * The Function Opertion: Returns the desired Map size.                                       *
     * *******************************************************************************************/
    
    Oblong getMapSize() const;
    
    /**********************************************************************************************
     * function name: getScreenSize                                                               *
     * The Input: none                                                                            *
     * The output: Oblong object                                                                  *
     * The Function Opertion: Returns the required screen (drawer) size.                          *
     * *******************************************************************************************/
    
    Oblong getScreenSize() const;
    
    /**********************************************************************************************
     * function name: getPlayerNameMaxLength                                                      *
     * The Input: none                                                                            *
     * The output: unsigned int                                                                   *
     * The Function Opertion: Returns the allowed maximum length of the player name.              *
     * *******************************************************************************************/
    
    unsigned int getPlayerNameMaxLength() const;
    
    /**********************************************************************************************
     * function name: getPlayerNameMinLength                                                      *
     * The Input: none                                                                            *
     * The output: unsigned int                                                                   *
     * The Function Opertion: Returns the allowed minimal length of the player name.              *
     * *******************************************************************************************/
    
    unsigned int getPlayerNameMinLength() const;
    
    /**********************************************************************************************
     * function name: setPlayerNumberOfShips                                                      *
     * The Input: unsigned int                                                                    *
     * The output: none                                                                           *
     * The Function Opertion: Sets the number of ships per player.                                *
     * *******************************************************************************************/
    
    void setPlayerNumberOfShips(unsigned int uiNumberOfShips);
    
    /**********************************************************************************************
     * function name: getPlayerNumberOfShips                                                      *
     * The Input: none                                                                            *
     * The output: unsigned int                                                                   *
     * The Function Opertion: Returns the number of ships per player.                             *
     * *******************************************************************************************/
    
    unsigned int getPlayerNumberOfShips() const;
    
    /**********************************************************************************************
     * function name: setRepresentationForType                                                    *
     * The Input: MapRepresentation (enum), char                                                  *
     * The output: none                                                                           *
     * The Function Opertion: Sets the representation char for the given MapRepresentation type.  *
     * *******************************************************************************************/
    
    void setRepresentationForType(MapRepresentation eType, char chContent);
    
    /**********************************************************************************************
     * function name: getRepresentationForType                                                    *
     * The Input: MapRepresentation (enum)                                                        *
     * The output: char                                                                           *
     * The Function Opertion: Return the representation char for the input MapRepresentation type.*
     * *******************************************************************************************/
    
    char getRepresentationForType(MapRepresentation eRepresentation) const;
    
    /**********************************************************************************************
     * function name: setOpponentMap                                                              *
     * The Input: OpponentMap (enum)                                                              *
     * The output: none                                                                           *
     * The Function Opertion: Sets if to hide or not the opponent's map.                          *
     * *******************************************************************************************/
    
    void setOpponentMap(OpponentMap eType);
    
    /**********************************************************************************************
     * function name: getOpponentMap                                                              *
     * The Input: none                                                                            *
     * The output: OpponentMap (enum)                                                             *
     * The Function Opertion: Returns if the opponents map should be hidden.                      *
     * *******************************************************************************************/
    
    OpponentMap getOpponentMap() const;
    
    /**********************************************************************************************
     * function name: setComputerWait                                                             *
     * The Input: VsCWait (enum)                                                                  *
     * The output: none                                                                           *
     * The Function Opertion: Sets if the computer should wait for an input to proceed.           *
     * *******************************************************************************************/

    void setComputerWait(VsCWait eIsWaiting);
    
    /**********************************************************************************************
     * function name: getComputerWait                                                             *
     * The Input: none                                                                            *
     * The output: VsCWait (enum)                                                                 *
     * The Function Opertion: Returns if the computer should wait for an input to proceed.        *
     * *******************************************************************************************/

    VsCWait getComputerWait() const;

};

#endif
