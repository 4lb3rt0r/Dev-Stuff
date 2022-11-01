/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 09/Sep/2021
Actividad: Actividad Integradora 1*/

//Algoritmo de Ordenamiento: Intercambio
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

template <class T>

void swipeSort (vector <T> & list, int& nSwaps, int& nComparis) {
    //recorremos la lista desde el primer elemento hasta el penúltimo elemento
    for (int i = 0; i < list.size(); i++) {
        for (int j = i + 1; j < list.size(); j++) {
            nComparis++;
            if (list[i] > list[j]) {
                //si el elemento i es mayor que el j, intercambias los lugares
                int iaux = list[i], jaux = list[j];
                list[i] = jaux;
                list[j] = iaux;
                nSwaps++;
            }
        }
    }
    cout<<"Número de Intercambios: "<<nSwaps<<endl;
    cout<<"Número de Comparaciones: "<<nComparis<<endl;
}

template <class T>
void print (vector <T> & list) {
    for (int i = 0; i < list.size(); i++) {
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

int main () {

    vector <int> list = {40,50,32,45,19,2,10,23,44,28};
    vector <int> originList = list;
    int nSwaps = 0,nComparis = 0;

    swipeSort(list,nSwaps,nComparis);

    cout<<"Lista Ordenada: "<<endl;
    print(list);

    cout<<"Lista Original: "<<endl;
    print(originList);

    getch();
    return 0;
}