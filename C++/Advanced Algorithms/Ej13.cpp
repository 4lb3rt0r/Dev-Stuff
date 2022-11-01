/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 29/Septiembre/2022
Ejem 13. El Problema de la Mochila con Dinamic Programming, DyV, Backtracking, Branch & Bound*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define MAXOBJ 11
#define MAXMOCH 101

struct obj {
    int valor, peso;
    float valPeso;
};

struct node {
    int niv;
    int va;
    int pa;
    int vp;
    bool operator<(const node &otro) const {
        return vp < otro.vp;
    }
};

bool my_comp(const obj &a, const obj &b) {
    return a.valPeso > b.valPeso;
}

int calculaVP(vector<obj> &datos, int i, int vpAux, int pAux, int N, int PESO) {
    int k = i + 1;
    while (k < N && pAux + datos[k].peso <= PESO ) {
        vpAux += datos[k].valor;
        pAux += datos[k].peso;
        k++;
    }
    // Incluir si cabe la proporción del k-ésimo obj
    if (k < N) {
        vpAux += ((PESO - pAux) * datos[k].valPeso);
    }
    return vpAux;
}

void btHelper(vector<obj> &datos, int i, int va, int pa, int vp, int N, int PESO, int &valOptimo) {
    if (i < N && pa <= PESO && vp > valOptimo) {
        if (va > valOptimo) {
            valOptimo = va;
        }
        //Si al siguiente objeto
        btHelper(datos, i + 1, va + datos[i + 1].valor, pa + datos[i + 1].peso, vp, N, PESO, valOptimo);
        // No al siguiente objeto
        int vpAux = calculaVP(datos, i +1, va, pa, N, PESO);
        btHelper(datos, i + 1, va, pa, vpAux, N, PESO, valOptimo);
    }
}

int mochBB(vector<obj> &datos, int N, int PESO) {
    priority_queue<node> pq;
    int valOptimo = 0;
    int vp = calculaVP(datos, -1, 0, 0, N, PESO);
    node arranque;
    arranque.niv = -1;
    arranque.va = 0;
    arranque.pa = 0;
    arranque.vp = vp;
    pq.push(arranque);

    while (!pq.empty()) {
        arranque = pq.top();
        pq.pop();

        if (arranque.va == valOptimo) {
            valOptimo = arranque.va;
        }
        if (arranque.vp > valOptimo) {
            arranque.niv++;
            // No incluir al siguiente objeto
            arranque.vp = calculaVP(datos, arranque.niv, arranque.va, arranque.pa, N, PESO);

            if (arranque.vp > valOptimo && arranque.pa <= PESO) {
                pq.push(arranque);
            }
            // Si incluye al siguiente objeto
            arranque.va += datos[arranque.niv].valor;
            arranque.pa += datos[arranque.niv].peso;
            arranque.vp = calculaVP(datos, arranque.niv, arranque.va, arranque.pa, N, PESO);

            if (arranque.vp > valOptimo && arranque.pa <= PESO) {
                pq.push(arranque);
            }
        }
    }

    return valOptimo;
}

// Mochila con Backtracking
// Complejidad: O(2^N)
int mochBT (vector<obj> &datos, int N, int PESO) {
    int valOptimo = 0;
    int vpAux = calculaVP(datos, -1, 0, 0, N, PESO);
    btHelper(datos, -1, 0, 0, vpAux, N, PESO, valOptimo);
    return valOptimo;
}

// Mochila con DP
// Complejidad: O(nP)
int mochDP (vector<obj> &datos, int N, int PESO, int &contDP) {
    int mat[MAXOBJ][MAXMOCH];

    for (int i = 0; i <= N; i++) {
        mat[i][0] = 0;
    }
        for (int j = 0; j < MAXMOCH; j++) {
        mat[0][j] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= PESO; j++) {
            contDP++;
            if (datos[i - 1].peso > j) {
                mat[i][j] = mat[i - 1][j];
            }
            else {
                mat[i][j] = max(mat[i - 1][j], // No incluir al obj i
                            datos[i - 1].valor + mat[i - 1][j - datos[i - 1].peso]);
                            // Si incluir al obj i
            }
        }
    }
    return mat[N][PESO];
}

// Mochila con DyV
// Complejidad: O(2^N)
int mochDyV (vector<obj> &datos, int N, int PESO, int &contDyV) {
    contDyV++;
    if (N == 0) {
        return 0;
    }
    if (datos[N - 1].peso > PESO) {
        mochDyV(datos, N - 1, PESO, contDyV);
    }
    return max(mochDyV(datos, N - 1, PESO, contDyV), // No incluir al obj N
                datos[N - 1].valor + mochDyV(datos, N - 1, PESO - datos[N - 1].peso, contDyV));
                // Si incluir al obj N
}


int main () {

    // N = Cantidad de objetos
    // PESO = Peso que soporta la mochila
    int v, p, N, PESO;
    int contDyV, contDP;
    float vp;

    cin >> N >> PESO;

    vector<obj> datos(N);
    for (int i = 0; i < N; i++) {
        cin >> v >> p;
        vp = v * 1.0/p;
        datos[i].valor = v;
        datos[i].peso = p;
        datos[i].valPeso = vp;
    }

    cout << "===============================" << endl;
    cout << endl;
    cout << "La mochila con DyV es igual a: " << mochDyV(datos, N, PESO, contDyV);
    cout << " con " << contDyV << " operaciones" << endl;
    cout << "La mochila con DP es igual a: " << mochDP(datos, N, PESO, contDP);
    cout << " con " << contDP << " operaciones" << endl;
    sort(datos.begin(), datos.end(), my_comp);
    cout << "La mochila con BT es igual a: " << mochBT(datos, N, PESO);
    // cout << " con " << contDP << " operaciones" << endl;
    cout << endl;
    cout << "La mochila con BB es igual a: " << mochBB(datos, N, PESO);

    return 0;
}

/*
4 16
10 5
40 2
50 10
30 5

3 30
50 5
60 10
140 20

6 89
64 26
85 22
52 4
99 18
39 13
54 9

*/