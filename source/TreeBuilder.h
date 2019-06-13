#ifndef TREEBUILDER_H
#define TREEBUILDER_H


#include <iostream>
#include <string>
#include "turtle.h"

using namespace std;

class TreeProduct {
protected:
	string type;
	string hojas;
	string tronco;
	string ramas;


public:
	TreeProduct(string _type) :type(_type) {}
	void setHojas(string h);
	void setTronco(string t);
	void setRamas(string r);

	string getHojas();
	string getTronco();
	string getRamas();

	void show() {} //Funcion que dibuja todos los arboles
};

class TreeBuilder {
protected:
	TreeProduct* treeP;
	turtle taux;
public:
	virtual void getPartsBuild() = 0;
	virtual void buildHojas() = 0;
	virtual void buildTronco() = 0;
	virtual void buildRamas() = 0;

	TreeProduct* getTreeProduct() { return treeP; }
	void setTurtleB(turtle _t);
	
};

class NormalBuilder : public TreeBuilder {
public:
	void getPartsBuild();
	void buildHojas();
	void buildTronco();
	void buildRamas();
};

class CherryBuilder : public TreeBuilder {
public:
	void getPartsBuild();
	void buildHojas();
	void buildTronco();
	void buildRamas();
};

class Director {
protected:
	TreeBuilder* builder;
public:
	TreeProduct* createTree(TreeBuilder* builder, turtle _tu);
};
#endif // !TREEBUILDER_H
