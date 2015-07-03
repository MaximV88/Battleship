/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Ship Class           *
 ***********************************************************/

#include "Ship.h"
#include "Point.h"

#include "ActionRotateBy.h"

#include "Settings.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Ship Constructor                                                              *
 * The Input: ShipType (enum), ShipDirection (enum), const Coordinate object (reference)        *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the class variables to default values, and to the input   *
 *                        values. Afterwards, according to input's type and direction it places *
 *                        points in appropriate position, and rotates it using an action if     *
 *                        its not facing the East direction.                                    *
 * *********************************************************************************************/

Ship::Ship(ShipType eType, ShipDirection eDirection, const Coordinate& cOrigin) : GameObject(cOrigin), m_uiShipLife(NULL) {
    
    m_eShipType = eType;
    m_eShipDirection = eDirection;
    
    //The representation of an occupied slot
    char chDefaultRepresentation = Settings::getInstance().getRepresentationForType(MapRepresentationOccupied);
    
    //Add the appropriate shape by the type
    switch (eType) {

        case ShipType1x2:
            
            m_uiShipHorizontalLength = 2;
            m_uiShipVerticalLength = 1;
            m_uiShipLife = 2;
            
            //Added with the map structure in mind
            collect(new Point(Coordinate(0, 0), chDefaultRepresentation));
            collect(new Point(Coordinate(2, 0), chDefaultRepresentation));
            break;
            
        case ShipType1x3:
            
            m_uiShipHorizontalLength = 3;
            m_uiShipVerticalLength = 1;
            m_uiShipLife = 3;

            //An even longer line
            collect(new Point(Coordinate(0, 0), chDefaultRepresentation));
            collect(new Point(Coordinate(2, 0), chDefaultRepresentation));
            collect(new Point(Coordinate(4, 0), chDefaultRepresentation));
            break;
            
        case ShipType1x4:
            
            m_uiShipHorizontalLength = 4;
            m_uiShipVerticalLength = 1;
            m_uiShipLife = 4;

            //A really long line
            collect(new Point(Coordinate(0, 0), chDefaultRepresentation));
            collect(new Point(Coordinate(2, 0), chDefaultRepresentation));
            collect(new Point(Coordinate(4, 0), chDefaultRepresentation));
            collect(new Point(Coordinate(6, 0), chDefaultRepresentation));
            break;
            
        case ShipType2x2:

            m_uiShipHorizontalLength = 2;
            m_uiShipVerticalLength = 2;
            m_uiShipLife = 4;

            //Rectangle with a size of 2x2
            collect(new Point(Coordinate(0, 0), chDefaultRepresentation));
            collect(new Point(Coordinate(2, 0), chDefaultRepresentation));
            collect(new Point(Coordinate(0, 2), chDefaultRepresentation));
            collect(new Point(Coordinate(2, 2), chDefaultRepresentation));
            break;

        case ShipType2x3:
            
            m_uiShipHorizontalLength = 3;
            m_uiShipVerticalLength = 2;
            m_uiShipLife = 6;

            //Rectangle with a size of 3x2
            collect(new Point(Coordinate(0, 0), chDefaultRepresentation));
            collect(new Point(Coordinate(2, 0), chDefaultRepresentation));
            collect(new Point(Coordinate(0, 2), chDefaultRepresentation));
            collect(new Point(Coordinate(2, 2), chDefaultRepresentation));
            collect(new Point(Coordinate(4, 0), chDefaultRepresentation));
            collect(new Point(Coordinate(4, 2), chDefaultRepresentation));
            break;
            
        //Shouldnt do that
        default: break;

    }
    
    //After the assignment of the shape is done, we rotate it according to the input
    //The building is made towards the East
    
    switch (m_eShipDirection) {
        case ShipDirectionEast:
            
            break; //Do nothing
            
        case ShipDirectionWest:
            
            ActionRotateBy(this, 180).Action::apply();
            
            break;
        case ShipDirectionNorth:
            
            ActionRotateBy(this, 90).Action::apply();
            
            break;
        case ShipDirectionSouth:
            
            ActionRotateBy(this, -90).Action::apply();
            
            break;
            
        //Shouldnt do that
        default: break;
  
    }

}

/************************************************************************************************
 * function name: Ship Copy Constructor                                                         *
 * The Input: const Ship object (reference)                                                     *
 * The output: none                                                                             *
 * The Function Opertion: Copies all of the Ship's properties, and copies all of it's shapes    *
 *                        by using the Copy Constructor of the GameObject.                      *
 * *********************************************************************************************/

