/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Scanner Class        *
 ***********************************************************/

#include <iostream>
#include <stdlib.h>
#include <limits>
#include "Scanner.h"

using namespace std;

//  ---                         PUBLIC FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: scanInt                                                                     *
 * The Input: int, int                                                                        *
 * The output: int                                                                            *
 * The Function Opertion: Reads using the cin object from the Terminal the input that the     *
 *                        user has given. if the input is smaller or larger than the range    *
 *                        specified a while loop is invoked until a legal input has been      *
 *                        given. Output to the user is made to clarify false input.           *
 * *******************************************************************************************/

int Scanner::scanInt(int uiLowest, int uiHighest) const {
    
    //Read selection
    int uiSelection = 0;
    while(!(cin >> uiSelection) || uiSelection >= uiHighest || uiSelection <= uiLowest) {
        
        //If the input is not legal...
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid selection. Please Try again: ";
        
    }
    
    //Return the legal input
    return uiSelection;
    
    
}

/**********************************************************************************************
 * function name: scanString                                                                  *
 * The Input: unsigned int, unsigned int                                                      *
 * The output: string                                                                         *
 * The Function Opertion: Reads using the cin object the string input from the Terminal.      *
 *                        It uses a while loop that is broken once a legal input has been     *
 *                        given. A legal input is a string that is not shorter than the       *
 *                        minimal specified range. Any input that is larger than the maximum  *
 *                        specified range is sliced.                                          *
 * *******************************************************************************************/

string Scanner::scanString(unsigned int uiMinLength, unsigned int uiMaxLength) const {
    
    string strTemp;
    
    //Read the input
     while(getline(cin,strTemp)) {
     
         //If the string is too long
         if (strTemp.length() >= uiMaxLength) {
             
             //Slice the string
             strTemp.resize(uiMaxLength);
             return strTemp;
         
             //If the string is legal
         } else if (strTemp.length() >= uiMinLength) {
             
             //Return it
             return strTemp;

             //Otherwise it is too short
         } else {
             
             //Continue to seek input without polluting consule
             if (strTemp.length() != 0)
                 cout << "Invalid input. Please Try again: ";
             
         }
         
     }

    //Return the input
    return strTemp;

}
