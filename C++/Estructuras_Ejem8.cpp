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
}alumnos[100];

int main () {
    float mayor = 0;
    int cant_Alumnos,posM = 0;
    float proms[100];

    cout<<"Cantidad de Alumnos a Considerar: ";
    cin>>cant_Alumnos;

    cout<<"Introduzca a continuación los datos de los Alumnos:"<<endl;
    for (int i = 0; i < cant_Alumnos; i++) {
        cout<<"Alumno "<<i+1<<" :"<<endl;
        fflush(stdin);
        cout<<"Nombre: ";
        cin.getline(alumnos[i].nombre,20,'\n');
        cout<<"Sexo: ";
        cin.getline(alumnos[i].sexo,10,'\n');
        cout<<"Edad: ";
        cin>>alumnos[i].edad;
        cout<<"\nCalificación 1: ";
        cin>>alumnos[i].promedio.nota1;
        cout<<"\nCalificación 2: ";
        cin>>alumnos[i].promedio.nota2;
        cout<<"\nCalificación 3: ";
        cin>>alumnos[i].promedio.nota3;

        proms[i] = (alumnos[i].promedio.nota1+alumnos[i].promedio.nota2+alumnos[i].promedio.nota3)/3;

        if (proms[i] > mayor) {
            mayor = proms[i];
            posM = i;
        }
    }

    //Imprimiendo datos del Alumno con el Mayor Promedio
    cout<<"\nDatos del alumno con mejor promedio:"<<endl;
    cout<<"Nombre: "<<alumnos[posM].nombre<<endl;
    cout<<"Sexo: "<<alumnos[posM].sexo<<endl;
    cout<<"Edad: "<<alumnos[posM].edad<<endl;
    cout<<"Promedio: "<<mayor<<endl;

    getch();
    return 0;
}