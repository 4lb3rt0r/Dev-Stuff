/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 8/Septiembre/2022
Ejem 10. Algoritmo de Trie*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "trie.h"

int main () {

    trie miTrie;
    int n, q;
    string dato;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> dato;
        miTrie.insert(dato);
    }

    cout << "****************" << endl;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> dato;
        if (miTrie.search(dato)) {
            cout << "SI se encuentra en el trie" << endl;
        }
        else {
            cout << "NO se encuentra en el trie" << endl; 
        }
    }

    return 0;
}