Ship::Ship(const Ship& cShip) : GameObject(cShip) {
    
    //Copy the type
    m_eShipType = cShip.m_eShipType;
    m_eShipDirection = cShip.m_eShipDirection;
    
    m_uiShipHorizontalLength = cShip.m_uiShipHorizontalLength;
    m_uiShipVerticalLength = cShip.m_uiShipVerticalLength;
    
    m_uiShipLife = cShip.getShipLife();
    
}

/**********************************************************************************************
 * function name: Ship Destructor                                                             *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

Ship::~Ship() {
    
}

/**********************************************************************************************
 * function name: hit                                                                         *
 * The Input: const Coordinate object (reference)                                             *
 * The output: bool                                                                           *
 * The Function Opertion: Returns false if the ship has no life (since it has nothing left    *
 *                        to hit). Otherwise, it gets the Shape stored in the input's position*
 *                        and directly changes the stored character of the Shape to the       *
 *                        required char. It then subtracs 1 life and returns true. If a shape *
 *                        has not been found, it returns false.                               *
 * *******************************************************************************************/

bool Ship::hit(const Coordinate& cCoordinate) {
    
    //There are no more life left in the ship
    if (m_uiShipLife == 0)
        return false;
    
    //Only stores points in the creation of the ship
    Shape *cShapeHit = getShape(cCoordinate);
    
    //If it can be hit in that location - hit it. The internal coordinate in the shape has a fixed location that needs to be stripped from the origin's influence
    if (cShapeHit != NULL && (cShapeHit->getRepresentation(cCoordinate - *this) != Settings::getInstance().getRepresentationForType(MapRepresentationHit))) {
    
        //Change the representation for this location
        cShapeHit->setRepresentation(cCoordinate - *this, Settings::getInstance().getRepresentationForType(MapRepresentationHit));
        
        //Decrease the life of the ship by one
        --m_uiShipLife;
        
        //Successfull
        return true;
        
    }
    
    return false;
    
}

/**********************************************************************************************
 * function name: hide                                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Iterates through all of the contained shapes in the Ship and        *
 *                        changes it's representation (char) to the 'Clear' representation.   *
 * *******************************************************************************************/

void Ship::hide() {
    
    //This will change every vertex in the contained shape to ' '
    for (std::vector<Shape*>::iterator iter = mutables().begin() ; iter != mutables().end() ; iter++) {
        
        //Get the shape stored in this location
        Shape* cShape = (*iter);
        
        //And hide it
        cShape->setRepresentation(Settings::getInstance().getRepresentationForType(MapRepresentationClear));
        
    }
    
}

/**********************************************************************************************
 * function name: getShipDirection                                                            *
 * The Input: none                                                                            *
 * The output: ShipDirection (enum)                                                           *
 * The Function Opertion: Returns the value of the member variable that holds the             *
 *                        Ship direction.                                                     *
 * *******************************************************************************************/

ShipDirection Ship::getShipDirection() const {
    
    return m_eShipDirection;
    
}

/**********************************************************************************************
 * function name: getShipVerticalLength                                                       *
 * The Input: none                                                                            *
 * The output: unsigned int                                                                   *
 * The Function Opertion: Returns the value of the member variable that holds the             *
 *                        Ship's Vertical length.                                             *
 * *******************************************************************************************/

unsigned int Ship::getShipVerticalLength() const {
    
    return m_uiShipVerticalLength;

}

/**********************************************************************************************
 * function name: getShipHorizontalLength                                                     *
 * The Input: none                                                                            *
 * The output: unsigned int                                                                   *
 * The Function Opertion: Returns the value of the member variable that holds the             *
 *                        Ship's Horizontal length.                                           *
 * *******************************************************************************************/

unsigned int Ship::getShipHorizontalLength() const {
    
    return m_uiShipHorizontalLength;
    
}

/**********************************************************************************************
 * function name: getShipLife                                                                 *
 * The Input: none                                                                            *
 * The output: unsigned int                                                                   *
 * The Function Opertion: Returns the value of the member variable that holds the             *
 *                        Ship's life.                                                        *
 * *******************************************************************************************/

unsigned int Ship::getShipLife() const { return m_uiShipLife; }

/**********************************************************************************************
 * function name: clone                                                                       *
 * The Input: none                                                                            *
 * The output: GameObject object (pointer)                                                    *
 * The Function Opertion: Returns a copy of the current object using it's Copy Constructor.   *
 * *******************************************************************************************/

GameObject* Ship::clone() const {
    
    return new Ship(*this);
    
}

