#ifndef FLOWERFACTORIES_H
#define FLOWERFACTORIES_H

#include <iostream>
#include <string>
#include"turtle.h"
using namespace std;


class Centro {

protected:
	string forma;
	float x;
	float y;
	const float DEG2RAD = 3.14159 / 180;
public:
	Centro(string _forma);
	string getForma();
	virtual void drawCentro(turtle & _tur) = 0;
};

class CentroNormal : public Centro {
public:
	CentroNormal() :Centro("normal") {}
	void drawCentro(turtle & _tur);
};

class CentroGirasol : public Centro {
public:
	CentroGirasol() :Centro("girasol") {}
	void drawCentro(turtle & _tur);
};

class Petalo {
protected:
	string forma;
	float x;
	float y;
public:
	Petalo(string _forma);

	string getForm();
	virtual void drawPetalo(turtle & _tur) = 0;
};


class PetaloNormal : public Petalo {
public:
	PetaloNormal() :Petalo("normal") {}
	void drawPetalo(turtle & _tur);
};

class PetaloGirasol : public Petalo {
public:
	PetaloGirasol() :Petalo("girasol") {}
	void drawPetalo(turtle & _tur);
};

class CFlor {
protected:
	string name;
	Centro *ce;
	Petalo * p;
	float xAr;
	float yAr;
public:
	CFlor(string _n) :name(_n) {}
	void setCentro(Centro * _ce);
	void setPetalo(Petalo * _p);

	void printDetail(turtle & _tur, float _x, float _y);

};

class FlowerFactory {
private:
	CFlor * f;
protected:
	virtual Centro* buildCentro() = 0;
	virtual Petalo* buildPetalo() = 0;

public:
	virtual CFlor* buildFlor() = 0;
};

class NorFlFactory : public FlowerFactory {
	Centro* buildCentro() {
		return new CentroNormal;
	}
	Petalo* buildPetalo() {
		return new PetaloNormal;
	}

	CFlor* buildFlor() {
		CFlor* f = new CFlor("Flor Normal");
		f->setCentro(buildCentro());
		f->setPetalo(buildPetalo());
		return f;
	}
};

class GirasolFactory : public FlowerFactory {
	Centro* buildCentro() {
		return new CentroGirasol;
	}
	Petalo* buildPetalo() {
		return new PetaloGirasol;
	}

	CFlor* buildFlor() {
		CFlor* f = new CFlor("Flor Girasol");
		f->setCentro(buildCentro());
		f->setPetalo(buildPetalo());
		return f;
	}
};

#endif // !FLOWERFACTORIES_H
