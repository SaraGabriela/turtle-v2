#pragma once
#include "shapes.h"
#include "TreeBuilder.h"
#include <string>

class Tree : public shape
{
protected:
	Director dir;

public:
	Tree() {}
	~Tree(){}
	void draw(string type, turtle & _tx);
};
