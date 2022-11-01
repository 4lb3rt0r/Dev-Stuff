//
//  main.cpp
//  ejercicioClasePersona
//
//  Created by Yolanda Martínez Treviño on 25/05/21.
//

#include <iostream>
using namespace std;

#include "Estudiante.h"
#include "Maestro.h"

int main() {
    
    Persona *listaPersonas[20];
    
    int cantPersonas;  // contiene la cantidad de objetos que hay en listaPersonas
    char opcionPersona, opcionMenu;
    int edad, edadIni, edadFin;
    string nombre, carrera, departamento;
    
    cout << "Cuantas personas hay? ";
    cin >> cantPersonas;
    
    for (int c = 0; c < cantPersonas; c++)
    {
        cout << "a) Estudiante, b) Maestro y c) Ninguno de los dos" << endl;
        cin >> opcionPersona;
        
        cout << "Nombre? ";
        cin >> nombre;
        
        cout << "Edad? ";
        cin >> edad;
        
        if (opcionPersona == 'a') {
            cout << "Carrera? ";
            cin >> carrera;
            
            listaPersonas[c] = new Estudiante(nombre, edad, carrera);
        }
        else if (opcionPersona == 'b') {
            cout << "Departamento? ";
            cin >> departamento;
            
            Maestro *maes = new Maestro(nombre, edad, departamento);

            listaPersonas[c] = maes;
                
            }
        else {
            listaPersonas[c] = new Persona(nombre, edad);
        }
    }
    
    
    do
    {
        cout << "Menu de opciones " << endl;
        cout << endl;
        cout << "a) muestra todas las personas " << endl;
        cout << "b) muestra personas en un rango de edad " << endl;
        cout << "c) terminar " << endl;
        cout << "opcion -> " << endl;
        cin >> opcionMenu;
        
        switch (opcionMenu) {
            case 'a':  {
                
                for (int c = 0; c < cantPersonas; c++)
                    listaPersonas[c]->muestraDatos();
                
                break;
            }
                
            case 'b':  {
                int edadTmp;
                cout << "edad inicial ";
                cin >> edadIni;
                cout << "edad final? ";
                cin >> edadFin;
                
                for (int c = 0; c < cantPersonas; c++) {
                    edadTmp = listaPersonas[c]->getEdad();
                    if (edadTmp >= edadIni && edadTmp <= edadFin)
                        listaPersonas[c]->muestraDatos();
                }
                break;
            }
        }
        
    } while (opcionMenu != 'c');
    
    return 0;
}
