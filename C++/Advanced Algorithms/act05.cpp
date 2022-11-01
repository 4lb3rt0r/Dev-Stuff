/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 4/Septiembre/2022
Actividad 05: Rail Road*/

/* Descripción breve del programa:
El algoritmo toma 2 vagones que son evaluados de forma que ambos en conjunto puedan igualar
una salida dada por el usuario. Si la combinación entre ellas es igual al tren de salida, el programa
lo desplegará el texto "possible", si no, desplegará "not possible".
*/

#include <iostream>

using namespace std;

/* Función encargada de evaluar la compatibilidad de la combinación de 2 trenes con el tren de salida. El registro
de las posibilidades se apoya en una matriz, de la cuál su último valor booleano determinará dicha compatibilidad, por ende
ese será el valor de retorno. Los valores recibidos son el tren 1 y 2 con sus respectivas longitudes y el tren de salida.*/
// Complejidad: O(n*m) o bien O(n1*n2) o si lo vemos de otra forma sería O(n^2)
bool solve (int n1, int n2, int t1[], int t2[], int sal[]) {
    // Declaración de la matriz booleana
    bool solve[n1 + 1][n2 + 1];
    // Caso base de la matriz sin utilizar t1 ni t2
    solve[0][0] = true;
    // Recorrido de n2 columnas con 0 filas
    for (int i = 1; i < n2 + 1; i++) {
        // Si el vagón i de tren de salida es igual a vagón i de t2 y no llevamos un mal recorrido (osea valores falsos):
        if (sal[i] == t2[i] && solve[0][i - 1]) {
            // Insertamos un valor verdadero en la posición [0][i]
            solve[0][i] = true;
        }
        // Si no se cumple lo anterior:
        else {
            // Simplemente descartamos el caso colocando un falso
            solve[0][i] = false;
        }
    }
    // Recorrido de n1 filas con 0 columnas
    for (int i = 1; i < n1 + 1; i++) {
        // Si el vagón i de tren de salida es igual a vagón i de t1 y no llevamos un mal recorrido (osea valores falsos):
        if (sal[i] == t1[i] && solve[i - 1][0]) {
            // Insertamos un valor verdadero en la posición [i][0]
            solve[i][0] = true;
        }
        // Si no se cumple lo anterior:
        else {
            // Simplemente descartamos el caso colocando un falso
            solve[i][0] = false;
        }
    }
    // Recorrido del resto de la matriz tomando en cuenta a t1 y t2
    for (int i = 1; i < n1 + 1; i++) {
        for (int j = 1; j < n2 + 1; j++) {
            // Si el vagón i de t1 o t2 es igual al vagón i de la salida y llevamos buen recorrido:
            if (sal[i + j] == t1[i] && solve[i - 1][j] || sal[i + j] == t2[j] && solve[i][j - 1]) {
                // Insertamos un valor verdadero en la posición [i][j]
                solve[i][j] = true;
            }
            // Si no se cumple lo anterior:
            else {
                // Simplemente descartamos el caso colocando un falso
                solve[i][j] = false;
            }
        }
    }
    //print de la matriz
    /*for (int i = 0; i < n1 + 1; i++) {
        for (int j = 0; j < n2 + 1; j++) {
            cout << solve[i][j] << " ";
        }
        cout << endl;
    }*/
    // Retornamos el último valor de la matriz que determina la compatibilidad de ambos trenes con el tren de salida
    return solve[n1][n2]; 
}

int main () {
    // Declaración de variables iniciales
    int n1, n2, dato = 0;
    // Input de n1 y n2
    cin >> n1 >> n2;
    // Si n1 y n2 sean diferentes de 0 seguiremos pidiendo valores
    while (n1 != 0 && n2 != 0) {
        // Declaración de los 3 trenes
        int t1[n1], t2[n2], sal [n1 + n2];
        // Inserción de valores dummy
        t1[0] = -1, t2[0] = -1, sal[0] = -1;
        // Input de n1 datos del tren 1
        for (int i = 1; i < n1 + 1; i++) {
            cin >> dato;
            t1[i] = dato;
        }
        // Input de n2 datos del tren 2
        for (int i = 1; i < n2 + 1; i++) {
            cin >> dato;
            t2[i] = dato;
        }
        // Input de n1 + n2 datos del tren salida
        for (int i = 1; i < n1 + n2 + 1; i++) {
            cin >> dato;
            sal[i] = dato;
        }
        // Si la combinación de t1 y t2 es compatible con el tren salida:
        if (solve(n1, n2, t1, t2, sal)) {
            // Desplegamos "possible"
            cout << "possible" << endl;
        }
        // Si no:
        else {
            // Desplegamos "not possible"
            cout << "not possible" << endl;
        }
        // Volvemos a pedir los valores de n1 y n2
        cin >> n1 >> n2;
    }

    return 0;
}