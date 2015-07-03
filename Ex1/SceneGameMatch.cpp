/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of SceneGameMatch Class *
 ***********************************************************/

#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <limits>

#include "SceneGameMatch.h"
#include "SceneMainMenu.h"
#include "SceneDirector.h"
#include "Settings.h"

#include "Line.h"
#include "Rectangle.h"
#include "Map.h"
#include "TextObject.h"

#include "HumanPlayer.h"
#include "ComputerPlayer.h"

#include "ActionMoveBy.h"

using namespace std;

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: start                                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: First calls the players to assign their ships. Afterwards it begins *
 *                        the game loops which goes on until one of the players is dead.      *
 *                        It then calls for the SceneDirector to load the MainMenu.           *
 * *******************************************************************************************/


void SceneGameMatch::start() {
    
    assignShips();
    
    //Selects randomly the begining player
    unsigned int uiPlayerIndex = rand() % m_vcPlayers.size();
    
    bool bIsBegining = true;
    
    //This is the GameLoop, and it always runs until something breaks it
    while (true) {
        
        //Each player plays against all the other players (in theory)
        for (unsigned int uiOpponentIndex = 0 ; uiOpponentIndex < m_vcPlayers.size() ; uiOpponentIndex++) {
            
            Player *cCurrentPlayer = m_vcPlayers[uiPlayerIndex % m_vcPlayers.size()].first;
            
            //Decide on an action regarding every other player and perform it (except itself)
            if (uiPlayerIndex%m_vcPlayers.size() != uiOpponentIndex) {
                
                std::cout << "\033[2J\033[1;1H";
                
                if (!bIsBegining) {
                    
                    //This will be ok as long as there are 2 players
                    std::cout << m_vcPlayers[uiOpponentIndex].first->getName() << "'s turn has ended. \n" << std::endl;
                    
                }
                else {
                    
                    bIsBegining = false;
                    
                    std::cout << "Match has begun!" << "\n" << std::endl;
                    
                }
                
                //Draw the scene before the turn
                draw();
                render();
                
                std::cout << "Current Player: " << cCurrentPlayer->getName() << "\n" << std::endl;
                
                //Decide what to do
                cCurrentPlayer->act(m_vcPlayers[uiOpponentIndex].second);
                
                
                //Check to see if the player that was attacked is dead
                if (m_vcPlayers[uiOpponentIndex].second->isAllHit()) {
                    
                    std::cout << "\033[2J\033[1;1H";
                    
                    //Draw to show the ending
                    draw();
                    render();
                    
                    cout << "\nThe Winner is " << cCurrentPlayer->getName() << "!" << endl;
                    
                    std::cout << "\n\nPress ENTER to continue..";
                    if (std::cin.rdbuf()->sungetc() != std::cin.eof() && std::cin.get() != std::cin.widen ( '\n' ) )
                        std::cin.ignore ( std::numeric_limits<std::streamsize>::max(), std::cin.widen ( '\n' ) );
                    
                    std::cout.clear();
                    std::cin.ignore();
                    
                    //After the GameLoop is ended, go to the MainMenu
                    SceneDirector::getInstance().present(new SceneMainMenu());
                    
                    return;
                    
                }
                
            }
            
        }
        
        ++uiPlayerIndex;
        
    }
    
}

/**********************************************************************************************
 * function name: assignShips                                                                 *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Calls for every player to assign it's ships. It prints the player's *
 *                        for every assignment if he is human.                                *
 * *******************************************************************************************/


