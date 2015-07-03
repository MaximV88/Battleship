//
//  Tests.cpp
//  Ex1
//
//  Created by Maxim Vainshtein on 11/17/14.
//  Copyright (c) 2014 Maxim Vainshtein. All rights reserved.
//

#include "Tests.h"

#include "Point.h"
#include "Line.h"
#include "Rectangle.h"

#include "Ship.h"
#include "Map.h"
#include "GameObject.h"

#include "ActionRotateBy.h"
#include "ActionMoveBy.h"

using namespace std;

Test::Test() : m_cDrawer(Oblong(65,23)) {
    
}

Test::~Test() {
    
    
}

void Test::test_shape_collision() {
    
    //Test Shapes - With Shapes
    
    Line line = Line(Coordinate(0,4),Coordinate(18,6));
    m_cDrawer.add(line);
    
    Line crossing = Line(Coordinate(0, 10), Coordinate(10, 6));
    m_cDrawer.add(crossing);
    
    Line colliding = Line(Coordinate(5,10), Coordinate(5, 0));
    m_cDrawer.add(colliding);
    
    cout << "Shape: Should not collide: " << crossing.isOverlap(line) << endl;
    cout << "Shape: Should collide: " << colliding.isOverlap(crossing) << ", " << colliding.isOverlap(line) << ", " << line.isOverlap(colliding) << endl;
    
    //Test GameObjects - With Shapes
    
    Ship cShipFirst = Ship(ShipType2x3, ShipDirectionEast, Coordinate(10,10));
    m_cDrawer.add(cShipFirst);
    
    Line cCrossingLine = Line(Coordinate(12, 15), Coordinate(29, 0));
    m_cDrawer.add(cCrossingLine);
    
    Point cCrossingPoint = Point(Coordinate(10, 8));
    m_cDrawer.add(cCrossingPoint);
    
    cout << "GameObject: Should collide: " << cShipFirst.isOverlap(cCrossingLine) << endl;
    cout << "GameObject: Should not collide: " << cShipFirst.isOverlap(static_cast<const Shape&>(cCrossingPoint)) << endl;
    
    //Test GameObjects - With GameObjects
    
    Ship cShipSecond = Ship(ShipType1x4, ShipDirectionNorth, Coordinate(30,10));
    m_cDrawer.add(cShipSecond);
    
    Ship cShipThird = Ship(ShipType2x2, ShipDirectionWest, Coordinate(32, 10));
    m_cDrawer.add(cShipThird);

    Ship cShipFourth = Ship(ShipType1x3, ShipDirectionSouth, Coordinate(32, 9));
    m_cDrawer.add(cShipFourth);
    
    cout << "GameObject - GameObject: Should collide: " << cShipThird.isOverlap(cShipSecond) << endl;
    cout << "GameObject - GameObject: Should not collide: " << cShipThird.isOverlap(cShipFourth) << endl;
    
    //Test GameCollection - With Shapes
    
    Map cMap = Map(Coordinate(40, 0), 10, 10);
    m_cDrawer.add(cMap);
    
    Line cMappedLine = Line(Coordinate(35, 20), Coordinate(55, 18));
    m_cDrawer.add(cMappedLine);
    
    Point cMappedPoint = Point(Coordinate(51,19));
    m_cDrawer.add(cMappedPoint);
    
    cout << "GameCollection - Shape: Should collide: " << cMap.GameObject::isOverlap(cMappedLine) << endl;
    cout << "GameCollection - Shape: Should not collide: " << cMap.GameObject::isOverlap(static_cast<const Shape&>(cMappedPoint)) << endl;

    //Test GameCollection - With GameObject
    
    Ship cMappedShip = Ship(ShipType1x4, ShipDirectionNorth, Coordinate(51, 8));
    m_cDrawer.add(cMappedShip);
    
    Ship cMappedShipped = Ship(ShipType2x2, ShipDirectionWest, Coordinate(7, 7));
    cMap.addShip(cMappedShipped);
    
    Ship cCollidedShip = Ship(ShipType1x2, ShipDirectionEast, Coordinate(57,7));
    m_cDrawer.add(cCollidedShip);
    
    cout << "GameCollection - GameObject: Should collide: " << cMap.isOverlap(cMappedShip) << endl;
    cout << "GameCollection+GameObject - Should not collide: " << cMap.isOverlap(cMappedShipped) << endl;
    cout << "GameCollection+GameObject - GameObject: Should collide: " << cMap.isOverlap(cCollidedShip) << endl;

    
    m_cDrawer.draw();
    m_cDrawer.render();
    
}

