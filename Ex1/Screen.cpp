/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Screen Class         *
 ***********************************************************/

#include <iostream>
#include "Screen.h"
#include "Coordinate.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: createScreenMatrix                                                          *
 * The Input: none                                                                            *
 * The output: char (pointer to pointer)                                                      *
 * The Function Opertion: Creates a 2d array based of from the Oblong size property, and      *
 *                        then returns the array.                                             *
 * *******************************************************************************************/

char** Screen::createScreenMatrix() const {
    
    //Changed the logic a bit to compensate for the rotation of the terminal
    
    char **screen;
    screen = new char*[getWidth()];
    
    for (unsigned int uiIndex = 0 ; uiIndex < getWidth() ; ++uiIndex) {
        
        //Create a new array
        screen[uiIndex] = new char[getHeight()];
        
        //And populate it with the default 'pixel' character
        for (unsigned int uiCounter = 0 ; uiCounter < getHeight() ; uiCounter++)
            screen[uiIndex][uiCounter] = DEFAULT_SCREEN_PIXEL;
        
    }
    
    return screen;
    
}

/**********************************************************************************************
 * function name: deleteScreenMatrix                                                          *
 * The Input: char (pointer to pointer)                                                       *
 * The output: none                                                                           *
 * The Function Opertion: Iterates over all of the pointers of pointer and deletes            *
 *                        them.                                                               *
 * *******************************************************************************************/

void Screen::deleteScreenMatrix(char **chMatrix) {
    
    //We need to delete a 2d dynamic array
    for(int i = 0 ; i < getWidth() ; ++i)
        delete[] chMatrix[i];
    
    delete[] chMatrix;
    
}

/**********************************************************************************************
 * function name: validInput                                                                  *
 * The Input: unsigned int, unsigned int                                                      *
 * The output: none                                                                           *
 * The Function Opertion: Checks against the height and width of the Screen and returns       *
 *                        true if the input is in range, or false otherwise.                  *
 * *******************************************************************************************/

bool Screen::validInput(unsigned int uiHeight, unsigned int uiWidth) const {
    
    //If it doesnt fit in the height or width of the screen - its not valid
    if ((uiHeight >= getHeight()) ||  (uiWidth >= getWidth()))
        return false;
    
    //Otherwise its ok
    return true;
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Screen Constructor                                                            *
 * The Input: const Oblong object (reference)                                                   *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with input Oblong as input to Oblong superclass*
 *                        and then creates the screen matrix (2d array of chars) using a        *
 *                        private function.                                                     *
 * *********************************************************************************************/

Screen::Screen(const Oblong& cSize) : Oblong(cSize) {
    
    m_chScreenMatrix = createScreenMatrix();
    
}

/**********************************************************************************************
 * function name: Screen Destructor                                                           *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Removes the stored matrix.                                          *
 * *******************************************************************************************/

Screen::~Screen() {
    
    deleteScreenMatrix(m_chScreenMatrix);
    
}

/**********************************************************************************************
 * function name: resize                                                                      *
 * The Input: const Oblong                                                                    *
 * The output: none                                                                           *
 * The Function Opertion: Removes the previous stored Pixel (char) matrix, resizes using      *
 *                        the operator= of the Oblong superclass and creates a new matrix.    *
 * *******************************************************************************************/

void Screen::resize(const Oblong& cSize) {
    
    //First we delete
    deleteScreenMatrix(m_chScreenMatrix);
    
    //Now resize
    Oblong::operator=(cSize);
    
    m_chScreenMatrix = createScreenMatrix();
    
}

/**********************************************************************************************
 * function name: setPixel                                                                    *
 * The Input: char, unsigned int, unsigned int                                                *
 * The output: bool                                                                           *
 * The Function Opertion: Calls for a similar function, but puts the input in a               *
 *                        Coordinate object. Returns the result.                              *
 * *******************************************************************************************/

bool Screen::setPixel(char chInput, const Coordinate& cCoordinate) {
    
    return setPixel(chInput, cCoordinate.getX(), cCoordinate.getY());
    
}

/**********************************************************************************************
 * function name: setPixel                                                                    *
 * The Input: char, const Coordinate object (reference)                                       *
 * The output: bool                                                                           *
 * The Function Opertion: Checks if the input is valid in it's width and height. If yes, then *
 *                        it changes the char value in the matrix to that of the input char,  *
 *                        and returns true. If not valid, then returns false.                 *
 * *******************************************************************************************/

bool Screen::setPixel(char chInput, unsigned int uiHeight, unsigned int uiWidth) {
    
    //Check if input is valid
    if (!validInput(uiWidth, uiHeight))
        return false;
    
    //Otherwise we continue
    m_chScreenMatrix[uiHeight][uiWidth] = chInput;
    
    //Success at changing value
    return true;
    
}

/**********************************************************************************************
 * function name: print                                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Iterates through all of the chars in the matrix prints every one    *
 *                        of them according to the matrix's structure (width and height).     *
 * *******************************************************************************************/

void Screen::print() const {
    
    //We iterate over each cell and print it
    for (unsigned int uiHeight = 0 ; uiHeight < getHeight() ; uiHeight++) {
        
        for (unsigned int uiWidth = 0 ; uiWidth < getWidth() ; uiWidth++) {
            
            //Adjusted for screen XY coordinates
            std::cout << m_chScreenMatrix[uiWidth][getHeight()-1 - uiHeight];
            
        }
        
        std::cout << std::endl;
        
    }
    
}
