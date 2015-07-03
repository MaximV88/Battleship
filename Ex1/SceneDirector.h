/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of SceneDirector Class     *
 ***********************************************************/

#ifndef __Ex1__SceneDirector__
#define __Ex1__SceneDirector__

#include <stdio.h>

/********************************************************************************
 * Settings Class: It is a singelton that holds manages the displayed scenes.   *
 *                 it holds a scene and displays it. Once it is called to show  *
 *                 another scene it deleted the previous one and loads (shows)  *
 *                 the received one. Can be extended to show transitions & etc. *
 *******************************************************************************/

class Scene;

class SceneDirector {
    
private:
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: SceneDirector Constructor                                                     *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Since the SceneDirector class is a singelton, from the pattern design *
     *                        it needs to have it's constructor as private to avoid any other       *
     *                        class other than the Settings class from initializing it.             *
     * *********************************************************************************************/
    
    SceneDirector();

    /***********************************************************************************************
     * function name: Copy Constructor                                                             *
     * The Input: none                                                                             *
     * The output: none                                                                            *
     * The Function Opertion: Since the SceneDirector class is a singelton, from the pattern design*
     *                        duplicating is unwanted because there should only be one singelton.  *
     * ********************************************************************************************/
    
    SceneDirector(SceneDirector const& cSceneDirector);
    
    /**********************************************************************************************
     * function name: operator=                                                                   *
     * The Input: const SceneDirector object (reference)                                          *
     * The output: none                                                                           *
     * The Function Opertion: Copies the content of the input Settings object to the current      *
     *                        object. Since the singelton is only one, there should not be a copy *
     *                        to perform this operator from, and because this operator is private *
     *                        it will never be called.                                            *
     * *******************************************************************************************/
    
    void operator=(SceneDirector const& cSceneDirector);

    /**********************************************************************************************
     * function name: printTitle                                                                  *
     * The Input: const string object (reference)                                                 *
     * The output: none                                                                           *
     * The Function Opertion: prints the title in a nice format in the terminal                   *
     * *******************************************************************************************/
    
    void printTitle(const std::string& strTitle) const;

    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Holds the current scene
    Scene* m_cCurrentScene;
    
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: getInstance                                                                 *
     * The Input: none                                                                            *
     * The output: SceneDirector object (reference)                                               *
     * The Function Opertion: Since the singleton has only one copy, a class function is made to  *
     *                        to access it. Calling this function will return the only copy of    *
     *                        the Settings class.                                                 *
     * *******************************************************************************************/
    
    static SceneDirector& getInstance();
    
    /**********************************************************************************************
     * function name: SceneDirector Destructor                                                    *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~SceneDirector();
    
    /**********************************************************************************************
     * function name: present                                                                     *
     * The Input: Scene object (pointer)                                                          *
     * The output: none                                                                           *
     * The Function Opertion: shows the input scene in the terminal                               *
     * *******************************************************************************************/
    
    void present(Scene* cScene);
    
};

#endif
