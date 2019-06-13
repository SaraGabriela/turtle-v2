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

#pragma once
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

	void start();

	void setupWindow();
	void setupWindow(int a, int b);

	void forward(double dis);
	void left(GLdouble angle);
	void right(GLdouble angle);
	void penup();
	void pendown();
	void turtleGo(double x1, double y1);
	void pencolor(float _r, float _g, float _b);
	void beginFill();
	void forwardFill(double dis);
	void end();
	double getPosx();
	double getPosy();
};