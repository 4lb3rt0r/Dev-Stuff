#include <iostream>
using namespace std;

//Funci�n para pedir los datos de un arreglo
void pideDatosArreglo (int arreglo[],int &size) {
	
	cout<<"�Cu�ntos datos? ";
	cin>>size;
	
	for (int cont = 1;cont < size+1;cont++) {
		cout<<"Valor para la casilla "<<cont<<endl;
		cin>>arreglo[cont];
	}
	
	cout<<endl;
}

//Funci�n que muestra los datos de un arreglo
void muestraDatosArreglo (int arr[],int size) {
	for (int cont = 1;cont < size+1;cont++) {
		cout<<arr[cont]<<endl;
	}
}

int main () {
	int arreglo[10],tam;
	
	pideDatosArreglo(arreglo,tam);
	muestraDatosArreglo(arreglo,tam);
	
	return 0;
}
