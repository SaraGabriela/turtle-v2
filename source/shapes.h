#ifndef SHAPES_H
#define SHAPES_H

#include "turtle.h"
#include <iostream>
#include <string>
using namespace std;

/**
* @class   shape
* @brief   Clase de figuras
* @detail  Clase padre de diferentes figuras
*/
class shape {
protected:
	float x, y;
	color* c;
public:
	/** Dibujar la forma seleccionada. Funciona de manera diferente para cada forma.
	*  @param t es una cadena que indica el tipo de figura
	*  @param _t nos indica que tortuga será usada para dibujar nuestra figura
	*/
	virtual void draw(string t, turtle & _t) = 0;
	/** Define la posición de la figura
	*  @param _x nos indica en donde estará ubicada respecto al eje x.
	*  @param _y nos indica en donde estará ubicada respecto al eje y.
	*/
	void setPosition(float _x = 0, float _y = 0);
//	void shapeColor(color _c) { c = _c; }
	void setColor(color* & cc);
};


#endif // !SHAPES_H