#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>
#include <conio.h>
using namespace std;
#include "Fraccion.h"

void startTime(struct timeval &begin) {
    gettimeofday(&begin, 0);
}

void getTime(struct timeval begin, struct timeval end) {
    long seconds, microseconds;
    double elapsed;
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed);
}

template<class T>
void swap(vector<T>& list, int i, int j) {
    // Creamos una variable auxiliar para guardar el valor de la posición i
    T aux = list[i];
    // Asignamos el valor de la posición j a la posición i
    list[i] = list[j];
    // Asignamos el valor de la posición i (aux) a la posición j
    list[j] = aux;
}


template<class T>
void print(vector<T> list) {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

template <class T>
void swapSort(vector<T>& list, int &nSwaps, int &nComparisons) {
    // Tiempo inicial
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    // Recorremos la lista desde el inicio hasta el penúltimo elemento
    for (int i = 0; i < list.size()-1; i++) {
        // Recorremos la lista desde el siguiente elemento hasta el final
        for (int j = i+1; j < list.size(); j++) {
            // Si el elemento actual (i) es mayor que el elemento (j), intercambiamos
            nComparisons++;
            if(list[i] > list[j]) {
                // Hacemos el intercambio
                swap(list, i, j);
                nSwaps++;
            }
        }
    }
    // Tiempo final
    gettimeofday(&end, 0);
    getTime(begin, end);
}

template <class T>
void bubbleSort(vector<T>& list, int &nSwaps, int &nComparisons) {
    // Tiempo inicial
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    // Crear una variable auxiliar con el tamaño de la lista - 1
    int aux = list.size()-1;
    // Creamos una variable booleana para saber si hubo intercambios
    bool swapped = true;
    // Recorremos la lista hasta que no haya intercambios y terminemos de validar
    while (aux > 0 && swapped) {
        // Inicializamos la variable booleana a false
        swapped = false;
        // Recorremos la lista desde el inicio hasta el penúltimo elemento
        for (int i = 0; i < aux; i++) {
            // Si el elemento actual (i) es mayor que el elemento siguiente (i+1), intercambiamos
            // Incrementamos el contador de comparaciones
            nComparisons++;
            if(list[i] > list[i+1]) {
                // Hacemos el intercambio
                swap(list, i, i+1);
                // incrementamos el contador de intercambios
                nSwaps++;
                // Cambiamos la variable booleana a true
                swapped = true;
            }
        }
        // Decrementamos el contador auxiliar
        aux--;
    }
    // Tiempo final
    gettimeofday(&end, 0);
    getTime(begin, end);
}

template <class T>
void selectionSort(vector<T>& list, int &nSwaps, int &nComparisons) {
    // Tiempo inicial
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    // Recorremos la lista desde el inicio hasta el penúltimo elemento
    for (int i = 0; i < list.size()-1; i++) {
        // Creamos una variable auxiliar para guardar la posición i
        int min = i;
        // Recorremos la lista desde el siguiente elemento hasta el final
        for (int j = i+1; j < list.size(); j++) {
            // Si el elemento actual (min) es mayor que el elemento (j), cambiamos el valor de min
            // incrementamos el contador de comparaciones
            nComparisons++;
            if(list[min] > list[j]) {
                // Cambiamos el valor de min
                min = j;
            }
        }
        // Si el valor de min no es la posición i, intercambiamos
        if(min != i) {
            // Hacemos el intercambio
            swap(list, i, min);
            // incrementamos el contador de intercambios
            nSwaps++;
        }
    }
    // Tiempo final
    gettimeofday(&end, 0);
    getTime(begin, end);
}

template <class T>
void insertionSort(vector<T>& list, int &nSwaps, int &nComparisons) {
    // Tiempo inicial
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    for (int i = 1; i < list.size(); i++) {
        int j = i;
        while (j > 0) { // && list[j] < list[j - 1]) {
            nComparisons++;
            if (list[j] < list[j - 1]) {
                swap(list,j,j-1);
                nSwaps++;
                j--;
            }
            else {
                j = 0; //o puedes usar un break;
            }
        }
    }
    // Tiempo final
    gettimeofday(&end, 0);
    getTime(begin, end);
}

template <class T>
void merge(vector<T>& list, int start, int mid, int end, int &nComparisons) {
    // Creamos un vector auxiliar para guardar los elementos de la lista del lado izquierdo
    vector<T> left;
    // Creamos un vector auxiliar para guardar los elementos de la lista del lado derecho
    vector<T> right;
    // Creamos una variable auxiliar para guardar el tamaño de la lista del lado izquierdo
    int leftSize = mid - start + 1;
    // Creamos una variable auxiliar para guardar el tamaño de la lista del lado derecho
    int rightSize = end - mid;
    // Recorremos la lista del lado izquierdo para guardar los elementos en la lista auxiliar
    for (int i = 0; i < leftSize; i++) {
        // Guardamos el elemento en la lista auxiliar
        left.push_back(list[start + i]);
    }
    // Recorremos la lista del lado derecho para guardar los elementos en la lista auxiliar
    for (int i = 0; i < rightSize; i++) {
        // Guardamos el elemento en la lista auxiliar
        right.push_back(list[mid + 1 + i]);
    }
    // crear una variable auxiliar para guardar la posición de la lista original
    int pos = start;
    // crear una variable auxiliar para guardar la posición de la lista auxiliar izquierda
    int leftPos = 0;
    // crear una variable auxiliar para guardar la posición de la lista auxiliar derecha
    int rightPos = 0;
    // Comparar los elementos de la lista auxiliar izquierda con la lista auxiliar derecha
    while (leftPos < leftSize && rightPos < rightSize) {
        // Incrementamos el contador de comparaciones
        nComparisons++;
        // Compara el elemento leftPos con el elemento rightPos
        if (left[leftPos] < right[rightPos]) {
            // Guardamos el elemento de la lista auxiliar izquierda en la posicion pos de la lista original
            list[pos] = left[leftPos];
            // Incrementamos la posición de la lista auxiliar izquierda
            leftPos++;
        } else {
            // Guardamos el elemento de la lista auxiliar derecha en la posicion pos de la lista original
            list[pos] = right[rightPos];
            // Incrementamos la posición de la lista auxiliar derecha
            rightPos++;
        }
        // Incrementamos la posición de la lista original
        pos++;
    }
    // Recorremos la lista auxiliar izquierda para guardar los elementos restantes en la lista original
    while (leftPos < leftSize) {
        // Guardamos el elemento de la lista auxiliar izquierda en la posicion pos de la lista original
        list[pos] = left[leftPos];
        // Incrementamos la posición de la lista auxiliar izquierda
        leftPos++;
        // Incrementamos la posición de la lista original
        pos++;
    }
    // Recorremos la lista auxiliar derecha para guardar los elementos restantes en la lista original
    while (rightPos < rightSize) {
        // Guardamos el elemento de la lista auxiliar derecha en la posicion pos de la lista original
        list[pos] = right[rightPos];
        // Incrementamos la posición de la lista auxiliar derecha
        rightPos++;
        // Incrementamos la posición de la lista original
        pos++;
    }
}

template <class T>
void mergeSort(vector<T>& list, int start, int end, int &nComparisons) {
    // Mientras el indice final sea mayor que el inicial
    if (end > start) {
        // Calculamos el indice medio
        int mid = (start + end) / 2;
        // Ordenamos la lista desde el inicio hasta el indice medio
        mergeSort(list, start, mid, nComparisons);
        // Ordenamos la lista desde el indice medio hasta el final
        mergeSort(list, mid+1, end, nComparisons);
        // Unimos las dos listas
        merge(list, start, mid, end, nComparisons);
    }
}

template <class T>
void quickSort(vector<T>& list, int start, int end, int &nComparisons) {
    if (end > start) {
        //Crear vector auxiliar con datos de la lista original
        vector <T> vAux = list;
        //Crear variable auxiliar para guardar indice actual
        int index = start;
        //Creamos una variable para guardar el valor del pivote
        T pivot = list[start];
        //Recorremos la lista original desde start +1 hasta end
        for (int i = start; i <= end; i++) {
            //Incrementamos el valor de comparaciones
            nComparisons++;
            //Comparamos si el elemento actual es menor que el pivote
            if (list[i] < pivot) {
                //Guardamos el elemento actual en la posición index de la lista auxiliar
                vAux[index] = list[i];
                index++;
            }
        }
        //Guardamos el pivote en la posición index de la lista auxiliar
        vAux[index] = pivot;
        //Creamos una variable auxiliar para guardar el indice del pivote
        int pivotIndex = index;
        //Incrementamos la posición de la lista auxiliar
        index++;
        for (int i = start + 1; i <= end; i++) {
            //Incrementamos el valor de comparaciones
            nComparisons++;
            //Comparamos si el elemento actual es mayor que el pivote
            if (list[i] > pivot) {
                //Guardamos el elemento actual en la posición index de la lista auxiliar
                vAux[index] = list[i];
                index++;
            }
        }
        //Asignamos la lista  auxiliar a la original 
        list = vAux;
        //Ordenamos la lista original desde start hasta el indice del pivote
        quickSort(list,start,pivotIndex-1,nComparisons);
        //Ordenamos la lista original desde el indice del pivote +1 hasta end
        quickSort(list,pivotIndex+1,end,nComparisons);
    }
     
}

template<class T>
void sortAlgorithm(vector<T> &list, string algorithm) {
    int nSwaps = 0;
    int nComparisons = 0;
    cout << "Ordenamiento por " << algorithm << endl;
    print(list);
    if (algorithm ==  "Intercambio") {
        swapSort(list, nSwaps, nComparisons);
    } else {
        if (algorithm ==  "Burbuja") {
            bubbleSort(list, nSwaps, nComparisons);
        } else {
            if (algorithm == "Selección Directa") {
                selectionSort(list, nSwaps, nComparisons);
            } else {
                if (algorithm == "Inserción") {
                    insertionSort(list, nSwaps, nComparisons);
                } else {
                    if (algorithm == "Merge") {
                        // Tiempo inicial
                        struct timeval begin, end;
                        gettimeofday(&begin, 0);
                        mergeSort(list, 0, list.size()-1, nComparisons);
                        // Tiempo final
                        gettimeofday(&end, 0);
                        getTime(begin, end);
                    }
                    else {
                        if (algorithm == "Quick") {
                            // Tiempo inicial
                            struct timeval begin, end;
                            gettimeofday(&begin, 0);
                            quickSort(list, 0, list.size()-1, nComparisons);
                            // Tiempo final
                            gettimeofday(&end, 0);
                            getTime(begin, end);
                        }
                    }
                }
            }
        }
    }
    cout << "Lista ordenada: ";
    print(list);
    cout << "Número de intercambios: " << nSwaps << endl;
    cout << "Número de comparaciones: " << nComparisons << endl;
}



void createListInt(vector<int> &lista, int cantidad) {
    lista.clear();
    for (int i=0; i<cantidad; i++) {
        lista.push_back(rand() % 100 + 1);
    }
}

void createListChar(vector<char> &lista, int cantidad) {
    lista.clear();
    int r;
    for (int i=0; i<cantidad; i++) {
        r = rand() % 26;
        lista.push_back('a' + r);
    }
}

void createListFrac(vector<Fraccion> &lista, int cantidad) {
    lista.clear();
    int numerador, denominador;
    for (int i=0;i<cantidad;i++) {
        cout << "Teclea el numerador: " << endl;
        cin >> numerador;
        cout << "Teclea el denominador: " << endl;
        cin >> denominador;
        lista.push_back(Fraccion(numerador,denominador));
    }
}

void createListString(vector<string> &lista, int cantidad) {
    lista.clear();
    string valor;
    for (int i=0;i<cantidad;i++) {
        cout << "Teclea una palabra: " << endl;
        cin >> valor;
        lista.push_back(valor);
    }
}

int main()
{
    srand(time(NULL));
    // vector<int> list = {40,50,32,45,19,2,10,23,44,28};
    vector<int> listIntOrig;
    vector<int> listInt;
    vector<Fraccion> listFracOrig;
    vector<Fraccion> listFrac;
    vector<char> listCharOrig;
    vector<char> listChar;
    vector<string> listStringOrig;
    vector<string> listString;
    int qty = 10;
    char listType = 'i';
    char opc = 'a';

    while (opc != 'z') {
                cout << endl;
        cout << "Menu" << endl;
        cout << "a) Selecciona tipo de dato para crear la lista" << endl;
        cout << "b) Orden por Intercambio" << endl;
        cout << "c) Orden por Burbuja" << endl;
        cout << "d) Orden por Selección Directa" << endl;
        cout << "e) Orden por Inserción" << endl;
        cout << "f) Orden por Merge" << endl;
        cout << "g) Orden por Quick" << endl;
        cout << "z) salir" << endl;
        cout << endl << "Teclea una opción: " << endl;
        cin >> opc;

        switch (opc) {
        case 'a':
            cout << "Teclea el tipo de datos deseado (e) entero, (f) fraccion, (c) char, (s) string " << endl;
            cin >> listType;
            switch (listType) {
            case 'e':
                cout << "Teclea la cantidad de números enteros que deseas en la lista" << endl;
                cin >> qty;
                createListInt(listIntOrig,qty);
                listInt = listIntOrig;
                print(listInt);
                break;
            case 'f':
                qty = 6;
                createListFrac(listFracOrig,qty);
                listFrac = listFracOrig;
                print(listFrac);
                break;
            case 'c':
                qty = 20;
                createListChar(listCharOrig,qty);
                listChar = listCharOrig;
                print(listChar);
                break;
            case 's':
                qty = 7;
                createListString(listStringOrig,qty);
                listString = listStringOrig;
                print(listString);
                break;
            default:
                cout << "Teclea la cantidad de números enteros que deseas en la lista" << endl;
                cin >> qty;
                createListInt(listIntOrig,qty);
                listInt = listIntOrig;
                print(listInt);
                break;
            }
            break;
        case 'b':
            switch (listType) {
            case 'e':
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Intercambio");
                break;
            case 'f':
                listFrac = listFracOrig;
                sortAlgorithm(listFrac, "Intercambio");
                break;
            case 'c':
                listChar = listCharOrig;
                sortAlgorithm(listChar, "Intercambio");
                break;
            case 's':
                listString = listStringOrig;
                sortAlgorithm(listString, "Intercambio");
                break;
            default:
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Intercambio");
                break;
            }
            break;
        case 'c':
            switch (listType) {
            case 'e':
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Burbuja");
                break;
            case 'f':
                listFrac = listFracOrig;
                sortAlgorithm(listFrac, "Burbuja");
                break;
            case 'c':
                listChar = listCharOrig;
                sortAlgorithm(listChar, "Burbuja");
                break;
            case 's':
                listString = listStringOrig;
                sortAlgorithm(listString, "Burbuja");
                break;
            default:
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Burbuja");
                break;
            }
            break;
        case 'd':
            switch (listType) {
            case 'e':
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Selección Directa");
                break;
            case 'f':
                listFrac = listFracOrig;
                sortAlgorithm(listFrac, "Selección Directa");
                break;
            case 'c':
                listChar = listCharOrig;
                sortAlgorithm(listChar, "Selección Directa");
                break;
            case 's':
                listString = listStringOrig;
                sortAlgorithm(listString, "Selección Directa");
                break;
            default:
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Selección Directa");
                break;
            }
            break;    
        case 'e':
            switch (listType) {
            case 'e':
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Inserción");
                break;
            case 'f':
                listFrac = listFracOrig;
                sortAlgorithm(listFrac, "Inserción");
                break;
            case 'c':
                listChar = listCharOrig;
                sortAlgorithm(listChar, "Inserción");
                break;
            case 's':
                listString = listStringOrig;
                sortAlgorithm(listString, "Inserción");
                break;
            default:
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Inserción");
                break;
            }
            break;
        case 'f':
            switch (listType) {
            case 'e':
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Merge");
                break;
            case 'f':
                listFrac = listFracOrig;
                sortAlgorithm(listFrac, "Merge");
                break;
            case 'c':
                listChar = listCharOrig;
                sortAlgorithm(listChar, "Merge");
                break;
            case 's':
                listString = listStringOrig;
                sortAlgorithm(listString, "Merge");
                break;
            default:
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Merge");
                break;
            }
            break;
        case 'g':
            switch (listType) {
            case 'e':
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Quick");
                break;
            case 'f':
                listFrac = listFracOrig;
                sortAlgorithm(listFrac, "Quick");
                break;
            case 'c':
                listChar = listCharOrig;
                sortAlgorithm(listChar, "Quick");
                break;
            case 's':
                listString = listStringOrig;
                sortAlgorithm(listString, "Quick");
                break;
            default:
                listInt = listIntOrig;
                sortAlgorithm(listInt, "Quick");
                break;
            }
            break;
        case 'z':
            cout << endl << "Gracias" << endl;
            break;
        default:
            break;
        }

    }

    
    /*
    createListInt(list, 100);
    vector<int> originalList = list;
    // Swap Sort
    list = originalList;
    int nSwaps = 0;
    int nComparisons = 0;
    cout << "Swap Sort" << endl;
    cout << "Lista original: ";
    print(list);
    swapSort(list, nSwaps, nComparisons);
    cout << "Lista ordenada: ";
    print(list);
    cout << "Número de intercambios: " << nSwaps << endl;
    cout << "Número de comparaciones: " << nComparisons << endl;

    // Bubble Sort
    list = originalList;
    nSwaps = 0;
    nComparisons = 0;
    cout << "Bubble Sort" << endl;
    cout << "Lista original: ";
    print(list);
    bubbleSort(list, nSwaps, nComparisons);
    cout << "Lista ordenada: ";
    print(list);
    cout << "Número de intercambios: " << nSwaps << endl;
    cout << "Número de comparaciones: " << nComparisons << endl;
    */

    getch();
    return 0;
}
