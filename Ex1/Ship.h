/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Ship Class              *
 ***********************************************************/

#ifndef __Ex1__Ship__
#define __Ex1__Ship__

#include <stdio.h>
#include "GameObject.h"

typedef enum {
    ShipTypeNone = 0,
    ShipType1x2,
    ShipType1x3,
    ShipType1x4,
    ShipType2x2,
    ShipType2x3,
    ShipTypeTotalNumber
} ShipType;

typedef enum {
    ShipDirectionNone = 0,
    ShipDirectionEast,
    ShipDirectionNorth,
    ShipDirectionSouth,
    ShipDirectionWest,
    ShipDirectionTotalNumber
} ShipDirection;

/****************************************************************************************************
 * Ship Class:       Its a subclassed GameObject (An object that can be displayed by the Drawer),   *
 *                   that has properties which are used by the map (i.e. hit/hide).                 *
 *                   Represents a Ship on the Map board.                                            *
 ***************************************************************************************************/

class Ship : public GameObject {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //
    
    
    //Stores the ship type
    ShipType m_eShipType;
    
    //Stores the ship direction
    ShipDirection m_eShipDirection;
    
    //Stores the ship's vertical length
    unsigned int m_uiShipVerticalLength;
    
    //Stores the ship's horizontal length
    unsigned int m_uiShipHorizontalLength;
    
    //Stores the ship's remaining life
    unsigned int m_uiShipLife;
        
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Ship Constructor                                                              *
     * The Input: ShipType (enum), ShipDirection (enum), const Coordinate object (reference)        *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with an origin, type and direction.            *
     * *********************************************************************************************/
    
    Ship(ShipType eType, ShipDirection eDirection, const Coordinate& cOrigin);
    
    /************************************************************************************************
     * function name: Ship Copy Constructor                                                         *
     * The Input: const Ship object (reference)                                                     *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object as a copy of the input                         *
     * *********************************************************************************************/
    
    Ship(const Ship& cShip);
    
    /**********************************************************************************************
     * function name: Ship Destructor                                                             *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~Ship();
    
    /**********************************************************************************************
     * function name: hit                                                                         *
     * The Input: const Coordinate object (reference)                                             *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if the ship has been hit in the specified location,    *
     *                        false otherwise.                                                    *
     * *******************************************************************************************/
    
    bool hit(const Coordinate& cCoordinate);
    
    /**********************************************************************************************
     * function name: hide                                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Hides the ship.                                                     *
     * *******************************************************************************************/
    
    void hide();
    
    /**********************************************************************************************
     * function name: getShipDirection                                                            *
     * The Input: none                                                                            *
     * The output: ShipDirection (enum)                                                           *
     * The Function Opertion: Returns the Ship's direction.                                       *
     * *******************************************************************************************/
    
    ShipDirection getShipDirection() const;
    
    /**********************************************************************************************
     * function name: getShipVerticalLength                                                       *
     * The Input: none                                                                            *
     * The output: unsigned int                                                                   *
     * The Function Opertion: Returns the Ship's Vertical length.                                 *
     * *******************************************************************************************/
    
    unsigned int getShipVerticalLength() const;
    
    /**********************************************************************************************
     * function name: getShipHorizontalLength                                                     *
     * The Input: none                                                                            *
     * The output: unsigned int                                                                   *
     * The Function Opertion: Returns the Ship's Horizontal length.                               *
     * *******************************************************************************************/
    
    unsigned int getShipHorizontalLength() const;
    
    /**********************************************************************************************
     * function name: getShipLife                                                                 *
     * The Input: none                                                                            *
     * The output: unsigned int                                                                   *
     * The Function Opertion: Returns the Ship's life.                                            *
     * *******************************************************************************************/
    
    unsigned int getShipLife() const;
    
    /**********************************************************************************************
     * function name: clone                                                                       *
     * The Input: none                                                                            *
     * The output: GameObject object (pointer)                                                    *
     * The Function Opertion: Returns a copy of the current object.                               *
     * *******************************************************************************************/
    
    virtual GameObject* clone() const;
    
};

#endif 
