/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of ComputerPlayer Class    *
 ***********************************************************/

#ifndef __Ex1__ComputerPlayer__
#define __Ex1__ComputerPlayer__

#include <stdio.h>
#include <stack>
#include "Player.h"
#include "Coordinate.h"

class Ship;

/***************************************************************************************
 * ComputerPlayer Class: Represents the Computer player. When presented with a possible*
 *                    action, it acts in the difficulty it was selected to have.       *
 **************************************************************************************/

class ComputerPlayer : public Player {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the coordinates when having a successful hit for DFS type algorithm
    std::stack<Coordinate> m_vcCoordiantes;

    //Stores the selected difficulty
    PlayerDifficulty m_ePlayerDifficulty;

    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: actEasy                                                                       *
     * The Input: Map object (pointer)                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Performs an action on the map. If successful in chaning the map,      *
     *                        returns true, otherwise return false.                                 *
     * *********************************************************************************************/
    
    bool actEasy(Map* cMap);
    
    /************************************************************************************************
     * function name: actMedium                                                                     *
     * The Input: Map object (pointer)                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Performs an action on the map. If successful in chaning the map,      *
     *                        returns true, otherwise return false.                                 *
     * *********************************************************************************************/
    
    bool actMedium(Map* cMap);
    
    /************************************************************************************************
     * function name: actHard                                                                       *
     * The Input: Map object (pointer)                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Performs an action on the map. If successful in chaning the map,      *
     *                        returns true, otherwise return false.                                 *
     * *********************************************************************************************/
    
    bool actHard(Map* cMap);
    
    /************************************************************************************************
     * function name: guess                                                                         *
     * The Input: none                                                                              *
     * The output: Coordinate object                                                                *
     * The Function Opertion: Returns a coordinate with random values that are based off on the     *
     *                        map size.                                                             *
     * *********************************************************************************************/

    Coordinate guess() const;
    
    /************************************************************************************************
     * function name: addAdjacentIntoStack                                                          *
     * The Input: const Coordinate object (reference)                                               *
     * The output: none                                                                             *
     * The Function Opertion: Adds the adjaced legal coordinates to the vector (legal means by not  *
     *                        extending the map boundries).                                         *
     * *********************************************************************************************/
    
    void addAdjacentIntoStack(const Coordinate& cCoordinate);
    
    /************************************************************************************************
     * function name: checkExtendedArea                                                             *
     * The Input: Ship object (pointer), Map object (pointer)                                       *
     * The output: bool                                                                             *
     * The Function Opertion: Returns true if the area sorrounding the ship is valid for placement, *
     *                        false otherwise.                                                      *
     * *********************************************************************************************/
    
    bool checkExtendedArea(Ship* cShip, Map* cMap);
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: ComputerPlayer Constructor                                                    *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object                                                *
     * *********************************************************************************************/
    
    ComputerPlayer();
    
    /**********************************************************************************************
     * function name: act                                                                         *
     * The Input: Map object (pointer)                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Makes a turn on the input map.                                      *
     * *******************************************************************************************/
    
    virtual void act(Map* cMap);
    
    /**********************************************************************************************
     * function name: assign                                                                      *
     * The Input: Map object (pointer)                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Assignes a ship on the input Map.                                   *
     * *******************************************************************************************/
    
    virtual void assign(Map* cMap);

    /**********************************************************************************************
     * function name: setPlayerDifficulty                                                         *
     * The Input: PlayerDifficulty (enum)                                                         *
     * The output: none                                                                           *
     * The Function Opertion: Sets the difficulty of the ComputerPlayer                           *
     * *******************************************************************************************/
    
    void setPlayerDifficulty(PlayerDifficulty eDifficulty);
};

#endif
