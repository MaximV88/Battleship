/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Line Class           *
 ***********************************************************/

#include <math.h>
#include <stdlib.h>
#include "Line.h"
#include "Vertex.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: coordinateAtRatio                                                           *
 * The Input: int, int                                                                        *
 * The output: Coordinate object                                                              *
 * The Function Opertion: Calculates the position of X and Y between the two line edges       *
 *                        (start and end point), and then returns a coordinate created from   *
 *                        the calculated value.                                               *
 * *******************************************************************************************/

Coordinate Line::coordinateAtRatio(int iNumerator, int iDenominator) const {
    
    //from http://math.tutorvista.com/geometry/section-formula.html
    
    //We divide into sections of ratio m:n using the formula x = (m*x2+n*x1)/(m+n), y = (m*y2+n*y1)/(m+n)
    const int uiPositionX = ((iNumerator * m_cEnd->getX()) + (iDenominator * m_cStart->getX())) / (iNumerator + iDenominator);
    const int uiPositionY = ((iNumerator * m_cEnd->getY()) + (iDenominator * m_cStart->getY())) / (iNumerator + iDenominator);
    
    return Coordinate(uiPositionX, uiPositionY);
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Line Constructor                                                              *
 * The Input: const Coordinate object (reference), const Coordinate object (reference), char    *
 * The output: none                                                                             *
 * The Function Opertion: Iterates through every point at the length of its magnitude,          *
 *                        and afterwards adds a vertex at every point in the ratio to create    *
 *                        a continous line.                                                     *
 * *********************************************************************************************/

Line::Line(const Coordinate& cStart, const Coordinate& cEnd, char chRepresentation) {
    
    //In order to encapsulate the data and prevent unwanted outside changes, the points will be copied
    
    m_cStart = new Coordinate(cStart);
    m_cEnd = new Coordinate(cEnd);
    
    
    //Create the Drawing elements that represent the shape.
    //We start from 1 due to the role that the loop invariant plays - its defining ratio
    for (unsigned int uiIndex = 0 ; uiIndex <= magnitude() ; uiIndex++) {
        
        //Get the location of the "section", i.e. dividing the line into multiple fractions using its magnitude
        //Put the information recieved into the shape defining vector
        collect(new Vertex(coordinateAtRatio(uiIndex, magnitude()-uiIndex), chRepresentation));
        
        
    }
    
}

/************************************************************************************************
 * function name: Line Copy Constructor                                                         *
 * The Input: const Line object (reference)                                                     *
 * The output: none                                                                             *
 * The Function Opertion: Sends the Shape's copy constructor the input object to copy all       *
 *                        the vertices, and then copies all of the coordinates from the         *
 *                        input line.                                                           *
 * *********************************************************************************************/

Line::Line(const Line& cLine) : Shape(cLine) {
    
    //In order to encapsulate the data and prevent unwanted outside changes, the points will be copied
    m_cStart = new Coordinate(*cLine.m_cStart);
    m_cEnd = new Coordinate(*cLine.m_cEnd);
    
}

/**********************************************************************************************
 * function name: Line Destructor                                                             *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Delete the stored member variables that were initialized from heap. *
 * *******************************************************************************************/

Line::~Line() {
    
    delete m_cStart;
    delete m_cEnd;
    
}

/**********************************************************************************************
 * function name: operator=                                                                   *
 * The Input: const Line object (reference)                                                   *
 * The output: Line object (reference)                                                        *
 * The Function Opertion: Checks if the current object is the input by comparing address of   *
 *                        pointer. If so then returns the object to avoid redundant work.     *
 *                        Otherwise calls for the operator= of the superclass's shape         *
 *                        and that of the coordinate. Also copies the member variables.       *
 *                        Afterwards returns the object.                                      *
 * *******************************************************************************************/

Line& Line::operator=(const Line& cLine) {
    
    if (this != &cLine) {
        
        //Remove previous Points
        delete m_cStart;
        delete m_cEnd;
        
        //Assign the new Points
        m_cStart = new Coordinate(*cLine.m_cStart);
        m_cEnd = new Coordinate(*cLine.m_cEnd);
        
        //The = operator needs to copy all of the information
        Shape::operator=(cLine);
        
    }
    
    return *this;
    
}

/**********************************************************************************************
 * function name: magnitude                                                                   *
 * The Input: none                                                                            *
 * The output: int                                                                            *
 * The Function Opertion: Calculates the length of the line using the formula, and then return*
 *                        the result.                                                         *
 * *******************************************************************************************/

int Line::magnitude() const {
    
    //Calculated using the formula sqrt((x2-x1)^2 + (y2-y1)^2)
    int iDifferenceX = abs(m_cEnd->getX() - m_cStart->getX());
    int iDifferenceY = abs(m_cEnd->getY() - m_cStart->getY());

    return sqrt(pow(iDifferenceX, 2) + pow(iDifferenceY, 2));
    
}

/**********************************************************************************************
 * function name: clone                                                                       *
 * The Input: none                                                                            *
 * The output: Shape object (pointer)                                                         *
 * The Function Opertion: Returns a copy of the current object using the copy constructor.    *
 * *******************************************************************************************/

Shape* Line::clone() const {
    
    return new Line(*this);
    
}

