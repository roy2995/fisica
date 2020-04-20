#ifndef WORLD_H
#define WORLD_H


#include "main_body.h"
//se encarga de hacer las interaciones necesarias para la situacion 
struct world {
	world() {}//constructor default 
	world(vect_2 gravity) : gravity(gravity) {}

	//establecer gravedad 
	void instansgravity(const vect_2& v);

	//body creation
	void addbody(cuerpo* b);

	//simulacion
	void step(float dt);

	//esto es para almacenar N cantidad de objetos sin ningun problema
	vect_2 gravity;
	std::vector<cuerpo*> bodies;
};

#endif