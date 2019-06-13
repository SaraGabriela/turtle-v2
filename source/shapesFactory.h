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

class turtleShapes { //TERMINAR RECORRIDO PARA SABER COMO SE IMPLEMENTARÍA ESTA FUNCION. PI EN SA
protected:
	turtle aux;
public:
	turtleShapes(turtle tur);
	void turtleTree(string st);
	void turtleFlower(string st);
	void turtleSnow(string st);
};
#endif // !SHAPESFACTORY_H

