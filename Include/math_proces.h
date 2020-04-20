#ifndef MATH_H
#define MATH_H



//librerias 
#include <iostream>
#include <math.h>
#include <vector>

//con este almacenaremos los vectores de 2 dimenciones 
struct vect_2 {
	//definimos los constructores 
	vect_2() {}//default
	vect_2(float x, float y) : x(x), y(y) {}

	//asignar valores a las componentes vector
	void setvalue(float x, float y);

	//propiedades del vector
	float longd();
	float longdsquare();
	void debug();

	//operaciones de vectores
	void operator += (const vect_2& v);
	void operator -= (const vect_2& v);

	float op_punto(const vect_2& a, const vect_2& b);
	float op_cruz(const vect_2& a, const vect_2& b);
	float x, y;
};


inline vect_2 operator * (float k, const vect_2& v) {
	return vect_2(k * v.x, k * v.y);
}


inline vect_2 operator + (vect_2 v1, vect_2 v2) {
	return vect_2(v1.x + v2.x, v1.y + v2.y);
}

#endif