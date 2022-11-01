/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 3/Dic/2021
Actividad: Actividad Integradora 5*/

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
#include "HashTable.h"

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

//Declaro esta función para separar los elementos numéricos de las ip's de los puntos
string createIPKey(string ip) {
    string IP = "";
    int count = 0;
    for (int i = 0; i < ip.size(); i++) {
        if (ip[count] != '.') {
            IP += ip[count];
            
        }
        count++;
    }

    return IP;
}


int main()
{
    //Declaramos variables
    int n = 0, m = 0, dia, index = 0, nAdj, ñ;
    string line, ip, mes, hora, msg, ip1, ip2, ip3 = "", word, key;
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

    //Creamos una variable tipo Estructura para guardar las ip's y su cantidad de adyacencias
    Estructura adj;
    //Creamos un vector que almacenará las ip's filtradas sin los puntos entre los valores numéricos
    vector<string> keys;
    //Realizamos un for loop para recopilar las ip's, su cantidad de adyacencias y las ip's filtradas
    //**Cabe resaltar que la hashTable se ve limitada por la cantidad de ip's que puedo insertarle,
    //es por ello que coloque un límite de 34 dentro del ciclo for siguiente:
    for (int i = 0; i < 34; i++) {
        //Almacenamos tanto las ip's y su cantidad de adyacencias en una estructura
        adj.IP = vertices[i];
        adj.cantidad = graph.countAdj(i);
        //Llamamos a la funcion createIPKey para separar los elementos numéricos de las ip's de los puntos
        key = createIPKey(vertices[i]);
        //Guardamos en el vector keys
        keys.push_back(key);
    }
    //Creación de la hashtable
    HashTable hashTable(keys);

    //hashTable.print();

    //Solicitamos al usuario introducir una IP
    cout<<"Introduzca la IP a buscar: ";
    cin>>ip;
    //Filtramos la IP y quitamos los puntos entre lso valores numericos
    ip3 = createIPKey(ip);
    //Llamamos a la función find() de la hashTable para validar si la ip ingresada existe
    ñ = hashTable.find(ip3);
    //Si la ip existe, imprimimos el índice donde se encuentra y su la cantidad de adyacencias
    if (ñ != -1) {
        cout<<"Índice: "<<hashTable.find(ip3)<<endl;
        for (int i = 0; i < n; i++) {
            if (ip == vertices[i])  {
                cout<<"Cantidad de adyacencias: "<<graph.countAdj(i)<<endl;
            }
        }
    }
    //Si find() arroja un -1, quiere decir que la IP no se pudo encontrar
    else {
        cout<<"No se encontró la IP"<<endl;
    }
    

    cout<<"\nPRESIONE [ENTER] PARA FINALIZAR";
    getch();
    return 0;
}
