#ifndef SHAPES_H
#define SHAPES_H

#include "turtle.h"
#include <iostream>
#include <string>
using namespace std;

class shape {
protected:
	float x, y;
//	color c;
public:
	virtual void draw(string t, turtle & _t) = 0;
	void setPosition(float _x = 0, float _y = 0);
//	void shapeColor(color _c) { c = _c; }
};


#endif // !SHAPES_H