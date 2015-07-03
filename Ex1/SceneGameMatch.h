/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of SceneGameMatch Class    *
 ***********************************************************/

#ifndef __Ex1__SceneGameMatch__
#define __Ex1__SceneGameMatch__

#include <stdio.h>
#include <stack>
#include "Scene.h"
#include "Drawer.h"
#include "Scanner.h"
#include "Shape.h"
#include "GameObject.h"
#include "Player.h"

typedef enum {
    
    SelectionGameMatchNone = 0,
    SelectionGameMatchPlayerVSComputer = 1,
    SelectionGameMatchComputerVSComputer = 2,
    SelectionGameMatchPlayerVSPlayer = 3,
    SelectionGameMatchTotalNumber = 4
    
} SelectionGameMatch;

class Map;

typedef std::pair<Player*, Map*> PlayerMapPair;

/***********************************************************************************
 * Scene Class: This class represents the GameMatch scene. It is to be handled     *
 *              only by the SceneDirector. It draws the GameObjects to the screen. *
 **********************************************************************************/

class SceneGameMatch : public Scene, public Drawer {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the players
    std::vector<PlayerMapPair> m_vcPlayers;
    
    //Used to read input from the user
    Scanner m_cScanner;
    
    //Stores the type of match selected
    SelectionGameMatch m_eSelectionGameMatch;
    
    //Stores the allocated shapes for decoration
    std::stack<Shape*> m_vcShapeStack;
    
    //Stores the allocated GameObjects (TextObjects) for decoration
    std::stack<GameObject*> m_vcGameObjectStack;

    
    //  ---                         PRIVATE FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: start                                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Starts the game loop.                                               *
     * *******************************************************************************************/
    
    void start();
    
    /**********************************************************************************************
     * function name: assignShips                                                                 *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Makes each of the player assign their ships                         *
     * *******************************************************************************************/
    
    void assignShips();
    
    /**********************************************************************************************
     * function name: sceneSideBySide                                                             *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Build the scene in a way that shows the maps side by side           *
     * *******************************************************************************************/
    
    void sceneSideBySide();
    
    /**********************************************************************************************
     * function name: sceneTopAndBottom                                                           *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Build the scene in a way that shows the maps top and bottom         *
     * *******************************************************************************************/
    
    void sceneTopAndBottom();
    
    /***********************************************************************************************
     * function name: getDifficulty                                                                *
     * The Input: const string object (reference)                                                  *
     * The output: PlayerDifficulty (enum)                                                         *
     * The Function Opertion: Asks the user which difficulty to return for a player with input name*
     *                        returns the difficulty selected.                                     *
     * ********************************************************************************************/
    
    PlayerDifficulty getDifficulty(const std::string& strName) const;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: SceneGameMatch Constructor                                                    *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object                                                *
     * *********************************************************************************************/
    
    SceneGameMatch();
    
    /**********************************************************************************************
     * function name: SceneGameMatch Destructor                                                   *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~SceneGameMatch();
    
    /**********************************************************************************************
     * function name: show                                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: presents the scene.                                                 *
     * *******************************************************************************************/
    
    virtual void show();
    
};

#endif /* defined(__Ex1__SceneGameMatch__) */
