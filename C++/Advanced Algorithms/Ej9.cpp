/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 5/Septiembre/2022
Ejem 9. Algoritmo de KMP (Knuth-Morris-Pratt)*/

// bacacabcaca
// aca

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Preprocesamiento: Longest Proper Prefix which is also a suffix
// Complejidad: O(m) m es la longitud del patron
vector<int> lps (string p) {
    int n = p.length();
    vector<int> lpsv(n, 0);

    int j = 0, i = 1;

    while (i < n) {
        if (p[i] == p[j]) {
            lpsv[i] = j + 1;
            j++;
            i++;
        }
        else {
            if (j == 0) {
                lpsv[i] = 0;
                i++;
            }
            else {
                j = lpsv[j - 1];
            }
        }
    }

    return lpsv;
}

// Complejidad: O(n + m) n es la longitud del texto y m es la longitud del patron
vector<int> kmp(string texto, string patron) {
    vector<int> posMatch;
    vector<int> lpsv = lps(patron);

    int j = 0, i = 0, n = texto.length(), m = patron.length();

    for (int a = 0; a < lpsv.size(); a++) {
        cout << "[" << a << "]" << lpsv[a] << endl;
    }

    while (i < n) {
        if (texto[i] == patron[j]) {
            i++;
            j++;
            if (j == m) {
                posMatch.push_back(i - m);
                j = lpsv[j - 1];
            }
        }
        else {
            if (j == 0) {
                i++;
            }
            else {
                j = lpsv[j - 1];
            }
        }
    }

    return posMatch;
}


int main () {

    string texto, patron;

    cin >> texto >> patron;

    vector<int> posMatch = kmp(texto, patron);

    if (posMatch.size() == 0) {
        cout << "No Match" << endl;
    }
    else {
        for (int i = 0; i < posMatch.size(); i++) {
            cout << posMatch[i] << " ";
        }
        cout << endl;
    }


    return 0;
}

/*
bacacabcaca
aca
*/