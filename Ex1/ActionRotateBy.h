/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of ActionRotateBy Class    *
 ***********************************************************/

#ifndef __Ex1__ActionRotateBy__
#define __Ex1__ActionRotateBy__

#include <stdio.h>
#include "Action.h"

/***********************************************************************************
 * ActionRotateBy Class: This will rotate the Target object by the specified input *
 *                      when initializing the class.                               *
 **********************************************************************************/

class ActionRotateBy : public Action {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the angle to rotate by
    float m_fAngle;
    
    //Stores the rotation center
    Coordinate m_cCoordinate;
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: update                                                                      *
     * The Input: Coordinate object (pointer)                                                     *
     * The output: none                                                                           *
     * The Function Opertion: Updates the input Coordinate's position.                            *
     * *******************************************************************************************/
    
    void update(Coordinate* cCoordinate);
    
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
     * function name: ActionRotateBy Constructor                                                    *
     * The Input: float, const Coordinate object (reference)                                        *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with rotation angle and rotation center.       *
     * *********************************************************************************************/

    ActionRotateBy(float fAngle, const Coordinate& cRotationCenter);
    
    /************************************************************************************************
     * function name: ActionRotateBy Constructor                                                    *
     * The Input: const Shape object (pointer), float, const Coordinate object (reference)          *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with a Target,                                 *
     *                        rotation angle and rotation center.                                   *
     * *********************************************************************************************/
    
    ActionRotateBy(Shape *cTarget, float fAngle, const Coordinate& cRotationCenter);
    
    /************************************************************************************************
     * function name: ActionRotateBy Constructor                                                    *
     * The Input: GameObject object (pointer), float                                                *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with a Target and rotation value.              *
     * *********************************************************************************************/

    ActionRotateBy(GameObject *cTarget, float fAngle);
    
    /**********************************************************************************************
     * function name: ActionRotateBy Destructor                                                   *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~ActionRotateBy();

};

#endif
