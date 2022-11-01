#include <iostream>
#include <fstream>
using namespace std;

#include "Estudiante.h"
#include "Maestro.h"
int main() {

 Persona *listaPersonas[20];

 int cantPersonas; // contiene la cantidad de objetos que hay en listaPersonas
 ifstream archPersonas;
 char opcionPersona, opcionMenu,tipo;
 int d,m,a, edadIni, edadFin;
 string nombre, carrera, departamento;
 Fecha fechaTmp;
 archPersonas.open("datosPersonas.txt");
 cantPersonas = 0;

 //leemos del archivo tipo de dato, nombre y fecha de nacimiento y de ser asi carrera o dpto
 while (archPersonas>>tipo>>nombre>>d>>m>>a) {
     fechaTmp.setFecha(d,m,a);
    if (tipo == 'e') {
        archPersonas>>carrera;
        Estudiante *est = new Estudiante (nombre, fechaTmp, carrera);
        listaPersonas[cantPersonas] = est;
        cantPersonas++;
    }
    else if (tipo == 'm') {
        archPersonas>>departamento;
        Maestro *maes = new Maestro (nombre, fechaTmp, departamento);
        listaPersonas[cantPersonas] = maes;
        cantPersonas++;
    }
    else {
        listaPersonas[cantPersonas] = new Persona (nombre, fechaTmp);
        cantPersonas++;
    }
 }
archPersonas.close();

 //MÉTODO CONVENCIONAL SIN ARCHIVO .TXT
 //cout << "Cuantas personas hay? ";
 //cin >> cantPersonas;

 //for (int c = 0; c < cantPersonas; c++)
 //{
 //cout << "a) Estudiante, b) Maestro y c) Ninguno de los dos" << endl;
 //cin >> opcionPersona;

 //cout << "Nombre? ";
 //cin >> nombre;

 //cout << "Fecha de Nacimiento? ";
 //cin >> d>>m>>a;
 //fechaTmp.setFecha(d,m,a);

 //if (opcionPersona == 'a') {
 //cout << "Carrera? ";
 //cin >> carrera;

 //Estudiante *est = new Estudiante (nombre, fechaTmp, carrera);
 //listaPersonas[c] = est;
 //}
 //else if (opcionPersona == 'b') {
 //cout << "Departamento? ";
 //cin >> departamento;

 //Maestro *maes = new Maestro(nombre, fechaTmp, departamento);
 //listaPersonas[c] = maes;

 //}
 //else {
 //listaPersonas[c] = new Persona(nombre, fechaTmp);
 //}
 //}


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
 case 'a': {

 for (int c = 0; c < cantPersonas; c++)
 listaPersonas[c]->muestraDatos();

 break;
 }

 case 'b': {
 int edadTmp;
 cout << "edad inicial ";
 cin >> edadIni;
 cout << "edad final? ";
 cin >> edadFin;

 for (int c = 0; c < cantPersonas; c++) {
 edadTmp = listaPersonas[c]->calculaEdad();
 if (edadTmp >= edadIni && edadTmp <= edadFin)
 listaPersonas[c]->muestraDatos();
 }
 break;
 }
 }

 } while (opcionMenu != 'c');

 return 0;
}
