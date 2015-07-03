/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Map Class            *
 ***********************************************************/

#include <math.h>

#include "Map.h"
#include "Point.h"
#include "Ship.h"

#include "ActionMoveTo.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: buildMap                                                                    *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Changes the map size to the new Grid's size, and starts building    *
 *                        the grid as specified below.                                        *
 * *******************************************************************************************/

void Map::buildMap() {
    
    //Since the map shape is a complex set of characters, Points with different representations will be used
    
    //Need to update to the correct size
    resize(getWidth() * 2 + 3, getHeight() * 2 + 3);
    
    //Construct the grid
    for (unsigned int uiGridWidth = 0 ; uiGridWidth < getWidth() ; uiGridWidth++) {
        
        for (unsigned int uiGridHeight = 0 ; uiGridHeight < getHeight() ; uiGridHeight++) {
            
            //Since numbers can go beyond 9, need to remove the first '|' where numbers should be
            if (((getHeight() - 2 ) / 2) < 11 && uiGridWidth%2 == 0 && uiGridHeight%2 != 0)
                Collection<Shape>::collect(new Point(uiGridWidth, uiGridHeight,'|'));
            else if (uiGridWidth != 0 && uiGridWidth%2 == 0  && uiGridHeight%2 != 0)
                Collection<Shape>::collect(new Point(uiGridWidth, uiGridHeight,'|'));
            else if (uiGridWidth%2 != 0 && uiGridHeight%2 == 0)
                Collection<Shape>::collect(new Point(uiGridWidth, uiGridHeight,'-'));
            else if (((getHeight() - 2 ) / 2) >= 11 && uiGridWidth == 0 && uiGridWidth%2 == 0 && uiGridHeight%2 == 0)
                Collection<Shape>::collect(new Point(uiGridWidth, uiGridHeight,'-'));
            else if (uiGridWidth%2 == 0 && uiGridHeight%2 == 0)
                Collection<Shape>::collect(new Point(uiGridWidth, uiGridHeight,'+'));
            
        }
        
    }
    
    //Add the letter and coordinates
    for (unsigned uiGridLetters = 0 ; uiGridLetters < (getWidth() - 3 ) / 2 ; uiGridLetters++)
        Collection<Shape>::collect(new Point(uiGridLetters * 2 + 3, getHeight() - 2, 'A'+uiGridLetters));
    
    //Add the numbers coordinates
    for (unsigned int uiGridNumbers = 0 ; uiGridNumbers < (getHeight() - 2 ) / 2 ; uiGridNumbers++) {
        
        //If there are more than 10 digits, we need to make room for another base digit,
        //so move one to the left, and add a digit where required
        
        if ((getHeight() - 2 ) / 2 <= 10)
            Collection<Shape>::collect(new Point(1, getHeight() - 4 - uiGridNumbers*2, '0' + uiGridNumbers));
        else {
            
            //The 10th digit has 2 digits
            if (uiGridNumbers < 10)
                Collection<Shape>::collect(new Point(0, getHeight() - 4 - uiGridNumbers * 2, '0' + uiGridNumbers));
            
            else {
                
                Collection<Shape>::collect(new Point(0, getHeight()  - 4 - uiGridNumbers * 2, '0' + uiGridNumbers/10));
                Collection<Shape>::collect(new Point(1, getHeight() - 4 - uiGridNumbers * 2, '0' + uiGridNumbers%10));
                
            }
            
        }
        
    }
    
}

/**********************************************************************************************
 * function name: conformed                                                                   *
 * The Input: const Coordinate object (reference)                                             *
 * The output: Coordinate object                                                              *
 * The Function Opertion: Using the input's value it calculated through a reverse mathematical*
 *                        equation that adapts to the map size and placement. It then returns *
 *                        then calculated value.                                              *
 * *******************************************************************************************/

