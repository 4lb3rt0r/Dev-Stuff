/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 21/Agosto/2022
Actividad 04: Median*/

/* Descripción breve del programa:
Este algoritmo toma un número n que indica el número de casos a evaluar. Luego, por cada caso, recibe un número n que indica la cantidad
de elementos dentro de 2 arreglos de números. El objetivo del programa es que pueda obtener la mediana de los números dentro de ambos arreglos
por medio de una búsqueda binaria.
*/

#include <iostream>
#include <vector>

using namespace std;

// Función encargada de retornar la mediana en caso de si la longitud de los arreglos llega a ser par
// Complejidad: O(1) 
float medianaLista (int list[], int n) {
    // Si el arreglo tiene un tamaño par:
    if (n % 2 == 0) {
        // Retornamos el promedio de los 2 valores de la mitad
        return (list[n / 2] + list[n / 2 - 1]) / 2.0;
    }
    // Si no: 
    else {
        // Retornamos solamente el valor de la mitad
        return list[n / 2];
    }
}

// Función encargada de retornar la mediana en caso de si la longitud de los arreglos es igual o menor que 2
// Complejidad: O(1) 
float medianaHelper (int list1[], int list2[], int n) {
    // Si la cantidad de elementos que quedan en ambos arreglos es 2:
    if (n == 2) {
        // Tomamos lso valores más altos y más bajos de cada lista, los sumamos y dividimos entre 2 para obtener la mediana
        return (max(list1[0], list2[0]) + min(list1[1], list2[1])) / 2.0;
    }
    // Si la cantidad de elementos que quedan en ambos arreglos es 1:
    else {
        // Regresamos el promedio de los 2 valores de en medio
        return (list1[0] + list2[0]) / 2;
    }
}

/* Función encargada de obtener el valor de la mediana por medio de una búsqueda binaria entre ambas listas proporcionadas.
*/
// Complejidad: O(log n) 
float mediana(int list1[], int list2[], int n) {
    // Si el valor de n se encuentra en el rango establecido:
	if((n >= 1) && (n <= 100)) {
        // En caso de que la longitud de la lista sea igual o menor que 2:
	    if ((n == 1) || (n == 2))
            // llamamos a la función encargada de retornar la mediana en caso de que la longitud de los arreglos sea igual o menor que 2
			return medianaHelper(list1, list2, n);

            // Calculamos el valor de las medianas en cada una de las listas
			float mArr1 = medianaLista(list1, n);
			float mArr2 = medianaLista(list2, n);

            // Si la mediana de la lista 1 es igual que la mediana de la lista 2:
			if (mArr1 == mArr2)
                // Retornamos la mediana de la lista 1
				return mArr1;
			// Si la mediana de la lista 1 es menor que la mediana de la lista 2:
			if (mArr1 < mArr2) {
                // En caso de que la longitud vuelva a ser par:
				if (n % 2 == 0)
                // Realizamos 2 llamadas recursivas para obtener la mediana de la lista 1 y la lista 2
					return mediana(list1 + n / 2 - 1, list2, n - n / 2 + 1);
					return mediana(list1 + n / 2, list2, n - n / 2);
			}
	}
    // En caso de que la longitud sea par:
	if (n % 2 == 0)
    // Realizamos 2 llamadas recursivas para obtener la mediana de la lista 1 y la lista 2
		return mediana(list2 + n / 2 - 1, list1, n - n / 2 + 1);
    	return mediana(list2 + n / 2, list1, n - n / 2);
}

// void print (vector<int> list) {
//     for (int i = 0; i < list.size(); i++) {
//         cout << list[i] << " ";
//     }
//     cout << endl;
// }

int main () {
    // Declaración de las variables iniciales
    int t = 0, n = 0;
    float dato = 0;
    vector<float> results = {};

    cin >> t;
    // Ciclo for que itera t veces para obtener los datos correspondientes a cada caso
    for (int i = 0; i < t; i++) {
        cin >> n;
        int list1[n], list2[n];
        // Ciclo for encargado de obtener n cantidad de datos de la lista 1
        for (int j = 0; j < n; j++) {
            cin >>list1[j];
        }
        // Ciclo for encargado de obtener n cantidad de datos de la lista 2
        for (int j = 0; j < n; j++) {
            cin >>list2[j];
        }
        results.push_back(mediana(list1, list2, n));
    }
    // Despliegue de los datos:
    for (int i = 0; i < results.size(); i++) {
        cout << "Median case " << i + 1 << ": ";
        printf("%.02f", results[i]);
        cout << endl;
    }

    return 0;
}