void SceneGameMatch::assignShips() {
    
    //Each player assigns his own ships on his map
    for (std::vector<PlayerMapPair>::iterator iter = m_vcPlayers.begin() ; iter != m_vcPlayers.end() ; iter++) {
        
        for (unsigned int uiIndex = 0 ; uiIndex < Settings::getInstance().getPlayerNumberOfShips() ; uiIndex++) {
            
            //The player assigns the ships to his own map
            (*iter).first->assign((*iter).second);
            
            //Draw the maps according to the situation
            switch (m_eSelectionGameMatch) {
                    
                    //Dont draw computer assignment moves
                case SelectionGameMatchComputerVSComputer: break;
                case SelectionGameMatchPlayerVSComputer:
                    
                    //The human player is in the first index
                    if (iter - m_vcPlayers.begin() == 0) {
                        
                        std::cout << "\033[2J\033[1;1H";
                        
                        
                        draw();
                        render();
                        
                    }
                    
                    break;
                    
                case SelectionGameMatchPlayerVSPlayer:
                    
                    //Show for both players
                    std::cout << "\033[2J\033[1;1H";
                    
                    
                    draw();
                    render();
                    
                    break;
                    
                default:
                    break;
            }
            
        }
        
    }
    
}

/**********************************************************************************************
 * function name: sceneSideBySide                                                             *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Adds shapes to the drawer by using the location given from the      *
 *                        player's maps.                                                      *
 * *******************************************************************************************/


void SceneGameMatch::sceneSideBySide() {
    
    //Find where to put the text
    unsigned int uiCorrectedX = m_vcPlayers[0].second->getX() + static_cast<unsigned int>(m_vcPlayers[0].second->getWidth() - m_vcPlayers[0].first->getName().length())/2;
    unsigned int uiCorrectedY = m_vcPlayers[0].second->getHeight() + 3;
    
    TextObject *cPlayerNameFirst = new TextObject(m_vcPlayers[0].first->getName(), Coordinate(uiCorrectedX+1, uiCorrectedY+1));
    m_vcGameObjectStack.push(cPlayerNameFirst);
    
    //Make a nice rectangle around the text
    Rectangle *cOutlineRectFirst = new Rectangle(Coordinate(uiCorrectedX, uiCorrectedY),
                                                 static_cast<unsigned int>(m_vcPlayers[0].first->getName().length()+2), 3);
    
    m_vcShapeStack.push(cOutlineRectFirst);
    
    
    uiCorrectedX = m_vcPlayers[1].second->getX() + static_cast<unsigned int>(m_vcPlayers[1].second->getWidth() - m_vcPlayers[1].first->getName().length())/2;
    uiCorrectedY = m_vcPlayers[1].second->getHeight() + 3;
    
    TextObject *cPlayerNameSecond = new TextObject(m_vcPlayers[1].first->getName(), Coordinate(uiCorrectedX+1, uiCorrectedY+1));
    
    //Make a nice rectangle around the text
    Rectangle *cOutlineRectSecond = new Rectangle(Coordinate(uiCorrectedX, uiCorrectedY),
                                                  static_cast<unsigned int>(m_vcPlayers[1].first->getName().length()+2), 3);
    
    m_vcGameObjectStack.push(cPlayerNameSecond);
    m_vcShapeStack.push(cOutlineRectSecond);
    
    add(*cPlayerNameFirst);
    add(*cOutlineRectFirst);
    add(*cPlayerNameSecond);
    add(*cOutlineRectSecond);
    
    //Make decorative rectangles
    Rectangle *cDecRectFirst = new Rectangle(Coordinate(0,0), m_vcPlayers[0].second->getWidth() * 2 + 3, 3);
    add(*cDecRectFirst);
    
    Rectangle *cDecRectSecond = new Rectangle(Coordinate(0,m_vcPlayers[0].second->getHeight() + 6), m_vcPlayers[0].second->getWidth() * 2 + 3, 3);
    add(*cDecRectSecond);
    
    m_vcShapeStack.push(cDecRectFirst);
    m_vcShapeStack.push(cDecRectSecond);
    
}

/**********************************************************************************************
 * function name: sceneTopAndBottom                                                           *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Adds shapes to the drawer by using the location given from the      *
 *                        player's maps.                                                      *
 * *******************************************************************************************/


