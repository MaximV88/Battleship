/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Vertex Class            *
 ***********************************************************/

#ifndef __Ex1__Vertex__
#define __Ex1__Vertex__

#include <stdio.h>
#include "Coordinate.h"

#define DEFAULT_REPRESENTATION_CHAR '*'

/********************************************************************
 * Vertex Class: Represents a Coodinate with an information (char). *
 *******************************************************************/

class Vertex : public Coordinate {
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the expression of the vertex
    char m_chRepresentation;
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Vertex Constructor                                                            *
     * The Input: int, int, char                                                                    *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input ints as position, and char as       *
     *                        it's representation.                                                  *
     * *********************************************************************************************/
    
    Vertex(int iPositionX, int iPositionY, char chRepresentation = DEFAULT_REPRESENTATION_CHAR);
    
    /************************************************************************************************
     * function name: Vertex Constructor                                                            *
     * The Input: const Coordinate object (reference), char                                         *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object with input ints as position, and char as       *
     *                        it's representation.                                                  *
     * *********************************************************************************************/
    
    Vertex(const Coordinate& cCoordinate, char chRepresentation = DEFAULT_REPRESENTATION_CHAR);
    
    /************************************************************************************************
     * function name: Vertex Copy Constructor                                                       *
     * The Input: int, int                                                                          *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object as a copy of the input object.                 *
     * *********************************************************************************************/
    
    Vertex(const Vertex& cVertex);
    
    /***********************************************************************************
     * function name: operator=                                                        *
     * The Input: const Vertex object (reference)                                      *
     * The output: Vertex object (reference)                                           *
     * The Function Opertion: Copies the contents of the input object                  *
     * *********************************************************************************/
    
    Vertex& operator=(const Vertex& cShapeVertex);
    
    /************************************************************************************
     * function name: getRepresentation                                                 *
     * The Input: none                                                                  *
     * The output: char                                                                 *
     * The Function Opertion: Returns the Representation of the Vertex.                 *
     * *********************************************************************************/
    
    char getRepresentation() const;
    
    /************************************************************************************
     * function name: setRepresentation                                                 *
     * The Input: char                                                                  *
     * The output: none                                                                 *
     * The Function Opertion: Sets the representation of the Vertex.                    *
     * *********************************************************************************/
    
    void setRepresentation(char chRepresentation);
    
};

#endif
