#include "Snow.h"



Snow::Snow()
{
}


Snow::~Snow()
{
	//delete f;
}

void Snow::draw(string type, turtle & _tt) {

	if (type == "normal") {
		for (int i = 0; i < 500; i++) {
			NormalSnow nor = NormalSnow(SnowFactory::getParticle("normal"));
			nor.display(_tt);
		}
	}
	else {
		for (int i = 0; i < 500; i++) {
			NormalSnow nor = NormalSnow(SnowFactory::getParticle("normal"));
			nor.display(_tt);
		}
	}

/*	float ax, ay;
	for (int i = 0; i < 500; i++) {
		float rx = rand() % 200;
		float ry = rand() % 200;

		if (rx != 0) { ax = rx / 100; }
		if (ry != 0) { ay = ry / 100; }
		punto u;
		u.x = ax; u.y = ay;
		Particle* pr = f->getParticle(u);
		pr->display(u.x, u.y, _tt);
		pr->display(-u.x, u.y, _tt);
	}*/
}