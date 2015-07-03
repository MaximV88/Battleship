/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Coordinate Class     *
 ***********************************************************/

#include "Coordinate.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Coordinate Constructor                                                        *
 * The Input: int, int                                                                          *
 * The output: none                                                                             *
 * The Function Opertion: Positions the input variables in the appropriate member variables     *
 * *********************************************************************************************/

Coordinate::Coordinate(int uiPositionX, int uiPositionY) {
    
    m_iPositionX = uiPositionX;
    m_iPositionY = uiPositionY;
    
}

/***************************************************************************************************
 * function name: Coordinate Copy Constructor                                                      *
 * The Input: int, int                                                                             *
 * The output: none                                                                                *
 * The Function Opertion: Copies the input coordinate X, Y to the current object's member variables*
 * ************************************************************************************************/

Coordinate::Coordinate(const Coordinate& cCoordinate) {
    
    //Perform a deep copy just in case (style wise)
    m_iPositionX = cCoordinate.m_iPositionX;
    m_iPositionY = cCoordinate.m_iPositionY;
    
}

/**********************************************************************************************
 * function name: operator=                                                                   *
 * The Input: const Coordinate object (reference)                                             *
 * The output: Coordinate object (reference)                                                  *
 * The Function Opertion: Checks if the current object is the input by comparing address of   *
 *                        pointer. If so then returns the object to avoid redundant work.     *
 *                        Otherwise it copies the input coordinate's values to the            *
 *                        current object's member variables.                                  *
 * *******************************************************************************************/

Coordinate& Coordinate::operator=(const Coordinate &cCoordinate) {
    
    if (this != &cCoordinate) {
        
        m_iPositionX = cCoordinate.m_iPositionX;
        m_iPositionY = cCoordinate.m_iPositionY;
        
    }
    
    return *this;
    
}

/**********************************************************************************************
 * function name: operator==                                                                  *
 * The Input: const Coordinate object (reference)                                             *
 * The output: bool                                                                           *
 * The Function Opertion: Returns true if the input coordinate matches the current object,    *
 *                        false otherwise.                                                    *
 * *******************************************************************************************/

bool Coordinate::operator==(const Coordinate &cCoordinate) const {
    
    return ((m_iPositionX == cCoordinate.m_iPositionX) && (m_iPositionY == cCoordinate.m_iPositionY));
    
}

/**********************************************************************************************
 * function name: operator!=                                                                  *
 * The Input: const Coordinate object (reference)                                             *
 * The output: bool                                                                           *
 * The Function Opertion: Returns false if the input coordinate matches the current object,   *
 *                        true otherwise.                                                     *
 * *******************************************************************************************/

bool Coordinate::operator!=(const Coordinate &cCoordinate) const {
    
    return ((m_iPositionX != cCoordinate.m_iPositionX) || (m_iPositionY != cCoordinate.m_iPositionY));
    
}

/**********************************************************************************************
 * function name: operator+                                                                   *
 * The Input: const Coordinate object (reference)                                             *
 * The output: const Coordinate object                                                        *
 * The Function Opertion: Copies the current object into a temporary object, performs the     *
 *                        operator+= on them, and return the temporary object.                *
 * *******************************************************************************************/

const Coordinate Coordinate::operator+(const Coordinate &cCoordinate) const {
    
    //Copy the coordinate
    Coordinate cResult = *this;
    
    cResult += cCoordinate;
    
    return cResult;
    
}

/**********************************************************************************************
 * function name: operator+=                                                                  *
 * The Input: const Coordinate object (reference)                                             *
 * The output: const Coordinate object                                                        *
 * The Function Opertion: Performs the operator+ on the coordinates of the current            *
 *                        object, with those of the input.                                    *
 * *******************************************************************************************/

Coordinate& Coordinate::operator+=(const Coordinate &cCoordinate) {
    
    //Normal vector math
    m_iPositionX += cCoordinate.m_iPositionX;
    m_iPositionY += cCoordinate.m_iPositionY;
    
    return *this;
}

/**********************************************************************************************
 * function name: operator-                                                                   *
 * The Input: const Coordinate object (reference)                                             *
 * The output: const Coordinate object                                                        *
 * The Function Opertion: Copies the current object into a temporary object, performs the     *
 *                        operator-= on them, and return the temporary object.                *
 * *******************************************************************************************/

const Coordinate Coordinate::operator-(const Coordinate &cCoordinate) const {
    
    //Copy the coordinate
    Coordinate cResult = *this;
    
    cResult -= cCoordinate;
    
    return cResult;
    
}

/**********************************************************************************************
 * function name: operator-=                                                                  *
 * The Input: const Coordinate object (reference)                                             *
 * The output: const Coordinate object                                                        *
 * The Function Opertion: Performs the operator- on the coordinates of the current            *
 *                        object, with those of the input.                                    *
 * *******************************************************************************************/

Coordinate& Coordinate::operator-=(const Coordinate &cCoordinate) {
    
    //Normal vector math
    m_iPositionX -= cCoordinate.m_iPositionX;
    m_iPositionY -= cCoordinate.m_iPositionY;
    
    return *this;
}

/************************************************************************************
 * function name: getX                                                              *
 * The Input: none                                                                  *
 * The output: none                                                                 *
 * The Function Opertion: Returns the member variable that holds the X value.       *
 * *********************************************************************************/

int Coordinate::getX() const {
    
    return m_iPositionX;
    
}

/************************************************************************************
 * function name: getY                                                              *
 * The Input: none                                                                  *
 * The output: none                                                                 *
 * The Function Opertion: Returns the member variable that holds the Y value.       *
 * *********************************************************************************/

int Coordinate::getY() const {
    
    return m_iPositionY;
    
}

/************************************************************************************
 * function name: operator<<                                                        *
 * The Input: ostream object (reference), const Coordinate object (reference)       *
 * The output: ostream object (reference)                                           *
 * The Function Opertion: Performs the operator<< on the ostream object, prints     *
 *                        the X and Y values, and returns the ostream object.       *
 * *********************************************************************************/

std::ostream& operator<< (std::ostream &out, const Coordinate &cCoordinate) {

    out << "(" << cCoordinate.m_iPositionX << ", " << cCoordinate.m_iPositionY << ")";
    return out;

}
