
#ifndef SHAPESFACTORY_H
#define SHAPESFACTORY_H

#include <iostream>
#include "Tree.h"
#include "Flower.h"
#include "Snow.h"
#include "shapes.h"

using namespace std;

/**
* @class   shapesFactory
* @brief   Clase que crea figuras
* @detail  La figura dibujada depende del tipo de forma indicada
*/
class shapesFactory {
public:
	/** Retorna el puntero a una shape
	*  @param ty es el tipo de figura a dibujar
	*/
	static shape * createShape(string ty);

};

/**
* @class   turtleShapes
* @brief   Clase que dibuja figuras usando una turtle
* @detail  Dibuja la forma segun el tipo indicado, usando una tortuga existente
*/
class turtleShapes { 
protected:
	turtle aux;
public:
	/** Indicamos con que tortuga se van a realizar los dibujos
	*  @param tur es el nombre de la tortuga con la que se empezara a dibujar
	*/
	turtleShapes(turtle tur);
	/** Dibuja un arbol en la pantalla
	*  @param st es el tipo de arbol a dibujar
	*  @param _x es la ubicacion en x donde se empieza a dibujar el arbol
	*  @param _y es la ubicacion en y donde se empieza a dibujar el arbol
	*/
	void turtleTree(string st,float _x, float y);
	//void turtleTree(string st, float _x, float _y, color _c);
	/** Dibuja una flor en la pantalla
	*  @param st es el tipo de flor a dibujar
	*  @param _x es la ubicacion en x donde se empieza a dibujar la flor
	*  @param _y es la ubicacion en y donde se empieza a dibujar la flor
	*/
	void turtleFlower(string st, float _x, float _y);
	/** Dibuja nieve en la pantalla
	*  @param st es el tipo de nieve a dibujar
	*/
	void turtleSnow(string st);
};
#endif // !SHAPESFACTORY_H

