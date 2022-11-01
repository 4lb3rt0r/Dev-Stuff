/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 1/Septiembre/2022
Ejem 8. Función Z*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> z_Function (string gral) {
    int n = gral.length();
    vector<int> z(n, 0);

    for (int i = 0, r = 0, l = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - 1]); 
        }
        while (i + z[i] < n && gral[z[i]] == gral[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

vector<int> PMT (string texto, string patron) {
    vector<int> salida;
    string gral = patron + "$" + texto;
    vector<int> zF = z_Function(gral);

    for (int i = 0; i < zF.size(); i++) {
        if (zF[i] == patron.length()) {
            salida.push_back(i);
        }
    }
    return salida;
}

int main () {

    string texto, patron;
    cin >> texto >> patron;
    vector<int> pos = PMT(texto, patron);

    for (int i = 0; i < pos.size(); i++) {
        cout << pos[i] - patron.length() - 1 << " ";
    }
    cout << endl;

    return 0;
}

/*
bacacabcaca
aca
*/