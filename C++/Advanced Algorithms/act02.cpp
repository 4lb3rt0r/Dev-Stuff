/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 14/Agosto/2022
Actividad 02: Arithmetic Operations Encrypted*/

/* Descripción breve del programa:
Básicamente el algoritmo toma un número entero n (representando la cantidad de operaciones a desencriptar), un dato de tipo string
(representando el alfabeto a utilizar), y dependiendo del valor de n, serían la cantidad de operaciones encriptadas proporcionadas. El programa
arroja las operaciones desencriptadas con un formato específico de paréntesis entre los operandos, el operador entre ambos números y calcular 
el resultado de cada operación.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Función encargada de calcular/retornar el resultado de cada operación encriptada, recibiendo como parámetros los operandos y el operador
desencriptados 
*/
// Complejidad: O(1)
int solver(string sNum1, string sOper, string sNum2) {
    // Conversión de los operandos de string a enteros
    int num1 = stoi(sNum1), num2 = stoi(sNum2), res = 0;
    // Conversión del operador de tipo string a char
    char oper = sOper[0];
    // Por cada operador (4 en total):
    for (int i = 0; i < 4; i++) {
        // Buscamos el caso correspondiente a la operacion a realizar  
        switch(oper) {
            // Caso para el operador '+'
            case '+': {
                res = num1 + num2;
                break;
            }
            // Caso para el operador '-'
            case '-': {
                res = num1 - num2;
                break;
            }
            // Caso para el operador '*'
            case '*': {
                res = num1 * num2;
                break;
            }
            // Caso para el operador '/'
            case '/': {
                res = num1 / num2;
                break;
            }
        }
    }
    // Dependiendo del caso, se retorna el resultado de la operación correspondiente
    return res;
}

/* Función encargada de desencriptar tanto operandos como operadores, recibiendo como parámetros un vector conteniendo los caracteres del
alfabeto y el número/operador encriptados. Al finalizar, se retorna un string con el operando/operador desencriptado.
*/
// Complejidad: O(n^2)
string decryptor(vector<char> codes, string num) {
    // Declaración inicial del string decriptado
    string decryption = "";
    // Vector que almacena los operandos desencriptados
    vector<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/'};
    // Recorremos el vector de caracteres del operador/operando encriptado
    for (int i = 0; i < num.length(); i++) {
        // Recorremos el vector de caracteres del alfabeto encriptado
        for (int j = 0; j < codes.size(); j++) {
            // Si el caracter encriptado es igual al caracter del alfabeto:
            if (num[i] == codes[j]) {
                // Utilizamos el index del caracter encriptado para obtener el caracter desencriptado y lo agregamos al string decriptado
                decryption += digits[j];
            }
        }
    }
    //Retornamos el string decriptado
    return decryption;
}

/* Función encargada de elaborar el resultado final del output que arroja el programa de la forma: (num1) operador (num2) = res
recibiendo como parámetros un vector con el alfabeto a utilizar, los números y operador encriptados. Cada parámetro es desencriptado
y/o utilizado por otras funciones para obtener el string final y retornarlo.  
*/
// Complejidad: O(1)
string outputGenerator(vector<char> codes, string eNum1, string eOper, string eNum2) {
    // Declaración del resultado tipo string
    string output = "";
    // Desencriptamos los números y operador
    string sNum1 = decryptor(codes, eNum1);
    string sOper = decryptor(codes, eOper);
    string sNum2 = decryptor(codes, eNum2);
    // Calculamos el resultado de la operación y la convertimos a string
    string resul = to_string(solver(sNum1, sOper, sNum2));
    // Construimos la estructura del output final de la operación
    output = "(" + sNum1 + ") " + sOper + " (" + sNum2 + ") = " + resul;
    // Retornamos el output final
    return output;
}

/* Función principal del programa, encargada de inicializar variables, solicitar los datos necesarios para realizar la operación desencriptada
y retornar el resultado de la forma: (num1) operador (num2) = res
*/
int main () {
    // Declaración de variables a utilizar
    int n = 0, n1 = 0, n2 = 0;
    char digito = ' ';
    string eNum1 = "", eNum2 = "", eOper = "";
    vector<char> codes = {};
    vector<string> outputs = {};
    // Input de la cantidad de operaciones a desencriptar y realizar con un rango específico
    while (n <= 0 || n >= (10^4)) {
        cin >> n;
    }
    // Ciclo que funciona para recibir el input de cada uno de los caracteres que conforman el alfabeto a utilizar
    for (int i = 0; i < 14; i++) {
        cin >> digito;
        codes.push_back(digito);
    }
    // Por cada operación (n):
    for (int j = 0; j < n; j++) {
        bool status = true;
        while (status) {
            // Recibimos los operandos y operador respectivos
            cin >> eNum1;
            cin >> eOper;
            cin >> eNum2;
            // Desencriptamos los operandos y los convertimos en enteros
            n1 = stoi(decryptor(codes, eNum1));
            n2 = stoi(decryptor(codes, eNum2));
            // Mientras que los 2 números proporcionados sean menores que 10^6:
            if (n1 <= 10^6 || n2 <= 10^6) {
                // No volvemos a solicitar los datos
                status = false;
            }
        }
        // Guardamos en un vector cada output con la operacion y el resultado
        outputs.push_back(outputGenerator(codes, eNum1, eOper, eNum2));
    }
    // Por cada operacion (n):
    for (int k = 0; k < n; k++) {
        // Desplegamos los resultados
        cout << outputs[k] << endl;
    }

    return 0;
}