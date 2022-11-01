/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 25/Septiembre/2022
Actividad 08: Audiophobia */

/* Descripción breve del programa:
El algoritmo recibe n cantidad de casos, los cuales consisten en evaluar el mapa de una ciudad (una especie de grafo),
que tiene como aristas las calles y los nodos como esquinas. Cada una de las calles posee un nivel promedio de decibeles,
y dichas calles conforman un camino compuesto por otras calles. El código obtiene el máximo valor de cada trayectoria, y de 
esos valores máximos retorna el mínimo valor. Esto con el fin de determinar qué trayectoria es la más tolerable y óptima para
llegar de un punto determinado a otro de esquina a esquina (nodo a nodo). 
*/

#include <iostream>
#include <climits>

using namespace std;

#define MAX 100

/* Función encargada de inicializar los valores de las matrices "mat" de costos y "p" de trayectorias.
Además, coloca el valor promedio en decibeles de ruido correspondiente a 2 nodos (esquinas). 
*/
void leeArcos (int mat[MAX][MAX], int p[MAX][MAX], int m) {
    int a, b, c; // de Nodo a <-> b con costo
    // Incialización de matriz
    for (int i = 0; i < MAX; i++) {
        mat[i][i] = 0;
        p[i][i] = -1; // -1 significa Conexión Directa
        for (int j = i + 1; j < MAX; j++){
            mat[i][j] = mat[j][i] = INT_MAX; // INT_MAX = infinito
            p[i][j] = p[j][i] = -1; // Significa que no existe un nodo intermedio
        }
    }
    for (int i = 0; i < m; i++) {
        //  Recordar que la base es 0 para los arreglos
        // base1 para la entrada del programa
        cin >> a >> b >> c;
        mat[a - 1][b - 1] = mat[b - 1][a - 1] = c;
    }
}
/* Función encargada de determinar el mejor camino para pasar mediante el recorrido de la
matriz de costos "mat". Esta comprobará si la sumatoria del costo de las posiciones mat[i][k] y
mat[k][j] es menor que el costo guardado en la posicion actual mat[i][j]. Si lo anterior se cumple,
actualizamos el valor en mat[i][j] por el costo menor, e indicamos dentro de p[i][j] que el mejor camino
a recorrer es por k.
*/
// Complejidad: O(n^3)
void floyd(int mat[MAX][MAX], int p[MAX][MAX], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                /* Se obtiene el valor máximo entre mat[i][k] y mat[k][j], y en base a ese valor máximo,
                se obtiene el valor mínmo entre ambos comparandolo con mat[i][j] para posteriormente
                sobreescribir el valor de mat[i][j] con el resultado obtenido
                */
                mat[i][j] = min(max(mat[i][k],mat[k][j]), mat[i][j]);
            }
        }
    }
}

/* Función encargada de desplegar la trayectoria con mejor costo desde el nodo "a" hasta
un valor del nodo de en medio y desde ese valor del nodo de en medio hasta el nodo final
*/
void checaTrayectoria (int p[MAX][MAX], int x, int y) {
    // Si la conexión no se trata de una conexión directa entre nodos (osea que sea una conexión de 2 nodos a -> b):
    if (p[x][y] != -1) {
        /* Desplegamos la trayectoria desde el inicia (a) hasta el número de 
        en medio (p[x][y]) y desde ese número de en medio hasta el final (b)
        */
        checaTrayectoria(p, x, p[x][y]);
        cout << (p[x][y] + 1) << "-"; //+1 pq es base1 el usuario
        checaTrayectoria(p, p[x][y], y);
    }
}

/* Función encargada de determinar y desplegar los mejores costos y la respectiva 
trayectoria que conforma dicho costo. 
*/
void consultas(int mat[MAX][MAX], int p[MAX][MAX], int q) {
    int a, b; // De cual a cual quieres consultar
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        // De ser que no exista conexión entre el nodo a con el b dentro de la trayectoria dada:
        if (mat[a - 1][b - 1] == INT_MAX) {
            cout << "no path" << endl;
        }
        // Si existe un camino:
        else {
            // Desplegamos el costo de la trayectoria y la misma trayectoria
            cout << mat[a - 1][b - 1] << endl;
            // checaTrayectoria(p, a - 1, b - 1);
            // cout << b << endl;
        }
    }
}

/* Función encargada de imprimir el contenido de la matriz de costos "mat"
y de la matriz de trayectorias "p"
*/
void print (int mat[MAX][MAX], int p[MAX][MAX], int n) {
    cout << "La matriz de costos: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Si no existe conexión entre ambos nodos:
            if (mat[i][j] == INT_MAX) {
                // Desplegamos "INF\t"
                cout << "INF\t";
            }
            // Si existe conexión:
            else {
                // Depslegamos el costo contenido en mat[i][j]
                cout << mat[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout << "La matriz de trayectorias: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << p[i][j] << "\t";
        }
        cout << endl;
    }
}

int main () {
    // Declaración de variables iniciales
    int mat[MAX][MAX], p[MAX][MAX];
    int t, n, m, q;
    // t = Cantidad de Casos
    // n = Cantidad de Nodos
    // m = Cantidad de Arcos
    // q = Cantidad de Consultas
    // Pedimos al usuario la cantidad de casos a evaluar
    cin >> t;
    // Por cada caso:
    for (int i = 0; i < t; i++) {
        // Pedimos cantidad de nodos, cantidad de arcos y cantidad de consultas
        cout << "Case " << i + 1 << ":" << endl;
        cin >> n >> m >> q;
        leeArcos(mat, p, m);
        floyd(mat, p, n);
        //print(mat, p ,n);
        consultas(mat, p, q);
    }

    return 0;
}

/*
1
7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
*/

/*
1
3 2 2
1 2 1
1 3 1
2 3
3 2
*/