#ifndef TREE_H
#define TREE_H



#include "shapes.h"
#include "TreeBuilder.h"
#include <string>

/**
* @class   Tree
* @brief   Clase que dibuja un arbol
* @detail  Es una figura del tipo arbol.
*/
class Tree : public shape
{
protected:
	Director dir;

public:
	Tree() {}
	~Tree(){}
	/** Dibuja un arbol e indica en la consola en que ubicacion fue dibujado
	*  @param type es el tipo de arbol a dibujar
	*  @param _tx es la tortuga que se va a usar para dibujar
	*/
	void draw(string type, turtle & _tx);
};
#endif // !TREE_H