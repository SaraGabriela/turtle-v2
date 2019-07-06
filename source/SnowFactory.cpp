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

NormalParticle::NormalParticle() {
	size = 5.0;
}

NormalParticle* SnowFactory::npar;

NormalSnow::NormalSnow(Particle* _p) { 
	par = _p; 
	x = rand() % 1600 +(-800);
	y = rand() % 800;
}

void NormalSnow::display(turtle & _tt, color* & cn){
	float f = par->getSize();
	if (cn->getname() == "d") {
		_tt.pencolor(159, 202, 242);
	}
	else {
		_tt.pencolor(cn->getR(), cn->getG(), cn->getB());
	}
	_tt.penup();
	_tt.turtleGo(x, y);
	_tt.pendown();
	//_tt.end();
	_tt.beginFill();
	for (int j = 0; j <= 12; j++) {
		_tt.forwardFill(f);
		_tt.left(360 / 12);
	}
	_tt.end();
}
