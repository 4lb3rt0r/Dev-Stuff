/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 09/Sep/2021
Actividad: Actividad Integradora 1*/

#include <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>

using namespace std;

template <class T>

//O(n)
int busquedaSecuencial (T n,vector<T> list) {
    for (int i = 0; i < sizeof(list); i++) {
        //Comparar si n es igual a un dato x de ls lista
        if (list[i] == n)  {
            return i;
        }
    }
    throw out_of_range("No se encontró el dato");
}

template <class T>

//O(log2(n))
int busquedaBinaria(T n,vector<T> list) {
    int l = 0, r = sizeof(list) - 1;

    while (l <= r) {
        //Calcular punto medio
        int m = (l + r) / 2;
        //Comparar si n es igual al dato de en medio
        if (n == list[m]) {
            return m;
        }
        else {
            if (n < list[m]) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
    }
    throw out_of_range("No se encontró el dato");
}

int main () {

    vector<int> list = {84,74,82,45,65,99,19,83,90,39};
    int n;

    cout<<"Teclee un número: ";
    cin>>n;

    try {
        int index = busquedaSecuencial(n,list);
        cout<<"El dato "<<n<<" se encuentra en la posición "<<index<<endl;
    }
    catch (out_of_range& e) {
        cout<<e.what()<<endl;
    }

    //Ordenar los elementos dentro del vector
    sort(list.begin(), list.end());
    try {
        int index = busquedaSecuencial(n,list);
        cout<<"El dato "<<n<<" se encuentra en la posición "<<index<<endl;
    }
    catch (out_of_range& e) {
        cout<<e.what()<<endl;
    }

   

    getch();
    return 0;
}