/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 16/Octubre/2022
Actividad 13: Cutting Sticks */

#include <iostream>
#include <climits>

using namespace std;

// Definimos un valor máximo para las dimensiones de las matrices
#define MAX 51

// Función encargada de inicializar las matrices D y P en ceros
void inicMat (int D[MAX][MAX], int P[MAX][MAX]) {
    // Por cada columna de la matriz hasta MAX:
    for (int i = 0; i < MAX; i++) {
        // Por cada fila de la matriz hasta MAX:
        for (int j = 0; j < MAX; j++) {
            // Tanto en la matriz D como en la matriz P se coloca el valor de 0 en todas las posiciones
            D[i][j] = P[i][j] = 0;
        }
    }
}

// Función encargada de recopilar todos los datos requeridos por parte del usuario
void lee(int d[MAX], int &n, int &l) {
    /* El arreglo d en la posición 0 es igual a 0, esto debido a
    que la tabla debe tomar en cuenta su medida desde 0.
    */
    d[0] = 0;

    // Obtenemos el valor de la cantidad de cortes a realizar en la tabla
    cin >> n;

    // Por cada corte en la tabla:
    for (int i = 1; i <= n; i++) {
        // Obtenemos los valores (costos) de cada corte
        cin >> d[i];
    }
    
    // El último valor dentro del arreglo siempre será la longitud inicial de la tabla
    d[n + 1] = l;
}

/* Función encargada de calcular en base a la lógica del algoritmo de 
GodBole o Matrix Chain Multiplication, la jerarquía de producto de matrices,
o en este caso, la jerarquía u orden en que se debe cortar la tabla de forma
que se obtenga el menor costo posible de dichos cortes.
*/
// Complejidad: O(n^3)
void calcula (int D[MAX][MAX], int P[MAX][MAX], int d[MAX], int n) {
    // Por cada diagonal en la matriz de forma D[0][0] y P[0][0]:
    for (int i = 1; i <= n; i++) {
        // El valor será igual a 0
        D[i][i] = P[i][i] = 0;
    }
    // Para cada diagonal:
    for (int diag = 1; diag < n; diag++) {
        for (int i = 1; i <= n - diag; i++) {
            // j será igual a i + diag
            int j = i + diag;
            // Inicializamos el valor mínimo con un valor infinito
            int min = INT_MAX;
            // Inicializamos la variable minK para almacenar la posición del elemento mínimo encontrado
            int minK;
            // Para cada posible corte de la tabla:
            for (int k = i; k < j; k++) {
                // Calculamos con la fórmula el costo del corte correspondiente
                int multEsc = D[i][k] + D [k + 1][j] + abs(d[j] - d[i - 1]);
                // Si este costo es menor que el costo mínimo actual:
                if (multEsc < min) {
                    // Asignamos el nuevo valor mínimo al costo calculado anteriormente
                    min = multEsc;
                    // Guardamos la posición de dicho costo
                    minK = k;
                }
            }
            // Guardamos el costo mínmo calculado dentro de D en la posición [i][j] actual
            D[i][j] = min;
            // Guardamos la posición del costo mínimo calculado dentro de P en la posición [i][j] actual
            P[i][j] = minK;
        }
    }
}

// Función encargada de desplegar los valores contenidos en las matrices D Y P
void despM (int D[MAX][MAX], int P[MAX][MAX], int n) {
    cout << "Matriz D" << endl;;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << D[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "==========================" << endl;
    cout << "Matriz P" << endl;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << P[i][j] << "\t";
        }
        cout << endl;
    }
}

/* Función encargada de desplegar la jerarquía de producto de matrices final,
o bien, el orden con el costo mínimo para llevar a cabo los cortes de la tabla.*/
void recorre (int P[MAX][MAX], int ini, int fin) {
    if (P[ini][fin] != 0) {
        cout << "(";
        recorre(P, ini, P[ini][fin]);
        cout << ")x(";
        recorre(P, P[ini][fin] + 1, fin);
        cout << ")";
    }
    else {
        char ch = 'A' + ini - 1;
        cout << ch;
    }
}

// Función encargada de llamar a la función recorre
void despliega (int P[MAX][MAX], int n) {
    recorre(P, 1, n);
    cout << endl;
}

int main () {
    // Declaración de variables iniciales
    int d[MAX]; // Las dimensiones de las matrices
    // D guarda las multiplicaciones mínimas escalares desde la matriz i hasta la matriz j
    // P guarda la k que minimiza las MEM Mi...Mj

    int D[MAX][MAX], P[MAX][MAX];
    int n, l = -1;

    // Obtenemos el valor de la longitud de la tabla
    cin >> l;

    // Mientras que la longitud no sea igual a 0:
    while (l != 0) {
        // Inicializamos las matrices D y P
        inicMat(D, P); // Inicializa Matrices
        // Obtenemos los datos por parte del usuario
        lee(d, n, l); // Lee los datos de dimen y la n
        /* Aumentamos el rango de recorrido de las matrices,
        esto debido a que agregamos l al final del array d,
        por lo que necesitamos aumentar la dimensión de las matrices
        por 1 fila y 1 columna*/
        n++;
        // Calculamos los costos mínimos por corte de la tabla
        calcula(D, P, d, n);
        // Desplegamos la posicion D[1][n], que es dónde se encuentra nuestro costo mínimo final
        cout << "The minimum cutting is " << D[1][n] << "." << endl;
        // despliega(P, n);
        // despM(D, P ,n);

        cin >> l;
    }

    return 0;
}

/*
100  
3  
25 50 75  
10  
4  
4 5 7 8  
0
*/