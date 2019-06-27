#pragma once
#ifndef SHAPESFACTORY_H
#define SHAPESFACTORY_H

#include <iostream>
#include "Tree.h"
#include "Flower.h"
#include "Snow.h"
#include "shapes.h"

using namespace std;


class shapesFactory {
public:
	static shape * createShape(string ty);

};

class turtleShapes { 
protected:
	turtle aux;
public:
	turtleShapes(turtle tur);
	void turtleTree(string st,float _x, float y);
	//void turtleTree(string st, float _x, float _y, color _c);
	void turtleFlower(string st, float _x, float _y);
	void turtleSnow(string st);
};
#endif // !SHAPESFACTORY_H

