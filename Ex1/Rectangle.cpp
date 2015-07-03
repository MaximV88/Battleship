/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Rectangle Class      *
 ***********************************************************/

#include "Rectangle.h"
#include <iostream>

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: buildRectangle                                                              *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Adds vertices to the shape by iterating over 2 loops and placing    *
 *                        the vertices in the derived locations.                              *
 * *******************************************************************************************/

void Rectangle::buildRectangle() {
    
    //Create the Drawing elements that represent the shape.
    //We do 2 loops - one for the vertical lines, and another for the horizontal ones
    unsigned int uiIndexHeight = 0;
    
    for (int iIndexWidth = m_cBottomLeft->getX() ; iIndexWidth < getWidth() + m_cBottomLeft->getX() ; iIndexWidth++, uiIndexHeight++) {
        
        //Add the first row as complete, and the last one as complete
        if (iIndexWidth == m_cBottomLeft->getX() || iIndexWidth == (getWidth() + m_cBottomLeft->getX())-1) {
            
            for (int iCounter =  m_cBottomLeft->getY() ; iCounter < m_cBottomLeft->getY() + getHeight() ; iCounter++) {
                
                collect(new Vertex(Coordinate(iIndexWidth, iCounter)));
                
            }
            
        }
        else {
            
            collect(new Vertex(Coordinate(iIndexWidth, m_cBottomLeft->getY())));
            collect(new Vertex(Coordinate(iIndexWidth, m_cBottomLeft->getY() + getHeight() - 1)));
            
        }
        
    }
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Rectangle Constructor                                                         *
 * The Input: const Coordinate object (reference), int, int, char                               *
 * The output: none                                                                             *
 * The Function Opertion: Calls for the Oblong constructor with the input, places the           *
 *                        appropriate member variable the coordinate and builds the rectangle.  *
 * *********************************************************************************************/

Rectangle::Rectangle(const Coordinate& cUpperLeft, unsigned int iWidth, unsigned int iHeight, char chRepresentation) :
Oblong(iWidth, iHeight) {
    
    //To preserve encapsulation the Coordiante will be copied
    m_cBottomLeft = new Coordinate(cUpperLeft);
    
    buildRectangle();
    
}

/************************************************************************************************
 * function name: Rectangle Constructor                                                         *
 * The Input: const Coordinate object (reference), const Oblong object (reference), char        *
 * The output: none                                                                             *
 * The Function Opertion: Calls for the Oblong constructor with the input, places the           *
 *                        appropriate member variable the coordinate and builds the rectangle.  *
 * *********************************************************************************************/

Rectangle::Rectangle(const Coordinate& cUpperLeft, const Oblong& cOblong, char chRepresentation) :
Oblong(cOblong) {
    
    //Constructor chaining isnt possible in ansi...
    //To preserve encapsulation the Coordiante will be copied
    m_cBottomLeft = new Coordinate(cUpperLeft);
    
    buildRectangle();
    
}

/************************************************************************************************
 * function name: Rectangle Copy Constructor                                                    *
 * The Input: const Rectangle object (reference)                                                *
 * The output: none                                                                             *
 * The Function Opertion: Sends the Shape's copy constructor the input object to copy all       *
 *                        the vertices, and then copies  the coordinates from the               *
 *                        input Rectangle.                                                      *
 * *********************************************************************************************/

Rectangle::Rectangle(const Rectangle& cRectangle) : Shape(cRectangle), Oblong(cRectangle) {
    
    m_cBottomLeft = new Coordinate(*cRectangle.m_cBottomLeft);
    
}

/**********************************************************************************************
 * function name: Rectangle Destructor                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Deletes the stored coordiante.                                      *
 * *******************************************************************************************/

Rectangle::~Rectangle() {
    
    delete m_cBottomLeft;
    
}

/**********************************************************************************************
 * function name: operator=                                                                   *
 * The Input: const Rectangle object (reference)                                              *
 * The output: Rectangle object (reference)                                                   *
 * The Function Opertion: Checks if the current object is the input by comparing address of   *
 *                        pointer. If so then returns the object to avoid redundant work.     *
 *                        Otherwise calls for the operator= of the superclass's shape         *
 *                        and that of the Oblong. Also copies the member variable.            *
 *                        Afterwards returns the object.                                      *
 * *******************************************************************************************/

Rectangle& Rectangle::operator=(const Rectangle& cRectangle) {
    
    if (this != &cRectangle) {
        
        //Remove previous Points
        delete m_cBottomLeft;
        
        //Assign the new Points
        m_cBottomLeft = new Coordinate(*cRectangle.m_cBottomLeft);

        Oblong::operator=(cRectangle);
        
        //The = operator needs to copy all of the information
        Shape::operator=(cRectangle);
        
    }
    
    return *this;
    
}

/**********************************************************************************************
 * function name: clone                                                                       *
 * The Input: none                                                                            *
 * The output: Shape object (pointer)                                                         *
 * The Function Opertion: Returns a copy of the current object using the copy constructor.    *
 * *******************************************************************************************/

Shape* Rectangle::clone() const {
    
    return new Rectangle(*this);
    
}

