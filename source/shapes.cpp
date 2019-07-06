#include "shapes.h"

void shape::setPosition(float _x, float _y) {
	x = _x;
	y = _y;
}

void shape::setColor(color* & cc) {
	c = cc;
}