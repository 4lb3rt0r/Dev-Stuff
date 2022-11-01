/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 14/Agosto/2022
Ejem 2. Divide y Vencerás*/

#include<iostream>
#include<vector>
#include<cstdlib>

#define MAX 128

using namespace std;

void genera (int datos [MAX] [MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            datos[i][j] = rand()%1000+1;
        }
    }
}

void print(int datos [MAX] [MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << datos[i][j] << " ";
        }
        cout << endl;
    }
    
}

// Complejidad: O(n^2)
int cuenta100Inter(int datos [MAX] [MAX], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (datos[i][j] > 100) {
            cont++;
            }
        } 
    }   
    return cont;
}

// Complejidad: O(n)
int cuenta100DyV(int datos [MAX] [MAX], int ri, int rf, int ci, int cf) {
    if (ri == rf && ci == cf) { // esta llamada está buscando en una casilla
        return (datos[ri][ci] > 100) ? 1 : 0;
    }
    else { // 
        int rm = (ri + rf) / 2;
        int cm = (ci + cf) / 2;
        return cuenta100DyV(datos, ri, rm, ci, cm) + cuenta100DyV(datos, ri, rm, cm+1, cf) + cuenta100DyV(datos, rm+1, rf, ci, cm) + cuenta100DyV(datos, rm+1, rf, cm+1, cf);
    }
}

int main () { 
    
    int n;
    cin >> n;
    int datos [MAX] [MAX];
    genera(datos, n);
    //print(datos, n);
    cout << "Iterativo: " << cuenta100Inter(datos, n) << endl;
    cout << "Divide y Vencerás: " << cuenta100DyV(datos, 0, n - 1, 0, n - 1) << endl;

    return 0; 
}