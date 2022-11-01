/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 14/Agosto/2022
Ejem 1. Divide y Vencerás*/

#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

vector<int> genera (int n) {
    vector<int> resul;
    for (int i = 0; i < n; i++) {
        resul.push_back(rand()%1000+1);
    }
    return resul;
}

void print (vector<int> &resul) {
    for (int i = 0; i < resul.size(); i++) {
        cout << resul[i] << " ";
    }
    cout << endl;
}

// Complejidad: O(n)
int cuenta100Inter(vector<int> &datos) {
    int cont = 0;
    for (int i = 0; i < datos.size(); i++) {
        if (datos[i] > 100) {
            cont++;
        }
    }   
    return cont;
}

// Complejidad: O(n)
int cuenta100DyV(vector<int> &datos, int start, int end) {
    if (start == end) { // esta llamada está buscando en una casilla
        return (datos[start] > 100) ? 1 : 0;
    }
    else { // esta llamada está buscando en una casilla intermedia
        int mid = (start + end) / 2;
        return cuenta100DyV(datos, start, mid) + cuenta100DyV(datos, mid+1, end);
    }
}

int main () { 
    
    int n;
    cin >> n;
    vector<int> datos = genera(n);
    //print(datos);
    cout << "Iterativo: " << cuenta100Inter(datos) << endl;
    cout << "Divide y Vencerás: " << cuenta100DyV(datos, 0, n - 1) << endl;

    return 0; 
}
