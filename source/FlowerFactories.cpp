#include "FlowerFactories.h"

Centro::Centro(string _forma) {
	forma = _forma;
	x = 0;
	y = 0;
};

string Centro::getForma() { return forma; }
void Centro::startPos(float _x, float _y) { x = _x; y = _y; }

void CentroNormal::drawCentro(turtle & _tur) {
	_tur.pencolor(233, 114, 76);
	_tur.turtleGo(-2, -2);
	_tur.beginFill();
	for (int j = 0; j <= 12; j++) {
		_tur.forwardFill(2);
		_tur.left(360 / 12);
	}
	_tur.end();
}

void CentroGirasol::drawCentro(turtle & _tur) {
	_tur.pencolor(233, 114, 76);
	_tur.turtleGo(-2, -2);
	_tur.beginFill();
	for (int j = 0; j <= 12; j++) {
		_tur.forwardFill(2);
		_tur.left(360 / 12);
	}
	_tur.end();
}

Petalo::Petalo(string _forma) {
	forma = _forma;
	x = 0;
	y = 0;
}

string Petalo::getForm() { return forma; }
void Petalo::startPos(float _x, float _y) { x = _x; y = _y; }

void PetaloNormal::drawPetalo(turtle & _tur) {
	_tur.pencolor(197, 40, 61);
	_tur.beginFill();
	for (int j = 0; j <= 6; j++) {
		_tur.forwardFill(4);
		_tur.left(360 / 18);
	}
	_tur.end();
	_tur.left(40);
	_tur.beginFill();
	for (int j = 0; j <= 6; j++) {
		_tur.forwardFill(4);
		_tur.left(360 / 18);
	}
	_tur.end();
}

void PetaloGirasol::drawPetalo(turtle & _tur) {
	_tur.pencolor(255, 200, 87);
	_tur.beginFill();
	for (int j = 0; j <= 6; j++) {
		_tur.forwardFill(4);
		_tur.left(360 / 18);
	}
	_tur.end();
	_tur.left(40);
	_tur.beginFill();
	for (int j = 0; j <= 6; j++) {
		_tur.forwardFill(4);
		_tur.left(360 / 18);
	}
	_tur.end();
}

void CFlor::setCentro(Centro * _ce) { ce = _ce; }
void CFlor::setPetalo(Petalo * _p) { p = _p; }
void CFlor::FlorPos(float _xa, float _ya) {
	xAr = _xa;
	yAr = _ya;
}

void CFlor::printDetail(turtle & _tur) {
	//cout << endl << "hoja de forma: " << h->getForma() << " y tronco " << Tr->getForm() << endl;
	ce->startPos(xAr, yAr);
	p->startPos(xAr, yAr);

	for (int k = 0; k < 5; k++) {
		p->drawPetalo(_tur);
		_tur.left(180);
	}

	ce->drawCentro(_tur);
	_tur.turtleGo(0, 0);
}

