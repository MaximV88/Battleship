/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Collection Class     *
 ***********************************************************/

#ifndef __Ex1__CollectionCPP__
#define __Ex1__CollectionCPP__

#include "Collection.h"


//  ---                         PROTECTED FUNCTIONS                       ---   //

/**********************************************************************************************
 * function name: clearCollection                                                             *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Goes through all of the elements in the current object and          *
 *                        deletes them. afterwards clears the vector.                         *
 * *******************************************************************************************/

template<class T>
void Collection<T>::clearCollection() {
    
    //Go through every type and delete it
    for (typename std::vector<T*>::iterator iter = m_vcCollected.begin() ; iter != m_vcCollected.end() ; iter++) {
        
        delete (*iter);
        
    }
    
    //And clear the vector
    m_vcCollected.clear();
    
}

/**********************************************************************************************
 * function name: collect                                                                     *
 * The Input: const T object (pointer)                                                        *
 * The output: none                                                                           *
 * The Function Opertion: Push the input object into the internal vector                      *
 * *******************************************************************************************/

template<class T>
void Collection<T>::collect(T* cCollected) {
    
    //Just add the copy of the element to the vector
    m_vcCollected.push_back(cCollected);
    
}

/**********************************************************************************************
 * function name: dispense                                                                    *
 * The Input: const T object (pointer)                                                        *
 * The output: none                                                                           *
 * The Function Opertion: Goes through all of the elements in the internal vector until it    *
 *                        finds the object required, deletes it and returns true if found     *
 *                        and deletes, false otherwise.                                       *
 * *******************************************************************************************/

template<class T>
bool Collection<T>::dispense(const T* cDispensed) {
    
    //Go through all of the vertices to get a match
    for (typename std::vector<T*>::iterator iter = m_vcCollected.begin() ; iter != m_vcCollected.end() ; iter++) {
        
        //Compare the pointers
        if (*iter == cDispensed) {
            
            delete *iter;
            m_vcCollected.erase(iter);
            
            //End the loop
            return true;
        }
        
    }
    
    //Didnt find the required object - didnt erase anything
    return false;
    
}

/**********************************************************************************************
 * function name: internals                                                                   *
 * The Input: none                                                                            *
 * The output: const vector object (reference)                                                *
 * The Function Opertion: Returns a constant reference to the vector that contains the objects*
 * *******************************************************************************************/

template<class T>
const std::vector<T*>& Collection<T>::internals() const {
    
    //Return a const reference to the vector that holds the data
    return m_vcCollected;
    
}

/**********************************************************************************************
 * function name: mutables                                                                    *
 * The Input: none                                                                            *
 * The output: vector object (reference)                                                      *
 * The Function Opertion: Returns a reference to the vector that contains the objects         *
 * *******************************************************************************************/

template<class T>
std::vector<T*>& Collection<T>::mutables() {
    
    //Return a const reference to the vector that holds the data
    return m_vcCollected;
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Collection Constructor                                                        *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Constructor for the Collection class                                  *
 * *********************************************************************************************/

template<class T>
Collection<T>::Collection()  { }

/**********************************************************************************************
 * function name: Collection Destructor                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

template<class T>
Collection<T>::~Collection() {
    
    clearCollection();
    
}

#endif
