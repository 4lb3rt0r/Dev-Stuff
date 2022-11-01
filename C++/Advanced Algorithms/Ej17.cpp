/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 17/Octubre/2022
Ejem 17. Algoritmo de Gilbert & Moore */

#include <iostream>
#include <vector>

using namespace std;

int BSTOp (vector<float> p, vector<float> pAcum) {
    int n = p.size();
    float A[n + 2][n + 1];

    for (int i = 1; i < n; i++) {
        A[i][i - 1] = 0;
        A[i][i] = p[i - 1];
    }
    A[n + 1][n] = 0;
    for (int diag = 1; diag < n - 1; diag++) {
        for (int i = 1; i <= n - diag; i++) {
            int j = i + diag;
            float min = INT_MAX;
            for (int k = i; k <= j; k++) {
                if (A[i][k - 1] + A[k + 1][j] < min) {
                    min = A[i][k - 1] + A[k + 1][j];
                }
            }
            A[i][j] = min + pAcum[j] - pAcum[i - 1];
        }
    }

    return A[1][n];
}

int main () {

    int n; //Cantidad de nodos
    float dato;
    vector<float> p, pAcum;
    pAcum.push_back(0);

    for (int i = 0; i < n; i++) {
        cin >> dato;
        p.push_back(dato);
        pAcum.push_back(pAcum[i] + dato);
    }

    cout << BSTOp(p, pAcum) << endl;

    return 0;
}