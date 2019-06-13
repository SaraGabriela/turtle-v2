#include "Flower.h"



Flower::Flower()
{
}


Flower::~Flower()
{
}

void Flower::draw(string type, turtle & _tx) {
	cout << "Dibujar flor en pos" << x << " " << y;


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

	if (x != 0 && y != 0) { f->FlorPos(x / 100, y / 100); }
	else if (x == 0 && y != 0) { f->FlorPos(x , y / 100); }
	else if (x != 0 && y == 0) { f->FlorPos(x / 100, y); }
	f->printDetail(_tx);
}