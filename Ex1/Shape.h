/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Shape Class             *
 ***********************************************************/

#ifndef __Ex1__Shape__
#define __Ex1__Shape__

#include <stdio.h>
#include "Coordinate.h"
#include "Collection.h"
#include "Vertex.h"

/********************************************************************
 * Shape Class: A drawable collection of vertices. It is the base   *
 *              of every drawable object.                           *
 *******************************************************************/

class Shape : public Collection<Vertex> {
    
private:
    
    //  ---                         PRIVATE FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: copyVertices                                                                *
     * The Input: const Shape object (reference)                                                  *
     * The output: none                                                                           *
     * The Function Opertion: Copies the input's Shape's vertecis into the current object.        *
     * *******************************************************************************************/
    
    void copyVertices(const Shape &cShape);
    
protected:
    
    //  ---                         PROTECTED FUNCTIONS                       ---   //

    /**********************************************************************************************
     * function name: getVertex                                                                   *
     * The Input: const Coordinate object (reference)                                             *
     * The output: Vertex object (pointer)                                                        *
     * The Function Opertion: Returns the Vertex object from the collection at the input          *
     *                        Coordinate. Null if not found                                       *
     * *******************************************************************************************/
    
    Vertex* getVertex(const Coordinate& cCoordinate);
    
    /**********************************************************************************************
     * function name: getVertex                                                                   *
     * The Input: const Coordinate object (reference)                                             *
     * The output: const Vertex object (pointer)                                                  *
     * The Function Opertion: Returns the Vertex object from the collection at the input          *
     *                        Coordinate. Null if not found                                       *
     * *******************************************************************************************/
    
    const Vertex* getVertex(const Coordinate &cCoordinate) const;

public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: Shape Constructor                                                             *
     * The Input: int, int                                                                          *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object.                                               *
     * *********************************************************************************************/
    
    Shape();
    
    /************************************************************************************************
     * function name: Shape Copy Constructor                                                        *
     * The Input: const Shape object (reference)                                                    *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object as a copy of the input object.                 *
     * *********************************************************************************************/
    
    Shape(const Shape& cShape);
    
    /**********************************************************************************************
     * function name: Shape Destructor                                                            *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~Shape();
    
    /**********************************************************************************************
     * function name: operator=                                                                   *
     * The Input: const Shape object (reference)                                                  *
     * The output: Shape object (reference)                                                       *
     * The Function Opertion: Copies the contents of the input object                             *
     * *******************************************************************************************/
    
    Shape& operator=(const Shape& cShape);
    
    /************************************************************************************
     * function name: setRepresentation                                                 *
     * The Input: char                                                                  *
     * The output: none                                                                 *
     * The Function Opertion: Sets the representation of the Shape.                     *
     * *********************************************************************************/
    
    void setRepresentation(char chRepresentation);
    
    /************************************************************************************
     * function name: getRepresentation                                                 *
     * The Input: const Coordinate object (reference)                                   *
     * The output: char                                                                 *
     * The Function Opertion: Returns the Representation at a coordiante. Returns       *
     *                        '\0' if not found.                                        *
     * *********************************************************************************/
    
    char getRepresentation(const Coordinate& cCoordinate);
    
    /************************************************************************************
     * function name: setRepresentation                                                 *
     * The Input: const Coordinate object (reference), char                             *
     * The output: none                                                                 *
     * The Function Opertion: Sets the representation at a specific Coordiante with     *
     *                        the input char.                                           *
     * *********************************************************************************/
    
    void setRepresentation(const Coordinate& cCoordinate, char chRepresentation);
    
    /**********************************************************************************************
     * function name: isOverlap                                                                   *
     * The Input: const Shape object (reference), const Coordinate object (reference)             *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if the current object overlaps the input Shape, with   *
     *                        the input coordinates being added to input shape's vertex's position*
     *                        Returns false otherwise.                                            *
     * *******************************************************************************************/
    
    bool isOverlap(const Shape& cShape, const Coordinate& cCoordinate = Coordinate(0, 0)) const;
    
    /**********************************************************************************************
     * function name: isOverlap                                                                   *
     * The Input: const Coordinate object (reference)                                             *
     * The output: bool                                                                           *
     * The Function Opertion: Returns true if the current object overlaps the input Coodinate.    *
     *                        Returns false otherwise.                                            *
     * *******************************************************************************************/
    
    bool isOverlap(const Coordinate& cCoordinate) const;
    
    /**********************************************************************************************
     * function name: clone                                                                       *
     * The Input: none                                                                            *
     * The output: Shape object (pointer)                                                         *
     * The Function Opertion: Returns a copy of the current object.                               *
     * *******************************************************************************************/
    
    virtual Shape* clone() const = 0;

};

#endif
