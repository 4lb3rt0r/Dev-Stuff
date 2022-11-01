#ifndef Laptop_h
#define Laptop_h

#include "Computadora.h"

class Laptop : public Computadora {
	public:
		Laptop();
		Laptop(string marca,string sisOp,int ram,int duracionPila);
		int getDuracionPila() { return duracionPila; };
		void setDuracionPila(int dpila) {duracionPila = dpila;}
		void muestra();
	private:
		int duracionPila;
};

Laptop :: Laptop() : Computadora() {
	duracionPila = 1;
}

Laptop::Laptop(string marc,string operacion,int r,int dpila):Computadora(marc,operacion,r) {
	duracionPila = dpila;
}

void Laptop :: muestra() {
	cout<<"Computadora "<<marca;
	cout<<" que contiene el sistema operativo "<<sisOp;
	cout<<" y RAM de "<<ram;
	cout<<" y bater�a de "<<duracionPila<<endl;
}

#endif
