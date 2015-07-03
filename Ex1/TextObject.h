/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of TextObject Class        *
 ***********************************************************/

#ifndef __Ex1__TextObject__
#define __Ex1__TextObject__

#include <stdio.h>
#include <vector>
#include <string>

#include "GameObject.h"
#include "Point.h"

/****************************************************************************************
 * TextObject Class: Its a GameObject (An object that can be displayed by the Drawer),  *
 *                   that can display text.                                             *
 ***************************************************************************************/

class TextObject : public GameObject {
        
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: TextObject Constructor                                                        *
     * The Input: const string object (reference), const Coordinate object (reference)              *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with an origin and a Text                      *
     * *********************************************************************************************/
    
    TextObject(const std::string& strInput, const Coordinate& cOrigin);
    
    /**********************************************************************************************
     * function name: clone                                                                       *
     * The Input: none                                                                            *
     * The output: GameObject object (pointer)                                                    *
     * The Function Opertion: Returns a copy of the current object.                               *
     * *******************************************************************************************/
    
    virtual GameObject* clone() const;

};

#endif
