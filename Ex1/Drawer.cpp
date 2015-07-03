/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Drawer Class         *
 ***********************************************************/

#include "Drawer.h"
#include "Shape.h"
#include "GameObject.h"
#include "GameCollection.h"

//  ---                         PRIVATE FUNCTIONS                       ---   //


/**********************************************************************************************
 * function name: draw                                                                        *
 * The Input: const GameObject object (reference), const Coordinate object (reference)        *
 * The output: none                                                                           *
 * The Function Opertion: Iterates through all of the stored Shapes in the recieved GameObject*
 *                        and draws every shape with the addition of the input coordinate     *
 *                        and the origin of the GameObject.                                   *
 * *******************************************************************************************/

void Drawer::draw(const GameObject& cGameObject, const Coordinate& cCoordinate) {
    
    //Iterate through all of the GameObjects contained in this collection
    for (std::vector<Shape*>::const_iterator iter = cGameObject.m_vcCollected.begin() ; iter != cGameObject.m_vcCollected.end() ; iter++) {
        
        //Add the coordiante of the origin of the GameObject with the displacement input to the drawn shape
        draw(**iter,  cCoordinate + cGameObject);
        
    }
    
}

/**********************************************************************************************
 * function name: draw                                                                        *
 * The Input: const Shape object (reference), const Coordinate object (reference)             *
 * The output: none                                                                           *
 * The Function Opertion: Iterates through all of the stored Vertices in the recieved Shape   *
 *                        and draws every Vertex with the addition of the input coordinate.   *
 * *******************************************************************************************/

void Drawer::draw(const Shape& cShape, const Coordinate& cCoordinate) {
    
    //Iterate through all of the Vertices contained in this collection
    for (std::vector<Vertex*>::const_iterator iter = cShape.m_vcCollected.begin() ; iter != cShape.m_vcCollected.end() ; iter++) {
        
        //Add the coordiante of the origin of the GameObject with the displacement input to the drawn shape
        draw(**iter, cCoordinate);
        
    }
    
}

/***********************************************************************************************
 * function name: draw                                                                         *
 * The Input: const Vertex object (reference), const Coordinate object (reference)             *
 * The output: none                                                                            *
 * The Function Opertion: Sets the pixel in the screen object at the input position (coordinate*
 *                        and origin of vertex) with the vertex's representation.              *
 * ********************************************************************************************/

void Drawer::draw(const Vertex& cVertex, const Coordinate& cCoordinate) {
    
    //And update the screen with it's information
    m_cScreen.setPixel(cVertex.getRepresentation(), cCoordinate + cVertex);
    
}

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Drawer Constructor                                                            *
 * The Input: const Oblong object (reference)                                                   *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the screen object with the input size.                    *
 * *********************************************************************************************/

Drawer::Drawer(const Oblong& cSize) : m_cScreen(cSize) { }

/**********************************************************************************************
 * function name: Drawer Destructor                                                           *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

Drawer::~Drawer() { }

/**********************************************************************************************
 * function name: draw                                                                        *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: First iterates through the stored GameCollections, and sends every  *
 *                        stored gameobject in them to be drawn, and draws the GameCollection *
 *                        itself. Afterwards it sends to draw the stored GameObjects, and     *
 *                        lastly the stored shapes are sent to be drawn.                      *
 * *******************************************************************************************/

void Drawer::draw() {
    
    //Start with the GameCollections
    for (std::vector<GameCollection const*>::const_iterator iter = m_vcGameCollections.begin() ; iter != m_vcGameCollections.end() ; iter++) {
        
        //Iterate through all of the GameObjects contained in this collection
        for (std::vector<GameObject*>::const_iterator runner = (*iter)->Collection<GameObject>::m_vcCollected.begin() ; runner != (*iter)->Collection<GameObject>::m_vcCollected.end() ; runner++) {
            
            draw(**runner, **iter);
            
        }
        
        //And the shapes that are contained in it (since its also a GameObject)
        for (std::vector<Shape*>::const_iterator runner = (*iter)->GameObject::m_vcCollected.begin() ; runner != (*iter)->GameObject::m_vcCollected.end() ; runner++) {
            
            draw(**runner, **iter);
            
        }
        
    }
    
    //Continue with the GameObjects
    for (std::vector<GameObject const*>::const_iterator iter = m_vcGameObjects.begin() ; iter != m_vcGameObjects.end() ; iter++) {
        
        //Iterate through all of the Shapes contained in this collection
        for (std::vector<Shape*>::const_iterator runner = (*iter)->m_vcCollected.begin() ; runner != (*iter)->m_vcCollected.end() ; runner++) {
            
            draw(**runner, **iter);
            
        }
        
    }
    
    //End with the Shapes
    for (std::vector<Shape const*>::const_iterator iter = m_vcShapes.begin() ; iter != m_vcShapes.end() ; iter++) {
        
        //Iterate through all of the GameObjects contained in this collection
        for (std::vector<Vertex*>::const_iterator runner = (*iter)->m_vcCollected.begin() ; runner != (*iter)->m_vcCollected.end() ; runner++) {
            
            draw(**runner);
            
        }
        
    }
    
}


