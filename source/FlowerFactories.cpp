#include "FlowerFactories.h"

Centro::Centro(string _forma) {
	forma = _forma;
	x = 0;
	y = 0;
};

string Centro::getForma() { return forma; }

void CentroNormal::drawCentro(turtle & _tur) {
	_tur.pencolor(233, 114, 76);
	_tur.beginFill();
	for (int j = 0; j <= 12; j++) {
		_tur.forwardFill(7.5);
		_tur.left(360 / 12);
	}
	_tur.end();
}

void CentroGirasol::drawCentro(turtle & _tur) {
	_tur.pencolor(109, 69, 35);
	_tur.penup();
	_tur.left(90);
	_tur.forward(10);
	_tur.left(90);
	_tur.forward(20);
	_tur.right(180);
	_tur.pendown();
	_tur.beginFill();
	for (int j = 0; j <= 40; j++) {
		_tur.forwardFill(30);
		_tur.left(150);
	}
	_tur.end();
}

Petalo::Petalo(string _forma) {
	forma = _forma;
	x = 0;
	y = 0;
}

string Petalo::getForm() { return forma; }

void PetaloNormal::drawPetalo(turtle & _tur, color* & cp) {
	if (cp->getname() == "d") {
		_tur.pencolor(197, 40, 61);
	}
	else {
		_tur.pencolor(cp->getR(), cp->getG(), cp->getB());
	}
	_tur.beginFill();
	for (int j = 0; j <= 6; j++) {
		_tur.forwardFill(15);
		_tur.left(360 / 18);
	}
	_tur.end();
	_tur.left(40);
	_tur.beginFill();
	for (int j = 0; j <= 6; j++) {
		_tur.forwardFill(15);
		_tur.left(360 / 18);
	}
	_tur.end();
}

void PetaloGirasol::drawPetalo(turtle & _tur, color* & cp) {
	if (cp->getname() == "d") {
		_tur.pencolor(255, 200, 87);
	}
	else {
		_tur.pencolor(cp->getR(), cp->getG(), cp->getB());
	}
	_tur.beginFill();
	for (int j = 0; j <= 8; j++) {
		_tur.forwardFill(10);
		_tur.left(360 / 40);
	}
	_tur.end();
	_tur.left(95);
	_tur.beginFill();
	for (int j = 0; j <= 8; j++) {
		_tur.forwardFill(10);
		_tur.left(360 / 40);
	}
	_tur.end();
}

void CFlor::setCentro(Centro * _ce) { ce = _ce; }
void CFlor::setPetalo(Petalo * _p) { p = _p; }

void CFlor::printDetail(turtle & _tur, float _x, float _y, color* & coo) {
	//cout << endl << "hoja de forma: " << h->getForma() << " y tronco " << Tr->getForm() << endl;

	_tur.penup();
	_tur.turtleGo(_x, _y);
	_tur.pendown();
	for (int k = 0; k < 5; k++) {
		p->drawPetalo(_tur,coo);
		_tur.left(180);
	}
	_tur.penup();
	_tur.turtleGo(_x, _y);
	_tur.right(90);
	_tur.forward(15);
	_tur.left(90);
	_tur.pendown();
	ce->drawCentro(_tur);
//	_tur.turtleGo(0, 0);
}

