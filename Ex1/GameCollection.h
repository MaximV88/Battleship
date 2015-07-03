/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of GameCollection Class    *
 ***********************************************************/

#ifndef __Ex1__GameCollection__
#define __Ex1__GameCollection__

#include <stdio.h>
#include <string>
#include "GameObject.h"
#include "Collection.h"

/*****************************************************************************************************
 * GameCollection Class:    Stores GameObjects, and itself a GameObject. it means that               *
 *                          Subclasses can add GameObjects and themselfs be a GameObjects.           *
 *                          (Like a Ship which is a GameObject, that has guns, who are GameObjects.  *
 *                          The class is usefull when subclassed and is added functionality,         *
 *                          The Drawer/Actions can later be performed without any modifications.     *
 ****************************************************************************************************/

class GameCollection : public GameObject, public Collection<GameObject> {
    
private:
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: copyGameObjects                                                               *
     * The Input: const GameCollection object (reference)                                           *
     * The output: none                                                                             *
     * The Function Opertion: Copies the input's GameCollection GameObjects into the current object.*
     * *********************************************************************************************/
    
    void copyGameObjects(const GameCollection &cGameCollection);
    
protected:
    
    //  ---                         PROTECTED FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: getGameObject                                                               *
     * The Input: const Coordinate object (reference)                                             *
     * The output: GameObject object (pointer)                                                    *
     * The Function Opertion: Returns the GameObject object from the collection at the input      *
     *                        Coordinate. Null if not found                                       *
     * *******************************************************************************************/
    
    GameObject* getGameObject(const Coordinate& cCoordinate);


public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: GameCollection Constructor                                                    *
     * The Input: const Coordinate object (reference)                                               *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with an origin                                 *
     * *********************************************************************************************/
    
    GameCollection(const Coordinate& cOrigin);
    
    /************************************************************************************************
     * function name: GameCollection Copy Constructor                                               *
     * The Input: const GameObject object (reference)                                               *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object as a copy of the input                         *
     * *********************************************************************************************/
    
    GameCollection(const GameCollection& cGameCollection);
    
    /**********************************************************************************************
     * function name: GameCollection Destructor                                                   *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~GameCollection();
    
    /**********************************************************************************************
     * function name: operator=                                                                   *
     * The Input: const GameCollection object (reference)                                         *
     * The output: GameCollection object (reference)                                              *
     * The Function Opertion: Copies the contents of the input object                             *
     * *******************************************************************************************/
    
    GameCollection& operator=(const GameCollection& cGameCollection);

    /****************************************************************************************************
     * function name: isOverlap                                                                         *
     * The Input: const GameCollection object (reference), const Coordinate object (reference)          *
     * The output: bool                                                                                 *
     * The Function Opertion: Returns true if the input GameCollection overlaps the current object,     *
     *                        with the addition of the Coordinate object to the input GameCollection's  *
     *                        position. If does not overlap, returns false.                             *
     * *************************************************************************************************/
    
    bool isOverlap(const GameCollection& cGameCollection, const Coordinate& cCoordinate = Coordinate(0, 0)) const;
    
    /**********************************************************************************************
     * function name: isOverlap                                                                   *
     * The Input: const GameObject object (reference), const Coordinate object (reference)        *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if the input GameObject overlaps the current object,   *
     *                        with the addition of the Coordinate object to the input GameObject  *
     *                        position. If does not overlap, returns false.                       *
     * *******************************************************************************************/
    
    bool isOverlap(const GameObject& cGameObject, const Coordinate& cCoordinate = Coordinate(0, 0)) const;

    /**********************************************************************************************
     * function name: clone                                                                       *
     * The Input: none                                                                            *
     * The output: GameCollection object (pointer)                                                 *
     * The Function Opertion: Returns a copy of the current object.                               *
     * *******************************************************************************************/
    
    virtual GameCollection* clone() const = 0;
    
};

#endif 
