/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of GameObject Class        *
 ***********************************************************/

#ifndef __Ex1__GameObject__
#define __Ex1__GameObject__

#include <stdio.h>

#include "Coordinate.h"
#include "Collection.h"
#include "Shape.h"

/****************************************************************************************
 * GameObject Class:Stores shapes assosiated with a GameObjects, can know if overlapped *
 *                  and has an origin point. Represents a collection of shapes with an  *
 *                  origin point.                                                       *
 ***************************************************************************************/

class GameObject : public Coordinate, public Collection<Shape> {
    
private:
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: copyShapes                                                                  *
     * The Input: const GameObject object (reference)                                             *
     * The output: none                                                                           *
     * The Function Opertion: Copies the input's GameObject's Shapes into the current object.     *
     * *******************************************************************************************/
    
    void copyShapes(const GameObject& cGameObject);
    
protected:
    
    //  ---                         PROTECTED FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: getShape                                                                    *
     * The Input: const Coordinate object (reference)                                             *
     * The output: Shape object (pointer)                                                         *
     * The Function Opertion: Returns the Shape object from the collection at the input           *
     *                        Coordinate. Null if not found                                       *
     * *******************************************************************************************/
    
    Shape* getShape(const Coordinate& cCoordinate);

public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: GameObject Constructor                                                        *
     * The Input: const Coordinate object (reference)                                               *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with an origin                                 *
     * *********************************************************************************************/
    
    GameObject(const Coordinate& cOrigin);
    
    /************************************************************************************************
     * function name: GameObject Copy Constructor                                                   *
     * The Input: const GameObject object (reference)                                               *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object as a copy of the input                         *
     * *********************************************************************************************/

    GameObject(const GameObject& cGameObject);

    /**********************************************************************************************
     * function name: GameObject Destructor                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~GameObject();
    
    /**********************************************************************************************
     * function name: operator=                                                                   *
     * The Input: const GameObject object (reference)                                             *
     * The output: GameObject object (reference)                                                  *
     * The Function Opertion: Copies the contents of the input object                             *
     * *******************************************************************************************/
    
    GameObject& operator=(const GameObject& cGameObject);
    
    /**********************************************************************************************
     * function name: isOverlap                                                                   *
     * The Input: const GameObject object (reference), const Coordinate object (reference)        *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if the input GameObject overlaps the current object,   *
     *                        with the addition of the Coordinate object to the input GameObject's*
     *                        position. If does not overlap, returns false.                       *
     * *******************************************************************************************/

    bool isOverlap(const GameObject& cGameObject, const Coordinate& cCoordinate = Coordinate(0, 0)) const;
    
    /**********************************************************************************************
     * function name: isOverlap                                                                   *
     * The Input: const Shape object (reference), const Coordinate object (reference)             *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if the input Shape overlaps the current object,        *
     *                        with the addition of the Coordinate object to the input Shape       *
     *                        position. If does not overlap, returns false.                       *
     * *******************************************************************************************/
    
    bool isOverlap(const Shape& cShape, const Coordinate& cCoordinate = Coordinate(0, 0)) const;
    
    /**********************************************************************************************
     * function name: isOverlap                                                                   *
     * The Input: const Coordinate object (reference)                                             *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if the current object overlaps the input Coordinate.   *
     * *******************************************************************************************/
    
    bool isOverlap(const Coordinate& cCoordinate) const;
    
    /**********************************************************************************************
     * function name: clone                                                                       *
     * The Input: none                                                                            *
     * The output: GameObject object (pointer)                                                    *
     * The Function Opertion: Returns a copy of the current object.                               *
     * *******************************************************************************************/
    
    virtual GameObject* clone() const = 0;
    
};

#endif
