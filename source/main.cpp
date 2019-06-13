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

void keyboard(unsigned char key,int _x, int _y) {
	switch ('key') {
	case 'a':
		turF.turtleTree("normal");
	}
}

void draw() {
	t.forward(100);
	t.end();

//	turF.turtleTree("normal");
	turF.turtleFlower("normal");
	turF.turtleSnow("nieve");
	/*t.right(90);
	t.forward(60);
	t.end();*/

	glFlush();
}

int main()
{
	t.start();
	t.setupWindow(800,600);

	glutKeyboardFunc(*keyboard);
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}

