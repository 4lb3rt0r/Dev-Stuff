/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 12/Oct/2021
Actividad: Actividad Integradora 1*/

#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
#include "Bitacora.hpp"
#include "DoublyLinkedList.h"
#include "NodeD.h"

using namespace std;

//template <class T>
int busquedaBinaria(DoublyLinkedList<Bitacora> bitacora, int aux) {
    //Declaramos variables
    int m;
    int l = 0;
    int r = bitacora.getSize() - 1;
    while (l <= r) {
        //Obtenemos punto medio
        m = (l + r) / 2;
        //IF para verificar si el dato es igual al de en medio
        if (bitacora[m].key == aux) {
            return m;
        } 
        else {
            if (aux < bitacora[m].key) {
                //Cambio de limite derecho a m menos uno
                r = m - 1;
            } 
            else {
                //Cambio de limite izquierdo a m mas uno
                l = m + 1;
            }
        }
    }
    //Retornamos m
    return m;
}

int main()
{
    ifstream fileIn("bitacora.txt");
    string line;
    string palabra;
    char delim = ' '; 
    string mes, hora, ip, msg;
    int dia,cont = 0;
    DoublyLinkedList<Bitacora> bitacora;

    while (getline(fileIn,line)) { 
        stringstream ss(line);
        ss>>mes>>dia>>hora>>ip>>msg;
        while (ss>>palabra) {
            msg += " " + palabra;
        }
        Bitacora temp(mes, dia, hora, ip, msg);
        bitacora.addLast(temp); //Append a la DoublyLinkedList
        cont++;
    }

    fileIn.close();

    //Hacemos uso de un QuickSort
    bitacora.sort();
	
	cout<<endl;

    //Pedimos datos al usuario
    string mesI,horaI,mesF,horaF;
    int diaI,diaF;
    cout<<"Introduzca un mes inicial: ";
    cin>>mesI;
    cout<<"Introduzca un mes final: ";
    cin>>mesF;
    cout<<"Introduzca un dia inicial: ";
    cin>>diaI;
    cout<<"Introduzca un dia final: ";
    cin>>diaF;
    cout<<"Introduzca una hora inicial (HH:MM:SS): ";
    cin>>horaI;
    cout<<"Introduzca una hora final (HH:MM:SS): ";
    cin>>horaF;

    cout<<endl;

    //Convergemos los datos obtenidos en una sola variable
    Bitacora fechaI(mesI,diaI,horaI);
    Bitacora fechaF(mesF,diaF,horaF);

    //Obtenemos los índices para realizar la búsqueda
    int i0 = busquedaBinaria(bitacora, fechaI.key);
    int iF = busquedaBinaria(bitacora, fechaF.key);

    //Imprimimos los datos que el usuario proporcionó (índices y fechas)
    cout<<"Indice inicial: "<<i0<<endl;
    cout<<"Indice final: "<<iF<<endl;
    cout<< endl;
    
	cout<<"Resultados de la Búsqueda: "<<endl;
	cout<<"Desde: "<<fechaI.month<<" "<<fechaI.day<<" "<<fechaI.time<<endl;
	cout<<"Hasta: "<<fechaF.month<<" "<<fechaF.day<<" "<<fechaF.time<<endl;

    cout<<"Presione ENTER para desplegar el resultado de la búsqueda";
    getch();
    
    //creamos el archivo "bitacora2.txt"
	ofstream fileOut("bitacora2.txt");

	fileOut<<"Resultados de la Búsqueda: "<<endl;
    cout<<endl;
	fileOut<<"Desde: "<<fechaI.month<<" "<<fechaI.day<<" "<<fechaI.time<<endl;
	fileOut<<"Hasta: "<<fechaF.month<<" "<<fechaF.day<<" "<<fechaF.time<<endl;

    //Imprimimos los datos de la búsqueda dentro de la consola
    for (int i = i0; i < iF ; i++){
        cout << bitacora[i].month << " " << bitacora[i].day << " " << bitacora[i].time << " " << bitacora[i].ip << " " << bitacora[i].message << endl;
    } 

    //Imprimimos los datos de la búsqueda dentro del archivo "bitacora2.txt"
    for (int i = 0; i < bitacora.getSize(); i++) {
        fileOut<<bitacora[i].month<<" "<<bitacora[i].day<<" "<<bitacora[i].time<<" "<< bitacora[i].ip << " " << bitacora[i].message <<endl;
    }

    //Cerramos el archivo original
    fileOut.close();
    //getch();
    return 0;
}

