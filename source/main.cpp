/** @file main.cpp
@author Sara Diaz Oporto
@version Revision 1.1
@brief Clase turtle que permite realizar graficos con un comportamiento similar a turtle python.
*/
#include <iostream>
#include "shapesFactory.h"


using namespace std;

turtle t;
turtleShapes turF(t);

//COLORES PREDEFINIDOS
//color rojo(255, 0, 0);
//color azul(0, 0, 255);

void draw() {


//	turF.turtleTree("normal",-400,0);
//	turF.turtleTree("cerezo", 400, 0);
//	turF.turtleTree("cerezo");
//	turF.turtleFlower("normal",100,0);
/*	turF.turtleFlower("girasol",50,0);
	turF.turtleSnow("nieve");*/
/*	int a = 0;
	for (int i = 0; i < 10; i++) {
		t.penup();
		t.turtleGo(a, 0);
		t.right(90);
		t.pendown();
		t.forward(800);
		a = a + 50;
	}
	t.end();*/
		/*
	t.forward(60);
	t.end();*/

	glFlush();
}

void MyKeyboardFunc(unsigned char Key, int x, int y)
{
	float ax, ay;
	string _typ;
	bool fr = 0;
	switch (Key)
	{
	case 'a':
		cout << "Ingrese tipo de arbol [normal o cerezo]: ";
		cin >> _typ;
		cout << "Ingrese coordenadas para arbol: ";
		cin >> ax >> ay;
		turF.turtleTree(_typ, ax, ay);
		glutPostRedisplay();
		break;

	case 'f':
		cout << "Ingrese tipo de flor [normal o girasol]: ";
		cin >> _typ;
		cout << "Ingrese coordenadas para flor: ";
		cin >> ax >> ay;
		turF.turtleFlower(_typ, ax, ay);
		glutPostRedisplay();
		break;
	case 'n':
		cout << "Ingrese tipo de nieve [normal]: ";
		cin >> _typ;
		turF.turtleSnow(_typ);
		glutPostRedisplay();
		break;
	case 'c':
		glColor3f(0.78, 0.78, 0.78);
		glClear(GL_COLOR_BUFFER_BIT);
		string st = "'a' para dibujar un arbol | 'f' para dibujar una flor | 'n' para dibujar nieve";
		int i, l;
		l = st.length();
		glRasterPos2f(-0.9, 0.9);
		for (i = 0; i < l; i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, st[i]);
		}

		st = "'c' para limpiar la pantalla";
		l = st.length();
		glRasterPos2f(-0.9, 0.85);
		for (i = 0; i < l; i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, st[i]);
		}
		glutPostRedisplay();
		glColor3f(0,0,0);
		cout << "Se limpio la pantalla " << endl;
		break;
	/*case'r':
		if (fr == 0) {
			cout << "A partir de ahora todo se dibujara de color rojo" << endl;
		}*/
	}
}

int main()
{
	t.start();
	t.setupWindow();

//	glutKeyboardFunc(*keyboard);
	glutKeyboardFunc(MyKeyboardFunc);
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}

//BRIDGE CON IMPLEMENTOR PARA COLORES
//HACER UN MENU QUE DIRIJA A VENTANA DE PAINT Y A VENTANA DE DEMOS. DEMOS CONTIENEN MEMENTO Y OBSERVER