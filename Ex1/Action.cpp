/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex1                                    *
 * File description: Implementation of Action Class         *
 ***********************************************************/

#include "Action.h"

//  ---                         PUBLIC FUNCTIONS                       ---   //


/************************************************************************************************
 * function name: Action Constructor                                                            *
 * The Input: none                                                                              *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object with targets as NULL                           *
 * *********************************************************************************************/

Action::Action() : m_cTargetShape(NULL), m_cTargetGameObject(NULL), m_cTargetGameCollection(NULL) { }

/************************************************************************************************
 * function name: Action Constructor                                                            *
 * The Input: Shape object (pointer)                                                            *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object and stores the shape member variable with the  *
 *                        input object, and the rest of the targest as NULL.                    *
 * *********************************************************************************************/

Action::Action(Shape* cTarget) : m_cTargetShape(cTarget), m_cTargetGameCollection(NULL), m_cTargetGameObject(NULL) { }

/************************************************************************************************
 * function name: Action Constructor                                                            *
 * The Input: GameObject object (pointer)                                                       *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object and stores the GameObject member               *
 *                        variable with the input object, and the rest of the targest as NULL.  *
 * *********************************************************************************************/

Action::Action(GameObject* cTarget) : m_cTargetGameObject(cTarget), m_cTargetGameCollection(NULL), m_cTargetShape(NULL) { }

/************************************************************************************************
 * function name: Action Constructor                                                            *
 * The Input: GameCollection object (pointer)                                                   *
 * The output: none                                                                             *
 * The Function Opertion: Initializes the object and stores the GameCollection member           *
 *                        variable with the input object, and the rest of the targest as NULL.  *
 * *********************************************************************************************/

Action::Action(GameCollection* cTarget) : m_cTargetGameCollection(cTarget), m_cTargetGameObject(NULL), m_cTargetShape(NULL) { }

/**********************************************************************************************
 * function name: Action Destructor                                                           *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: Destroys the current object.                                        *
 * *******************************************************************************************/

Action::~Action() { }

/**********************************************************************************************
 * function name: apply                                                                       *
 * The Input: none                                                                            *
 * The output: none                                                                           *
 * The Function Opertion: First tries to apply the target to shape, if not found then tries   *
 *                        to apply to a GameObject. If not found then tries to apply to a     *
 *                        GameCollection. Otherwise doesnt apply to anything. The assumption  *
 *                        is that there is at most one target to the Action.                  *
 * *******************************************************************************************/

void Action::apply() {
    
   if (m_cTargetShape != NULL)
       apply(m_cTargetShape);
   else if (m_cTargetGameObject != NULL)
       apply(m_cTargetGameObject);
   else if (m_cTargetGameCollection != NULL)
       apply(m_cTargetGameCollection);
    
}

/**********************************************************************************************
 * function name: apply                                                                       *
 * The Input: Shape object (pointer)                                                          *
 * The output: none                                                                           *
 * The Function Opertion: Iterates the Vertices stored in the shape (through the friend access*
 *                        given from the collection class), and updates every vertex.         *
 * *******************************************************************************************/

void Action::apply(Shape *cTarget) {
    
    //Since being applied to a shape, there is no origin to consider - thus an action must affect the shape
    for (std::vector<Vertex*>::iterator iter = cTarget->m_vcCollected.begin() ; iter != cTarget->m_vcCollected.end() ; iter++) {
            
        update(*iter);
            
    }
        
    
}

/**********************************************************************************************
 * function name: apply                                                                       *
 * The Input: GameObject object (pointer)                                                     *
 * The output: none                                                                           *
 * The Function Opertion: Checks if there is need to update the vertices. If yes, then it     *
 *                        iterates through all of the stored shapes in the GameObjects and    *
 *                        updates it. Afterwards it checks if the Origin needs to be updated. *
 *                        If yes, it updates the GameObject's origin. Otherwise not.          *
 * *******************************************************************************************/

void Action::apply(GameObject *cTarget) {
    
    if (applyToVertices()) {
        
        //First move the vertices
        for (std::vector<Shape*>::iterator iter = cTarget->m_vcCollected.begin() ;
             iter != cTarget->m_vcCollected.end();
             iter++) {
            
            apply(*iter);
            
        }
        
    }
    
    //And update the Coordinate of the GameObject
    if (applyToOrigin())
        update(cTarget);
    
}

/**************************************************************************************************
 * function name: apply                                                                           *
 * The Input: GameCollection object (pointer)                                                     *
 * The output: none                                                                               *
 * The Function Opertion: Checks if there is need to update the vertices. If yes, then it         *
 *                        iterates through all of the stored GameObjects in the GameCollection    *
 *                        and updates it. Afterwards it checks if the Origin needs to be updated. *
 *                        If yes, it updates the GameCollection's origin. Otherwise not.          *
 * ***********************************************************************************************/

void Action::apply(GameCollection *cTarget) {
    
    //Move every GameObject contained in the GameCollection
    if (applyToVertices()) {
        
        for (std::vector<GameObject*>::iterator iter = cTarget->Collection<GameObject>::m_vcCollected.begin() ;
             iter != cTarget->Collection<GameObject>::m_vcCollected.end() ;
             iter++) {
            
            apply(*iter);
            
        }
        
        //Update the origin of the collection. Without a modelview matrix, this is necessery
        apply(static_cast<GameObject*>(cTarget));
        
    }
    
    //And treat the object as a GameObject - all vertices will be updated
    if (applyToOrigin())
        apply(static_cast<GameObject*>(cTarget));
    
}
