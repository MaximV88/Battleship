/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Scene Class          *
 ***********************************************************/

#include "Scene.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Scene Constructor                                                             *
 * The Input: const string object (reference)                                                   *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with the input as name                         *
 * *********************************************************************************************/

Scene::Scene(const std::string& strName) : Nameable(strName) { }

/**********************************************************************************************
 * function name: Scene Destructor                                                            *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

Scene::~Scene() { }