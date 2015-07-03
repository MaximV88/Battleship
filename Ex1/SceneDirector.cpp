/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of SceneDirector Class  *
 ***********************************************************/

#include <iostream>
#include "SceneDirector.h"
#include "Scene.h"

using namespace std;

//  ---                         PRIVATE FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: SceneDirector Constructor                                                     *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the member variables to be NULL.                          *
 * *********************************************************************************************/

SceneDirector::SceneDirector() : m_cCurrentScene(NULL) { }

/**********************************************************************************************
 * function name: SceneDirector Destructor                                                    *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Removes the contained scene if one is stored.                       *
 * *******************************************************************************************/

SceneDirector::~SceneDirector() {

    if (m_cCurrentScene != NULL)
        delete m_cCurrentScene;

}

/**********************************************************************************************
 * function name: printTitle                                                                  *
 * The Input: const string object (reference)                                                 *
 * The output: none                                                                           *
 * The Function Opertion: calls to a cout object and input's the input string in a series     *
 *                        of calls that make a framework around the text.                     *
 * *******************************************************************************************/

void SceneDirector::printTitle(const std::string &strTitle) const {
    
    //Start escape sequence - clear the screen (2J) - move the curser to 1,1
    cout << "\033[2J\033[1;1H";
    
    cout << "\n" << std::endl;
    cout << "\t- - --****" << std::string(strTitle.length(), '*') << "****-- - -" << std::endl;
    cout << "\t| " << std::string(strTitle.length()+16, ' ') << " |" << std::endl;
    cout << "\t|   --*** " << strTitle << " ***--   |" << std::endl;
    cout << "\t| " << std::string(strTitle.length()+16, ' ') << " |" << std::endl;
    cout << "\t- - --****" << std::string(strTitle.length(), '*') << "****-- - -" << std::endl;
    cout << "\n" << std::endl;
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: getInstance                                                                 *
 * The Input: none                                                                            *
 * The output: SceneDirector object (reference)                                               *
 * The Function Opertion: Sets a Settings object on a static variable, and then returns the   *
 *                        reference to that variable every time the function is called.       *
 * *******************************************************************************************/

SceneDirector& SceneDirector::getInstance() {
    
    static SceneDirector instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
    
}

/**********************************************************************************************
 * function name: present                                                                     *
 * The Input: Scene object (pointer)                                                          *
 * The output: none                                                                           *
 * The Function Opertion: Deletes the current scene if exists, prints the title of the        *
 *                        input scene and calls it to show (prints itself).                   *
 * *******************************************************************************************/

void SceneDirector::present(Scene* cScene) {

    //Delete if a current scene exists
    if (m_cCurrentScene != NULL)
        delete m_cCurrentScene;
    
    //Place the input at a member variable and save it for later deletion
    m_cCurrentScene = cScene;
    
    //Print the title of the input scene
    printTitle(cScene->getName());
    
    //Show the scene
    cScene->show();
    
}
