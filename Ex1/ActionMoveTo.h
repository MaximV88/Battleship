/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of ActionMoveTo Class      *
 ***********************************************************/

#ifndef __Ex1__ActionMoveTo__
#define __Ex1__ActionMoveTo__

#include <stdio.h>
#include "Action.h"

/*******************************************************************************
 * ActionMoveTo Class: This will move the Target object to the specified input *
 *                      when initializing the class.                           *
 ******************************************************************************/

class ActionMoveTo : public Action {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the X to move to
    const int m_iMoveToX;
    
    //Stores the Y to move to
    const int m_iMoveToY;
    
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
     * function name: ActionMoveTo Constructor                                                      *
     * The Input: int, int                                                                          *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input Movement values                     *
     * *********************************************************************************************/
    
    ActionMoveTo(int iMoveToX, int iMoveToY);
    
    /************************************************************************************************
     * function name: ActionMoveTo Constructor                                                      *
     * The Input: Shape object (pointer), int, int                                                  *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with a Target and input Movement values.       *
     * *********************************************************************************************/
    
    ActionMoveTo(Shape* cTarget, int iMoveToX, int iMoveToY);
    
    /************************************************************************************************
     * function name: ActionMoveTo Constructor                                                      *
     * The Input: GameObject object (pointer)                                                       *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with a Target and input Movement values.       *
     * *********************************************************************************************/
    
    ActionMoveTo(GameObject* cTarget, int iMoveToX, int iMoveToY);
    
    /************************************************************************************************
     * function name: ActionMoveTo Constructor                                                      *
     * The Input: GameCollection object (pointer)                                                   *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with a Target and input Movement values.       *
     * *********************************************************************************************/
    
    ActionMoveTo(GameCollection* cTarget, int iMoveToX, int iMoveToY);
    
    /**********************************************************************************************
     * function name: ActionMoveTo Destructor                                                     *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~ActionMoveTo();


};

#endif /* defined(__Ex1__ActionMoveTo__) */
