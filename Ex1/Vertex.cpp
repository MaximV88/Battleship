/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Vertex Class         *
 ***********************************************************/

#include "Vertex.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Vertex Constructor                                                            *
 * The Input: int, int, char                                                                    *
 * The output: none                                                                             *
 * The Function Opertion: Initializes with an initialization list the Superclass coordiante     *
 *                        using the input, and the representation using the input.              *
 * *********************************************************************************************/

Vertex::Vertex(int iPositionX, int iPositionY, char chRepresentation) :
Coordinate(iPositionX, iPositionY), m_chRepresentation(chRepresentation) { }

/************************************************************************************************
 * function name: Vertex Constructor                                                            *
 * The Input: const Coordinate object (reference), char                                         *
 * The output: none                                                                             *
 * The Function Opertion: Initializes with an initialization list the Superclass coordiante     *
 *                        using the input, and the representation using the input.              *
 * *********************************************************************************************/

Vertex::Vertex(const Coordinate& cCoordinate, char chRepresentation) :
Coordinate(cCoordinate), m_chRepresentation(chRepresentation) { }

/************************************************************************************************
 * function name: Vertex Copy Constructor                                                       *
 * The Input: int, int                                                                          *
 * The output: none                                                                             *
 * The Function Opertion: Uses the Copy Constructor from the Superclass (Coordinate) and        *
 *                        changes the member variable responsible for the char representation.  *
 * *********************************************************************************************/

Vertex::Vertex(const Vertex& cVertex) :
Coordinate(cVertex), m_chRepresentation(cVertex.m_chRepresentation) { }

/**********************************************************************************************
 * function name: operator=                                                                   *
 * The Input: const Vertex object (reference)                                                 *
 * The output: Vertex object (reference)                                                      *
 * The Function Opertion: Checks if the current object is the input by comparing address of   *
 *                        pointer. If so then returns the object to avoid redundant work.     *
 *                        Otherwise it copies the input Vertex's values to the                *
 *                        current object's member variables.                                  *
 * *******************************************************************************************/

Vertex& Vertex::operator=(const Vertex& cShapeVertex) {
    
    //We check to avoid redundant work
    if (this != &cShapeVertex) {
        
        //Copy the representation
        m_chRepresentation = cShapeVertex.m_chRepresentation;
        
        //Copy the coordinate
        Coordinate::operator=(cShapeVertex);
        
    }
    
    return *this;
    
}

/************************************************************************************
 * function name: getRepresentation                                                 *
 * The Input: none                                                                  *
 * The output: char                                                                 *
 * The Function Opertion: Returns the member variable that is the                   *
 *                        representation of the Vertex.                             *
 * *********************************************************************************/

char Vertex::getRepresentation() const {
    
    return m_chRepresentation;

}

/************************************************************************************
 * function name: setRepresentation                                                 *
 * The Input: char                                                                  *
 * The output: none                                                                 *
 * The Function Opertion: Sets the member variable that represents the              *
 *                        representation.                                           *
 * *********************************************************************************/

void Vertex::setRepresentation(char chRepresentation) {
    
    m_chRepresentation = chRepresentation;

}
