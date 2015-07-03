/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of ActionRotateBy Class *
 ***********************************************************/

#include <math.h>

#include "ActionRotateBy.h"
#include "GameObject.h"
#include "GameCollection.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: update                                                                      *
 * The Input: Coordinate object (pointer)                                                     *
 * The output: none                                                                           *
 * The Function Opertion: Updates the input Coordinate's position.                            *
 * *******************************************************************************************/

void ActionRotateBy::update(Coordinate *cCoordinate) {
    
    int uiRotatedPositionX = round(m_cCoordinate.getX() +
                                   (cCoordinate->getX() - m_cCoordinate.getX()) * cosf(m_fAngle) -
                                   (cCoordinate->getY() - m_cCoordinate.getY()) * sinf(m_fAngle));
    
    int uiRotatedPositionY = round(m_cCoordinate.getY() +
                                   (cCoordinate->getX() - m_cCoordinate.getX()) * sinf(m_fAngle) +
                                   (cCoordinate->getY() - m_cCoordinate.getY()) * cosf(m_fAngle));
    
    cCoordinate->Coordinate::operator=(Coordinate(uiRotatedPositionX, uiRotatedPositionY));
    
}

/**********************************************************************************************
 * function name: applyToOrigin                                                               *
 * The Input: none                                                                            *
 * The output: bool                                                                           *
 * The Function Opertion: Always return false.                                                *
 * *******************************************************************************************/

bool ActionRotateBy::applyToOrigin() const { return false; }

/**********************************************************************************************
 * function name: applyToVertices                                                             *
 * The Input: none                                                                            *
 * The output: bool                                                                           *
 * The Function Opertion: Always return true.                                                 *
 * *******************************************************************************************/

bool ActionRotateBy::applyToVertices() const { return true; }

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: ActionRotateBy Constructor                                                    *
 * The Input: float, const Coordinate object (reference)                                        *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with rotation angle and rotation center.       *
 *                        The angle is transformed into radians.                                *
 * *********************************************************************************************/

ActionRotateBy::ActionRotateBy(float fAngle, const Coordinate& cRotationCenter) :
m_fAngle(fAngle * M_PI / 180), m_cCoordinate(cRotationCenter) { }

/************************************************************************************************
 * function name: ActionRotateBy Constructor                                                    *
 * The Input: const Shape object (pointer), float, const Coordinate object (reference)          *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with a Target,                                 *
 *                        rotation angle and rotation center.                                   *
 *                        The angle is transformed into radians.                                *
 * *********************************************************************************************/

ActionRotateBy::ActionRotateBy(Shape *cTarget, float fAngle, const Coordinate& cRotationCenter) :
Action(cTarget), m_cCoordinate(cRotationCenter), m_fAngle(fAngle * M_PI / 180) { }

/************************************************************************************************
 * function name: ActionRotateBy Constructor                                                    *
 * The Input: GameObject object (pointer), float                                                *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with a Target and rotation value.              *
 *                        The angle is transformed into radians.                                *
 * *********************************************************************************************/

ActionRotateBy::ActionRotateBy(GameObject *cTarget, float fAngle) :
Action(cTarget), m_fAngle(fAngle * M_PI / 180), m_cCoordinate(Coordinate(0, 0)) { }

/**********************************************************************************************
 * function name: ActionRotateBy Destructor                                                   *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

ActionRotateBy::~ActionRotateBy() { }



