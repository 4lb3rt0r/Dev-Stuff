/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 09/Sep/2021
Actividad: Actividad Integradora 1*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void swap(vector<T>& list, int i, int j) {
    T aux = list[i];
    list[i] = list[j];
    list[j] = aux;
}

//SWAP SORT
template <class T>
void swapSort(vector<T>& list, int &nSwaps, int &nComparisons) {
    // Recorremos la lista desde el inicio hasta el penúltimo elemento
    for (int i = 0; i < list.size()-1; i++) {
        // Recorremos la lista desde el siguiente elemento hasta el final
        for (int j = i+1; j < list.size(); j++) {
            nComparisons++;
            if(list[i] > list[j]) {
                swap(list, i, j);
                nSwaps++;
            }
        }
    }
}

//BUBBLE SORT
template <class T>
void bubbleSort(vector<T>& list, int &nSwaps, int &nComparisons) {
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
            nComparisons++;
            if(list[i] > list[i+1]) {
                swap(list, i, i+1);
                nSwaps++;
                swapped = true;
            }
        }
        aux--;
    }
}

//SELECTION SORT

template <class T>
void selectionSort(vector<T>& list, int &nSwaps, int &nComparisons) {
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
}

//INSERTION SORT

template <class T>
void insertionSort(vector<T>& list, int &nSwaps, int &nComparisons) {
    // Recorremos la desde el segundo elemento hasta el final
    for (int i = 1; i < list.size(); i++) {
        // Creamos una variable auxiliar para guardar la posición i
        int j = i;
        // Recorremos la lista mientra j > 0
        while (j > 0) {
            // Si el elemento actual (j) es menor que el elemento anterior (j-1), intercambiamos  
            // Incrementamos el contador de comparaciones
            nComparisons++;
            if(list[j] < list[j-1]) {
                // Hacemos el intercambio
                swap(list, j, j-1);
                // incrementamos el contador de intercambios
                nSwaps++;
                // Decrementamos el valor de j
                j--;
            } else {
                // Si el elemento actual (j) es mayor o igual que el elemento anterior (j-1), salimos del ciclo
                j = 0;
            }
        }
    }
}   


void crearListaEnteros(vector<int> &lista, int cantidad)
{
    lista.clear();
    for (int i = 0; i < cantidad; i++)
    {
        lista.push_back(rand() % 100 + 1);
    }
}

void crearListaChar(vector<char> &lista, int cantidad)
{
    lista.clear();
    int r;
    for (int i = 0; i < cantidad; i++)
    {
        r = rand() % 26;
        lista.push_back('a' + r);
    }
}

void crearListaString(vector<string> &lista, int cantidad)
{
    lista.clear();
    string valor;
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Teclea una palabra: " << endl;
        cin >> valor;
        lista.push_back(valor);
    }
}

template <class T>
void print(vector<T> list)
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

template <class T>
void sortAlgorithm(vector<T> &list, string algorithm)
{
    int nSwaps = 0;
    int nComparisons = 0;
    cout << "Ordenamiento por " << algorithm << endl;
    cout << "Lista original: ";
    print(list);
    if (algorithm == "Intercambio")
    {
        swapSort(list, nSwaps, nComparisons);
    }
    else
    {
        if (algorithm == "Burbuja")
        {
            bubbleSort(list, nSwaps, nComparisons);
        }
        else
        {
            if (algorithm == "Selección Directa")
            {
                selectionSort(list, nSwaps, nComparisons);
            }
            else
            {
                if (algorithm == "Inserción")
                {
                    insertionSort(list, nSwaps, nComparisons);
                }
            }
        }
    }
    cout << "Lista ordenada: ";
    print(list);
    cout << "Número de intercambios: " << nSwaps << endl;
    cout << "Número de comparaciones: " << nComparisons << endl;
}

