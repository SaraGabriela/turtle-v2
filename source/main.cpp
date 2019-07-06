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
color* co = NULL;

class state {
public:
	virtual void run() = 0;
};

class menu : public state {
public:
	menu(){}
	void run();
};

class normalPaint : public state {
public:
	normalPaint() {}
	void run();
};

class historial : public state {
public:
	historial() {}
	void run();
};

class follower : public state {
public:
	follower() {}
	void run();
};


void printMenu() {
	glColor3f(0, 0, 0);
	string st = "***** GLUT PAINT *****";
	int i, l;
	l = st.length();
	glRasterPos2f(-0.5, 0.7);
	for (i = 0; i < l; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, st[i]);
	}

	st = "Escribe el numero de la seccion a la que deseas acceder:";
	l = st.length();
	glRasterPos2f(-0.5, 0.6);
	for (i = 0; i < l; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, st[i]);
	}

	st = "1: Paint normal";
	l = st.length();
	glRasterPos2f(-0.5, 0.5);
	for (i = 0; i < l; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, st[i]);
	}

	st = "-DEMOS-";
	l = st.length();
	glRasterPos2f(-0.5, 0.4);
	for (i = 0; i < l; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, st[i]);
	}

	st = "2: Turtle observer";
	l = st.length();
	glRasterPos2f(-0.5, 0.3);
	for (i = 0; i < l; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, st[i]);
	}

	st = "3: Turtle Memento";
	l = st.length();
	glRasterPos2f(-0.5, 0.2);
	for (i = 0; i < l; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, st[i]);
	}

	glFlush();
	glFlush();
}

void instructions() {
	string st = "'t' para dibujar un arbol | 'f' para dibujar una flor | 'n' para dibujar nieve";
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

	glFlush();
}

void notif() {
	glClear(GL_COLOR_BUFFER_BIT);
	t.pencolor(0, 0, 0);
	int a = 700;
	for (int i = 0; i < 4; i++) {
		t.pendown();
		t.forward(a);
		t.forward(-a);
		t.right(90);
	}
	t.end();
	/*if (co == NULL) co = new def;
	turF.turtleTree(_typ, ax, ay, co);*/
}

state* current;

void menuOptions(unsigned char Key, int x, int y)
{
	switch (Key) {
	case '1':
		cout << "Opcion de Paint normal" << endl;
		current = new normalPaint;
		current->run();
		glutPostRedisplay();
		break;
	case '2':
		cout << "Opcion de Turtle observer" << endl;
		current = new follower;
		current->run();
		glutPostRedisplay();
		break;
	case '3':
		cout << "Opcion de Turtle memento" << endl;
		current = new historial; //cambiar por clase estado memento
		current->run();
		glutPostRedisplay();
		break;
	}
}

void MyKeyboardFunc(unsigned char Key, int x, int y)
{
	float ax, ay;
	string _typ;
	bool fr = 0;
	string st;
	switch (Key)
	{
	case 't':
		cout << "Ingrese tipo de arbol [normal o cerezo]: ";
		cin >> _typ;
		cout << "Ingrese coordenadas para arbol: ";
		cin >> ax >> ay;
		if (co == NULL) co = new def;
		turF.turtleTree(_typ, ax, ay, co);
		glutPostRedisplay();
		break;

	case 'f':
		cout << "Ingrese tipo de flor [normal o girasol]: ";
		cin >> _typ;
		cout << "Ingrese coordenadas para flor: ";
		cin >> ax >> ay;
		if (co == NULL) co = new def;
		turF.turtleFlower(_typ, ax, ay, co);
		glutPostRedisplay();
		break;
	case 'n':
		cout << "Ingrese tipo de nieve [normal]: ";
		cin >> _typ;
		if (co == NULL) co = new def;
		turF.turtleSnow(_typ, co);
		glutPostRedisplay();
		break;
	case 'c':
		glColor3f(0.78, 0.78, 0.78);
		glClear(GL_COLOR_BUFFER_BIT);
		st = "'t' para dibujar un arbol | 'f' para dibujar una flor | 'n' para dibujar nieve";
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
		glColor3f(0, 0, 0);
		cout << "Se limpio la pantalla " << endl;
		break;
	case 'r':
		cout << "a partir de ahora los dibujos seran rojos" << endl;
		co = new rojo;
		break;
	case 'b':
		cout << "a partir de ahora los dibujos seran azules" << endl;
		co = new azul;
		break;
	case 'd':
		cout << "Los colores vuelven a su estado original" << endl;
		co = new def;
		break;
	case 27:
		cout << "Menu principal" << endl;
		current = new menu;
		current->run();
		glutPostRedisplay();
		break;
	}
}

void goBack(unsigned char Key, int x, int y) {
	switch(Key) {
	case 27:
		cout << "Menu principal" << endl;
		current = new menu;
		current->run();
		glutPostRedisplay();
		break;
	}
}
void menu::run() {
		glClear(GL_COLOR_BUFFER_BIT);
		glutKeyboardFunc(menuOptions);
		glutDisplayFunc(printMenu);
	};



	void normalPaint::run() {
		glClear(GL_COLOR_BUFFER_BIT);
		glutKeyboardFunc(MyKeyboardFunc);
		glutDisplayFunc(instructions);
	}



	void historial::run() {
		glClear(GL_COLOR_BUFFER_BIT);
		glutKeyboardFunc(MyKeyboardFunc);
		glutDisplayFunc(instructions);
	}

	void follower::run() {
		
		glClear(GL_COLOR_BUFFER_BIT);
		glutKeyboardFunc(goBack);
		glutDisplayFunc(notif);
		
	}



int main()
{
	t.start();
	t.setupWindow();
	current = new menu;
	current->run();
	glutMainLoop();

	return 0;
}

//BRIDGE CON IMPLEMENTOR PARA COLORES
//HACER UN MENU QUE DIRIJA A VENTANA DE PAINT Y A VENTANA DE DEMOS. DEMOS CONTIENEN MEMENTO Y OBSERVER