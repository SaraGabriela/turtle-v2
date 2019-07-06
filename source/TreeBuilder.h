#ifndef TREEBUILDER_H
#define TREEBUILDER_H


#include <iostream>
#include <string>
#include "turtle.h"

using namespace std;

/**
* @class   TreeProduct
* @brief   Clase que retorna el dibujo de un arbol
* @detail  Todos los arboles tienen un tipo y están formados por un tronco, hojas y ramas.
*/
class TreeProduct {
protected:
	string type;
	string hojas;
	string tronco;
	string ramas;


public:
	/** Construye un arbol del tipo indicado
	*  @param _type es una cadena que indica el tipo de arbol a construir
	*/
	TreeProduct(string _type) :type(_type) {}
	/** Establece cuales son las hojas para el arbol
	*  @param h indica el tipo de hojas para construir el arbol
	*/
	void setHojas(string h);
	/** Establece cual es el tronco para el arbol
	*  @param t indica el tipo de tronco para construir el arbol
	*/
	void setTronco(string t);
	/** Establece cuales son las ramas para el arbol
	*  @param r indica el tipo de ramas para construir el arbol
	*/
	void setRamas(string r);

	/** Devuelve las hojas del arbol
	*  La cadena devuelta depende del tipo de arbol
	*/
	string getHojas();
	/** Devuelve el tronco del arbol
	*  La cadena devuelta depende del tipo de arbol
	*/
	string getTronco();
	/** Devuelve las ramas del arbol
	*  La cadena devuelta depende del tipo de arbol
	*/
	string getRamas();

	//void show() {} //Funcion que dibuja todos los arboles
};

/**
* @class   TreeBuilder
* @brief   Clase que se encarga de construir un arbol
* @detail  Se contruye un arbol usando el patron de diseño Builder. La mayoria de sus metodos son virtuales porque se comporta de manera diferente dependiendo del tipo de arbol a construir.
*/
class TreeBuilder {
protected:
	TreeProduct* treeP;
	turtle taux;
	color _col;
public:
	/** Construye un arbol
	*  Llama a todas las partes para construir un producto final
	*/
	virtual void getPartsBuild() = 0;
	/** Construye las hojas del arbol
	*  El tipo de hojas a construir depende del tipo de arbol que se desea
	*/
	virtual void buildHojas(color* & ch) = 0;
	/** Construye el tronco del arbol
	*  El tipo de tronco a construir depende del tipo de arbol que se desea
	*/
	virtual void buildTronco() = 0;
	/** Construye las ramas del arbol
	*  El tipo de ramas a construir depende del tipo de arbol que se desea
	*/
	virtual void buildRamas() = 0;

	/** Retorna un arbol
	*  Luego de haber sido construido, retornamos un arbol
	*/
	TreeProduct* getTreeProduct() { return treeP; }
	/** Define con que tortuga se relizaran los dibujos de las partes del arbol
	*  @param _t es el nombre de la tortuga con la que se va a dibujar
	*/
	void setTurtleB(turtle _t);
	//void treeColor(color a) { _col = a; }
	
};
/**
* @class   NormalBuilder
* @brief   Clase que construye un arbol del tipo normal
* @detail  Los metodos de esta clase se comportan considerando que el arbol es de tipo normal
*/
class NormalBuilder : public TreeBuilder {
public:
	//NormalBuilder(); { _col._r = 121; _col._g = 180; _col._b = 115; }
	void getPartsBuild();
	void buildHojas(color* & ch);
	void buildTronco();
	void buildRamas();
};
/**
* @class   CherryBuilder
* @brief   Clase que construye un arbol del tipo cerezo
* @detail  Los metodos de esta clase se comportan considerando que el arbol es de tipo cerezo
*/
class CherryBuilder : public TreeBuilder {
public:
	void getPartsBuild();
	void buildHojas(color* & ch);
	void buildTronco();
	void buildRamas();
};

/**
* @class   Director
* @brief   Clase que indica que tipo de arbol se va a construir
* @detail  Dirige a los constructores para saber que tipo de arbol construir
*/
class Director {
protected:
	TreeBuilder* builder;
public:
	/** Crea un arbol
	*  @param builder indica el tipo de constructor con el que se va a trabajar
	*  @param _tu indica que tortuga se usa para dibujar el arbol
	*  @param _x indica la posicion respecto a x donde empieza a dibujarse el arbol
	*  @param _y indica la posicion respecto a y donde empieza a dibujarse el arbol
	*/
	TreeProduct* createTree(TreeBuilder* builder, turtle _tu, float _x, float _y,color* & cou);
};
#endif // !TREEBUILDER_H