void SceneGameMatch::sceneTopAndBottom() {
    
    //Find where to put the text
    unsigned int uiCorrectedX = m_vcPlayers[0].second->getX() + static_cast<unsigned int>(m_vcPlayers[0].second->getWidth() - m_vcPlayers[0].first->getName().length())/2;
    unsigned int uiCorrectedY = m_vcPlayers[0].second->getHeight();
    
    TextObject *cPlayerNameFirst = new TextObject(m_vcPlayers[0].first->getName(), Coordinate(uiCorrectedX+1, uiCorrectedY+1));
    m_vcGameObjectStack.push(cPlayerNameFirst);
    
    //Make a nice rectangle around the text
    Rectangle *cOutlineRectFirst = new Rectangle(Coordinate(uiCorrectedX, uiCorrectedY),
                                                 static_cast<unsigned int>(m_vcPlayers[0].first->getName().length()+2), 3);
    m_vcShapeStack.push(cOutlineRectFirst);
    
    
    uiCorrectedX = m_vcPlayers[1].second->getX() + static_cast<unsigned int>(m_vcPlayers[1].second->getWidth() - m_vcPlayers[1].first->getName().length())/2;
    uiCorrectedY = m_vcPlayers[1].second->getHeight();
    
    TextObject *cPlayerNameSecond = new TextObject(m_vcPlayers[1].first->getName(), Coordinate(uiCorrectedX+1, uiCorrectedY * 2 + 5));
    m_vcGameObjectStack.push(cPlayerNameSecond);
    
    //Make a nice rectangle around the text
    Rectangle *cOutlineRectSecond = new Rectangle(Coordinate(uiCorrectedX, uiCorrectedY * 2 + 4),
                                                  static_cast<unsigned int>(m_vcPlayers[1].first->getName().length()+2), 3);
    m_vcShapeStack.push(cOutlineRectSecond);
    
    add(*cPlayerNameFirst);
    add(*cOutlineRectFirst);
    add(*cPlayerNameSecond);
    add(*cOutlineRectSecond);
    
    //Add nice decorative rectangles and lines
    Rectangle *cDecRectFirst = new Rectangle(Coordinate(0,0),3 , m_vcPlayers[0].second->getHeight() + 3);
    Rectangle *cDecRectSecond = new Rectangle(Coordinate(m_vcPlayers[0].second->getWidth()+5,0),3 , m_vcPlayers[0].second->getHeight() + 3);
    add(*cDecRectFirst);
    add(*cDecRectSecond);
    
    Rectangle *cDecRectThird = new Rectangle(Coordinate(0,m_vcPlayers[0].second->getHeight() + 4),3 , m_vcPlayers[0].second->getHeight() + 3);
    Rectangle *cDecRectFourth = new Rectangle(Coordinate(m_vcPlayers[0].second->getWidth()+5,m_vcPlayers[0].second->getHeight() + 4),3 , m_vcPlayers[0].second->getHeight() + 3);
    add(*cDecRectThird);
    add(*cDecRectFourth);
    
    m_vcShapeStack.push(cDecRectFirst);
    m_vcShapeStack.push(cDecRectSecond);
    m_vcShapeStack.push(cDecRectThird);
    m_vcShapeStack.push(cDecRectFourth);
    
}

/***********************************************************************************************
 * function name: getDifficulty                                                                *
 * The Input: const string object (reference)                                                  *
 * The output: PlayerDifficulty (enum)                                                         *
 * The Function Opertion: Asks the user with a cout message and waits for an input that is     *
 *                        restricted in numerical range for the Difficulties available. it then*
 *                        returns the difficulty selected.                                     *
 * ********************************************************************************************/

