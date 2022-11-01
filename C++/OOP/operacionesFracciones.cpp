/*Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 12/Mayo/2021*/

#include <iostream>
#include <fstream>
using namespace std;

#include "Fraccion.h"

int main () {
	//Fraccion frac1(2,3), frac2(3,4), frac3, frac4;
	
	//frac3 = frac1.suma(frac2);
	//frac4 = frac1.multiplica(frac2);
	//frac1.muestra();
	//frac2.muestra();
	//frac3.muestra();
	//frac4.muestra();
	
	Fraccion listaFracciones[10],listaFracc2[10];
	int contFracc;
	int opera,num1,den1,num2,den2;
	
	ifstream archFracc;
	archFracc.open("operaciones.txt");
	
	//leo la primera línea que es la cantidad de operaciones a ejecutar
	archFracc >> contFracc;
	
	int count = 0,count2 = 0;

	while (archFracc >> opera >> num1 >> den1 >> num2 >> den2) {
		Fraccion frac1(num1,den1),frac2(num2,den2),frac3;
			frac1.muestra();
			frac2.muestra();
		
		//calculamos la suma
		if (opera == 1) {
			frac3 = frac1.suma(frac2);
			listaFracciones[count] = frac3;
			count++;
		}
		//calculamos la multiplicación
		else if (opera == 2){
			frac3 = frac1.multiplica(frac2);
			listaFracc2[count2] = frac3;
			count2++;
		}
	}
	
	archFracc.close();
	
	for (int cont = 0;cont < count;cont++){
		listaFracciones[cont].muestra();
	}
	
	for (int cont = 0;cont < count2;cont++){
		listaFracc2[cont].muestra();
	}
	
	return 0;
}
