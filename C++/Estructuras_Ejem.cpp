//Introducción a Estructuras en C++
#include <iostream>
#include <conio.h>
using namespace std;

struct Persona {
    char Nombre [20];
    int Edad;
} persona_1
//persona_1 = {"Alberto",18}, persona_2 = {"Alonso",16}
;

int main () {
    //cout<<"Nombre de la Persona 1: "<<persona_1.Nombre<<endl;
    //cout<<"Edad de la Persona 1: "<<persona_1.Edad<<endl;
    //cout<<"\n";
    //cout<<"Nombre de la Persona 2: "<<persona_2.Nombre<<endl;
    //cout<<"Edad de la Persona 2: "<<persona_2.Edad<<endl;

    cout<<"Nombre de la Persona 1: "<<endl;
    cin.getline(persona_1.Nombre,20,'\n');
    cout<<"Edad de la Persona 1:"<<endl;
    cin>>persona_1.Edad;

    cout<<"\nImprimiendo Datos Adquiridos"<<endl;
    cout<<"Nombre: "<<persona_1.Nombre<<endl;
    cout<<"Edad: "<<persona_1.Edad<<endl;

    getch();
    return 0;
}