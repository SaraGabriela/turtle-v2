#include "shapesFactory.h"

shape* shapesFactory::createShape(string ty) {
	shape * s = NULL;
	if (ty == "tree") {
		s = new Tree;
	}
	else if (ty == "flower") {
		s = new Flower;
	}
	else if (ty == "snow") {
		s = new Snow;
	}
	else {
		cout << "Nombre no válido";
	}
	//set shape turtle to _tu

	return s;
}

turtleShapes::turtleShapes(turtle tur) {
	aux = tur;
}

void turtleShapes::turtleTree(string st, float _x, float _y) { //Hacer metodos que incluyen color y pos
	shape * n = shapesFactory::createShape("tree");
	n->setPosition(_x,_y);
	n->draw(st,aux);
}

/*
void turtleShapes::turtleTree(string st, float _x, float _y, color _c) {
	shape * n = shapesFactory::createShape("tree");
	n->shapeColor(_c);
	n->setPosition(_x, _y);
	n->draw(st, aux);
}*/

void turtleShapes::turtleFlower(string st, float _x, float _y) {
	shape * n = shapesFactory::createShape("flower");
	n->setPosition(_x, _y);
	n->draw(st, aux);
}

void turtleShapes::turtleSnow(string st) {
	shape *s = shapesFactory::createShape("snow");
	s->draw(st, aux);
}