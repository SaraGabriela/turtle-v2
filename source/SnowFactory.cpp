#include "SnowFactory.h"


Particle::Particle(float _s) { size = _s; }
float Particle::getSize() { return size; }

SnowFactory::~SnowFactory() {

}

Particle* SnowFactory::getParticle(string ty) {
	if (ty == "normal") {
		if (!npar) {
			npar = new NormalParticle;
		}
		return npar;
	}
	else {
		if (!npar) { //Diferentes punteros a diferentes tipos
			npar = new NormalParticle;
		}
		return npar;
	}
}

NormalParticle* SnowFactory::npar;

NormalSnow::NormalSnow(Particle* _p) { 
	par = _p; 
	x = rand() % 400 +(-200);
	y = rand() % 200;

	if (x != 0) { x = x / 100; }
	if (y != 0) { y = y / 100; }
}

void NormalSnow::display(turtle & _tt){
	float f = par->getSize();
	glPointSize(f);
	glColor3f(0,0,0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}
