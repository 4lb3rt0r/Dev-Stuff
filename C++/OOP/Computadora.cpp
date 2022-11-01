#include <iostream>
using namespace std;
//#include "Computadora.h"
#include "Laptop.h"

int main () {
	Computadora compu1("Dell","Linux",16),compu2("HP","Windows",8);
	Laptop lap1("Mac Book","OSX",8,12),lap2("Dell","Windows",16,10);
	
	compu1.muestra();
	lap1.muestra();
	
	cout<<"Computadora "<<compu2.getMarca();
	cout<<" con sistema operativo "<<compu2.getSisOp();
	cout<<" y con "<<compu2.getRAM()<<" GB de RAM"<<endl;
	
	cout<<"Computadora - Laptop "<<lap2.getMarca();
	cout<<" con sistema operativo "<<lap2.getSisOp();
	cout<<" y con "<<lap2.getRAM()<<" GB de RAM ";
	cout<<"y con batería de "<<lap2.getDuracionPila()<<" de duración"<<endl;
	return 0;
}
