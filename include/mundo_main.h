#pragma once
#include "mian_body.h"
//se encarga de hacer las interaciones necesarias para la situacion 
struct world {
	world() : gravity(vect_2(0.0f, 9.81f)) {}//constructor default 
	world(vect_2 gravity) : gravity(gravity) {}

	//establecer gravedad 
	void instansgravity(vect_2 v);

	//body creation
	void addbody(cuerpo* b);

	//simulacion
	void step(float dt);
private:
	//esto es para almacenar N cantidad de objetos sin ningun problema
	vect_2 gravity;
	std::vector<cuerpo*> bodies;
};