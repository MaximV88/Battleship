/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of TextObject Class     *
 ***********************************************************/

#include "TextObject.h"

using namespace std;

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: TextObject Constructor                                                        *
 * The Input: const string object (reference), const Coordinate object (reference)              *
 * The output: none                                                                             *
 * The Function Opertion: Iterates on the input string, and for every character it positions    *
 *                        a point in an increasing order that has the character's char.         *
 *                        This creates a series of points that combine to be a string when      *
 *                        displayed in the Terminal.                                            *
 * *********************************************************************************************/

TextObject::TextObject(const string& strInput, const Coordinate& cOrigin) : GameObject(cOrigin) {
    
    //Add a point for every character in the input string, and increment the position x
    unsigned int uiPositionX = 0;
    
    //Iterate through every character in the input string and place a point at incrementing X position
    for (std::string::const_iterator iter  = strInput.begin() ; iter != strInput.end() ; iter++, uiPositionX++) {
        
        collect(new Point(uiPositionX, 0, *iter));
        
    }
    
}

/**********************************************************************************************
 * function name: clone                                                                       *
 * The Input: none                                                                            *
 * The output: GameObject object (pointer)                                                    *
 * The Function Opertion: Returns a copy of the current object using the Copy Constructor     *
 * *******************************************************************************************/

GameObject* TextObject::clone() const {
    
    return new TextObject(*this);
    
}