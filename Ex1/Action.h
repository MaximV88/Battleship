/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Action Class            *
 ***********************************************************/

#ifndef __Ex1__Action__
#define __Ex1__Action__

#include <stdio.h>
#include "Shape.h"
#include "GameObject.h"
#include "GameCollection.h"

/**********************************************************************************************************
 * Action Class:  This class performs actions on GameObjects/GameCollections/Shapes. It updates all       *
 *                of the input's vertices according to position and origin using more specific subclassed *
 *                classes. Because matrices were not implemented, storing information about position,     *
 *                rotation and scale is not possible - which is why the vertices are operated on          *
 *                directly. Once Matrices will be added this                                              *
 *                class will perform operations only on the ModelView matrix.                             *
 *********************************************************************************************************/

class Action {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //


    //Stores the target if its a Shape subclass
    Shape* const m_cTargetShape;
    
    //Stores the target if its a GameObject subclass
    GameObject* const m_cTargetGameObject;
    
    //Stores the target if its a GameCollection subclass
    GameCollection* const m_cTargetGameCollection;
    
protected:
    
    //  ---                         PROTECTED FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: update                                                                      *
     * The Input: Coordinate object (pointer)                                                     *
     * The output: none                                                                           *
     * The Function Opertion: Updates the input Coordinate's position.                            *
     * *******************************************************************************************/
    
    virtual void update(Coordinate* cCoordinate) = 0;
    
    /**********************************************************************************************
     * function name: applyToOrigin                                                               *
     * The Input: none                                                                            *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if should apply to origin, false otherwise.            *
     * *******************************************************************************************/
    
    virtual bool applyToOrigin() const = 0;
    
    /**********************************************************************************************
     * function name: applyToVertices                                                             *
     * The Input: none                                                                            *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if should apply to vertices, false otherwise.          *
     * *******************************************************************************************/
    
    virtual bool applyToVertices() const = 0;

public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: Action Constructor                                                            *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object                                                *
     * *********************************************************************************************/
    
    Action();
    
    /************************************************************************************************
     * function name: Action Constructor                                                            *
     * The Input: Shape object (pointer)                                                            *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with a Target.                                 *
     * *********************************************************************************************/
    
    Action(Shape* cTarget);
    
    /************************************************************************************************
     * function name: Action Constructor                                                            *
     * The Input: GameObject object (pointer)                                                       *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with a Target.                                 *
     * *********************************************************************************************/
    
    Action(GameObject* cTarget);
    
    /************************************************************************************************
     * function name: Action Constructor                                                            *
     * The Input: GameCollection object (pointer)                                                   *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with a Target.                                 *
     * *********************************************************************************************/
    
    Action(GameCollection* cTarget);
    
    /**********************************************************************************************
     * function name: Action Destructor                                                           *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~Action();
    
    /**********************************************************************************************
     * function name: apply                                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Applies the action on the Target.                                   *
     * *******************************************************************************************/
    
    void apply();
    
    /**********************************************************************************************
     * function name: apply                                                                       *
     * The Input: Shape object (pointer)                                                          *
     * The output: none                                                                           *
     * The Function Opertion: Applies the action on the input object.                             *
     * *******************************************************************************************/
    
    virtual void apply(Shape* cTarget);
    
    /**********************************************************************************************
     * function name: apply                                                                       *
     * The Input: GameObject object (pointer)                                                     *
     * The output: none                                                                           *
     * The Function Opertion: Applies the action on the input object.                             *
     * *******************************************************************************************/
    
    virtual void apply(GameObject* cTarget);
    
    /**********************************************************************************************
     * function name: apply                                                                       *
     * The Input: GameCollection object (pointer)                                                 *
     * The output: none                                                                           *
     * The Function Opertion: Applies the action on the input object.                             *
     * *******************************************************************************************/
    
    virtual void apply(GameCollection* cTarget);
    
};

#endif /* defined(__Ex1__Action__) */
