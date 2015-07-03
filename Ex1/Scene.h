/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Scene Class             *
 ***********************************************************/

#ifndef __Ex1__Scene__
#define __Ex1__Scene__

#include <stdio.h>
#include <string>
#include "Nameable.h"

/***********************************************************************************
 * Scene Class: This class is meant to be a handle to switch different scenes. It  *
 *              is an abstract class that the ones that inherent from it need to   *
 *              apply a presentation (show) function.                              *
 **********************************************************************************/

class Scene : public Nameable {
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: Scene Constructor                                                             *
     * The Input: const string object (reference)                                                   *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with the input as name                         *
     * *********************************************************************************************/
    
    Scene(const std::string& strName);
    
    /**********************************************************************************************
     * function name: Scene Destructor                                                            *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~Scene();
    
    /**********************************************************************************************
     * function name: show                                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: presents the scene.                                                 *
     * *******************************************************************************************/
    
    virtual void show() = 0;
    
};

#endif /* defined(__Ex1__Scene__) */
