#pragma once
#include "shapes.h"
#include "FlowerFactories.h"
#include <string>

class Flower :	public shape
{
protected:
	FlowerFactory * fl;
public:
	Flower(){}
	~Flower(){}
	void draw(string type, turtle & _tx);
};

