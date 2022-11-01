/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 14/Agosto/2022
Actividad 01: Changing the product name*/

/* Descripción breve del programa:
Básicamente el algoritmo toma un número entero n (representando la cantidad de diseñadores contratados), un dato de tipo string
(representando el nombre del producto), y dependiendo de la cantidad de diseñadores contratados, n par de letras en la forma: xi yi.
Por cada par de letras proporcionadas, se modifica el nombre del producto, reemplazando la letra xi por la letra yi y viceversa.
Finalmente y después de los n cambios realizados, se imprime el nombre del producto modificado.
*/

#include <iostream>
#include <string>
// #include <vector>

using namespace std;

/* Función encargada de generar (retornar) un nuevo nombre del producto en base a los siguientes parámetros recibidos: 
nombre original del producto y un par de letras contenidas en variables xi y yi.
*/
// Complejidad: O(n)
string newProductName (string productName, char xi, char yi) {
    // Inicializamos el nuevo nombre del producto
    string newProductName = "";
    // Recorremos el nombre original del producto por caracteres
    for (int i = 0; i < productName.length(); i++) {
        // Si el caracter actual es igual a la letra xi, se reemplaza por la letra yi
        if (productName[i] == xi) {
            newProductName += yi;
        }
        // Si el caracter actual es igual a la letra yi, se reemplaza por la letra xi
        else if (productName[i] == yi) {
            newProductName += xi;
        }
        // Si no, se deja el caracter original
        else {
            newProductName += productName[i];
        } 
    }
    // Retornamos el nombre modificado
    return newProductName;
}

/* Función principal encargada de inicializar los valores de la cantidad de diseñadores (n),
el nombre del producto (productName) y el par de letras a utilizar para modificar el nombre del producto.
Después se reciben los valores de cada uno de estos por medio del usuario para generar el nuevo nombre del producto. 
*/
int main () {

    // Declaramos variables
    int n = 0;
    string productName = "";
    char xi = ' ', yi = ' ';
    // Input de la cantidad de diseñadores y nombre del producto con un rango específico
    while (n <= 0 || n > 200000) {
        cin >> n;
    }
    // Recibimos el nombre del producto modificado
    cin >> productName;
    
    /* Este ciclo for sirve para recopilar cada par de letras a utilizar para modificar el nombre del producto
    y cada iteración representa una modificacion por cada par de letras.
    */
   // Complejidad: O(n)
    for (int i = 0; i < n; i++) {
        // Input del par de letras en formato: xi yi
        cin >> xi;
        cin >> yi;
        /* Sobreescribimos el valor de productName con el nuevo nombre generado por la función newProductName,
        enviando como parámetros el nombre original y el par de letras a modificar.
        */
        productName = newProductName(productName, xi, yi);
    }

    // Desplegamos el nuevo nombre del producto
    cout << productName << endl;


    return 0;
}