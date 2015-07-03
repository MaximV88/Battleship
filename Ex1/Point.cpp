/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Point Class          *
 ***********************************************************/

#include "Point.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Point Constructor                                                             *
 * The Input: const Coordinate object (reference), char                                         *
 * The output: none                                                                             *
 * The Function Opertion: Sends the initialization list's Coordinate constructor the input      *
 *                        coordinate, and creates a vertex at the input coordinate with the     *
 *                        input char as representation.                                         *
 * *********************************************************************************************/

Point::Point(const Coordinate& cCoordinate, char chRepresentation) : Coordinate(cCoordinate) {
    
    //Create the Drawing elements that represent the shape
    collect(new Vertex(cCoordinate, chRepresentation));
    
}

/************************************************************************************************
 * function name: Point Constructor                                                             *
 * The Input: int, int, char                                                                    *
 * The output: none                                                                             *
 * The Function Opertion: Sends the initialization list's Coordinate constructor the input      *
 *                        ints, and creates a vertex at the input ints with the                 *
 *                        input char as representation.                                         *
 * *********************************************************************************************/

Point::Point(int iPositionX, int iPositionY, char chRepresentation) : Coordinate(iPositionX, iPositionY) {
    
    //Create the Drawing elements that represent the shape
    collect(new Vertex(Coordinate(iPositionX,iPositionY), chRepresentation));
    
}

/************************************************************************************************
 * function name: Point Copy Constructor                                                        *
 * The Input: const Point object (reference)                                                    *
 * The output: none                                                                             *
 * The Function Opertion: Sends the initialization list's Coordinate constructor the input      *
 *                        object to copy the origin, and sends to the Shape's Copy constructor  *
 *                        to copy all the vertices.                                             *
 * *********************************************************************************************/

Point::Point(const Point& cPoint) : Shape(cPoint), Coordinate(cPoint) { }

/**********************************************************************************************
 * function name: Point Destructor                                                            *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

Point::~Point() { }

/**********************************************************************************************
 * function name: operator=                                                                   *
 * The Input: const Point object (reference)                                                  *
 * The output: Point object (reference)                                                       *
 * The Function Opertion: Checks if the current object is the input by comparing address of   *
 *                        pointer. If so then returns the object to avoid redundant work.     *
 *                        Otherwise calls for the operator= of the superclass's shape         *
 *                        and that of the coordinate. Afterwards returns the object.          *
 * *******************************************************************************************/

Point& Point::operator=(const Point& cPoint) {

    if (this != &cPoint) {
        
        //The = operator needs to copy all of the information in the shape
        Shape::operator=(cPoint);
        
        //This will copy the coordinate information of the point
        Coordinate::operator=(cPoint);
        
    }
    
    return *this;
    
}

/**********************************************************************************************
 * function name: clone                                                                       *
 * The Input: none                                                                            *
 * The output: Shape object (pointer)                                                         *
 * The Function Opertion: Returns a copy of the current object using the copy constructor.    *
 * *******************************************************************************************/

Shape* Point::clone() const {
    
    return new Point(*this);
    
}
