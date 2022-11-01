/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 6/Octubre/2022
Ejem 14. El Problema del Viajero (Traveling Salesman Problem) con Branch & Bound*/

#include <iostream>
#include <climits>
#include <queue>

#define MAX 21

using namespace std;

struct Nodo {
    int niv; // Nivel del nodo dentro del árbol de búsq. soluciones
    int costoAcum; // Costo acumulado hasta ese punto
    int costoPos; // Costo posible de esta trayectoria
    int verticeAnterior;
    int verticeActual;
    bool visitados[MAX] = {false};
    bool operator<(const Nodo &otro) const { // Para que la fila priorizada tenga prioridad
        return costoPos >= otro.costoPos; // Menor costo posible
    }
};

void calculaCostoPosible (Nodo &nodoActual, int matAdj[MAX][MAX], int n) {
    nodoActual.costoPos = nodoActual.costoAcum;
    int costoObtenido;

    for (int i = 1; i <= n; i++) {
        // No he visitado al nodo i o es el último que visité
        costoObtenido = INT_MAX;
        if (!nodoActual.visitados[i] || i == nodoActual.verticeActual) {
            if (!nodoActual.visitados[i]) { // Al nodo i no lo he visitado
                for (int j = 1; j <= n; j++) {
                    if (i != j && (!nodoActual.visitados[j] || j == 1)) {
                        costoObtenido = min(costoObtenido, matAdj[i][j]);
                    }
                }
            }
            else { // El nodo i es el último visitado
                for (int j = 1; j <= n; j++) {
                    if (!nodoActual.visitados[j]) {
                        costoObtenido = min(costoObtenido, matAdj[i][j]);
                    }
                }
            }
            if (costoObtenido == INT_MAX) {
                nodoActual.costoPos = INT_MAX;
            }
            else {
                nodoActual.costoPos += costoObtenido;
            }
        }

    }
}

// Complejidad: O(2^n)
int tsp (int matAdj[MAX][MAX], int n) {
    int costoOptimo = INT_MAX;
    Nodo raiz;
    raiz.niv = 0;
    raiz.costoAcum = 0;
    raiz.verticeActual = 1;
    raiz.verticeAnterior = 0;
    raiz.visitados[1] = true;
    calculaCostoPosible(raiz, matAdj, n);
    priority_queue<Nodo> pq;
    pq.push(raiz);

    while (!pq.empty()) {
        // Sacar de pq;
        Nodo u = pq.top();
        pq.pop();
        // ver si el CostoPos < CostoOptimo
        if (u.costoPos < costoOptimo) {
            // SI, generar todos los posibles hijos de este nodo
            // Para cada hijo generar un nuevo nodo, actualizar los datos
            for (int i = 1; i <= n; i++) {
                if (!u.visitados[i]) {
                    Nodo son;
                    son.niv = u.niv + 1;
                    son.costoAcum = u.costoAcum + matAdj[u.verticeActual][i];
                    son.verticeActual = i;
                    son.verticeAnterior = u.verticeActual;
                    copy(begin(u.visitados), end(u.visitados), begin(son.visitados));
                    son.visitados[i] = true;

                    if (son.costoAcum < 0) {
                        son.costoAcum = INT_MAX;
                    }

                    calculaCostoPosible(son, matAdj, n);

                    if (son.costoPos < 0) {
                        son.costoPos = INT_MAX;
                    }

                    // y cuando el nivel == n - 2 (nodo hoja), calcular el costo real
                    if (son.niv == n - 2 && son.costoPos < costoOptimo) {
                        costoOptimo = son.costoPos;
                    }
                    // Si el nivel < n - 2 .... checar si el costo posible es mejor
                    // que el costo optimo y lo metes a la pq.
                    if (son.niv < n - 2 && son.costoPos < costoOptimo) {
                        pq.push(son);
                    }
                }
            }
        }
    }
    return costoOptimo;
}

void iniciaMat (int matAdj[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        matAdj[i][i] = 0;
        for (int j = i + 1; j < MAX; j++) {
            matAdj[i][j] = matAdj[j][i] = INT_MAX;
        }
    }
}

// void print(int matAdj[MAX][MAX], int n) {
//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= n; j++) {
//             if (matAdj[i][j] != INT_MAX) {
//                 cout << matAdj[i][j] << " ";
//             }
//             else {
//                 cout << "INF" << " ";
//             }
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

void leeArcos (int matAdj[MAX][MAX], int m) {
    char a, b;
    int c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        matAdj[a - 'A' + 1][b - 'A' + 1] = matAdj[b - 'A' + 1][a - 'A' + 1] = c;
    }
}

int main () {

    // n = Cantidad de Nodos
    // m = Cantidad de Arcos

    int n, m;
    cin >> n >> m;

    int matAdj[MAX][MAX];

    iniciaMat(matAdj);
    leeArcos(matAdj, m);
    // print(matAdj, n);

    if (tsp(matAdj, n) != INT_MAX) {
        cout <<  tsp(matAdj, n)  << endl;
    }
    else {
        cout << "INF" << endl;
    }


    return 0;
}