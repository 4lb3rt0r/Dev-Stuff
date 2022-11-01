/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 21/Agosto/2022
Actividad 03: Invest*/

/* Descripción breve del programa:
Este algoritmo toma un número n que indica el número de casos a evaluar. Luego, por cada caso, recibe un número d que indica la cantidad de
de días que se tomarán en cuenta. Finalmente se ingresa por cada día un precio que en conjunto con los demás precios serviran como referente
para determinar qué día es mejor para realizar una compra y venta de inversiones.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Función encargada de determinar el mejor caso para compra - venta de las 3 subdivisiones del arreglo: compra y venta izquierda, compra y
venta derecha y compra y venta mixta.
*/
// Complejidad: O(1)
void invHelper(vector<int> &precios, int bLeft, int sLeft, int bRight, int sRight, int bMix, int sMix, int &buy, int &sell) {
    // Declaración de las ganancias mediante la diferencia entre compra y venta para cada caso:
    // Ganancia en el caso de la izquierda
    int leftBest = precios[sLeft] - precios[bLeft];
    // Ganancia en el caso de la derecha
    int rightBest = precios[sRight] - precios[bRight];
    // Ganancia en el caso mixto
    int mixBest = precios[sMix] - precios[bMix];

    // Se determina el mejor caso para compra y venta de las 3 subdivisiones:
    // Si la ganancia del caso de la izquierda es mayor:
    if (leftBest > rightBest && leftBest > mixBest) {
        // La mejor compra y venta se encuentra en la izquierda
        buy = bLeft;
        sell = sLeft;
    }
    // Si la ganancia del caso de la derecha es mayor:
    else if (rightBest > mixBest) {
        // La mejor compra y venta se encuentra en la derecha
        buy = bRight;
        sell = sRight;
    }
    // Si no es alguno de los casos anteriores:
    else {
        // La mejor compra y venta se encuentra en el caso mixto
        buy = bMix;
        sell = sMix;

    }
}

/* Función encargada de dividir el arreglo en 3 secciones para facilitar la búsqueda binaria de los 3 mejores
casos de compra y venta.
*/
// Complejidad: O(n log)
void inv(vector<int> &precios, int start, int end, int &buy, int &sell) {
    // Si el arreglo tiene más de un elemento:
    if (start < end) {
        int bLeft = 0, sLeft = 0, bRight = 0, sRight = 0, bMix = 0, sMix = 0, bAux = precios[buy], sAux = precios[sell];
        int mid = (start + end) / 2;
        buy = start;
        sell = mid + 1;

        // Llamadas recursivas para dividir el arreglo
        inv(precios, start, mid, bLeft, sLeft);
        inv(precios, mid + 1, end, bRight, sRight);

        // Buscamos el valor de compra más barato del lado izquierdo
        for (int i = start; i <= mid; i++) {
            if (bAux >= precios[i]) {
                bAux = precios[i];
                buy = i;
            }
        }
        // Buscamos el valor de venta más caro del lado derecho
        for (int i = mid + 1; i <= end; i++) {
            if (sAux < precios[i]) {
                sAux = precios[i];
                sell = i;
            }
        }
    }
    // Si el arreglo posee solamente un elemento:
    else {
        // Se determina que el mejor caso para compra y venta es el único día que se tiene disponible
        buy = start;
        sell = start;
    }
}

// Función encargada de generar el texto de output del programa
// Complejidad: O(1) 
string outputGenerator(int buy, int sell) {
    string output = "";
    string b = to_string(buy + 1);
    string s = to_string(sell + 1);
    output = "Buy in " + b + ", sell in " + s;
    return output;
}

int main() {
    // Declaración de las variables iniciales
    int n = 0, d = 0;
    vector<string> results = {};

    cin >> n;
    // Repetimos el proceso de recopilaciones de datos por cada caso
    for (int i = 0; i < n; i++) {
        int precio = 0, buy = 0, sell = 0;
        vector<int> precios = {};
        cin >> d;
        // Repetimos el proceso de recopilacion de datos por cada día
        for (int j = 0; j < d; j++) {
            cin >> precio;
            precios.push_back(precio);
        }
        // Llamamos a la función inv() para modificar el valor de la compra y venta según el caso
        inv(precios, 0, precios.size() - 1, buy, sell);
        // Guardamos el texto de output correspondiente
        results.push_back(outputGenerator(buy, sell));
    }
    // Desplegamos los n outputs dependiendo de la cantidad de casos
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }

    return 0;
}