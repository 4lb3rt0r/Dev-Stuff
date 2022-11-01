/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 7/Nov/2021
Actividad: Actividad Integradora 3*/

#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#include "Bitacora.hpp"
#include "Heap.h"
#include "IP.h"

int partition(vector<IP> &lista, int inicio, int final) {
    int pivote = final;
    int i = inicio;
    for (int j = inicio; j < final; j++) {
        if (lista[pivote] < lista[j]) {
            swap(lista[j], lista[i]);
            i++;
        }
    }
    swap(lista[i], lista[pivote]);
    return i;
}

void quickSort(vector<IP>&lista, int inicio, int final){
    if(inicio < final){ //Caso base
        int pivote = partition(lista, inicio, final);  
        quickSort(lista, inicio, pivote-1); //Llamada recursiva lado izquierdo
        quickSort(lista, pivote+1, final);  //Llamada recursiva lado derecho
    }
}

int main () {
    
    ifstream fileIn("bitacoraHeap.txt");
    string mes,hora,ip,msg,line,word;
    int dia,count = 0;
    Heap<Bitacora> bitacora;

    while (getline(fileIn,line)) { 
        stringstream ss(line);
        ss>>mes>>dia>>hora>>ip>>msg;
        while (ss>>word) {
            msg += " " + word;
        }
        Bitacora temp(mes, dia, hora, ip, msg);
        bitacora.push(temp); //Añadimos un elemento al Árbol Heap
        count++;
    }

    fileIn.close();

    //Utilizamos el HeapSort para ordenar los datos mediante su IP
    bitacora.heapSort("desc");

    vector<IP> Ipes;
    IP auxIP(bitacora.heap[0].ip);
    auxIP.counter = 1;
    for (int i = 1; i < count; i++) {
        if (auxIP.key != bitacora.heap[i].key ) {
            Ipes.push_back(auxIP);
            auxIP = IP(bitacora.heap[i].ip);
            auxIP.counter = 1;
        } 
        else {
            auxIP.counter++;
        }
    }

    quickSort(Ipes, 0, Ipes.size() - 1);
    
    for (int i = 0; i < 5; i++){
        cout << Ipes[i].ip << " " << Ipes[i].counter << endl;
    }


    cout<<"PRESIONES [ENTER] PARA FINALIZAR";
    getch();
    return 0;
}