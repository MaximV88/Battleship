/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Line Class              *
 ***********************************************************/

#ifndef __Ex1__Line__
#define __Ex1__Line__

#include <stdio.h>
#include "Point.h"

/********************************************************************
 * Point Class: Its a shape that is a collection of vertices        *
 *              arranges in a line.                                 *
 *******************************************************************/

class Line : public Shape {

private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the start of the line
    Coordinate* m_cStart;
    
    //Stores the end of the line
    Coordinate* m_cEnd;
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /**********************************************************************************************
     * function name: coordinateAtRatio                                                           *
     * The Input: int, int                                                                        *
     * The output: Coordinate object                                                              *
     * The Function Opertion: Returns a coordinate at a ratio between the two input ints.         *
     * *******************************************************************************************/
    
    Coordinate coordinateAtRatio(int iNumerator, int iDenominator) const;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Line Constructor                                                              *
     * The Input: const Coordinate object (reference), const Coordinate object (reference), char    *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input Coordinates as star and end,        *
     *                        sets the char to represent the line.                                  *
     * *********************************************************************************************/
    
    Line(const Coordinate& cStart, const Coordinate& cEnd, char chRepresentation = DEFAULT_REPRESENTATION_CHAR);
    
    /************************************************************************************************
     * function name: Line Copy Constructor                                                         *
     * The Input: const Line object (reference)                                                     *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object as a copy of the input object.                 *
     * *********************************************************************************************/
    
    Line(const Line& cLine);
    
    /**********************************************************************************************
     * function name: Line Destructor                                                             *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~Line();
    
    /**********************************************************************************************
     * function name: operator=                                                                   *
     * The Input: const Line object (reference)                                                   *
     * The output: Line object (reference)                                                        *
     * The Function Opertion: Copies the contents of the input object                             *
     * *******************************************************************************************/
    
    Line& operator=(const Line& cLine);

    /**********************************************************************************************
     * function name: magnitude                                                                   *
     * The Input: none                                                                            *
     * The output: int                                                                            *
     * The Function Opertion: Returns the length of the line.                                     *
     * *******************************************************************************************/
    
    int magnitude() const;
    
    /**********************************************************************************************
     * function name: clone                                                                       *
     * The Input: none                                                                            *
     * The output: Shape object (pointer)                                                         *
     * The Function Opertion: Returns a copy of the current object.                               *
     * *******************************************************************************************/
    
    virtual Shape* clone() const;

};

#endif  
