#ifndef SHAPES_H
#define SHAPES_H

#include "turtle.h"
#include <iostream>
#include <string>
using namespace std;

class shape {
protected:
	float x, y;
public:
	virtual void draw(string t, turtle & _t) = 0;
	void setPosition(float _x = 0, float _y = 0);
};


#endif // !SHAPES_H