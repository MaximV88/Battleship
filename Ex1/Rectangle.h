/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Rectangle Class         *
 ***********************************************************/

#ifndef __Ex1__Rectangle__
#define __Ex1__Rectangle__

#include <stdio.h>
#include "Shape.h"
#include "Oblong.h"

/********************************************************************
 * Rectangle Class: Its a shape that is a collection of vertices    *
 *              arranges in a rectangle.                            *
 *******************************************************************/

class Rectangle : public Shape, public Oblong {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the bottom left coordinate
    Coordinate* m_cBottomLeft;

    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /**********************************************************************************************
     * function name: buildRectangle                                                              *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Builds the rectangle's shape by placing vertices in appropriate     *
     *                        locations.                                                          *
     * *******************************************************************************************/
    
    void buildRectangle();
    

public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Rectangle Constructor                                                         *
     * The Input: const Coordinate object (reference), int, int, char                               *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with the coordinate as bottom left, the ints   *
     *                        as width and height, and the char as the representation for the       *
     *                        rectangle's vertices.                                                 *
     * *********************************************************************************************/
    
    Rectangle(const Coordinate& cUpperLeft, unsigned int iWidth, unsigned int iHeight, char chRepresentation = DEFAULT_REPRESENTATION_CHAR);
    
    /************************************************************************************************
     * function name: Rectangle Constructor                                                         *
     * The Input: const Coordinate object (reference), const Oblong object (reference), char        *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with the coordinate as bottom left, the Oblong *
     *                        as width and height, and the char as the representation for the       *
     *                        rectangle's vertices.                                                 *
     * *********************************************************************************************/
    
    Rectangle(const Coordinate& cUpperLeft, const Oblong& cOblong, char chRepresentation = DEFAULT_REPRESENTATION_CHAR);
    
    /************************************************************************************************
     * function name: Rectangle Copy Constructor                                                    *
     * The Input: const Rectangle object (reference)                                                *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object as a copy of the input object.                 *
     * *********************************************************************************************/
    
    Rectangle(const Rectangle& cRectangle);
    
    /**********************************************************************************************
     * function name: Rectangle Destructor                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~Rectangle();
    
    /**********************************************************************************************
     * function name: operator=                                                                   *
     * The Input: const Rectangle object (reference)                                              *
     * The output: Rectangle object (reference)                                                   *
     * The Function Opertion: Copies the contents of the input object                             *
     * *******************************************************************************************/
    
    Rectangle& operator=(const Rectangle& cRectangle);
    
    /**********************************************************************************************
     * function name: clone                                                                       *
     * The Input: none                                                                            *
     * The output: Shape object (pointer)                                                         *
     * The Function Opertion: Returns a copy of the current object.                               *
     * *******************************************************************************************/
    
    virtual Shape* clone() const;

};

#endif 
