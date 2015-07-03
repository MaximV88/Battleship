/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Shape Class          *
 ***********************************************************/

#include "Shape.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: copyVertices                                                                *
 * The Input: const Shape object (reference)                                                  *
 * The output: none                                                                           *
 * The Function Opertion: Iterates through the vertices contained in the input object, and    *
 *                        copies them into the current object's collection (vector).          *
 * *******************************************************************************************/


void Shape::copyVertices(const Shape &cShape) {
    
    for (std::vector<Vertex*>::const_iterator iter = cShape.internals().begin() ; iter != cShape.internals().end() ; iter++) {
        
        //Add a copy of the vertex to the collection
        collect(new Vertex(**iter));
        
    }
    
}

//  ---                         PROTECTED FUNCTIONS                       ---   //

/**********************************************************************************************
 * function name: getVertex                                                                   *
 * The Input: const Coordinate object (reference)                                             *
 * The output: Vertex object (pointer)                                                        *
 * The Function Opertion: Iterates through the vertices contained in the current object, and  *
 *                        checks every one if its equal a given coordiante that is            *
 *                        has been recieved in the input. Returns the Vertex if               *
 *                        found, Null otherwise.                                              *
 * *******************************************************************************************/

Vertex* Shape::getVertex(const Coordinate &cCoordinate) {
    
    //Go through all of the vertices contained
    for (std::vector<Vertex*>::iterator iter = mutables().begin() ; iter != mutables().end() ; iter++) {
        
        //And return the one that overlaps the coordinate
        if (**iter == cCoordinate)
            return (*iter);
        
    }
    
    //Otherwise dont return anything
    return NULL;
    
}

/**********************************************************************************************
 * function name: getVertex                                                                   *
 * The Input: const Coordinate object (reference)                                             *
 * The output: const Vertex object (pointer)                                                  *
 * The Function Opertion: Iterates through the vertices contained in the current object, and  *
 *                        checks every one if its equal a given coordiante that is            *
 *                        has been recieved in the input. Returns the Vertex if               *
 *                        found, Null otherwise.                                              *
 * *******************************************************************************************/

const Vertex* Shape::getVertex(const Coordinate &cCoordinate) const {
    
    //Go through all of the vertices contained
    for (std::vector<Vertex*>::const_iterator iter = internals().begin() ; iter != internals().end() ; iter++) {
        
        //And return the one that overlaps the coordinate
        if (**iter == cCoordinate)
            return (*iter);
        
    }
    
    //Otherwise dont return anything
    return NULL;
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Shape Constructor                                                             *
 * The Input: int, int                                                                          *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object.                                               *
 * *********************************************************************************************/

Shape::Shape() { }

/************************************************************************************************
 * function name: Shape Copy Constructor                                                        *
 * The Input: const Shape object (reference)                                                    *
 * The output: none                                                                             *
 * The Function Opertion: Copies all of the input's vertices.                                   *
 * *********************************************************************************************/

Shape::Shape(const Shape& cShape) {

    //Copy all of the vertices contained in the shape
    copyVertices(cShape);

}

/**********************************************************************************************
 * function name: Shape Destructor                                                            *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

Shape::~Shape() { }

/**********************************************************************************************
 * function name: operator=                                                                   *
 * The Input: const Shape object (reference)                                                  *
 * The output: Shape object (reference)                                                       *
 * The Function Opertion: Checks if the current object is the input by comparing address of   *
 *                        pointer. If so then returns the object to avoid redundant work.     *
 *                        Otherwise cleans the current object's Vertex vector (collection),   *
 *                        and copies the vertices from the input object.                      *
 * *******************************************************************************************/

Shape& Shape::operator=(const Shape &cShape) {

    //We check to avoid redundant work
    if (this != &cShape) {
        
        //Copy the contents of the shape
        Collection<Vertex>::operator=(cShape);
        
        //Remove all of the vertices stored
        clearCollection();
        
        //Copy all of the vertices from the input
        copyVertices(cShape);
        
    }
    
    return *this;
    
}

/************************************************************************************
 * function name: setRepresentation                                                 *
 * The Input: char                                                                  *
 * The output: none                                                                 *
 * The Function Opertion: Iterates through all of the contained vertices in the     *
 *                        shape and for every one it sets the representation to that*
 *                        of the input.                                             *
 * *********************************************************************************/

void Shape::setRepresentation(char chRepresentation) {
    
    //Go through every vertex in the shape
    for (std::vector<Vertex*>::iterator iter = mutables().begin() ; iter != mutables().end() ; iter++) {
    
        //And change it's representation to chRepresentation
        (*iter)->setRepresentation(chRepresentation);
        
    }
    
}

/************************************************************************************
 * function name: getRepresentation                                                 *
 * The Input: const Coordinate object (reference)                                   *
 * The output: char                                                                 *
 * The Function Opertion: Gets the vertex from the specified input Coordiante       *
 *                        and checks if exists. If yes then it returns it's char    *
 *                        representation. Otherwise returns '\0'.                   *
 * *********************************************************************************/

char Shape::getRepresentation(const Coordinate &cCoordinate) {
    
    //Get the vertex from the collection
    Vertex* cVertex = getVertex(cCoordinate);
    
    if (cVertex != NULL)
        return char(cVertex->getRepresentation());
   
    //Otherwise
    return '\0';
    
}

/************************************************************************************
 * function name: setRepresentation                                                 *
 * The Input: const Coordinate object (reference), char                             *
 * The output: none                                                                 *
 * The Function Opertion: Gets the specified Vertex from the input Coordiante       *                                          
 *                        and if it exists it sets it representation to input char. *
 * *********************************************************************************/

void Shape::setRepresentation(const Coordinate &cCoordinate, char chRepresentation) {
    
    //Get the vertex from the collection
    Vertex* cPulledVert = getVertex(cCoordinate);
    
    if (cPulledVert)
        cPulledVert->setRepresentation(chRepresentation);
    
}

/**********************************************************************************************
 * function name: isOverlap                                                                   *
 * The Input: const Shape object (reference), const Coordinate object (reference)             *
 * The output: bool                                                                           *
 * The Function Opertion: Iterates through all of the vertices in the input object.           *
 *                        It checks everyone for overlapping with an input coordinate         *
 *                        adjustment (the summation) who represent the position of the input  *
 *                        shape. Returns true if found an overlap, false otherwise.           *
 * *******************************************************************************************/

bool Shape::isOverlap(const Shape& cShape, const Coordinate& cCoordinate) const {

        //Check if any of the vertices in the given shape have the same values as ours
        for (std::vector<Vertex*>::const_iterator iter = cShape.internals().begin() ; iter != cShape.internals().end() ; iter++) {

            //Check to see if the current vertex overlaps
            if (isOverlap(**iter + cCoordinate))
                return true;
            
        }
    
    return false;
    
}

/**********************************************************************************************
 * function name: isOverlap                                                                   *
 * The Input: const Coordinate object (reference)                                             *
 * The output: bool                                                                           *
 * The Function Opertion: If it can get a vertex from the input Coordinate, and that vertex   *
 *                        exists it returns true, false otherwise.                            *
 * *******************************************************************************************/

bool Shape::isOverlap(const Coordinate& cCoordinate) const {
    
    //Use the comparison that is given from the Coordinate class
    if (getVertex(cCoordinate) != NULL)
        return true;
    
    return false;
    
}

