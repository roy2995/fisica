#pragma once
//librerias 
#include <iostream>
#include <math.h>
#include <vector>

//con este almacenaremos los vectores de 2 dimenciones 
struct vect_2 {
	//definimos los constructores 
	vect_2() :x(0.0f), y(0.0f) {}//default
	vect_2(float x, float y) : x(x), y(y) {}

	//asignar valores a las componentes vector
	void setvalue(float x, float y);

	//propiedades del vector
	float longd();
	float longdsquare();
	void debug();

	//obtener componentes del vector
	float getX();
	float getY();

	//operaciones de vectores
	void operator += (vect_2 v);
	void operator -= (vect_2 v);
	float op_punto(vect_2 a, vect_2 b);
	float op_cruz(vect_2 a, vect_2 b);
private:
	//por motivos de seguridad el profesor hace esto para que solo se puedean modificar por funciones 
	float x, y;
};