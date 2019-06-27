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
	setupWindow(680, 680);
}

void turtle::setupWindow(int a, int b) {
	glutInitWindowSize(a, b);
	glutInitWindowPosition(30, 10);
	glutCreateWindow("Turtle C++");

	glClearColor(1, 1, 1, 1);
	glColor3f(0.78, 0.78, 0.78);
	glLineWidth(2.f);
	glOrtho(680, 0,680, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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
	glColor3f(0,0,0);
}

void turtle::forward(double dis) {

	if (dis != 0) {
		dis = dis / 800;
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
		x1 = x1 / 800;
	}
	if (y1 != 0) {
		y1 = y1 / 800;
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

void turtle::pencolor(color _c) {
	pencolor(_c.getR(), _c.getG(), _c.getB());

}

void turtle::beginFill() {
	glBegin(GL_POLYGON);
}

void turtle::forwardFill(double dis) {
	if (dis != 0) {
		dis = dis / 800;
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