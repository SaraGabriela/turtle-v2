#include "Flower.h"



void Flower::draw(string type, turtle & _tx) {
	if (type == "normal" || type == "Normal") {
		fl = new NorFlFactory;
	}

	else if (type == "girasol" || type == "Girasol") {
		fl = new GirasolFactory;
	}

	else {
		fl = new NorFlFactory;
	}

	CFlor* f = fl->buildFlor();
	
	f->printDetail(_tx,x,y,c);
}