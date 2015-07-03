/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Oblong Class         *
 ***********************************************************/

#include "Oblong.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Oblong Constructor                                                            *
 * The Input: int, int                                                                          *
 * The output: none                                                                             *
 * The Function Opertion: Assignes the member variables with the appropriate input.             *
 * *********************************************************************************************/

Oblong::Oblong(unsigned int uiWidth, unsigned int uiHeight) {
    
    m_uiHeight = uiHeight;
    m_uiWidth = uiWidth;
    
}

/************************************************************************************************
 * function name: Oblong Copy Constructor                                                       *
 * The Input: const Oblong object (reference)                                                   *
 * The output: none                                                                             *
 * The Function Opertion: Assignes the member variables with the appropriate input's            *
 *                        member variables.                                                     *
 * *********************************************************************************************/

Oblong::Oblong(const Oblong& cOblong) {
    
    //Perform a deep copy just in case (style wise)
    m_uiHeight = cOblong.m_uiHeight;
    m_uiWidth = cOblong.m_uiWidth;
    
}

/**********************************************************************************************
 * function name: operator=                                                                   *
 * The Input: const Oblong object (reference)                                                 *
 * The output: Oblong object (reference)                                                      *
 * The Function Opertion: Checks if the current object is the input by comparing address of   *
 *                        pointer. If so then returns the object to avoid redundant work.     *
 *                        Otherwise it copies the input Oblong's values to the                *
 *                        current object's member variables.                                  *
 * *******************************************************************************************/

Oblong& Oblong::operator=(const Oblong &cOblong) {
    
    if (this != &cOblong) {
        
        m_uiHeight = cOblong.m_uiHeight;
        m_uiWidth = cOblong.m_uiWidth;

    }
    
    return *this;
    
}

/**********************************************************************************************
 * function name: operator==                                                                  *
 * The Input: const Oblong object (reference)                                                 *
 * The output: bool                                                                           *
 * The Function Opertion: Returns true if the input Oblong matches the size of current object,*
 *                        false otherwise.                                                    *
 * *******************************************************************************************/

bool Oblong::operator==(const Oblong &cOblong) const {
    
    return ((m_uiWidth == cOblong.m_uiWidth) && (m_uiHeight == cOblong.m_uiHeight));
    
}

/**********************************************************************************************
 * function name: operator!=                                                                  *
 * The Input: const Oblong object (reference)                                                 *
 * The output: bool                                                                           *
 * The Function Opertion: If either the width or the height of the current object and the     *
 *                        input object's match, it returns false. otherwise true.             *
 * *******************************************************************************************/

bool Oblong::operator!=(const Oblong &cOblong) const {
    
    return ((m_uiWidth != cOblong.m_uiWidth) || (m_uiHeight != cOblong.m_uiHeight));
    
}

/************************************************************************************
 * function name: getWidth                                                          *
 * The Input: none                                                                  *
 * The output: unsigned int                                                         *
 * The Function Opertion: Returns the member variable that holds the height.        *
 * *********************************************************************************/

unsigned int Oblong::getHeight() const {
    
    return m_uiHeight;
    
}

/************************************************************************************
 * function name: getHeight                                                         *
 * The Input: none                                                                  *
 * The output: unsigned int                                                         *
 * The Function Opertion: Returns the height of the current object.                 *
 * *********************************************************************************/

unsigned int Oblong::getWidth() const {
    
    return m_uiWidth;
    
}

/************************************************************************************
 * function name: getSize                                                           *
 * The Input: none                                                                  *
 * The output: unsigned int                                                         *
 * The Function Opertion: Multiplies the height and width and returns it.           *
 * *********************************************************************************/

unsigned int Oblong::getSize() const {
    
    return m_uiWidth * m_uiHeight;
    
}

/************************************************************************************
 * function name: resize                                                            *
 * The Input: unsigned int, unsigned int                                            *
 * The output: none                                                                 *
 * The Function Opertion: Assignes the member variables with the input.             *
 * *********************************************************************************/

void Oblong::resize(unsigned int uiWidth, unsigned int uiHeight) {
    
    m_uiHeight = uiHeight;
    m_uiWidth = uiWidth;
    
}
