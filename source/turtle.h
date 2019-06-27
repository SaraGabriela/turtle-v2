/** @file turtle.h
@author Sara Diaz Oporto
@version Revision 1.1
@brief Clase turtle que permite realizar graficos con un comportamiento similar a turtle python. 
*/

/**
@mainpage
Turtle Python se usa popularmente como una herramienta para aprender a programar.
Este codigo se asemeja a la tortuga de Python, implementado en c++.
Antes de empezar es necesario incluir la clase turtle e instanciar nuestra tortuga.
La tortuga empieza a dibujar desde la coordenada (0,0)
*/
#ifndef TURTLE_H
#define TURTLE_H



#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <stdio.h>
#include <vector>


/**
* @class   turtle
* @brief   Clase con funcionalidad similar a la tortuga de Python.
* @detail  Definicion de la funciones usadas en la clase.
*/
using namespace std;

class color {
protected:
	float _r;
	float _g;
	float _b;
public:
	color() { _r = 0; _g = 0; _b = 0; }
	color(float a, float b, float c) {
		_r = a; _g = b; _b = c;
	}
	float getR() { return _r; }
	float getG() { return _g; }
	float getB() { return _b; }
};

class rojo : public color {
	rojo() {
		_r = 255; _g = 0; _b = 0;
	}
};

class turtle
{
private:
	bool pen;
	GLdouble dir;
	GLdouble x;
	GLdouble y;
	float r;
	float g;
	float b;

	GLdouble Pi = 3.1415926535897932384626433832795;


public:

	/** Crear la turtle.
   *Empieza en la coordenada (0,0)
	*/
	turtle();
	~turtle();
	/** Funcion necesaria para empezar a dibujar.
   *Propiedades de la tortuga con la que dibujamos.
	*/
	void start();
	/** Crea la ventana donde se dibujara la turtle
	*Es necesaria para empezar a dibujar
	*/
	void setupWindow();
	/** Crea la ventana donde se dibujara la turtle con valores personalizados
	*  @param a es el ancho de la ventana
	*  @param b es el alto de la ventana
	*/
	void setupWindow(int a, int b);
	/** Avanzar una distancia determinada
	*  @param dis es la distancia que la tortuga va a recorrer
	*/
	void forward(double dis);
	/** Que la tortuga gire a la izquierda
	*  @param angle es el angulo que girara hacia la izquierda
	*/
	void left(GLdouble angle);
	/** Que la tortuga gire a la derecha
	*  @param angle es el angulo que girara hacia la derecha
	*/
	void right(GLdouble angle);
	/** Levanta el lapiz de dibujo
	*Mientras el lapiz este arriba, la tortuga no va a dibujar
	*/
	void penup();
	/** Baja el lapiz de dibujo
	*La tortuga va a dibujar solo cuando el lapiz este abajo
	*/
	void pendown();
	/** Ir a un punto en el plano
	*  @param x1 es la coordenada del punto en x
	*  @param y1 es la coordenada del punto en y
	*/
	void turtleGo(double x1, double y1);
	/** Cambiar el color del lapiz en RGB. (Por ejemplo: 000 es negro)
	*  @param _r es la cantidad de color rojo (de 0 a 255)
	*  @param _g es la cantidad de color verde (de 0 a 255)
	*  @param _b es la cantidad de color azul (de 0 a 255)
	*/
	void pencolor(float _r, float _g, float _b);
	/** Cambiar el color del lapiz en RGB. (Por ejemplo: 000 es negro)
	*  @param _c es un objeto de tipo color
	*/
	void pencolor(color _c);
	/** Funcion que se debe colocar antes de empezar una figura con relleno (coloreado) 
	*  Le sigue la funcion forwardFill() para empezar a dibujar
	*/
	void beginFill();
	/** Avanzar una distancia determinada dibujando una linea. Finalmente las lineas se conectarán y se dibuja una forma con relleno.
	*  @param dis es la distancia que la tortuga va a recorrer
	*/
	void forwardFill(double dis);
	/** Funcion que determina que se terminó un dibujo
	*  Se debe colocar al finalizar un dibujo con las funciones forward() o forwardFill()
	*/
	void end();
	/** Retorna la posicion de la tortuga en x
	*  
	*/
	double getPosx();
	/** Retorna la posicion de la tortuga en y
	*
	*/
	double getPosy();
};

#endif // !TURTLE_H