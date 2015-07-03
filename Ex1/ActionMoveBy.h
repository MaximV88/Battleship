/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of ActionMoveBy Class      *
 ***********************************************************/

#ifndef __Ex1__ActionMoveBy__
#define __Ex1__ActionMoveBy__

#include <stdio.h>
#include "Action.h"

/*******************************************************************************
 * ActionMoveBy Class: This will move the Target object by the specified input *
 *                      when initializing the class.                           *
 ******************************************************************************/

class ActionMoveBy : public Action {
    
private:

    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the X to move by
    const int m_iMoveByX;
    
    //Stores the Y to move by
    const int m_iMoveByY;
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: update                                                                      *
     * The Input: Coordinate object (pointer)                                                     *
     * The output: none                                                                           *
     * The Function Opertion: Updates the input Coordinate's position.                            *
     * *******************************************************************************************/
    
    virtual void update(Coordinate* cCoordinate);
    
    /**********************************************************************************************
     * function name: applyToOrigin                                                               *
     * The Input: none                                                                            *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if should apply to origin, false otherwise.            *
     * *******************************************************************************************/
    
    virtual bool applyToOrigin() const;
    
    /**********************************************************************************************
     * function name: applyToVertices                                                             *
     * The Input: none                                                                            *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if should apply to vertices, false otherwise.          *
     * *******************************************************************************************/
    
    virtual bool applyToVertices() const;

public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: ActionMoveBy Constructor                                                      *
     * The Input: int, int                                                                          *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input Movement values                     *
     * *********************************************************************************************/
    
    ActionMoveBy(int iMoveByX, int iMoveByY);
    
    /************************************************************************************************
     * function name: ActionMoveBy Constructor                                                      *
     * The Input: Shape object (pointer), int, int                                                  *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with a Target and input Movement values.       *
     * *********************************************************************************************/
    
    ActionMoveBy(Shape* cTarget, int iMoveByX, int iMoveByY);
    
    /************************************************************************************************
     * function name: ActionMoveBy Constructor                                                      *
     * The Input: GameObject object (pointer)                                                       *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with a Target and input Movement values.       *
     * *********************************************************************************************/
    
    ActionMoveBy(GameObject* cTarget, int iMoveByX, int iMoveByY);
    
    /************************************************************************************************
     * function name: ActionMoveBy Constructor                                                      *
     * The Input: GameCollection object (pointer)                                                   *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with a Target and input Movement values.       *
     * *********************************************************************************************/
    
    ActionMoveBy(GameCollection* cTarget, int iMoveByX, int iMoveByY);

    /**********************************************************************************************
     * function name: ActionMoveBy Destructor                                                     *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~ActionMoveBy();
    
};


#endif 
