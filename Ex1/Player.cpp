/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Player Class         *
 ***********************************************************/

#include "Player.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Player Constructor                                                            *
 * The Input: const string object (reference)                                                   *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object and sends the input string to the Nameable     *
 *                        class constructor as parameter to be used as a name.                  *
 * *********************************************************************************************/

Player::Player(const std::string& strName) : Nameable(strName) {}

/**********************************************************************************************
 * function name: Action Destructor                                                           *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

Player::~Player() { }