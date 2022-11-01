/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 09/Sep/2021
Actividad: Actividad Integradora 1*/

//Algoritmo de Ordenamiento: Bubble
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

template <class T> 
void bubbleSort (vector <T>& list,int& nSwaps,int& nComparis) {
    for (int i = 0; i < list.size(); i++) {
        for (int j = i + 1; j < list.size(); j++) {
            if (list[i] > list[j]) {
                int iaux = list[i],jaux = list[j];
                list[i] = jaux;
                list[j] = iaux;
                nSwaps++;
            }
            nComparis++;
        }
    }
}

template <class T>
void print (vector <T>& list) {
    for (int i = 0; i < list.size(); i++) {
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

int main () {
    vector <int> list = {40,50,32,45,19,2,10,23,44,28};
    vector <int> originList = list;
    int nSwaps = 0,nComparis = 0;

    bubbleSort(list,nSwaps,nComparis);

    cout<<"Lista Original"<<endl;
    print(list);
    cout<<"Lista Ordenada"<<endl;
    print(originList);
    cout<<"Número de Comparaciones: "<<nComparis<<endl;
    cout<<"Número de Intercambios: "<<nSwaps<<endl;

    getch ();
    return 0;
}