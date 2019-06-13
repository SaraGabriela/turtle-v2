#ifndef SNOWFACTORY_H
#define SNOWFACTORY_H

#include <iostream>
#include <iterator>
#include <map>
#include <tuple>
#include "turtle.h"

using namespace std;

class punto {
public:
	float x;
	float y;

	friend bool operator< (const punto& lhs, const punto& rhs) {
		// std::tuple's lexicographic ordering does all the actual work for you
		// and using std::tie means no actual copies are made
		return std::tie(lhs.x, lhs.y) < std::tie(rhs.x, rhs.y);
	}
};

class Particle {
protected:

	//agregar color como atributo compartido
	float size;
//	punto pos;
public:
	Particle(float _s=2.0);
//	virtual void display(float a, float b, turtle & _auxtt) = 0;
//	punto getPos();
//	void setPos(float x, float y);
	float getSize();
};

class NormalParticle : public Particle {
public:
	NormalParticle() :Particle(5.0){}
};
//Diferentes tipos de nieve segun color
/*class ClearSnow : public Particle {
public:
	ClearSnow() { size = 0.5; }

	void display(float a, float b, turtle &_auxtt);
};*/

class SnowFactory {
private:
	//map<punto, Particle*> myMap;
	static NormalParticle* npar;
public:
	~SnowFactory();

	static Particle* getParticle(string ty);
};



class NormalSnow : public Particle {
private:
	Particle* par;
	float x, y;
public:
	NormalSnow(Particle* _p);
	void display(turtle & _tt);
};

#endif // !SNOWFACTORY_H