/**********************************************************************************************
 * function name: resize                                                                      *
 * The Input: const Oblong                                                                    *
 * The output: none                                                                           *
 * The Function Opertion: Resizes the screen to input size.                                   *
 * *******************************************************************************************/

void Drawer::resize(const Oblong& cSize) {
    
    m_cScreen.resize(cSize);
    
}

/**********************************************************************************************
 * function name: add                                                                         *
 * The Input: const Shape object (reference)                                                  *
 * The output: none                                                                           *
 * The Function Opertion: Adds the input to the Shape vector.                                 *
 * *******************************************************************************************/

//Shapes are collections of vertices
void Drawer::add(Shape const& cShape) {

    m_vcShapes.push_back(&cShape);
    
}

/**********************************************************************************************
 * function name: add                                                                         *
 * The Input: const GameObject object (reference)                                             *
 * The output: none                                                                           *
 * The Function Opertion: Adds the input to the GameObject vector.                            *
 * *******************************************************************************************/

void Drawer::add(GameObject const& cGameObject) {
    
    m_vcGameObjects.push_back(&cGameObject);
    
}

/**********************************************************************************************
 * function name: add                                                                         *
 * The Input: const GameCollection object (reference)                                         *
 * The output: none                                                                           *
 * The Function Opertion: Adds the input to the GameCollection vector.                        *
 * *******************************************************************************************/

void Drawer::add(GameCollection const& cGameCollection) {
    
    m_vcGameCollections.push_back(&cGameCollection);

}

/**********************************************************************************************
 * function name: remove                                                                      *
 * The Input: const Shape object (reference)                                                  *
 * The output: none                                                                           *
 * The Function Opertion: Iterate through all of the contained shapes, and once a matching    *
 *                        object to input (using the pointer address) it erases it and stops  *
 *                        the iteration.                                                      *
 * *******************************************************************************************/

void Drawer::remove(Shape const& cShape) {

    for (std::vector<Shape const*>::iterator iter = m_vcShapes.begin() ; iter != m_vcShapes.end() ; iter++) {
        
        //Once we find the shape by it's pointer
        if ((*iter) == &cShape) {
            
            m_vcShapes.erase(iter);
            break;
            
        }
        
    }
    
}

/***********************************************************************************************
 * function name: remove                                                                       *
 * The Input: const GameObject object (reference)                                              *
 * The output: none                                                                            *
 * The Function Opertion: Iterate through all of the contained GameObjects, and once a matching*
 *                        object to input (using the pointer address) it erases it and stops   *
 *                        the iteration.                                                       *
 * ********************************************************************************************/

void Drawer::remove(GameObject const& cGameObject) {
    
    for (std::vector<GameObject const*>::iterator iter = m_vcGameObjects.begin() ; iter != m_vcGameObjects.end() ; iter++) {
        
        //Once we find the shape by it's pointer
        if ((*iter) == &cGameObject) {
            
            m_vcGameObjects.erase(iter);
            break;
            
        }
        
    }
    
}

/****************************************************************************************************
 * function name: remove                                                                            *
 * The Input: const GameCollection object (reference)                                               *
 * The output: none                                                                                 *
 * The Function Opertion: Iterate through all of the contained GameCollections, and once a matching *
 *                        object to input (using the pointer address) it erases it and stops        *
 *                        the iteration.                                                            *
 * *************************************************************************************************/

void Drawer::remove(GameCollection const& cGameCollection) {
    
    for (std::vector<GameCollection const*>::iterator iter = m_vcGameCollections.begin() ; iter != m_vcGameCollections.end() ; iter++) {
        
        //Once we find the shape by it's pointer
        if ((*iter) == &cGameCollection) {
         
            m_vcGameCollections.erase(iter);
            break;
            
        }
    
    }
    
}

/**********************************************************************************************
 * function name: clear                                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Clears all of the vectors.                                          *
 * *******************************************************************************************/

void Drawer::clear() {
    
    //We just clear all the vectors
    m_vcShapes.clear();
    m_vcGameObjects.clear();
    m_vcGameCollections.clear();
    
}

/**********************************************************************************************
 * function name: render                                                                      *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Calls the stored screen to print it's content.                      *
 * *******************************************************************************************/

void Drawer::render() const {
    
    //We tell the screen to print the input that we have placed in it
    m_cScreen.print();
    
}
