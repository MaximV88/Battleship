/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of GameObject Class     *
 ***********************************************************/

#include "GameObject.h"
#include "Shape.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: copyShapes                                                                  *
 * The Input: const GameObject object (reference)                                             *
 * The output: none                                                                           *
 * The Function Opertion: Iterates through the Shapes contained in the input object, and      *
 *                        copies them into the current object's collection (vector).          *
 * *******************************************************************************************/

void GameObject::copyShapes(const GameObject &cGameObject) {
    
    for (std::vector<Shape*>::const_iterator iter = cGameObject.internals().begin() ; iter != cGameObject.internals().end() ; iter++) {
        
        //Add a copy of the shape to the collection
        collect((*iter)->clone());
        
    }
    
}

//  ---                         PROTECTED FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: getShape                                                                    *
 * The Input: const Coordinate object (reference)                                             *
 * The output: Shape object (pointer)                                                         *
 * The Function Opertion: Iterates through the Shapes contained in the current object, and    *
 *                        checks every one if it overlaps a given coordiante that is          *
 *                        subtracted from the current object's origin. Returns the Shape if   *
 *                        found, Null otherwise.                                              *
 * *******************************************************************************************/

Shape* GameObject::getShape(const Coordinate& cCoordinate) {
    
    Coordinate cTruePos = cCoordinate - *this;
    
    //Go through all of the shapes contained
    for (std::vector<Shape*>::iterator iter = mutables().begin() ; iter != mutables().end() ; iter++) {
        
        //And return the one that overlaps the coordinate
        if ((*iter)->isOverlap(cTruePos))
            return (*iter);
        
    }
    
    //Otherwise dont return anything
    return NULL;
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: GameObject Constructor                                                        *
 * The Input: const Coordinate object (reference)                                               *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with an origin                                 *
 * *********************************************************************************************/

GameObject::GameObject(const Coordinate& cOrigin) : Coordinate(cOrigin) { }

/************************************************************************************************
 * function name: GameObject Copy Constructor                                                   *
 * The Input: const GameObject object (reference)                                               *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with the given input's origin point, and       *
 *                        copies the shapes contained from it.                                  *
 * *********************************************************************************************/

GameObject::GameObject(const GameObject& cGameObject) : Coordinate(cGameObject) {

    //Copy all of the recieved object's Shapes
    copyShapes(cGameObject);

}

/**********************************************************************************************
 * function name: GameObject Destructor                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

GameObject::~GameObject() { }

/**********************************************************************************************
 * function name: operator=                                                                   *
 * The Input: const GameObject object (reference)                                             *
 * The output: GameObject object (reference)                                                  *
 * The Function Opertion: Checks if the current object is the input by comparing address of   *
 *                        pointer. If so then returns the object to avoid redundant work.     *
 *                        Otherwise cleans the current object's shape vector (collection),    *
 *                        and copies the shapes from the input object.                        *
 * *******************************************************************************************/

GameObject& GameObject::operator=(const GameObject &cGameObject) {
    
    //We check to avoid redundant work
    if (this != &cGameObject) {
        
        //Copy the origin
        Coordinate::operator=(cGameObject);

        //Remove all of the stored shapes
        clearCollection();
        
        //Copy the object's shapes
        copyShapes(cGameObject);
        
    }
    
    return *this;
    
}

/**********************************************************************************************
 * function name: isOverlap                                                                   *
 * The Input: const GameObject object (reference), const Coordinate object (reference)        *
 * The output: bool                                                                           *
 * The Function Opertion: Adds the input GameObject's origin with the input's fix, and        *
 *                        then iterates through all of the input's contained shapes, and      *
 *                        checks for overlaps of the current object's shapes with the input   *
 *                        ones. If an overlap has been made, return true. false otherwise.    *
 * *******************************************************************************************/

bool GameObject::isOverlap(const GameObject& cGameObject, const Coordinate& cCoordinate) const {
    
    //Take the true position of the coordinate
    Coordinate cTruePos = cGameObject + cCoordinate;
    
    //Check for every shape in the current object
    for (std::vector<Shape*>::const_iterator iter = cGameObject.internals().begin() ;
         iter != cGameObject.internals().end() ;
         iter++) {
        
        //Check for conflict in every shape in the recieved object
        if (isOverlap(**iter, cTruePos))
            return true;
        
    }
    
    //If did not find accross all of the contained shapes - its not overlaping
    return false;
    
}

/**********************************************************************************************
 * function name: isOverlap                                                                   *
 * The Input: const Shape object (reference), const Coordinate object (reference)             *
 * The output: bool                                                                           *
 * The Function Opertion: Calculates the correct coordiante by subtracting the origin point   *
 *                        from the input's origin (second parameter). Afterwards iterates     *
 *                        through all of the contained shapes in the current object's vector  *
 *                        and checks for overlaps (with the correct coordinate). Returns      *
 *                        true if an overlap has been found. If nothing matches, Return false.*
 * *******************************************************************************************/

bool GameObject::isOverlap(const Shape& cShape, const Coordinate& cCoordinate) const {
    
    //Take the true position of the coordinate 
    Coordinate cTruePos = *this - cCoordinate;
    
    //Check for every shape in the current object
    for (std::vector<Shape*>::const_iterator iter = internals().begin() ; iter != internals().end() ; iter++) {
        
        //Check for overlap
        if (cShape.isOverlap(**iter, cTruePos))
            return true;
        
    }
    
    //If did not find accross all of the contained shapes - its not overlaping
    return false;
    
}

/**********************************************************************************************
 * function name: isOverlap                                                                   *
 * The Input: const Coordinate object (reference)                                             *
 * The output: bool                                                                           *
 * The Function Opertion: Goes through all of the contained shapes in the current object,     *
 *                        and checks for overlaps with the input coordinate. Return true      *
 *                        if an overlap has been found, false otherwise.                      *
 * *******************************************************************************************/

bool GameObject::isOverlap(const Coordinate& cCoordinate) const {
    
    //Check for every shape in the current object
    for (std::vector<Shape*>::const_iterator iter = internals().begin() ; iter != internals().end() ; iter++) {
        
        //Check for overlap
        if ((*iter)->isOverlap(cCoordinate - *this))
            return true;
        
    }
    
    //If did not find accross all of the contained shapes - its not overlaping
    return false;
    
}


