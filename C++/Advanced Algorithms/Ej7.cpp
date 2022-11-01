/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 22/Agosto/2022
Ejem 7. Algoritmos de BackTracking*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// n es la cantidad de objetos
// Valor = Valor que se desea encontrar
int n, VALOR;
// include = es un vector que representa los objetos que SI se deben incluir
vector<bool> include;
//obj = Los valores de los objetos
vector<int> obj;
// Complejidad: O(2^n)
void sum_of_subset(int i, int acum, int total) {
    if (acum + total >= VALOR && (acum == VALOR || acum + obj[i + 1] <= VALOR)) {
        if (acum == VALOR) {
            for (int j = 0; j < n; j++) {
                if (include[j]) {
                    cout << obj[j] << " ";
                }
            }
            cout << endl;
        }
        else {
            // Si incluir al siguiente objeto
            include[i + 1] = true;
            sum_of_subset(i + 1, acum + obj[i + 1], total - obj[i + 1]);
            // No incluir al siguiente objeto
            include[i + 1] = false;
            sum_of_subset(i + 1, acum, total - obj[i + 1]);
        }
    }
}

int main () { 

    cin >> n >> VALOR;
    int dato, total = 0;

    for (int i = 0; i < n; i++) {
        cin >> dato;
        obj.push_back(dato);
        total += dato;
        include.push_back(false);
    }

    sort(obj.begin(), obj.end());
    sum_of_subset(-1, 0, total);
    
    return 0;
    
}

/*
5 21
10
6
5
16
11
*/