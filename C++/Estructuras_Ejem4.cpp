#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct Alumno {
    char nombre[20];
    int edad;
    float promedio;
}al1,al2,al3;

int main () {
    int count = 0;
    float promedios[10],mayor = 0;

    cout<<"Nombre de Alumno 1: "<<endl;
    cin.getline(al1.nombre,20,'\n');
    cout<<"Edad del Alumno 1: "<<endl;
    cin>>al1.edad;
    cout<<"Promedio del Alumno 1: "<<endl;
    cin>>al1.promedio;
    promedios[0] = al1.promedio;
    cout<<"========================="<<endl;
    cout<<"Nombre de Alumno 2: "<<endl;
    fflush(stdin);
    cin.getline(al2.nombre,20,'\n');
    cout<<"Edad del Alumno 2: "<<endl;
    cin>>al2.edad;
    cout<<"Promedio del Alumno 2: "<<endl;
    cin>>al2.promedio;
    promedios[1] = al2.promedio;
    cout<<"========================="<<endl;
    cout<<"Nombre de Alumno 3: "<<endl;
    fflush(stdin);
    cin.getline(al3.nombre,20,'\n');
    cout<<"Edad del Alumno 3: "<<endl;
    cin>>al3.edad;
    cout<<"Promedio del Alumno 3: "<<endl;
    cin>>al3.promedio;
    promedios[2] = al3.promedio;
    cout<<"========================="<<endl;

    for (int i = 0; i < 3; i++) {
        if (promedios[i] > mayor) {
            mayor = promedios [i];
        }
    }
    cout<<"El promedio mayor es: "<<mayor<<endl;

    cout<<"\nImprimiendo datos del Alumno 1: "<<endl;
    cout<<"Nombre: "<<al1.nombre<<endl;
    cout<<"Edad: "<<al1.edad<<endl;
    cout<<"Promedio: "<<al1.promedio<<endl;
    cout<<"========================="<<endl;
    cout<<"\nImprimiendo datos del Alumno 2: "<<endl;
    cout<<"Nombre: "<<al2.nombre<<endl;
    cout<<"Edad: "<<al2.edad<<endl;
    cout<<"Promedio: "<<al2.promedio<<endl;
    cout<<"========================="<<endl;
    cout<<"\nImprimiendo datos del Alumno 3: "<<endl;
    cout<<"Nombre: "<<al3.nombre<<endl;
    cout<<"Edad: "<<al3.edad<<endl;
    cout<<"Promedio: "<<al3.promedio<<endl;
    cout<<"========================="<<endl;



    getch();
    return 0;
}