/** @file turtle.cpp
@author Sara Diaz Oporto
@version Revision 1.1
@brief Clase turtle que permite realizar graficos con un comportamiento similar a turtle python.
*/

#include "turtle.h"


turtle::turtle()
{
	pen = 1;
	dir = 0;
	x = y = r = g = b = 0;

}


turtle::~turtle()
{
	
}

void turtle::start() {
	int argc = 1;
	char *argv[1] = { (char*)"Something" };
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_ALPHA);
}

void turtle::setupWindow() {
	setupWindow(800, 600);
}

void turtle::setupWindow(int a, int b) {
	glutInitWindowSize(a, b);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Turtle C++");

	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0);
	glLineWidth(3.f);
	glOrtho(800, 0, 600, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
}

void turtle::forward(double dis) {

	if (dis != 0) {
		dis = dis / 100;
	}

	if (pen) {
		glBegin(GL_LINES);
		glColor3f(r, g, b);
		glVertex2f(x, y);

		y = y + (dis * sin(Pi * dir / 180.0));
		x = x + (dis * cos(Pi * dir / 180.0));
		glVertex2f(x, y);
	}
	else {
		y = y + (dis * sin(Pi * dir / 180.0));
		x = x + (dis * cos(Pi * dir / 180.0));
	}
}

void turtle::left(GLdouble angle) {
	dir += angle;
}

void turtle::right(GLdouble angle) {
	left(-1 * angle);
}
void turtle::penup() {
	pen = 0;
}

void turtle::pendown() {
	pen = 1;
}

void turtle::turtleGo(double x1, double y1) {
	if (x1 != 0) {
		x1 = x1 / 100;
	}
	if (y1 != 0) {
		y1 = y1 / 100;
	}

	if (pen) {
		glBegin(GL_LINES);
		glColor3f(r, g, b);
		glVertex2f(x, y);

		y = y1;
		x = x1;
		glVertex2f(x, y);
	}
	else {
		y = y1;
		x = x1;
	}
	dir = 0;
}

void turtle::pencolor(float _r, float _g, float _b) {
	if (_r != 0) { r = _r / 255; }
	else{ r = _r; }

	if (_g != 0) { g = _g / 255; }
	else { g = _g; }
	
	if (_b != 0) { b = _b / 255; }
	else { b = _b; }
}

void turtle::beginFill() {
	glBegin(GL_POLYGON);
}

void turtle::forwardFill(double dis) {
	if (dis != 0) {
		dis = dis / 100;
	}

	glColor3f(r, g, b);
	glVertex2f(x, y);
	y = y + (dis * sin(Pi * dir / 180.0));
	x = x + (dis * cos(Pi * dir / 180.0));
	glVertex2f(x, y);
}

void turtle::end() {
	glEnd();
}

double turtle::getPosx() { return x; }
double turtle::getPosy() { return y; }