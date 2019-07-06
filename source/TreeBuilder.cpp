#include "TreeBuilder.h"

void TreeProduct::setHojas(string h) { hojas = h; }

void TreeProduct::setTronco(string t){ tronco = t; } 

void TreeProduct::setRamas(string r) { ramas = r; };

//void TreeProduct::setTurtleTree(turtle* _taux) { tpaux = _taux; }

//turtle* TreeProduct::getTurtleTree() { return tpaux; }

string TreeProduct::getHojas() { return hojas; }

string TreeProduct::getTronco() { return tronco; };

string TreeProduct::getRamas() { return ramas; }

void TreeBuilder::setTurtleB(turtle _t) { taux = _t; }

void NormalBuilder::getPartsBuild() { treeP = new TreeProduct("Normal Tree"); }


void NormalBuilder::buildHojas(color* & ch) {
	if (ch->getname() == "d") {
		taux.pencolor(121, 180, 115);
	}
	else {
		taux.pencolor(ch->getR(), ch->getG(), ch->getB());
	}

	float a = 250;
	while (a / 2 > 1) {
		taux.beginFill();
		taux.forwardFill(a/2);
		taux.left(120);
		taux.forwardFill(a);
		taux.left(120);
		taux.forwardFill(a);
		taux.left(120);
		taux.forwardFill(a/2);
		taux.left(90);
		taux.end();
		taux.forward(a/2);
		taux.right(90);
		taux.end();

		a = a - 50;
	}
	taux.penup();
	taux.right(90);
	taux.forward(380);
	taux.left(90);
	taux.forward(10);
	taux.pendown();


	treeP->setHojas("Hojas normales");
}

void NormalBuilder::buildTronco() {
	taux.pencolor(204, 88, 3);
	taux.penup();
	taux.left(90);
	taux.forward(100);
	taux.right(90);
	taux.pendown();
	taux.beginFill();
	taux.forwardFill(35);
	taux.right(90);
	taux.forwardFill(100);
	taux.right(90);
	taux.forwardFill(70);
	taux.right(90);
	taux.forwardFill(100);
	taux.right(90);
	taux.forwardFill(35);
	taux.end();
	treeP->setTronco("Tronco normal");
	//Dibujar tronco normal
}

void NormalBuilder::buildRamas() {
	taux.pencolor(0,0,0);
	/*taux.penup();
	taux.turtleGo(15, -200);
	taux.pendown();*/

	int b = 30;
		taux.right(90);
		taux.forward(b);
		taux.right(90);
		taux.penup();
		taux.forward(b);
		taux.left(90);
		taux.pendown();
		taux.forward(b);
		taux.left(90);
		taux.penup();
		taux.forward(b);
		taux.right(90);
		taux.pendown();
		taux.forward(b);
		taux.right(90);
		taux.penup();

	taux.end();
	treeP->setRamas("Ramas normales");
	//Dibujar ramas normales
}

void CherryBuilder::getPartsBuild() { treeP = new TreeProduct("Cherry Blossom Tree"); }

void CherryBuilder::buildHojas(color* & ch) {
	if (ch->getname() == "d") {
		taux.pencolor(255, 188, 181);
	}
	else {
		taux.pencolor(ch->getR(), ch->getG(), ch->getB());
	}
	taux.beginFill();
	for (int j = 0; j <= 12; j++) {
		taux.forwardFill(100);
		taux.left(360 / 12);
	}
	taux.end();
	taux.right(30);
	treeP->setHojas("Hojas de cerezo");

}

void CherryBuilder::buildTronco() {
	taux.pencolor(99, 55, 44);
	taux.penup();
	taux.left(90);
	taux.forward(90);
	taux.right(90);
	taux.pendown();
	taux.beginFill();
	taux.forwardFill(25);
	taux.right(90);
	taux.forwardFill(90);
	taux.right(90);
	taux.forwardFill(50);
	taux.right(90);
	taux.forwardFill(90);
	taux.right(90);
	taux.end();
	taux.penup();
	taux.left(180);
	taux.forward(25);
	taux.right(180);
	taux.pendown();
	treeP->setTronco("Tronco de cerezo");
	//Dibujar tronco normal
}

void CherryBuilder::buildRamas() {
	taux.pencolor(201, 125, 96);
	taux.penup();
	taux.left(180);
	taux.forward(40);
	taux.right(180);
	taux.pendown();
	int b = 20;
	taux.right(90);
	taux.forward(b);
	taux.right(90);
	taux.penup();
	taux.forward(b);
	taux.left(90);
	taux.pendown();
	taux.forward(b);
	taux.left(90);
	taux.penup();
	taux.forward(b);
	taux.right(90);
	taux.pendown();
	taux.forward(b);
	taux.right(90);
	taux.penup();

	taux.end();
	treeP->setRamas("Ramas de cerezo");
	//Dibujar ramas normales
}

TreeProduct* Director::createTree(TreeBuilder* builder, turtle _t, float _x, float _y, color* & cou) {
	_t.penup();
	_t.turtleGo(_x, _y);
	_t.pendown();
	//builder->treeColor(_co);
	builder->setTurtleB(_t);
	builder->getPartsBuild();
	builder->buildTronco();
	builder->buildHojas(cou);
	builder->buildRamas();
	return builder->getTreeProduct();
}