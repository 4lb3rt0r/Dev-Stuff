/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 11/Septiembre/2022
Actividad 07: Longest Common Subsequence*/

/* Descripción breve del programa:
El algoritmo recibe 2 strings principales, con ello este debe de hallar el/las subsecuencuas más larga(s)
que son subsecuencias de estos ambos strings. Esto se evalua gracias a una matriz que va evaluando
las similitudes entre ambos substrings y regresa la cantidad de coincidencias. 
*/

#include <iostream>
#include <string>

using namespace std;

/* Función encargada de obtener todas las coincidencias de las subsecuencias pertenecientes
respectivamente al string1 y al string2
*/
// Complejidad: O(n*m) o bien O(n1*n2) o si lo vemos de otra forma sería O(n^2)
int lcSubsequence(string s1, string s2) {
    // Declaración de la matriz de tamaño s1.length() por s2.length()
    int mat[s1.length()][s2.length()];
    // Si el elemento 0 del string1 es igual al elemento 0 del string2:
    if (s1[0] == s2[0]) {
        // El elemento [0][0] de la matriz es igual a 1
        mat[0][0] = 1;
    }
    // Si no:
    else {
        // El elemento [0][0] de la matriz es igual a 0
        mat[0][0] = 0;
    }
    // Recorrido de s1.length() filas con 0 columnas
    for (int i = 1; i < s1.length(); i++) {
        // Si el elemento i del string1 es igual al elemento 0 del string2:
        if (s1[i] == s2[0]) {
            // El elemento [i][0] de la matriz es igual a 1
            mat[i][0] = 1;
        }
        // Si no:
        else {
            // El elemento [i][0] de la matriz es igual al elemento [i - 1] [0]
            mat[i][0] = mat[i - 1][0];
        }
    }
    // Recorrido de s2.length() columnas con 0 filas
    for (int i = 1; i < s2.length(); i++) {
        // Si el elemento i del string2 es igual al elemento 0 del string1:
        if (s2[i] == s1[0]) {
            // El elemento [0][i] de la matriz es igual a 1
            mat[0][i] = 1;
        }
        // Si no:
        else {
            // El elemento [0][i] de la matriz es igual al elemento [0] [i - 1]
            mat[0][i] = mat[0][i - 1];
        }
    }
    // Recorrido del resto de la matriz tomando en cuenta a s1.length() y s2.length()
    for (int i = 1; i < s1.length(); i++) {
        for (int j = 1; j < s2.length(); j++) {
            // Si el caracter i de string1 es igual al caracter j del string2:
            if (s1[i] == s2[j]) {
                // El elemento [i][j] de la matriz es igual a la suma del elemento [i - 1][j - 1] y 1
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            // Si no:
            else {
                // El elemento [i][j] de la matriz es igual al máximo elemento entre la posicion [i - 1][j] y [i][j - 1]
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            }
        } 
    }
    // Retornamos el último elemento en la posición [string1.length()][s2.length()]
    return mat[s1.length() - 1][s2.length() - 1];
}

int main () {
// Declaración de variables iniciales
    int n = 0;
    string s1, s2;
    // Input de n
    cin >> n;
    // Por cada cantidad n de casos a evaluar
    for (int i = 0; i < n; i++) {
        // Pedimos al usuario el valor de los 2 strings a comparar
        cin >> s1 >> s2;
        // Deplegamos el texto correspondiente con la cuenta de coincidencias
        cout << "Case " << i + 1 << ": " << lcSubsequence(s1, s2) << endl; 
    }

    return 0;
}
