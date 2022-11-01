/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 09/Sep/2021
Actividad: Actividad Integradora 1*/

#include <iostream>

using namespace std;

#include "Lista.h"

int main () { 

    Lista <string> lista;
    string num = "";
    while (num != "*") {
        cout << "Introduce texto a continuación: ";
        cin >> num;
        if (num != "*") {
            lista.insert(num);
        }
    }
    // lista.insert(1);
    // lista.insert(2);
    // lista.insert(3);

    lista.print();
    
    lista.erase();
    
    try {
        string aux = lista.getData(1);
        cout << "El elemento 1 es igual a: " << aux << endl;
    } catch(out_of_range& e) {
        cout << e.what() << endl;
    }
    cout << "La lista es de " << lista.getSize() << " elementos" << endl;

    lista.print();

    return 0;
}