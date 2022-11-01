/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 14/Agosto/2022
Ejem 6. Algoritmos Voraces*/



#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solve (string str, int n) {
    vector<int> Ts, Ms;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'T') {
            Ts.push_back(i);
        }
        else {
            Ms.push_back(i);
        }
    }
    if (Ts.size() != Ms.size()*2) {
        return false;
    }
    for (int i = 0; i < Ms.size(); i++) {
        if (Ts[i] > Ms[i] || Ts[Ms.size() + 1] < Ms[i]) {
            return false;
        }
    }
    return true;
}

int main () {

    int t, n;
    string str;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> str;
        cout << (solve(str, n) ? "YES" : "NO") << endl;
    }

    return 0;
}