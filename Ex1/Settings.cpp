/*******************************************************
 * Student Name:     Maxim Vainshtein                  *
 * Exercise Name:    Ex1                               *
 * File description: Implementation of Settings Class  *
 ******************************************************/

#include "Settings.h"

#define DEFAULT_MAP_HEIGHT 10
#define DEFAULT_MAP_WIDTH 10

#define DEFAULT_PLAYER_NAME_MAX_LENGTH 19
#define DEFAULT_PLAYER_NAME_MIN_LENGTH 2

#define DEFAULT_PLAYER_NUMBER_OF_SHIPS 6

#define DEFAULT_MAP_REPRESENTATION_CLEAR ' '
#define DEFAULT_MAP_REPRESENTATION_OCCUPIED '*'
#define DEFAULT_MAP_REPRESENTATION_HIT 'X'
#define DEFAULT_MAP_REPRESENTATION_MISSED '~'

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: Settings Constructor                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Constructor. Initializes to macro parameters                        *
 * *******************************************************************************************/

Settings::Settings() : m_cMapSize(DEFAULT_MAP_HEIGHT, DEFAULT_MAP_WIDTH) {
    
    //Default values
    m_eMapOverlay = MapOverlaySideBySide;
    m_uiPlayerNameMaxLength = DEFAULT_PLAYER_NAME_MAX_LENGTH;
    m_uiPlayerNameMinLength = DEFAULT_PLAYER_NAME_MIN_LENGTH;
    m_uiPlayerNumberOfShips = DEFAULT_PLAYER_NUMBER_OF_SHIPS;
    
    m_chMapRepresentations[MapRepresentationHit] = DEFAULT_MAP_REPRESENTATION_HIT;
    m_chMapRepresentations[MapRepresentationClear] = DEFAULT_MAP_REPRESENTATION_CLEAR;
    m_chMapRepresentations[MapRepresentationOccupied] = DEFAULT_MAP_REPRESENTATION_OCCUPIED;
    m_chMapRepresentations[MapRepresentationMissed] = DEFAULT_MAP_REPRESENTATION_MISSED;
    
    m_eOpponentMap = OpponentMapHide;
    
    m_eIsWaitingComputerVSComputer = VsCWaitYES;
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: getInstance                                                                 *
 * The Input: none                                                                            *
 * The output: Settings object (reference)                                                    *
 * The Function Opertion: Sets a Settings object on a static variable, and then returns the   *
 *                        reference to that variable every time the function is called.       *
 * *******************************************************************************************/

Settings& Settings::getInstance() {
    
    static Settings instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
    
}

/**********************************************************************************************
 * function name: setMapOverlay                                                               *
 * The Input: MapOverlay object (enum)                                                        *
 * The output: none                                                                           *
 * The Function Opertion: Changes the value of the member variable that holds the desired     *
 *                        drawing style of the maps.                                          *
 * *******************************************************************************************/

void Settings::setMapOverlay(MapOverlay eMapOverlay) {
    
    m_eMapOverlay = eMapOverlay;
    
}

/**********************************************************************************************
 * function name: getMapOverlay                                                               *
 * The Input: none                                                                            *
 * The output: MapOverlay object (enum)                                                       *
 * The Function Opertion: Returns the value of the member variable that holds the desired     *
 *                        drawing style of the maps.                                          *
 * *******************************************************************************************/

MapOverlay Settings::getMapOverlay() const {
    
    return m_eMapOverlay;
    
}

/**********************************************************************************************
 * function name: setMapSize                                                                  *
 * The Input: const Oblong object (reference)                                                 *
 * The output: none                                                                           *
 * The Function Opertion: Changes the value of the member variable object that holds the size *
 *                        of the game map.                                                    *
 * *******************************************************************************************/

void Settings::setMapSize(const Oblong& cOblong) {
    
    //Copy value
    m_cMapSize = cOblong;
    
}

/**********************************************************************************************
 * function name: getMapSize                                                                  *
 * The Input: none                                                                            *
 * The output: Oblong object                                                                  *
 * The Function Opertion: Returns a copy of the member variable object that holds the size    *
 *                        of the game map.                                                    *
 * *******************************************************************************************/

Oblong Settings::getMapSize() const {
    
    return m_cMapSize;
    
}

/**********************************************************************************************
 * function name: getScreenSize                                                               *
 * The Input: none                                                                            *
 * The output: Oblong object                                                                  *
 * The Function Opertion: Returns an Oblong object that holds the size of the drawer required *
 *                        to correctly draw the given map sizes. It first calculates the size *
 *                        required by the stored overlay setting, and then return the results *
 *                        as an Oblong object.                                                *
 * *******************************************************************************************/

Oblong Settings::getScreenSize() const {

    //This will hold calculated size of the screen
    unsigned int uiWidth = 0;
    unsigned int uiHeight = 0;
    
    switch (m_eMapOverlay) {
        case MapOverlaySideBySide:
            
            //This will calculate the required size from the map - the maps are side by side,
            //The screen width should have enough room for 2 maps.
            uiWidth = (getMapSize().getWidth() * 2 + 3) * 2 + 3;
            uiHeight = (getMapSize().getHeight() * 2 + 12);
            
            break;
            
        case MapOverlayTopAndBottom:
            
            //This will calculate the required size from the map - the maps are top and bottom,
            //The screen height should have enough room for 2 maps.
            uiWidth = (getMapSize().getWidth() * 2 + 3) + 8;
            uiHeight = (getMapSize().getHeight() * 2 + 3) * 2 + 7;
            
        default:  break;
  
    }
    
    //Return the calculated result as an Oblong object
    return Oblong(uiWidth, uiHeight);
    
}

/**********************************************************************************************
 * function name: getPlayerNameMaxLength                                                      *
 * The Input: none                                                                            *
 * The output: unsigned int                                                                   *
 * The Function Opertion: Returns the value of the member variable that holds the maximum     *
 *                        length of the player name.                                          *
 * *******************************************************************************************/

unsigned int Settings::getPlayerNameMaxLength() const {
    
    return m_uiPlayerNameMaxLength;
    
}

/**********************************************************************************************
 * function name: getPlayerNameMinLength                                                      *
 * The Input: none                                                                            *
 * The output: unsigned int                                                                   *
 * The Function Opertion: Returns the value of the member variable that holds the minimum     *
 *                        length of the player name.                                          *
 * *******************************************************************************************/

unsigned int Settings::getPlayerNameMinLength() const {
    
    return m_uiPlayerNameMinLength;
    
}

/**********************************************************************************************
 * function name: setPlayerNumberOfShips                                                      *
 * The Input: unsigned int                                                                    *
 * The output: none                                                                           *
 * The Function Opertion: Changes the value of the member variable that holds the number of   *
 *                        ships per player.                                                   *
 * *******************************************************************************************/

void Settings::setPlayerNumberOfShips(unsigned int uiNumberOfShips) {
    
    m_uiPlayerNumberOfShips = uiNumberOfShips;
    
}

/**********************************************************************************************
 * function name: getPlayerNumberOfShips                                                      *
 * The Input: none                                                                            *
 * The output: unsigned int                                                                   *
 * The Function Opertion: Returns the value of the member variable that holds the number of   *
 *                        ships per player.                                                   *
 * *******************************************************************************************/

unsigned int Settings::getPlayerNumberOfShips() const {
    
    return m_uiPlayerNumberOfShips;
    
}

/**********************************************************************************************
 * function name: setRepresentationForType                                                    *
 * The Input: MapRepresentation (enum), char                                                  *
 * The output: none                                                                           *
 * The Function Opertion: Sets the MapRepresentation array's cells that represent the char    *
 *                        value of the MapRepresentation's enum value with the input char.    *
 * *******************************************************************************************/

void Settings::setRepresentationForType(MapRepresentation eType, char chContent) {
    
    m_chMapRepresentations[eType] = chContent;
    
}

/**********************************************************************************************
 * function name: getRepresentationForType                                                    *
 * The Input: MapRepresentation (enum)                                                        *
 * The output: char                                                                           *
 * The Function Opertion: Returns the char value stored in the MapRepresentaiton array from   *
 *                        then index of the input's enum int value.                           *
 * *******************************************************************************************/

char Settings::getRepresentationForType(MapRepresentation eRepresentation) const {
    
    return m_chMapRepresentations[eRepresentation];
    
}

/**********************************************************************************************
 * function name: setOpponentMap                                                              *
 * The Input: OpponentMap (enum)                                                              *
 * The output: none                                                                           *
 * The Function Opertion: Changes the value of the member variable that holds if the opponents*
 *                        map should be hidden.                                               *
 * *******************************************************************************************/

void Settings::setOpponentMap(OpponentMap eType) {
    
    m_eOpponentMap = eType;
    
}

/**********************************************************************************************
 * function name: getOpponentMap                                                              *
 * The Input: none                                                                            *
 * The output: OpponentMap (enum)                                                             *
 * The Function Opertion: Returns the value of the member variable that holds if the opponents*
 *                        map should be hidden.                                               *
 * *******************************************************************************************/

OpponentMap Settings::getOpponentMap() const {
    
    return m_eOpponentMap;
    
}

/**********************************************************************************************
 * function name: setComputerWait                                                             *
 * The Input: VsCWait (enum)                                                                  *
 * The output: none                                                                           *
 * The Function Opertion: Changes the value of the member variable that holds if the computer *
 *                        should wait at the end of each turn.                                *
 * *******************************************************************************************/

void Settings::setComputerWait(VsCWait eIsWaiting) {
    
    m_eIsWaitingComputerVSComputer = eIsWaiting;
    
}

/**********************************************************************************************
 * function name: getComputerWait                                                             *
 * The Input: none                                                                            *
 * The output: VsCWait (enum)                                                                 *
 * The Function Opertion: Returns the value of the member variable that holds if the computer *
 *                        should wait at the end of each turn.                                *
 * *******************************************************************************************/

VsCWait Settings::getComputerWait() const {
    
    return m_eIsWaitingComputerVSComputer;
    
}
