/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 2/Octubre/2022
Actividad 10: SuperSale */

/* Descripción breve del programa:
El algoritmo de SuperSale se encarga de desplegar el máximo valor de bienes (objetos) que puede
comprar una familia dependiendo de la cantidad, costo, peso de los productos y el peso
soportado por cada individuo de la familia.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definimos los límites máximos tanto para los objetos como para el máximo peso que soporta la mochila
#define MAXOBJ 101
#define MAXMOCH 1001

// Estructura que representa un objeto con los atributos de valor del mismo, su peso y un dato de tipo valor/peso
struct obj {
    int valor, peso;
    float valPeso;
};

/* Función Mochila con DP encargada de regresar el último valor de una
matriz mat[MAXOBJ][MAXMOCH]
*/
// Complejidad: O(NP)
int mochDP (vector<obj> &datos, int N, int PESO) {
    int mat[MAXOBJ][MAXMOCH];

    // Inicializamos la primera columna con 0's
    for (int i = 0; i <= N; i++) {
        mat[i][0] = 0;
    }
    // Inicializamos la primera fila con 0's
    for (int j = 0; j < MAXMOCH; j++) {
        mat[0][j] = 0;
    }
    // Por cada objeto desde 1 hasta (o igual a) el valor de N objetos: 
    for (int i = 1; i <= N; i++) {
        // Por cada cantidad de pesos desde 1 hasta (o igual a) el valor de PESO:
        for (int j = 1; j <= PESO; j++) {
            // Si el peso del objeto actual es mayor a un peso j:
            if (datos[i - 1].peso > j) {
                // Mi objeto [i - 1] no cabe dentro de una mochila de peso j
                mat[i][j] = mat[i - 1][j];
            }
            // Si no, quiere decir que el objeto [i - 1] cabe dentro de una mochila de peso j
            else {
                /* La posición actual [i][j] de la matriz es igual al máximo entre no incluir
                al objeto (mat[i - 1][j] y si incluirlo (datos[i - 1].valor + mat[i - 1][j - datos[i - 1].peso])
                */
                mat[i][j] = max(mat[i - 1][j], // No incluir al obj i
                            datos[i - 1].valor + mat[i - 1][j - datos[i - 1].peso]);
                            // Si incluir al obj i
            }
        }
    }
    // Retornamos el valor que representa la cantidad de objetos que puede soportar la mochila
    return mat[N][PESO];
}

int main () {
    // Declaración de variables iniciales
    int t = 0, n = 0, v = 0, p = 0, pInd, g = 0, acum = 0;
    float vp = 0;
    // Pedimos el valor de la cantidad de casos a evaluar
    cin >> t;

    // Por cada cantidad de casos:
    for (int i = 0; i < t; i++) {
        // Pedimos el valor de la cantidad de objetos en la venta
        cin >> n;
        // El vector de datos de tipo "obj" tendrá un tamaño "n" dependiendo de la cantidad de objetos
        vector<obj> datos(n);
        // Por cada objeto:
        for (int j = 0; j < n; j++) {
            // Pedimos su respectivo valor y peso
            cin >> v >> p;
            // Calculamos su valor/peso como un dato de tipo flotante
            vp = v * 1.0 / p;
            // Guardamos los datos anteriores dentro del vector de tipo obj en cada uno de sus atributos respectivamente
            datos[j].valor = v;
            datos[j].peso = p;
            datos[j].valPeso = vp;
        }
        // Pedimos la cantidad de miembros que conforman la familia que va a comprar
        cin >> g;

        // Por cada miembro de la familia:
        for (int i = 0; i < g; i++) {
            // Pedimos el máximo peso por cada individuo que puede soportar cargar
            cin >> pInd;
            /* Dentro del acumulador se sumará el máximo valor de bienes que se pueden comprar
            entre todos los miembros de la familia */
            acum += mochDP(datos, n, pInd);
        }
        // Desplegamos el acumulador conteniendo el máximo valor de bienes
        cout << acum << endl;
        // Reiniciamos el valor del acumulador para evaluar el siguiente caso (iteración)
        acum = 0;
    }

    return 0;
}

/*
2 
3 
72 17 
44 23 
31 24 
1 
26 
6 
64 26 
85 22 
52 4 
99 18 
39 13 
54 9 
4 
23 
20 
20 
26
*/