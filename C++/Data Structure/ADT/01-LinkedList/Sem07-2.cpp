/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 28/Sep/2021
Actividad: Actividad Integradora 1*/

#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
    
    LinkedList<int> list;
    char opcion;
    int n,New,index;

    do {
        cout<<endl;
        cout<<"MENÚ DE OPCIONES: "<<endl;
        cout<<"a) Añadir un elemento al inicio de la lista"<<endl;
        cout<<"b) Añadir un elemento al final de la lista"<<endl;
        cout<<"c) Borrar un elemento dado de la lista"<<endl;
        cout<<"d) Borrar un elemento en una posición de la lista"<<endl;
        cout<<"e) Obtener el elemento de una posición dada de la lista"<<endl;
        cout<<"f) Actualizar un elemento dado de la lista"<<endl;
        cout<<"g) Actualizar un elemento que se encuentra en una posición dada de la lista"<<endl;
        cout<<"h) Desplegar datos de la lista"<<endl;
        cout<<"i) Finalizar programa"<<endl;

        cout<<endl<<"Elija una opción: ";
        cin>>opcion;
        cout<<endl;

        switch(opcion) {
            case 'a':
            {
                cout<<"A continuación teclee el número que quiere añadir: ";
                cin>>n;
                list.addFirst(n);
                break;
            }
            case 'b':
            {
                cout<<"A continuación teclee el número que quiere añadir: ";
                cin>>n;
                list.addLast(n);
                break;
            }
            case 'c':
            {
                cout<<"A continuación teclee el número que quiere eliminar: ";
                cin>>n;
                list.deleteData(n);
                break;
            }
            case 'd':
            {
                cout<<"A continuación teclee el índice del número que quiere eliminar: ";
                cin>>index;
                list.deleteAt(index);
                break;
            }
            case 'e':
            {
                try {
                    cout<<"A continuación teclee el índice del número que quiere desplegar: ";
                    cin>>n;
                    int data = list.getData(n);
                    cout << "En el índice " << n << " esta el dato: " << data << endl;
                } 
                catch (out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 'f':
            {
                cout<<"A continuación teclee el número que quiere actualizar: ";
                cin>>n;
                cout<<"A continuación teclee el nuevo valor: ";
                cin>>New;
                list.updateData(n,New);
                break;
            }
            case 'g':
            {
                cout<<"A continuación teclee el índice del número que quiere actualizar: ";
                cin>>index;
                cout<<"A continuación teclee el nuevo valor: ";
                cin>>New;
                list.updateAt(index, New);
                break; 
            }
            case 'h':
            {
                cout<<"A continuación teclee el número que quiere buscar: ";
                cin>>index;
                list.updateAt(index, New);
                break;
            }
            case 'i':
            {
                break;
            }
            case 'j':
            {
                break;
            }
            case 'k':
            {   
                list.print();
                break;
            }
        }
    }
    while (opcion != 'i');
    cout<<"Espere un momento por favor..."<<endl;
    cout<<"Programa finalizado con éxito :D"<<endl;
    
    return 0;
}
