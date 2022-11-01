/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 21/Sep/2021
Actividad: Actividad Integradora 1*/

#include <iostream>
#include <conio.h>  
#include "LinkedList2.h"

using namespace std;

int main () {

    int n;
    Nodo <int> *lista = NULL;

    cout<<"Teclee el valor que quiere agregar a la lista: ";
    cin>>n;


    insertarDato(lista,n);

    cout<<"Desplegando Lista Enlazada: ";
    //lista.print();

    getch();
    return 0;
}