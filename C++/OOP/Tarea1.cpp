/* Programación Orientada a Objetos
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 14/Mayo/2021
Actividad: Tarea 1*/

// Escribe aquí tu programa que soluciona el ejercicio

#include <iostream>
#include <fstream>
using namespace std;

#include "Complejo.h"

void sumatoria (Complejo list1[],Complejo list2[],Complejo list3[],Complejo list4[]) {
	for (int i = 0; i < 2;i++) {
		list4[i] = list3[i].suma(list1[i].suma(list2[i]));
	}
}

void muestraComplex (Complejo l[]) {
		l[0].muestra();
}

int main () {
	Complejo l1[10],l2[10],l3[10],l4[10];
	double r,im,contCom;
	
	ifstream numComplex;
	numComplex.open("numerosComplejos.txt");
	
	for (int i = 0; i < 3;i++) {
        numComplex>>r>>im;
        if (i == 0) {
        	l1[0].setReal(r);
        	l1[0].setImaginario(im);
		}
		else if (i == 1) {
			l2[0].setReal(r);
        	l2[0].setImaginario(im);
		}
		else if (i == 2) {
			l3[0].setReal(r);
        	l3[0].setImaginario(im);
		}
    }
    
    numComplex.close();
    
    sumatoria(l1,l2,l3,l4);
    
    muestraComplex(l1);
    muestraComplex(l2);
    muestraComplex(l3);
    
    cout<<"Suma: ";
    muestraComplex(l4);
    
	return 0;
}
