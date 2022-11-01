#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

#include "Reloj.h"

int main () { 
    Reloj reloj;

    cout<<"Ingresa la hora exacta para inicializar en reloj:"<<endl;
    cout<<"Hora: ";
    cin>>reloj.horas;
    cout<<"Minutos: ";
    cin>>reloj.minutos;
    cout<<"Segundos: ";
    cin>>reloj.segundos;

    reloj.clock();

    //cout<<"Día terminado";
    getch();
    return 0;
}