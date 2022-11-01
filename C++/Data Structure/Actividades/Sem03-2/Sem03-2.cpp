/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 09/Sep/2021
Actividad: Actividad Integradora 1*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//orden secuencial
template <typename T>
string busquedaSecuencial(vector<T> list) {
    for (int cont=0; cont < list.size(); cont++) {
        string aux = list[cont];
        if(list[cont+1] != aux) {
            return list[cont+1];
        }
    }
}


//orden binario
string busquedaBinaria(string letras){
    string unico = "";
    int upper = letras.length()-1;
    int lower = 0;
    int count = 0;
    int mid;
    if (letras.length() == 3){
        if (!(letras.at(0) == letras.at(1))){
            unico += letras.at(0);
            unico.append(" ").append(to_string(1));
            return unico;
        }else{
            unico += letras.at(letras.length()-1);
            unico.append(" ").append(to_string(1));
            return unico;
        }
    }
    while (lower < upper){
        count++;
        mid = (upper+lower)/2;
        if (mid == 0){
            unico += letras.at(mid);
            unico.append(" ").append(to_string(count-1));
            return unico;
        }
        if (mid == letras.length()-2){
            unico += letras.at(letras.length()-1);
            unico.append(" ").append(to_string(count-1));
            return unico;
        }
        if (!(letras.at(mid-1) == letras.at(mid)) && !(letras.at(mid+1) == letras.at(mid))){
            unico += letras.at(mid);
            unico.append(" ").append(to_string(count));
            return unico;
        } else if (letras.at(mid-1) == letras.at(mid)){
            if (mid % 2 == 0){
                upper = mid-2;
            } else {
                lower = mid+1;
            }
        } else if (letras.at(mid+1) == letras.at(mid)){
            if (mid % 2 == 0){
                lower = mid+2;
            } else {
                upper = mid-1;
            }
        }
    }
    if (count == 0){count+=1;}
    mid = (upper+lower)/2;
    unico += letras.at(mid);
    unico.append(" ").append(to_string(count));
    return unico;
}


int main() {
    string s;
    vector<string> line;
    int num;
    ifstream in("entrada.txt");
    in >> num;
    cout << "El numero de renglones es: " << num << endl;
    //leyendo la cantidad de renglones
    for (int cont = 0; cont < num; cont++) {
        in >> s;
        line.push_back(s);
    }

    busquedaSecuencial(line);




    return 0;
}