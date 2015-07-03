/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of GameCollection Class *
 ***********************************************************/

#include "GameCollection.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: copyGameObjects                                                               *
 * The Input: const GameCollection object (reference)                                           *
 * The output: none                                                                             *
 * The Function Opertion: Iterates through the GameObjects contained in the input object, and   *
 *                        copies them into the current object's collection (vector).            *
 * *********************************************************************************************/

void GameCollection::copyGameObjects(const GameCollection &cGameCollection) {
    
    //Iterate through all of the contained GameObjects
    for (std::vector<GameObject*>::const_iterator iter = cGameCollection.Collection<GameObject>::internals().begin() ;
         iter != cGameCollection.Collection<GameObject>::internals().end() ;
         iter++) {
        
        //Add a copy of the shape to the collection
        Collection<GameObject>::collect((*iter)->clone());
        
    }
    
}

//  ---                         PROTECTED FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: getGameObject                                                                 *
 * The Input: const Coordinate object (reference)                                               *
 * The output: GameObject object (pointer)                                                      *
 * The Function Opertion: Iterates through the GameObjects contained in the current object, and *
 *                        checks every one if it overlaps a given coordiante that is            *
 *                        subtracted from the current object's origin. Returns the Shape if     *
 *                        found, Null otherwise.                                                *
 * *********************************************************************************************/

GameObject* GameCollection::getGameObject(const Coordinate& cCoordinate) {
    
    Coordinate cTruePos = cCoordinate - *this;
    
    //Go through all of the shapes contained
    for (std::vector<GameObject*>::iterator iter = Collection<GameObject>::mutables().begin() ;
         iter != Collection<GameObject>::mutables().end() ;
         iter++) {
        
        //And return the one that overlaps the coordinate
        if ((*iter)->isOverlap(cTruePos))
            return (*iter);
        
    }
    
    //Otherwise dont return anything
    return NULL;
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: GameCollection Constructor                                                    *
 * The Input: const Coordinate object (reference)                                               *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with an origin                                 *
 * *********************************************************************************************/

GameCollection::GameCollection(const Coordinate& cOrigin) : GameObject(cOrigin) { }

/************************************************************************************************
 * function name: GameCollection Copy Constructor                                               *
 * The Input: const GameObject object (reference)                                               *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with the given input's origin point, and       *
 *                        copies the GameObjects contained from it.                             *
 * *********************************************************************************************/

GameCollection::GameCollection(const GameCollection& cGameCollection) : GameObject(cGameCollection) {

    //Copy the GameObjects contained in the collection
    copyGameObjects(cGameCollection);

}

/**********************************************************************************************
 * function name: GameCollection Destructor                                                   *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

GameCollection::~GameCollection() { }

/**********************************************************************************************
 * function name: operator=                                                                   *
 * The Input: const GameCollection object (reference)                                         *
 * The output: GameCollection object (reference)                                              *
 * The Function Opertion: Checks if the current object is the input by comparing address of   *
 *                        pointer. If so then returns the object to avoid redundant work.     *
 *                        Otherwise cleans the current object's shape vector (collection),    *
 *                        and copies the GameObjects from the input object.                   *
 * *******************************************************************************************/

GameCollection& GameCollection::operator=(const GameCollection& cGameCollection) {
    
    //We check to avoid redundant work
    if (this != &cGameCollection) {
        
        //Copy the GameObject properties
        GameObject::operator=(cGameCollection);
        
        //Remove all of the stored shapes
        Collection<GameObject>::clearCollection();
        
        //Copy the object's shapes
        copyGameObjects(cGameCollection);
        
    }
    
    return *this;
    
}

/****************************************************************************************************
 * function name: isOverlap                                                                         *
 * The Input: const GameCollection object (reference), const Coordinate object (reference)          *
 * The output: bool                                                                                 *
 * The Function Opertion: Adds the input GameCollection's origin with the input's fix, and          *
 *                        then iterates through all of the input's contained GameObjects, and       *
 *                        checks for overlaps of the current object's GameObjects with the input    *
 *                        ones. If an overlap has been made, return true. false otherwise.          *
 * *************************************************************************************************/

bool GameCollection::isOverlap(const GameCollection& cGameCollection, const Coordinate& cCoordinate) const {
    
    //Check for every GameObject stored in the GameCollection
    for (std::vector<GameObject*>::const_iterator iter = Collection<GameObject>::internals().begin() ;
         iter !=  Collection<GameObject>::internals().end() ;
         iter++) {

            //Check for overlap using the GameObject behaviour
            if (isOverlap(**iter, cCoordinate + cGameCollection))
                return true;
        
    }
    
    //If did not find accross all of the contained GameObjects - its not overlaping
    return false;
    
}

/***************************************************************************************************
 * function name: isOverlap                                                                        *
 * The Input: const GameObject object (reference), const Coordinate object (reference)             *
 * The output: bool                                                                                *
 * The Function Opertion: Calculates the correct coordiante by subtracting the origin point        *
 *                        from the input's origin (second parameter). Afterwards iterates          *
 *                        through all of the contained GameObjects in the current object's vector  *
 *                        and checks for overlaps (with the correct coordinate). Returns           *
 *                        true if an overlap has been found. If nothing matches, Return false.     *
 * ************************************************************************************************/

bool GameCollection::isOverlap(const GameObject& cGameObject, const Coordinate& cCoordinate) const {
    
    //Check for every GameObject in the recieved collection
    for (std::vector<GameObject*>::const_iterator iter = Collection<GameObject>::internals().begin() ;
         iter !=  Collection<GameObject>::internals().end() ;
         iter++) {
        
        //Check for overlap using the GameObject behaviour
        if ((*iter)->isOverlap(cGameObject, Coordinate(0,0) - *this))
            return true;
        
    }
    
    //Check if the recieved GameObject is stored in the GameCollection
    for (std::vector<GameObject*>::const_iterator iter = Collection<GameObject>::internals().begin() ;
         iter !=  Collection<GameObject>::internals().end() ;
         iter++) {
     
        //If so, then true coordinate is with the origin of the collection
        if ((*iter)->Coordinate::operator==(cGameObject + *this))
            return GameObject::isOverlap(cGameObject, *this);
        
    }
    
    
    //Otherwise, check with the Shapes contained
    return GameObject::isOverlap(cGameObject);
    
}
