#pragma once
#include "shapes.h"
#include "TreeBuilder.h"
#include <string>

class Tree : public shape
{
protected:
	Director dir;

public:
	Tree();
	~Tree();
	void draw(string type, turtle & _tx);
};

/*		glColor3f(0.019, 0.686,0.1529);
		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + 0.05, y + 0.035);
		glVertex2f(x + 0.065, y + 0.09);
		glVertex2f(x + 0.05, y + 0.14);
		glVertex2f(x + 0.0, y + 0.20);
		glVertex2f(x - 0.05, y + 0.14);
		glVertex2f(x - 0.065, y + 0.09);
		glVertex2f(x - 0.05, y + 0.035);
		glEnd();

		glColor3f(0.007,0.349, 0.1725);
		glBegin(GL_LINE_LOOP);
		glVertex2f(x, y);
		glVertex2f(x + 0.05, y + 0.035);
		glVertex2f(x + 0.065, y + 0.09);
		glVertex2f(x + 0.05, y + 0.14);
		glVertex2f(x + 0.0, y + 0.20);
		glVertex2f(x - 0.05, y + 0.14);
		glVertex2f(x - 0.065, y + 0.09);
		glVertex2f(x - 0.05, y + 0.035);
		glEnd();*/