int main()
{

    //declarando variables
    char opcion, tipoLista;
    int cantidadNum;

    //creando vectores Enteros
    vector<int> listaInt0;
    vector<int> listInt;

    //creando vectores Char
    vector<char> listChar0;
    vector<char> listChar;

    //creando vectores String
    vector<string> listString0;
    vector<string> listString;

    do {

        //Texto del menú

        cout << "Menu" << endl;
        cout << "a) Selecciona tipo de dato para crear la lista" << endl;
        cout << "b) Orden por Intercambio" << endl;
        cout << "c) Orden por Burbuja" << endl;
        cout << "d) Orden por Selección Directa" << endl;
        cout << "e) Orden por Inserción" << endl;
        cout << "f) Salir" << endl;
        cout << endl
             << "Ingrese una opción: " << endl;

        cin >> opcion;

        switch (opcion)
        {

        case 'a':
            cout << "Teclea el tipo de datos deseado:" << endl;
            cout << "(e) entero" << endl;
            cout << "(c) char" << endl;
            cout << "(s) string" << endl;
            cin >> tipoLista;
            switch (tipoLista)
            {
            case 'e':
                cout << "Teclea la cantidad de números enteros que deseas en la lista" << endl;
                cin >> cantidadNum;
                crearListaEnteros(listaInt0, cantidadNum);
                listInt = listaInt0;
                print(listInt);
                break;
            case 'c':
                cantidadNum = 20;
                crearListaChar(listChar0, cantidadNum);
                listChar = listChar0;
                print(listChar);
                break;
            case 's':
                cantidadNum = 7;
                crearListaString(listString0, cantidadNum);
                listString = listString0;
                print(listString);
                break;
            default:
                cout << "Teclea la cantidad de números enteros que deseas en la lista" << endl;
                cin >> cantidadNum;
                crearListaEnteros(listaInt0, cantidadNum);
                listInt = listaInt0;
                print(listInt);
                break;
            }

        case 'b':
            switch (tipoLista)
            {
            case 'e':
                listInt = listaInt0;
                sortAlgorithm(listInt, "Intercambio");
                break;
            case 'c':
                listChar = listChar0;
                sortAlgorithm(listChar, "Intercambio");
                break;
            case 's':
                listString = listString0;
                sortAlgorithm(listString, "Intercambio");
                break;
            default:
                listInt = listaInt0;
                sortAlgorithm(listInt, "Intercambio");
                break;
            }
            break;

        case 'c':
            switch (tipoLista)
            {
            case 'e':
                listInt = listaInt0;
                sortAlgorithm(listInt, "Burbuja");
                break;
            case 'c':
                listChar = listChar0;
                sortAlgorithm(listChar, "Burbuja");
                break;
            case 's':
                listString = listString0;
                sortAlgorithm(listString, "Burbuja");
                break;
            default:
                listInt = listaInt0;
                sortAlgorithm(listInt, "Burbuja");
                break;
            }
            break;

        case 'd':
            switch (tipoLista)
            {
            case 'e':
                listInt = listaInt0;
                sortAlgorithm(listInt, "Selección Directa");
                break;
            case 'c':
                listChar = listChar0;
                sortAlgorithm(listChar, "Selección Directa");
                break;
            case 's':
                listString = listString0;
                sortAlgorithm(listString, "Selección Directa");
                break;
            default:
                listInt = listaInt0;
                sortAlgorithm(listInt, "Selección Directa");
                break;
            }
            break;
        case 'e':
            switch (tipoLista)
            {
            case 'e':
                listInt = listaInt0;
                sortAlgorithm(listInt, "Inserción");
                break;
            case 'c':
                listChar = listChar0;
                sortAlgorithm(listChar, "Inserción");
                break;
            case 's':
                listString = listString0;
                sortAlgorithm(listString, "Inserción");
                break;
            default:
                listInt = listaInt0;
                sortAlgorithm(listInt, "Inserción");
                break;
            }
            break;
        case 'z':
            
            break;
        default:
            break;
        }
    } while (opcion != 'f');

    cout <<endl<< "Gracias" <<endl;

    return 0;
}