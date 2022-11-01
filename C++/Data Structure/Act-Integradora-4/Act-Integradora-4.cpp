/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 23/Nov/2021
Actividad: Actividad Integradora 4*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
#include <algorithm>
#include <queue>

using namespace std;

#include "Edge.h"
#include "Graph.h"
#include "Estructura.h"
#include "Heap.h"

//Declaro esta función para separar las ip's de sus respectivos puertos
string ipGenerator (string ip) {
    string IP = "";
    int count = 0;
    while (ip[count] != ':') {
        IP += ip[count];
        count++;
    }
    return IP;
}

int main () {

    //Declaramos variables
    int n = 0, m = 0, dia, index = 0, nAdj;
    string line, ip, mes, hora, msg, ip1, ip2, word;
    vector <string> vertices;

    //Leemos el archivo de entrada
    ifstream fileIn("bitacoraGrafos.txt");
    getline(fileIn,line);
    stringstream ss(line);
    //Recopilamos los 2 primeros valores del archivo
    ss>>n>>m;
    
    //Realizamos un for loop para recopilar los n vertices existentes en el archivo .txt
    for (int i = 0; i < n; i++) { 
        getline(fileIn,line);
        stringstream ss(line);
        ss>>ip;
        vertices.push_back(ip);
        //cout<<vertices[i]<<endl;
    }

    //Declaramos un string de tipo Graph que contenga los vertices recopilados
    Graph<string> graph(vertices);

    //Realizamos un for loop para recopilar los m arcos existentes en el archivo .txt
    for (int i = 0; i < (n + m); i++) {
        if (i > n) {
            getline(fileIn,line);
            stringstream ss(line);
            ss>>mes>>dia>>hora>>ip1>>ip2>>msg;
            while (ss>>word) {
                msg += " " + word;
            }
            //Llamamos a la funcion ipGenerator para separar las ip's de sus respectivos puertos
            ip1 = ipGenerator(ip1);
            ip2 = ipGenerator(ip2);
            //Insertamos los arcos en el grafo
            graph.insert(Edge<string>(ip1,ip2,0));
        }
    }

    fileIn.close();

    //graph.print();

    //Creamos una variable tipo Estructura para guardar las ip's y su cantidad de adyacencias
    Estructura adj;
    //Creamos una variable Heap de tipo Estructura para almacenar los datos dentro de la estructura creada anteriormente
    Heap<Estructura> heap;
    
    //Realizamos un for loop para recopilar las ip's y su cantidad de adyacencias
    for (int i = 0; i < n; i++) {
        //Almacenamos tanto las ip's y su cantidad de adyacencias en una estructura
        adj.IP = vertices[i];
        adj.cantidad = graph.countAdj(i);
        //Almacenamos cada valor de la estructura "Estructura" en un Heap
        heap.push(adj);
    }

    //Imprimimos las ip's con mayor adyacencia mediante el método pop() que posee el heap
    cout<<"5 IP's que poseen la mayor cantidad de adyacencias: "<<endl;
    for (int i = 0; i < 5; i++) {
        cout<<heap.pop()<<endl;
    }
    
    //graph.breadthFirstSearch("36.29.138.97");
    //graph.depthFirstSearch("254.20.94.9");

    cout<<"\nPRESIONE [ENTER] PARA FINALIZAR";
    getch();
    return 0;
}