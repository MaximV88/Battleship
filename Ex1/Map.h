/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Map Class               *
 ***********************************************************/

#ifndef __Ex1__Map__
#define __Ex1__Map__

#include <stdio.h>
#include "Oblong.h"
#include "GameCollection.h"
#include "Ship.h"
#include "Settings.h"


/****************************************************************************************************
 * Map Class:        Its a subclassed GameCollection (An object that can be displayed by the Drawer,*
 *                   that has complex objects - a combination of shapes - which can be displayed    *
 *                   by the drawer), that is used as a Map.                                         *
 ***************************************************************************************************/

class Map : public GameCollection, public Oblong {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores if the ships should be hidden
    bool m_bIsHidingShips;

    //  ---                         PRIVATE FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: buildMap                                                                    *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Constructs the Map grid using points.                               *
     * *******************************************************************************************/
    
    void buildMap();
    
    /**********************************************************************************************
     * function name: conformed                                                                   *
     * The Input: const Coordinate object (reference)                                             *
     * The output: Coordinate object                                                              *
     * The Function Opertion: Gets the given coordiante, and returns a conformed coordinate to    *
     *                        the position's input.                                               *
     * *******************************************************************************************/
    
    Coordinate conformed(const Coordinate& cCoordinate) const;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Map Constructor                                                               *
     * The Input: const Coordinate object (reference), unsigned int, unsigned int                   *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with an origin, width and height.              *
     * *********************************************************************************************/
    
    Map(const Coordinate& cOrigin, unsigned int uiWidth, unsigned int uiHeight);
    
    /************************************************************************************************
     * function name: Map Constructor                                                               *
     * The Input: const Coordinate object (reference), const Oblong object (reference)              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with an origin, and Oblong's width and height. *
     * *********************************************************************************************/
    
    Map(const Coordinate& cOrigin, const Oblong& cMapSize);
    
    /************************************************************************************************
     * function name: Map Copy Constructor                                                          *
     * The Input: const Ship object (reference)                                                     *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object as a copy of the input.                        *
     * *********************************************************************************************/
    
    Map(const Map& cMap);
    
    /**********************************************************************************************
     * function name: Map Destructor                                                              *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~Map();
    
    /**********************************************************************************************
     * function name: addShip                                                                     *
     * The Input: const Ship object (reference)                                                   *
     * The output: none                                                                           *
     * The Function Opertion: Adds the ship to the location in the grid using it's origin.        *
     * *******************************************************************************************/
    
    void addShip(const Ship &cShip);
    
    /**********************************************************************************************
     * function name: hit                                                                         *
     * The Input: const Coordiante object (reference)                                             *
     * The output: MapRepresentation (enum)                                                       *
     * The Function Opertion: Tries to perform a hit on the input coordinate. Returns the result  *
     *                        of an occupied slot, miss or hit using the MapRepresentation.       *
     * *******************************************************************************************/
    
    MapRepresentation hit(const Coordinate& cCoordinate);
    
    /**********************************************************************************************
     * function name: isValid                                                                     *
     * The Input: const Ship object (reference)                                                   *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if its possible to place a Ship (input) in the map,    *
     *                        false otherwise.                                                    *
     * *******************************************************************************************/
    
    bool isValid(const Ship& cShip) ;
    
    /**********************************************************************************************
     * function name: isAllHit                                                                    *
     * The Input: none                                                                            *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if all of the ships in the map have been hit, false    *
     *                        otherwise.                                                          *
     * *******************************************************************************************/
    
    bool isAllHit() const;
 
    /**********************************************************************************************
     * function name: hideShips                                                                   *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Hides all of the ships added to the map.                            *
     * *******************************************************************************************/
    
    void hideShips();
    
    /**********************************************************************************************
     * function name: clone                                                                       *
     * The Input: none                                                                            *
     * The output: GameObject object (pointer)                                                    *
     * The Function Opertion: Returns a copy of the current object.                               *
     * *******************************************************************************************/
    
    virtual GameCollection* clone() const;
    
};

#endif /* defined(__Ex1__Map__) */
