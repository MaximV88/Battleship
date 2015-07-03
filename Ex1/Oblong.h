/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Oblong Class            *
 ***********************************************************/

#ifndef __Ex1__Oblong__
#define __Ex1__Oblong__

#include <stdio.h>

/********************************************************************
 * Oblong Class: Represents an oblong with width and height.        *
 *******************************************************************/

class Oblong {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the width
    unsigned int m_uiWidth;
    
    //Stores the height
    unsigned int m_uiHeight;
    
public:

    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Oblong Constructor                                                            *
     * The Input: int, int                                                                          *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input ints as width and height.           *
     * *********************************************************************************************/
    
    Oblong(unsigned int uiWidth, unsigned int uiHeight);
    
    /************************************************************************************************
     * function name: Oblong Copy Constructor                                                       *
     * The Input: const Oblong object (reference)                                                   *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object as a copy of the input object.                 *
     * *********************************************************************************************/
    
    Oblong(const Oblong& cOblong);
    
    /**********************************************************************************************
     * function name: operator=                                                                   *
     * The Input: const Oblong object (reference)                                                 *
     * The output: Oblong object (reference)                                                      *
     * The Function Opertion: Copies the contents of the input object                             *
     * *******************************************************************************************/
    
    Oblong& operator=(const Oblong& cOblong);
    
    /**********************************************************************************************
     * function name: operator==                                                                  *
     * The Input: const Oblong object (reference)                                                 *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if the input Oblong matches the size of current object,*
     *                        false otherwise.                                                    *
     * *******************************************************************************************/
    
    bool operator==(const Oblong &cOblong) const;
    
    /**********************************************************************************************
     * function name: operator!=                                                                  *
     * The Input: const Oblong object (reference)                                                 *
     * The output: bool                                                                           *
     * The Function Opertion: Returns false if the input Oblong matches the size of current object*
     *                        true otherwise.                                                     *
     * *******************************************************************************************/
    
    bool operator!=(const Oblong &cOblong) const;
    
    /************************************************************************************
     * function name: getWidth                                                          *
     * The Input: none                                                                  *
     * The output: unsigned int                                                         *
     * The Function Opertion: Returns the width of the current object.                  *
     * *********************************************************************************/
    
    unsigned int getWidth() const;
    
    /************************************************************************************
     * function name: getHeight                                                         *
     * The Input: none                                                                  *
     * The output: unsigned int                                                         *
     * The Function Opertion: Returns the width of the current object.                  *
     * *********************************************************************************/
    
    unsigned int getHeight() const;
    
    /************************************************************************************
     * function name: getSize                                                           *
     * The Input: none                                                                  *
     * The output: unsigned int                                                         *
     * The Function Opertion: Returns the size of the Oblong.                           *
     * *********************************************************************************/
    
    unsigned int getSize() const;
    
    /************************************************************************************
     * function name: resize                                                            *
     * The Input: unsigned int, unsigned int                                            *
     * The output: none                                                                 *
     * The Function Opertion: Resize the current object to the given input              *
     * *********************************************************************************/
    
    void resize(unsigned int uiWidth, unsigned int uiHeight);
    
};

#endif 
