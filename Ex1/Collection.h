/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Collection Class        *
 ***********************************************************/

#ifndef __Ex1__Collection__
#define __Ex1__Collection__

#include <stdio.h>
#include <vector>

/******************************************************************************************
 * Collection Class: This class gatheres objects that have been given to it.              *
 *                   The stored objects can later be iterated from the collection's       *
 *                   vector by using the iterator.                                        *
 *                   The class is a template to allow for different implementations       *
 *                   of this class and handling multiple collections - without virtual    *
 *                   inheritance (that will allow for only one copy of the collection.    *
 *                   This class takes the handling of memory deletion away from inherited *
 *                   classes and saves a lot of code. Most importantly - It allows for    *
 *                   classes that need direct access to the information stored without    *
 *                   making them friends with later classes that inherent from collection.*
 *                   Those classes can access the member variables without using a        *
 *                   special interface for it (like getShapes, getGameObjects, ect).      *
 *****************************************************************************************/

template<class T>
class Collection {
    
    //Needs access to draw to the screen
    friend class Drawer;
    
    //The actions needs access to change vertices position
    friend class Action;
    
private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    std::vector<T*> m_vcCollected;
    
protected:
    
    //  ---                         PROTECTED FUNCTIONS                       ---   //

    
    /**********************************************************************************************
     * function name: clearCollection                                                             *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Clears the objects stored in the current object                     *
     * *******************************************************************************************/
    
    void clearCollection();
    
    /**********************************************************************************************
     * function name: collect                                                                     *
     * The Input: const T object (pointer)                                                        *
     * The output: none                                                                           *
     * The Function Opertion: Stores the input object into the collection                         *
     * *******************************************************************************************/
    
    void collect(T* cCollected);
    
    /**********************************************************************************************
     * function name: dispense                                                                    *
     * The Input: const T object (pointer)                                                        *
     * The output: bool                                                                           *
     * The Function Opertion: Removes the input object from the collection. returns true if found,*
     *                        and deleted. false otherwise.                                       *
     * *******************************************************************************************/
    
    bool dispense(const T* cDispensed);
    
    /**********************************************************************************************
     * function name: internals                                                                   *
     * The Input: none                                                                            *
     * The output: const vector object (reference)                                                *
     * The Function Opertion: Returns a constant reference to the vector that contains the objects*
     * *******************************************************************************************/
    
    const std::vector<T*>& internals() const;
    
    /**********************************************************************************************
     * function name: mutables                                                                    *
     * The Input: none                                                                            *
     * The output: vector object (reference)                                                      *
     * The Function Opertion: Returns a reference to the vector that contains the objects         *
     * *******************************************************************************************/
    
    std::vector<T*>& mutables();
    
public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //

    
    /************************************************************************************************
     * function name: Collection Constructor                                                        *
     * The Input: none                                                                              *
     * The output: none                                                                             *
     * The Function Opertion: Constructor for the Collection class                                  *
     * *********************************************************************************************/
    
    Collection();
    
    /**********************************************************************************************
     * function name: Collection Destructor                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    virtual ~Collection();

};

#include "Collection.cpp"

#endif /* defined(__Ex1__Collection__) */
