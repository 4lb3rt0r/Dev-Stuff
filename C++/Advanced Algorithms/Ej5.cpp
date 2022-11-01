/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 14/Agosto/2022
Ejem 5. Algoritmos Voraces*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n) {
    vector<int> datos(n);

    for (int i = 0; i < n; i++) {
        cin >> datos[i];
    }

    sort(datos.begin(), datos.end(), greater<int>());
    int acum = 0;
    for (int i = 0; i < n; i++) {
        acum = (acum*10) + datos[i];
    }

    return acum;
}

int main () {

    int n;
    cin >> n;

    cout << solve(n) << endl;

    return 0;
}