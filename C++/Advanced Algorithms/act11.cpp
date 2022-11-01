/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 9/Octubre/2022
Actividad 11: Sparko Birthday II */

#include <iostream>
#include <climits>
#include <queue>

#define MAX 21

using namespace std;

// Estructura que representa el Nodo de un grafo con sus atributos y sobrecarga del operador "<"
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

/* Función encargada de obtener el costo posible cada vez que se
crea/explora un nodo nuevo dentro del grafo.
*/
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

/* Función TSP encargada de determinar el mejor camino, y por ende,
el mejor costo posible que se obtiene al atravesar dicho camino.
*/
// Complejidad: O(2^n)
int tsp (int matAdj[MAX][MAX], int n) {
    // El costo óptimo o "upper" inicializa con el valor de INF
    int costoOptimo = INT_MAX;
    // Declaración del nodo raíz con sus respectivos atributos:
    Nodo raiz;
    raiz.niv = 0;
    raiz.costoAcum = 0;
    raiz.verticeActual = 1;
    raiz.verticeAnterior = 0;
    raiz.visitados[1] = true;
    // Calculo de su costo posible
    calculaCostoPosible(raiz, matAdj, n);
    // Inicializamos una fila priorizada de tipo "Nodo"
    priority_queue<Nodo> pq;
    // Colocamos el nodo raíz dentro de dicha fila priorizada
    pq.push(raiz);

    // Mientras que la fila priorizada no se encuentre vacía:
    while (!pq.empty()) {
        // Sacamos el primer nodo que se encuentre dentro de la fila priorizada
        Nodo u = pq.top();
        // Eliminamos ese primer nodo de la fila priorizada
        pq.pop();
        // Si el CostoPos de dicho nodo es menor que el CostoOptimo:
        if (u.costoPos < costoOptimo) {
            /* Si entra, quiere decir que vale la pena explorar este camino
            y generar todos los posibles hijos de este nodo*/

            // Para cada hijo generamos un nuevo nodo y declaramos sus respectivos atributos
            for (int i = 1; i <= n; i++) {
                // Si se trata de un nodo que no hemos visitado:
                if (!u.visitados[i]) {
                    // Declaramos los atributos del nodo hijo
                    Nodo son;
                    son.niv = u.niv + 1;
                    son.costoAcum = u.costoAcum + matAdj[u.verticeActual][i];
                    son.verticeActual = i;
                    son.verticeAnterior = u.verticeActual;
                    copy(begin(u.visitados), end(u.visitados), begin(son.visitados));
                    son.visitados[i] = true;

                    // Si el costo acumulado del nodo hijo es menor que 0:
                    if (son.costoAcum < 0) {
                        // El costo acumulado del nodo hijo es INF
                        son.costoAcum = INT_MAX;
                    }

                    // Calculamos el costo posible de dicho nodo hijo
                    calculaCostoPosible(son, matAdj, n);

                    //  Si el costo posible del nodo hijo es menor que 0:
                    if (son.costoPos < 0) {
                        // El costo posible del nodo hijo es INF
                        son.costoPos = INT_MAX;
                    }

                    // Si el nivel del nodo hijo es igual que n - 2 (nodo hoja) y su costo posible es menor que el costo optimo:
                    if (son.niv == n - 2 && son.costoPos < costoOptimo) {
                        // El costo optimo es igual al costo posible del nodo hijo
                        costoOptimo = son.costoPos;
                    }
                    // Si el nivel del nodo hijo es menor que n - 2 (nodo hoja) y su costo posible es menor que el costo optimo:
                    if (son.niv < n - 2 && son.costoPos < costoOptimo) {
                        // Metemos este nodo dentro de la fila priorizada
                        pq.push(son);
                    }
                }
            }
        }
    }
    // Retornamos el valor final del costo optimo que representa el mejor camino
    return costoOptimo;
}

/*Función encargada de inicializar la matriz de adyacencias con valores infinitos
excepto cuando se trate de una conexión de un nodo a él mismo, ya que este caso no
es posible dentro del contexto del problema.
*/
void iniciaMat (int matAdj[MAX][MAX]) {
    // Por cada columna de la matriz de adyacencias:
    for (int i = 0; i < MAX; i++) {
        // Colocamos valores de 0 entre las conexiones de un nodo a sí mismo
        matAdj[i][i] = 0;
        // Por cada fila de la matriz de adyacencias:
        for (int j = i + 1; j < MAX; j++) {
            // Colocamos valores infinitos
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

/* Función encargada de recopilar y guardar todas los m arcos
existentes entre nodos dentro de la matriz de adyacencias
*/
void leeArcos (int matAdj[MAX][MAX], int m) {
    // Inicializamos las variables que representan los nodos
    char a, b;
    // Inicializamos la variable que representa el costo de ese arco
    int c;

    // Por cada arco existente:
    for (int i = 0; i < m; i++) {
        // Pedimos 2 nodos y su respectivo costo de arco
        cin >> a >> b >> c;
        // Guardamos dicha conexión dentro de la matriz de adyacencias:
        matAdj[a - 'A' + 1][b - 'A' + 1] = matAdj[b - 'A' + 1][a - 'A' + 1] = c;
    }
}

int main () {
    // Declaración de variables iniciales
    // n = Cantidad de Nodos
    // m = Cantidad de Arcos

    int n, m;
    cin >> n >> m;
    // Matriz de adyacencias
    int matAdj[MAX][MAX];
    // Inicializamos la matriz de adyacencias
    iniciaMat(matAdj);
    // Recopilamos todos los datos de los nodos y sus costos de arco
    leeArcos(matAdj, m);
    // print(matAdj, n);

    // Si el costo optimo existe:
    if (tsp(matAdj, n) != INT_MAX) {
        // Desplegamos ese costo optimo
        cout <<  tsp(matAdj, n)  << endl;
    }
    // Si no existe el costo optimo:
    else {
        // Desplegamos INF
        cout << "INF" << endl;
    }

    return 0;
}

/*
4 5 
A B 5 
A C 10 
A D 8 
B C 2 
C D 1

Output: 16

5 7 
A B 4 
A C 8 
A D 2 
B C 7 
B D 2 
C D 1 
D E 3

Output: INF

7 11 
A B 2 
A C 4 
A D 6 
B C 2 
B E 6 
C D 1 
C E 3 
D E 2 
D F 3 
E G 5 
F G 4

Output: 25

5 10 
A B 4 
A C 8 
A D 5 
A E 3 
B C 7 
B D 2 
B E 2 
C D 1 
C E 4 
D E 3

Output: 14
*/