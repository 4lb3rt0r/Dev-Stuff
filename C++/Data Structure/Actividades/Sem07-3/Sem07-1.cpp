/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 24/Sep/2021
Actividad: Actividad Integradora 1*/

#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
    
    LinkedList<int> list;
    list.addLast(5);
    list.addLast(10);
    list.addLast(15);
    list.addLast(20);
    list.print();
    list.addFirst(1);
    list.addFirst(0);
    list.print();
    try {
        int index = 6;
        int data = list.getData(index);
        cout << "En el índice " << index << " esta el dato: " << data << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }
    
    
    return 0;
}
