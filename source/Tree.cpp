#include "Tree.h"

Tree::Tree()
{
}


Tree::~Tree()
{
}

void Tree::draw(string type, turtle & _tx) {
	

	if (type == "normal" || type == "Normal") {
		TreeProduct* nor = dir.createTree(new NormalBuilder, _tx);
	}

	else if (type == "cherry" || type=="cerezo" || type == "Cherry" || type == "Cerezo") {

		TreeProduct* cher = dir.createTree(new CherryBuilder, _tx);
	}

	else {
		NormalBuilder norb;
		TreeProduct* nor = dir.createTree(new NormalBuilder, _tx);
	}
	
	
}

