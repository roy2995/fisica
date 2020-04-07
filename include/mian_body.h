#pragma once
#include "math_proces.h"

struct cuerpo
{
	//constructor
	cuerpo() : mass(1.0f) {}
	cuerpo(float mass) : mass(mass) {}

	//establecer el valor de la masa
	void massvalue(float m);

	//establecer posicion y velocidad
	void intansvel(vect_2 v);
	void intanspos(vect_2 v);

	//obtener los valores de masa, pocision y velocidad
	float getmass();
	float intansinvmass();
	vect_2 getvel();
	vect_2 getpos();

	//mostrar informacion del cuerpo 
	void debuginfo();

	//aplicacion de la fuerza 
	void addforce(vect_2 v);

private:
	float mass;
	float invmass = 1 / mass;
	vect_2 position;
	vect_2 velocity;
	vect_2 force;

};

