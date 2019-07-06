#include "Shape.h"
#include "Tree.h"
#include "Flower.h"
#include "Snow.h"

class ShapeCreate
{
public:
	Shape * getShape(string type) {
		if (type == "Tree") {
			return new Tree();
		}
		
		else if (type == "Flower") {
			return new Flower();
		}

		else if (type == "Snow") {
			return new Snow();
		}
		else {
			return NULL;
		}


	}
};