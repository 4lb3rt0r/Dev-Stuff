#include <iostream>
#include <conio.h>

using namespace std;

struct Promedio {
    float nota1;
    float nota2;
    float nota3; 
};

struct Alumno {
    char nombre [20];
    char sexo [10];
    int edad;
    struct Promedio promedio;
}alumno1;

int main () {
    float media = 0;

    cout<<"Introduzca a continuación los datos del Alumno:"<<endl;
    cout<<"Nombre: ";
    cin.getline(alumno1.nombre,20,'\n');
    cout<<"Sexo: ";
    cin.getline(alumno1.sexo,10,'\n');
    cout<<"Edad: ";
    cin>>alumno1.edad;
    cout<<"\nCalificación 1: ";
    cin>>alumno1.promedio.nota1;
    cout<<"\nCalificación 2: ";
    cin>>alumno1.promedio.nota2;
    cout<<"\nCalificación 3: ";
    cin>>alumno1.promedio.nota3;

    media = (alumno1.promedio.nota1+alumno1.promedio.nota2+alumno1.promedio.nota3)/3;

    //Imprimiendo datos del Alumno
    cout<<"\nDatos del alumno:"<<endl;
    cout<<"Nombre: "<<alumno1.nombre<<endl;
    cout<<"Sexo: "<<alumno1.sexo<<endl;
    cout<<"Edad: "<<alumno1.edad<<endl;
    cout<<"Promedio: "<<media<<endl;

    getch();
    return 0;
}