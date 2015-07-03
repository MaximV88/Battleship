/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Screen Class            *
 ***********************************************************/

#ifndef __Ex1__Screen__
#define __Ex1__Screen__

#include <stdio.h>
#include "Oblong.h"

#define DEFAULT_SCREEN_PIXEL ' '

class Coordinate;

/********************************************************************
 * Screen Class: Draws it's stored 'pixels' (char matrix)           *
 *               to the Terminal.                                   *
 *******************************************************************/

class Screen : public Oblong {

private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the 2d array that represents the pixels
    char** m_chScreenMatrix;
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /**********************************************************************************************
     * function name: createScreenMatrix                                                          *
     * The Input: none                                                                            *
     * The output: char (pointer to pointer)                                                      *
     * The Function Opertion: Creates a 2d array based of from the Oblong size property, and      *
     *                        then returns the array.                                             *
     * *******************************************************************************************/
    
    char** createScreenMatrix() const;
    
    /**********************************************************************************************
     * function name: deleteScreenMatrix                                                          *
     * The Input: char (pointer to pointer)                                                       *
     * The output: none                                                                           *
     * The Function Opertion: Deletes the input 2d array.                                         *
     * *******************************************************************************************/
    
    void deleteScreenMatrix(char **chMatrix);
    
    /**********************************************************************************************
     * function name: validInput                                                                  *
     * The Input: unsigned int, unsigned int                                                      *
     * The output: none                                                                           *
     * The Function Opertion: Returns true if the input width and height have pixel representation*
     *                        false otherwise (if the input is not out of bounds).                *
     * *******************************************************************************************/
    
    bool validInput(unsigned int uiHeight, unsigned int uiWidth) const;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Screen Constructor                                                            *
     * The Input: const Oblong object (reference)                                                   *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input as screen size.                     *
     * *********************************************************************************************/
    
    Screen(const Oblong& cSize);
    
    /**********************************************************************************************
     * function name: Screen Destructor                                                           *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~Screen();
    
    /**********************************************************************************************
     * function name: resize                                                                      *
     * The Input: const Oblong                                                                    *
     * The output: none                                                                           *
     * The Function Opertion: Resizes the screen to input size.                                   *
     * *******************************************************************************************/
    
    void resize(const Oblong& cSize);
    
    /**********************************************************************************************
     * function name: setPixel                                                                    *
     * The Input: char, unsigned int, unsigned int                                                *
     * The output: bool                                                                           *
     * The Function Opertion: Sets the char at input position to input char. If successful        *
     *                        it returns true, false otherwise.                                   *
     * *******************************************************************************************/
    
    bool setPixel(char chInput, unsigned int uiHeight, unsigned int uiWidth);
    
    /**********************************************************************************************
     * function name: setPixel                                                                    *
     * The Input: char, const Coordinate object (reference)                                       *
     * The output: bool                                                                           *
     * The Function Opertion: Sets the char at input position to input char. If successful        *
     *                        it returns true, false otherwise.                                   *
     * *******************************************************************************************/
    
    bool setPixel(char chInput, const Coordinate& cCoordinate);
    
    /**********************************************************************************************
     * function name: print                                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Prints the contents to the Terminal.                                *
     * *******************************************************************************************/
    
    void print() const;
};

#endif
