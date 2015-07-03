/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Coordinate Class        *
 ***********************************************************/

#ifndef __Ex1__Coordinate__
#define __Ex1__Coordinate__

#include <stdio.h>
#include <iostream>

/********************************************************************
 * Coordinate Class: Represents a pair of (X, Y) coordinate.        *
 *******************************************************************/

class Coordinate {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the X position
    int m_iPositionX;
    
    //Stores the Y position
    int m_iPositionY;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Coordinate Constructor                                                        *
     * The Input: int, int                                                                          *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input ints as position.                   *
     * *********************************************************************************************/
    
    Coordinate(int uiPositionX, int uiPositionY);
    
    /************************************************************************************************
     * function name: Coordinate Copy Constructor                                                   *
     * The Input: int, int                                                                          *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object as a copy of the input object.                 *
     * *********************************************************************************************/
    
    Coordinate(const Coordinate& cCoordinate);
    
    /**********************************************************************************************
     * function name: operator=                                                                   *
     * The Input: const Coordinate object (reference)                                             *
     * The output: Coordinate object (reference)                                                  *
     * The Function Opertion: Copies the contents of the input object                             *
     * *******************************************************************************************/
    
    Coordinate& operator=(const Coordinate& cCoordinate);
    
    /**********************************************************************************************
     * function name: operator==                                                                  *
     * The Input: const Coordinate object (reference)                                             *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if the input coordinate matches the current object,    *
     *                        false otherwise.                                                    *
     * *******************************************************************************************/
    
    bool operator==(const Coordinate &cCoordinate) const;
    
    /**********************************************************************************************
     * function name: operator!=                                                                  *
     * The Input: const Coordinate object (reference)                                             *
     * The output: bool                                                                           *
     * The Function Opertion: Returns false if the input coordinate matches the current object,   *
     *                        true otherwise.                                                     *
     * *******************************************************************************************/
    
    bool operator!=(const Coordinate &cCoordinate) const;
    
    /**********************************************************************************************
     * function name: operator+                                                                   *
     * The Input: const Coordinate object (reference)                                             *
     * The output: const Coordinate object                                                        *
     * The Function Opertion: Returns the sum of the input object and current object.             *
     * *******************************************************************************************/
    
    const Coordinate operator+(const Coordinate& cCoordinate) const;
    
    /**********************************************************************************************
     * function name: operator+=                                                                  *
     * The Input: const Coordinate object (reference)                                             *
     * The output: const Coordinate object                                                        *
     * The Function Opertion: Performs the operator+ on the current object.                       *
     * *******************************************************************************************/
    
    Coordinate& operator+=(const Coordinate& cCoordinate);
    
    /**********************************************************************************************
     * function name: operator-                                                                   *
     * The Input: const Coordinate object (reference)                                             *
     * The output: const Coordinate object                                                        *
     * The Function Opertion: Returns the subtraction of the input object and current object.     *
     * *******************************************************************************************/
    
    const Coordinate operator-(const Coordinate& cCoordinate) const;
    
    /**********************************************************************************************
     * function name: operator-=                                                                  *
     * The Input: const Coordinate object (reference)                                             *
     * The output: const Coordinate object                                                        *
     * The Function Opertion: Performs the operator- on the current object.                       *
     * *******************************************************************************************/
    
    Coordinate& operator-=(const Coordinate& cCoordinate);
    
    /************************************************************************************
     * function name: getX                                                              *
     * The Input: none                                                                  *
     * The output: none                                                                 *
     * The Function Opertion: Returns the X position of the Coordinate.                 *
     * *********************************************************************************/
    
    int getX() const;
    
    /************************************************************************************
     * function name: getY                                                              *
     * The Input: none                                                                  *
     * The output: none                                                                 *
     * The Function Opertion: Returns the X position of the Coordinate.                 *
     * *********************************************************************************/
    
    int getY() const;
    
    /************************************************************************************
     * function name: operator<<                                                        *
     * The Input: ostream object (reference), const Coordinate object (reference)       *
     * The output: ostream object (reference)                                           *
     * The Function Opertion: Returns the X position of the Coordinate.                 *
     * *********************************************************************************/
    
    friend std::ostream& operator<<(std::ostream &out, const Coordinate &cCoordinate);
    
};

#endif
