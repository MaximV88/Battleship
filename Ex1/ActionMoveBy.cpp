/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of ActionMoveBy Class   *
 ***********************************************************/

#include "ActionMoveBy.h"
#include "GameObject.h"
#include "GameCollection.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: update                                                                      *
 * The Input: Coordinate object (pointer)                                                     *
 * The output: none                                                                           *
 * The Function Opertion: Takes the input coordinate object, adds the stored input to every   *
 *                        axis and then modified the input coordinate's object.               *
 * *******************************************************************************************/

void ActionMoveBy::update(Coordinate *cCoordinate) {
    
    //Calculate the moved distance - the coordinates are always positive
    int iMovedPositionX = cCoordinate->getX() + m_iMoveByX;
    int iMovedPositionY = cCoordinate->getY() + m_iMoveByY;
    
    cCoordinate->Coordinate::operator=(Coordinate(iMovedPositionX, iMovedPositionY));
    
}

/**********************************************************************************************
 * function name: applyToOrigin                                                               *
 * The Input: none                                                                            *
 * The output: bool                                                                           *
 * The Function Opertion: Always return true.                                                 *
 * *******************************************************************************************/

bool ActionMoveBy::applyToOrigin() const { return true; }

/**********************************************************************************************
 * function name: applyToVertices                                                             *
 * The Input: none                                                                            *
 * The output: bool                                                                           *
 * The Function Opertion: Always return false.                                                *
 * *******************************************************************************************/

bool ActionMoveBy::applyToVertices() const { return false; }

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: ActionMoveBy Constructor                                                      *
 * The Input: int, int                                                                          *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input Movement values                     *
 * *********************************************************************************************/

ActionMoveBy::ActionMoveBy(int iMoveByX, int iMoveByY) :
Action(), m_iMoveByX(iMoveByX), m_iMoveByY(iMoveByY) { }

/************************************************************************************************
 * function name: ActionMoveBy Constructor                                                      *
 * The Input: Shape object (pointer), int, int                                                  *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with a Target and input Movement values.       *
 * *********************************************************************************************/

ActionMoveBy::ActionMoveBy(Shape* cTarget, int iMoveByX, int iMoveByY) :
Action(cTarget), m_iMoveByX(iMoveByX), m_iMoveByY(iMoveByY) { }

/************************************************************************************************
 * function name: ActionMoveBy Constructor                                                      *
 * The Input: GameObject object (pointer)                                                       *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with a Target and input Movement values.       *
 * *********************************************************************************************/

ActionMoveBy::ActionMoveBy(GameObject* cTarget, int iMoveByX, int iMoveByY) :
Action(cTarget), m_iMoveByX(iMoveByX), m_iMoveByY(iMoveByY) { }

/************************************************************************************************
 * function name: ActionMoveBy Constructor                                                      *
 * The Input: GameCollection object (pointer)                                                   *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with a Target and input Movement values.       *
 * *********************************************************************************************/

ActionMoveBy::ActionMoveBy(GameCollection* cTarget, int iMoveByX, int iMoveByY) :
Action(cTarget), m_iMoveByX(iMoveByX), m_iMoveByY(iMoveByY) { }

/**********************************************************************************************
 * function name: ActionMoveBy Destructor                                                     *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

ActionMoveBy::~ActionMoveBy() { }
