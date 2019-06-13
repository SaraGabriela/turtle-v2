#pragma once
#include "shapes.h"
#include "SnowFactory.h"
#include <stdlib.h>

class Snow : public shape
{
private:
//	SnowFactory* f = new SnowFactory;
public:
	Snow();
	~Snow();
	void draw(string type, turtle & _tt);
};

