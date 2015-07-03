/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Point Class             *
 ***********************************************************/

#ifndef __Ex1__Point__
#define __Ex1__Point__

#include <stdio.h>
#include "Shape.h"

/********************************************************************
 * Point Class: Its a shape that has one Vertex and an origin       *
 *              (the Vertex's position).                            *
 *******************************************************************/

class Point : public Shape, public Coordinate {

    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Point Constructor                                                             *
     * The Input: const Coordinate object (reference), char                                         *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input Coordinate as location, and         *
     *                        the char as representation to it's vertex.                            *
     * *********************************************************************************************/
    
    Point(const Coordinate& cCoordinate, char chRepresentation = DEFAULT_REPRESENTATION_CHAR);
    
    /************************************************************************************************
     * function name: Point Constructor                                                             *
     * The Input: int, int, char                                                                    *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input ints location, and                  *
     *                        the char as representation to it's vertex.                            *
     * *********************************************************************************************/

    Point(int iPositionX, int iPositionY, char chRepresentation = DEFAULT_REPRESENTATION_CHAR);
    
    /************************************************************************************************
     * function name: Point Copy Constructor                                                        *
     * The Input: const Point object (reference)                                                    *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object as a copy of the input object.                 *
     * *********************************************************************************************/
    
    Point(const Point& cPoint);
    
    /**********************************************************************************************
     * function name: Point Destructor                                                            *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~Point();
    
    /**********************************************************************************************
     * function name: operator=                                                                   *
     * The Input: const Point object (reference)                                                  *
     * The output: Point object (reference)                                                       *
     * The Function Opertion: Copies the contents of the input object                             *
     * *******************************************************************************************/
    
    Point& operator=(const Point& cPoint);
    
    /**********************************************************************************************
     * function name: clone                                                                       *
     * The Input: none                                                                            *
     * The output: Shape object (pointer)                                                         *
     * The Function Opertion: Returns a copy of the current object.                               *
     * *******************************************************************************************/

    virtual Shape* clone() const;
    
};

#endif