PlayerDifficulty SceneGameMatch::getDifficulty(const std::string& strName) const {
    
    cout << "Please enter the desired difficulty for " << strName << ": \n" ;
    
    //Make it in order for easier changing of text - ordered by enum values
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;

    cout << "\nWaiting for selection: ";
    
    return PlayerDifficulty(m_cScanner.scanInt(PlayerDifficultyNone, PlayerDifficultyTotalNumber));
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: SceneGameMatch Constructor                                                    *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with a given size from the settings singleton  *
 *                        for the drawer property, and a name for the Name property. it also    *
 *                        seeds the random function.                                            *
 * *********************************************************************************************/

SceneGameMatch::SceneGameMatch() : Scene("Game Match"), Drawer(Settings::getInstance().getScreenSize()) { srand(static_cast<unsigned int>(time(NULL))); }

/**********************************************************************************************
 * function name: SceneGameMatch Destructor                                                   *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Goes through all of the stores objects in the stack and removes     *
 *                        them. Afterwards it removes the players and their maps.             *
 * *******************************************************************************************/

SceneGameMatch::~SceneGameMatch() {
    
    //Delete all of the created shapes in this scene
    while (!m_vcShapeStack.empty()) {
        
        Shape* cFront = m_vcShapeStack.top();
        delete cFront;
        m_vcShapeStack.pop();
        
    }
    
    //Delete all of the created GameObjects in this scene
    while (!m_vcGameObjectStack.empty()) {
        
        GameObject* cFront = m_vcGameObjectStack.top();
        delete cFront;
        m_vcGameObjectStack.pop();
        
    }
    
    //Delete the stored maps and players
    delete m_vcPlayers[0].first;
    delete m_vcPlayers[1].first;
    delete m_vcPlayers[0].second;
    delete m_vcPlayers[1].second;
    
}

/**********************************************************************************************
 * function name: show                                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Prints a selection for the player to choose from, which determines  *
 *                        the game type. afterwards it continues to initialize the player's   *
 *                        maps and other variables to allow for starting the game.            *
 * *******************************************************************************************/

void SceneGameMatch::show() {
    
    //Present a choice if to play vs a computer or to see two computers play
    cout << "Please enter the number for your selection:\n" << endl;
    
    //Make it in order for easier changing of text - ordered by enum values
    cout << "1. Player vs Computer" << endl;
    cout << "2. Computer vs Computer" << endl;
    cout << "3. Player vs Player" << endl;
    
    cout << "\nWaiting for selection: ";
    
    m_eSelectionGameMatch = SelectionGameMatch(m_cScanner.scanInt(SelectionGameMatchNone, SelectionGameMatchTotalNumber));
    
    switch (m_eSelectionGameMatch) {
        case SelectionGameMatchPlayerVSComputer:
            
        {
            unsigned int uiNameMinLength = Settings::getInstance().getPlayerNameMinLength();
            unsigned int uiNameMaxLength = Settings::getInstance().getPlayerNameMaxLength();
            
            cout << "Please enter your name (from " << uiNameMinLength << " up to " << uiNameMaxLength << " characters): ";
            
            //Create the human player
            m_vcPlayers.push_back(PlayerMapPair(new HumanPlayer(m_cScanner.scanString(uiNameMinLength ,uiNameMaxLength)),
                                  new Map(Coordinate(0,0), Settings::getInstance().getMapSize())));
            
            //Create the computer player
            m_vcPlayers.push_back(PlayerMapPair(new ComputerPlayer(),
                                                new Map(Coordinate(0,0), Settings::getInstance().getMapSize())));
            
            //Select the difficulty
            static_cast<ComputerPlayer*>(m_vcPlayers[1].first)->setPlayerDifficulty(getDifficulty(m_vcPlayers[1].first->getName()));
            
            //Hide only if set so in the settings
            switch (Settings::getInstance().getOpponentMap()) {
                case OpponentMapDontHide:
                    
                    //Dont do anythig
                    
                    break;
                    
                    case OpponentMapHide:
                    
                    //Hide the opponent
                    
                    m_vcPlayers[1].second->hideShips();
                    
                //Shouldnt reach that
                default:
                    break;
            }
            
            
            break;
            
        }
            
        case SelectionGameMatchComputerVSComputer:
            
            //Create the computer player
            m_vcPlayers.push_back(PlayerMapPair(new ComputerPlayer(),
                                                new Map(Coordinate(0,0), Settings::getInstance().getMapSize())));
            
            //Select the difficulty
            static_cast<ComputerPlayer*>(m_vcPlayers[0].first)->setPlayerDifficulty(getDifficulty(m_vcPlayers[0].first->getName()));
            
            //Create the computer player
            m_vcPlayers.push_back(PlayerMapPair(new ComputerPlayer(),
                                                new Map(Coordinate(0,0), Settings::getInstance().getMapSize())));
            
            //Select the difficulty
            static_cast<ComputerPlayer*>(m_vcPlayers[1].first)->setPlayerDifficulty(getDifficulty(m_vcPlayers[1].first->getName()));
            
            break;
            
        case SelectionGameMatchPlayerVSPlayer: {
            
            unsigned int uiNameMinLength = Settings::getInstance().getPlayerNameMinLength();
            unsigned int uiNameMaxLength = Settings::getInstance().getPlayerNameMaxLength();
            
            cout << "Player1: Please enter your name (from " << Settings::getInstance().getPlayerNameMinLength()
            << " up to " << Settings::getInstance().getPlayerNameMaxLength() << " characters): ";
            
            //Create the human player
            m_vcPlayers.push_back(PlayerMapPair(new HumanPlayer(m_cScanner.scanString(uiNameMinLength ,uiNameMaxLength)),
                                                new Map(Coordinate(0,0), Settings::getInstance().getMapSize())));
            
            cout << "Player2: Please enter your name (from " << Settings::getInstance().getPlayerNameMinLength()
            << " up to " << Settings::getInstance().getPlayerNameMaxLength() << " characters): ";
            
            //Create the human player
            m_vcPlayers.push_back(PlayerMapPair(new HumanPlayer(m_cScanner.scanString(uiNameMinLength ,uiNameMaxLength)),
                                                new Map(Coordinate(0,0), Settings::getInstance().getMapSize())));
            break;
            
        }
            
        default: break;
            
    }
    
    //Add the maps to drawing
    add(*m_vcPlayers[0].second);
    add(*m_vcPlayers[1].second);
    
    //Its for decoration
    Line *cLineDivider;
    
    //Decide where to place the other player's map according to the settings
    //We move the entire map (which is a GameCollection, and thus actions can perform on it)
    switch (Settings::getInstance().getMapOverlay()) {
        case MapOverlaySideBySide:
            
            //Move it sideways
            ActionMoveBy(m_vcPlayers[1].second, m_vcPlayers[0].second->getWidth() + 3, 3).Action::apply();
            ActionMoveBy(m_vcPlayers[0].second, 0, 3).Action::apply();

            //Create a Line that divides the Board verticaly
            cLineDivider = new Line(Coordinate(m_vcPlayers[0].second->getWidth() + 1, 0),
                                    Coordinate(m_vcPlayers[0].second->getWidth() + 1, Settings::getInstance().getScreenSize().getHeight()));
            
            break;
            
        case MapOverlayTopAndBottom:
            
        {

            //Move Them Slightly to the right to be in the center of the screen
            unsigned int uiDifference = (Settings::getInstance().getScreenSize().getWidth() - m_vcPlayers[0].second->getWidth()) / 2;

            //Also move it upwards
            ActionMoveBy(m_vcPlayers[1].second, uiDifference, m_vcPlayers[0].second->getHeight() + 4).Action::apply();
            ActionMoveBy(m_vcPlayers[0].second, uiDifference, 0).Action::apply();

            //Create a Line that divides the Board horizontly
            cLineDivider = new Line(Coordinate(0, m_vcPlayers[0].second->getHeight() + 3),
                                    Coordinate(Settings::getInstance().getScreenSize().getWidth(), m_vcPlayers[0].second->getHeight() + 3));
            
            break;
            
        }
            
        default: break;
    }
    
    //Add the dividing line
    add(*cLineDivider);
    m_vcShapeStack.push(cLineDivider);
    
    //Make an opening statement and put it into a TextObject using the required overlay
    switch (Settings::getInstance().getMapOverlay()) {
        case MapOverlaySideBySide:      sceneSideBySide();      break;
        case MapOverlayTopAndBottom:    sceneTopAndBottom();    break;
            
        default:
            break;
    }
    
    cout << "\033[2J\033[1;1H";
    
    draw();
    render();
    
    //Start the game!
    start();
    
}