void Test::test_shapes_gameObjects_actions() {
    
    Point p = Point(2, 2);
    Line *line = new Line(Coordinate(13,4),Coordinate(18,6));
    Rectangle rect = Rectangle(Coordinate(5,10), 5, 5);
    Rectangle *test = new Rectangle(Coordinate(2, 19), Oblong(6, 6));
    
    m_cDrawer.add(p);
    m_cDrawer.add(*line);
    m_cDrawer.add(rect);
    m_cDrawer.add(*test);
    
    Action *rotate = new ActionRotateBy(test, -45, Coordinate(2,19));
    
    rotate->apply();
    
    Action *move = new ActionMoveBy(test, 5, -1);
    move->apply();
    move->apply();
    move->apply();

    move->apply(line);
    
    Action *act = new ActionMoveBy(-4, -2);
    act->apply(&rect);
    
    Ship s(ShipType2x3, ShipDirectionSouth, Coordinate(10, 10));
    ActionRotateBy(&s, 45).Action::apply();
    
    Ship copy = s;
    m_cDrawer.add(copy);
    
    move->apply(&copy);
    
    Ship *testing = new Ship(copy);
    m_cDrawer.add(*testing);
    
    ActionRotateBy(testing, 0).Action::apply();
    ActionMoveBy(testing, 15, -4).Action::apply();
    
    m_cDrawer.add(s);
    
    m_cDrawer.draw();
    m_cDrawer.render();
    
    delete line;
    delete test;
    delete rotate;
    delete move;
    delete act;
    delete testing;

}

void Test::test_gameObject_shape_deletion() {
    
    Ship *testShip = new Ship(ShipType2x2, ShipDirectionEast, Coordinate(0,0));
    Rectangle *rect = new Rectangle(Coordinate(0,0), 100, 100);
    
    delete testShip;
    delete rect;
    
    Map map = Map(Coordinate(2,2), 14, 14);

    m_cDrawer.add(map);
    
    map.addShip(Ship(ShipType1x4, ShipDirectionEast, Coordinate(5,5)));
    map.addShip(Ship(ShipType2x2, ShipDirectionEast, Coordinate(2,2)));
    
    ActionRotateBy(-45, Coordinate(0,0)).apply(&map);
    ActionMoveBy(&map, -5, 12).Action::apply();
    
    Ship *tester = new Ship(ShipType1x3, ShipDirectionEast, Coordinate(1,0));
    
    map.addShip(*tester);
    delete tester;
    
    m_cDrawer.draw();
    m_cDrawer.render();
    
    
}

void Test::test_map_creation_display() {
    
    Map map = Map(Coordinate(0,0), 10, 10);
    m_cDrawer.add(map);

    map.addShip(Ship(ShipType2x3, ShipDirectionEast, Coordinate(2,6)));

    Ship *cTestShip = new Ship(ShipType2x2, ShipDirectionSouth, Coordinate(1,7));
 
    if (map.isValid(*cTestShip))
        map.addShip(*cTestShip);

    map.isAllHit();
    
    ActionMoveBy(&map, 0, 3).Action::apply();
 //   ActionRotateBy(-45, Coordinate(0,0)).apply(&map);

    m_cDrawer.draw();
    m_cDrawer.render();
 
  delete cTestShip;

}