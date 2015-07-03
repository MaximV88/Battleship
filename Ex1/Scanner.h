/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Scanner Class           *
 ***********************************************************/

#ifndef __Ex1__Scanner__
#define __Ex1__Scanner__

#include <stdio.h>
#include <string>

/***********************************************************************************
 * Scanner Class: It is used to read input from the Terminal. It can read both ints*
 *                from a predefined range, or strings with a specific length.      *
 **********************************************************************************/

class Scanner {
    
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: scanInt                                                                     *
     * The Input: int, int                                                                        *
     * The output: int                                                                            *
     * The Function Opertion: Reads an input from the Terminal, and returns it once a legal       *
     *                        integer with the specified input range has been read.               *
     * *******************************************************************************************/
    
    int scanInt(int uiLowest, int uiHighest) const;
    
    /**********************************************************************************************
     * function name: scanString                                                                  *
     * The Input: unsigned int, unsigned int                                                      *
     * The output: string                                                                         *
     * The Function Opertion: Reads an input from the Terminal, and returns it once a legal       *
     *                        string with the specified input range has been read. if the input   *
     *                        is longer than the maximum range input, it slices the rest of the   *
     *                        read string.                                                        *
     * *******************************************************************************************/
    
    std::string scanString(unsigned int uiMinLength, unsigned int uiMaxLength) const;
    
};

#endif /* defined(__Ex1__Scanner__) */