Coordinate Map::conformed(const Coordinate &cCoordinate) const {
    
    return Coordinate(cCoordinate.getX() + 3, getHeight() - 4 - 3 * cCoordinate.getY()) + cCoordinate;
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Map Constructor                                                               *
 * The Input: const Coordinate object (reference), unsigned int, unsigned int                   *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with an origin, width and height. Afterwards   *
 *                        calls to the building of the grid, and sets the hiding property of the*
 *                        added ships to be false.                                              *
 * *********************************************************************************************/

Map::Map(const Coordinate& cOrigin, unsigned int uiWidth, unsigned int uiHeight) : GameCollection(cOrigin), Oblong(uiWidth, uiHeight) {

    m_bIsHidingShips = false;
    
    buildMap();
    
}

/************************************************************************************************
 * function name: Map Constructor                                                               *
 * The Input: const Coordinate object (reference), const Oblong object (reference)              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with an origin, and the Oblong's width and     *
 *                        height. Afterwards calls to the building of the grid, and sets the    *
 *                        hiding property of the added ships to be false.                       *
 * *********************************************************************************************/

Map::Map(const Coordinate& cOrigin, const Oblong& cMapSize) : GameCollection(cOrigin), Oblong(cMapSize){
 
    m_bIsHidingShips = false;
    
    buildMap();
    
}

/************************************************************************************************
 * function name: Map Copy Constructor                                                          *
 * The Input: const Ship object (reference)                                                     *
 * The output: none                                                                             *
 * The Function Opertion: Uses the Copy Contrusctor of the GameCollection to copy all contained *
 *                        GameObjects (which in turn also copies the grid), copies the size of  *
 *                        the map, and the hiding property of the ships.                        *
 * *********************************************************************************************/

Map::Map(const Map& cMap) : GameCollection(cMap), Oblong(cMap) {
    
    m_bIsHidingShips = cMap.m_bIsHidingShips;
    
}

/**********************************************************************************************
 * function name: Map Destructor                                                              *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

Map::~Map() {


}

/**********************************************************************************************
 * function name: addShip                                                                     *
 * The Input: const Ship object (reference)                                                   *
 * The output: none                                                                           *
 * The Function Opertion: Makes a copy of the input ship, gets it's conformed position from   *
 *                        it's origin, and then translates it using an action. afterwards     *
 *                        hides the ship if required, and then stores it in the collection.   *
 * *******************************************************************************************/

void Map::addShip(const Ship &cShip) {
    
    //We always add only ships
    Ship cCopiedShip = Ship(cShip);
    
    Coordinate cConfCoord = conformed(cShip);
    
    ActionMoveTo(&cCopiedShip, cConfCoord.getX(), cConfCoord.getY()).apply();
    
    //Hide the ship if required to
    if (m_bIsHidingShips)
        cCopiedShip.hide();
    
    //Store a copy of the copied ship (this is a temporary stack copy)
    Collection<GameObject>::collect(cCopiedShip.clone());
    
}

/****************************************************************************************************
 * function name: hit                                                                               *
 * The Input: const Coordiante object (reference)                                                   *
 * The output: MapRepresentation (enum)                                                             *
 * The Function Opertion: Gets the conformed position from the input Coordinate, First tries        *
 *                        to get a shape (the grid) from it's coordinate. if found, return occupied.*
 *                        otherwise if did not get then continues to find a ship placed in the      *
 *                        coordinate. If found, it then tries to hit it. If successful hit it       *
 *                        return the value of Hit, otherwise occupied. If not found a ship add      *
 *                        a shape that represents a miss and return Missed.                         *
 * *************************************************************************************************/

MapRepresentation Map::hit(const Coordinate &cCoordinate) {
    
    Coordinate cConfCoord = conformed(cCoordinate);
    
    
    //There was a previous hit, and cant make another one on that spot
    if (getShape(cConfCoord + *this))
        return MapRepresentationOccupied;
    
    //Check for a ship on this location
    Ship* cShip = static_cast<Ship*>(getGameObject(cConfCoord + *this));
    
    //If didnt find anything on this slot its clear to hit
    if (cShip == NULL) {
        
        //Make a miss hit
        Collection<Shape>::collect(new Point(cConfCoord, Settings::getInstance().getRepresentationForType(MapRepresentationMissed)));
        
        //Missed the ship
        return MapRepresentationMissed;
        
    }
    
    //Otherwise found a ship, and need to check if it can be hit in that location
    if (cShip->hit(cConfCoord)) {
        
        //Made a hit
        return MapRepresentationHit;
        
    }
    else {
        
        //The spot is already occupied by a previous hit
        return MapRepresentationOccupied;
        
    }
    
}

/**********************************************************************************************
 * function name: isValid                                                                     *
 * The Input: const Ship object (reference)                                                   *
 * The output: bool                                                                           *
 * The Function Opertion: Checks if the placement is valid by creating a copy of the input    *
 *                        ship, moving it to the specified coordiante and checking if the     *
 *                        bounds are overlapping or if it hits any other shape that already   *
 *                        occupies the map. Returns true if all is ok, false otherwise.       *
 * *******************************************************************************************/

bool Map::isValid(const Ship &cShip)  {
    
    //Check to see if the recieved ship has valid position
    //This is done by checking conflicts with the map. if it conflicts with
    //the vertex, that may also belong to another ship, its not good.
    //Correct the position of the ship to conform to that of the Map
    Ship cCopiedShip = Ship(cShip);
    Coordinate cCorrectedPos =  conformed(cShip) + *this;
    ActionMoveTo(&cCopiedShip, cCorrectedPos.getX(), cCorrectedPos.getY()).apply();
    
    if (GameCollection::isOverlap(cCopiedShip))
        return false;
    
    
    //Also needs to check against valid position (not outside of map)
    //Assumes that there was initial check for validity of values vs map size
    switch (cShip.getShipDirection()) {
        case ShipDirectionEast:
            
            //                                   |
            //The ships faces East - (origin) -> +--
            return ((cShip.getX() + cShip.getShipHorizontalLength() <= Settings::getInstance().getMapSize().getWidth()) &&
                    (static_cast<int>(cShip.getY() - cShip.getShipVerticalLength()) >= -1));
            
            break;
            
        case ShipDirectionNorth:
            
            
            //                                       |
            //The ships faces North - (origin) ->  --+
            return ((static_cast<int>(cShip.getX() - cShip.getShipVerticalLength()) >= -1 ) &&
                    (static_cast<int>(cShip.getY() - cShip.getShipHorizontalLength()) >= -1 ));
            
            break;
            
        case ShipDirectionSouth:
            
            //The ships faces South - (origin) ->  +--
            //                                     |
            return ((cShip.getX() + cShip.getShipVerticalLength() <= Settings::getInstance().getMapSize().getWidth()) &&
                    (cShip.getY() + cShip.getShipHorizontalLength() <= Settings::getInstance().getMapSize().getHeight()));
            
            break;
            
        case ShipDirectionWest:
            
            //The ships faces West - (origin) ->   --+
            //                                       |
            return ((static_cast<int>(cShip.getX() - cShip.getShipHorizontalLength()) >= -1 ) &&
                    (cShip.getY() + cShip.getShipVerticalLength() <= Settings::getInstance().getMapSize().getHeight()));
            
            break;
            
            //Shouldnt do that
        default: break;
            
    }
    
    
    return true;
    
}

/**********************************************************************************************
 * function name: isAllHit                                                                    *
 * The Input: none                                                                            *
 * The output: bool                                                                           *
 * The Function Opertion: Iterates through all of the contained ships and checks them if they *
 *                        contain any life. If found a ship that contains life return false.  *
 *                        Otherwise if reached the end, return true.                          *
 * *******************************************************************************************/

bool Map::isAllHit() const {
    
    //Just iterate through all of the Ships and check if they have life left
    for (std::vector<GameObject*>::const_iterator iter = Collection<GameObject>::internals().begin() ;
         iter != Collection<GameObject>::internals().end() ;
         iter++) {
        
        //The GameObjects are known to be only ships
        const Ship *cShip = static_cast<const Ship*>(*iter);
        
        if (cShip->getShipLife() != 0)
            return false;
        
        
        
    }
    
    return true;
    
}

/**********************************************************************************************
 * function name: hideShips                                                                   *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Changes the internal value reponsible for hiding the ships when     *
 *                        adding them to the map.                                             *
 * *******************************************************************************************/

void Map::hideShips() {
    
    m_bIsHidingShips = true;
    
}

/**********************************************************************************************
 * function name: clone                                                                       *
 * The Input: none                                                                            *
 * The output: GameObject object (pointer)                                                    *
 * The Function Opertion: Returns a copy of the current object using it's Copy Constructor.   *
 * *******************************************************************************************/

GameCollection* Map::clone() const {
    
    return new Map(*this);
    
}
