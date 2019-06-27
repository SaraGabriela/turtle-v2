#include "Tree.h"

void Tree::draw(string type, turtle & _tx) {
	cout << "Arbol dibujado en pos x:" << x << " y:" << y << endl;

	if (type == "normal" || type == "Normal") {
		TreeProduct* nor = dir.createTree(new NormalBuilder, _tx, x, y);
	}

	else if (type == "cherry" || type=="cerezo" || type == "Cherry" || type == "Cerezo") {

		TreeProduct* cher = dir.createTree(new CherryBuilder, _tx, x, y);
	}

	else {
		NormalBuilder norb;
		TreeProduct* nor = dir.createTree(new NormalBuilder, _tx, x, y);
	}
	
	
}

