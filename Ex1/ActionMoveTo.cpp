/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of ActionMoveTo Class   *
 ***********************************************************/

#include "ActionMoveTo.h"
#include "GameObject.h"
#include "GameCollection.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: update                                                                      *
 * The Input: Coordinate object (pointer)                                                     *
 * The output: none                                                                           *
 * The Function Opertion: Updates the input Coordinate's position.                            *
 * *******************************************************************************************/

void ActionMoveTo::update(Coordinate *cCoordinate) {
    
    cCoordinate->Coordinate::operator=(Coordinate(m_iMoveToX, m_iMoveToY));
    
}

/**********************************************************************************************
 * function name: applyToOrigin                                                               *
 * The Input: none                                                                            *
 * The output: bool                                                                           *
 * The Function Opertion: Always return true.                                                 *
 * *******************************************************************************************/

bool ActionMoveTo::applyToOrigin() const { return true; }

/**********************************************************************************************
 * function name: applyToVertices                                                             *
 * The Input: none                                                                            *
 * The output: bool                                                                           *
 * The Function Opertion: Always return false.                                                *
 * *******************************************************************************************/

bool ActionMoveTo::applyToVertices() const { return false; }

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: ActionMoveTo Constructor                                                      *
 * The Input: int, int                                                                          *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input Movement values                     *
 * *********************************************************************************************/

ActionMoveTo::ActionMoveTo(int iMoveToX, int iMoveToY) :
Action(), m_iMoveToX(iMoveToX), m_iMoveToY(iMoveToY) { }

/************************************************************************************************
 * function name: ActionMoveTo Constructor                                                      *
 * The Input: Shape object (pointer), int, int                                                  *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with a Target and input Movement values.       *
 * *********************************************************************************************/

ActionMoveTo::ActionMoveTo(Shape* cTarget, int iMoveToX, int iMoveToY) :
Action(cTarget), m_iMoveToX(iMoveToX), m_iMoveToY(iMoveToY) { }

/************************************************************************************************
 * function name: ActionMoveTo Constructor                                                      *
 * The Input: GameObject object (pointer)                                                       *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with a Target and input Movement values.       *
 * *********************************************************************************************/

ActionMoveTo::ActionMoveTo(GameObject* cTarget, int iMoveToX, int iMoveToY) :
Action(cTarget), m_iMoveToX(iMoveToX), m_iMoveToY(iMoveToY) { }

/************************************************************************************************
 * function name: ActionMoveTo Constructor                                                      *
 * The Input: GameCollection object (pointer)                                                   *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with a Target and input Movement values.       *
 * *********************************************************************************************/

ActionMoveTo::ActionMoveTo(GameCollection* cTarget, int iMoveToX, int iMoveToY) :
Action(cTarget), m_iMoveToX(iMoveToX), m_iMoveToY(iMoveToY) { }

/**********************************************************************************************
 * function name: ActionMoveTo Destructor                                                     *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

ActionMoveTo::~ActionMoveTo() { }



