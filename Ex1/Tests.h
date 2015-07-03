//
//  Tests.h
//  Ex1
//
//  Created by Maxim Vainshtein on 11/17/14.
//  Copyright (c) 2014 Maxim Vainshtein. All rights reserved.
//

#ifndef __Ex1__Tests__
#define __Ex1__Tests__

#include <stdio.h>
#include "Drawer.h"

class Test {
    
    Drawer m_cDrawer;
    
public:
    
    Test();
    ~Test();
    
    void test_shapes_gameObjects_actions();
    void test_gameObject_shape_deletion();
    void test_map_creation_display();
    void test_shape_collision();
    
};

#endif /* defined(__Ex1__Tests__) */
