/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Declaration of Drawer Class            *
 ***********************************************************/

#ifndef __Ex1__Drawer__
#define __Ex1__Drawer__

#include <stdio.h>
#include <vector>

#include "Screen.h"
#include "Coordinate.h"

class Vertex;
class Shape;
class GameObject;
class GameCollection;

class Drawer {
    

private:
    
    //  ---                         PRIVATE VARIABLES                       ---   //

    
    //Stores the screen
    Screen m_cScreen;
    
    //Vector that stores the shapes
    std::vector<Shape const*> m_vcShapes;
    
    //Vector that stores the GameObjects
    std::vector<GameObject const*> m_vcGameObjects;
    
    //Vector that stores the GameCollections
    std::vector<GameCollection const*> m_vcGameCollections;

    //  ---                         PRIVATE FUNCTIONS                       ---   //
    
    
    /**********************************************************************************************
     * function name: draw                                                                        *
     * The Input: const GameObject object (reference), const Coordinate object (reference)        *
     * The output: none                                                                           *
     * The Function Opertion: Draws the input GameObjects at the addition of Coordinate input     *
     *                        location on the screen.                                             *
     * *******************************************************************************************/
    
    void draw(const GameObject& cGameObject, const Coordinate& cCoordinate = Coordinate(0,0));
    
    /**********************************************************************************************
     * function name: draw                                                                        *
     * The Input: const Shape object (reference), const Coordinate object (reference)             *
     * The output: none                                                                           *
     * The Function Opertion: Draws the input Shape at the addition of Coordinate input           *
     *                        location on the screen.                                             *
     * *******************************************************************************************/
    
    void draw(const Shape& cShape, const Coordinate& cCoordinate = Coordinate(0,0));
    
    /**********************************************************************************************
     * function name: draw                                                                        *
     * The Input: const Vertex object (reference), const Coordinate object (reference)            *
     * The output: none                                                                           *
     * The Function Opertion: Draws the input Vertex at the addition of Coordinate input          *
     *                        location on the screen.                                             *
     * *******************************************************************************************/
    
    void draw(const Vertex& cVertex, const Coordinate& cCoordinate = Coordinate(0,0));

public:
    
    //  ---                         PUBLIC FUNCTIONS                       ---   //
    
    
    /************************************************************************************************
     * function name: Drawer Constructor                                                            *
     * The Input: const Oblong object (reference)                                                   *
     * The output: none                                                                             *
     * The Function Opertion: Initializes the object at the input size                              *
     * *********************************************************************************************/
    
    Drawer(const Oblong& cSize);
    
    /**********************************************************************************************
     * function name: Drawer Destructor                                                           *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Destroys the current object.                                        *
     * *******************************************************************************************/
    
    ~Drawer();
    
    /**********************************************************************************************
     * function name: draw                                                                        *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Draws the scene into the screen.                                    *
     * *******************************************************************************************/
    
    void draw();
    
    /**********************************************************************************************
     * function name: resize                                                                      *
     * The Input: const Oblong                                                                    *
     * The output: none                                                                           *
     * The Function Opertion: Resizes the Drawer to input size.                                   *
     * *******************************************************************************************/
    
    void resize(const Oblong& cSize);
    
    /**********************************************************************************************
     * function name: add                                                                         *
     * The Input: const Shape object (reference)                                                  *
     * The output: none                                                                           *
     * The Function Opertion: Adds the input to the drawer.                                       *
     * *******************************************************************************************/

    void add(Shape const& cShape);
    
    /**********************************************************************************************
     * function name: add                                                                         *
     * The Input: const GameObject object (reference)                                             *
     * The output: none                                                                           *
     * The Function Opertion: Adds the input to the drawer.                                       *
     * *******************************************************************************************/
    
    void add(GameObject const& cGameObject);
    
    /**********************************************************************************************
     * function name: add                                                                         *
     * The Input: const GameCollection object (reference)                                         *
     * The output: none                                                                           *
     * The Function Opertion: Adds the input to the drawer.                                       *
     * *******************************************************************************************/
    
    void add(GameCollection const& cGameCollection);
    
    /**********************************************************************************************
     * function name: remove                                                                      *
     * The Input: const Shape object (reference)                                                  *
     * The output: none                                                                           *
     * The Function Opertion: Remove the input from the drawer.                                   *
     * *******************************************************************************************/

    void remove(Shape const& cShape);
    
    /**********************************************************************************************
     * function name: remove                                                                      *
     * The Input: const GameObject object (reference)                                             *
     * The output: none                                                                           *
     * The Function Opertion: Remove the input from the drawer.                                   *
     * *******************************************************************************************/
    
    void remove(GameObject const& cGameObject);
    
    /**********************************************************************************************
     * function name: remove                                                                      *
     * The Input: const GameCollection object (reference)                                         *
     * The output: none                                                                           *
     * The Function Opertion: Remove the input from the drawer.                                   *
     * *******************************************************************************************/
    
    void remove(GameCollection const& cGameCollection);

    /**********************************************************************************************
     * function name: clear                                                                       *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Clears any object that has been previously added.                   *
     * *******************************************************************************************/
    
    void clear();
    
    /**********************************************************************************************
     * function name: render                                                                      *
     * The Input: none                                                                            *
     * The output: none                                                                           *
     * The Function Opertion: Prints to the Terminal the stored objects                           *
     * *******************************************************************************************/

    void render() const;
    
};

#endif
