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

void NormalBuilder::buildHojas() {
	taux.pencolor(121, 180, 115);
	taux.right(90);
	taux.penup();
	taux.forward(50);
	taux.pendown();
	taux.left(90);
	taux.end();

	float a = 50.0;
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

		a = a - 10;
	}



	treeP->setHojas("Hojas normales");
}

void NormalBuilder::buildTronco() {
	taux.pencolor(204, 88, 3);
	taux.penup();
	taux.turtleGo(0, -50);
	taux.pendown();
	taux.beginFill();
	taux.forwardFill(7.5);
	taux.right(90);
	taux.forwardFill(30);
	taux.right(90);
	taux.forwardFill(15);
	taux.right(90);
	taux.forwardFill(30);
	taux.right(90);
	taux.end();
	treeP->setTronco("Tronco normal");
	//Dibujar tronco normal
}

void NormalBuilder::buildRamas() {
	taux.pencolor(0,0,0);
	taux.penup();
	taux.turtleGo(5, -50);
	taux.pendown();

		taux.right(90);
		taux.forward(10);
		taux.right(90);
		taux.penup();
		taux.forward(10);
		taux.left(90);
		taux.pendown();
		taux.forward(10);
		taux.left(90);
		taux.penup();
		taux.forward(10);
		taux.right(90);
		taux.pendown();
		taux.forward(10);
		taux.right(90);
		taux.penup();

	taux.end();
	treeP->setRamas("Ramas normales");
	//Dibujar ramas normales
}

void CherryBuilder::getPartsBuild() { treeP = new TreeProduct("Cherry Blossom Tree"); }

void CherryBuilder::buildHojas() {
	taux.pencolor(255, 188, 181);
	taux.beginFill();
	for (int j = 0; j <= 12; j++) {
		taux.forwardFill(20);
		taux.left(360 / 12);
	}
	taux.end();
	treeP->setHojas("Hojas de cerezo");

}

void CherryBuilder::buildTronco() {
	taux.pencolor(99, 55, 44);
	taux.penup();
	taux.turtleGo(10, 0);
	taux.pendown();
	taux.beginFill();
	taux.forwardFill(5);
	taux.right(90);
	taux.forwardFill(30);
	taux.right(90);
	taux.forwardFill(10);
	taux.right(90);
	taux.forwardFill(30);
	taux.right(90);
	taux.end();
	treeP->setTronco("Tronco de cerezo");
	//Dibujar tronco normal
}

void CherryBuilder::buildRamas() {
	taux.pencolor(201, 125, 96);
	taux.penup();
	taux.turtleGo(13,0);
	taux.pendown();

	taux.right(90);
	taux.forward(7);
	taux.right(90);
	taux.penup();
	taux.forward(7);
	taux.left(90);
	taux.pendown();
	taux.forward(7);
	taux.left(90);
	taux.penup();
	taux.forward(7);
	taux.right(90);
	taux.pendown();
	taux.forward(7);
	taux.right(90);
	taux.penup();

	taux.end();
	treeP->setRamas("Ramas de cerezo");
	//Dibujar ramas normales
}

TreeProduct* Director::createTree(TreeBuilder* builder, turtle _t) {

	builder->setTurtleB(_t);
	builder->getPartsBuild();
	builder->buildHojas();
	builder->buildTronco();
	builder->buildRamas();
	return builder->getTreeProduct();
}