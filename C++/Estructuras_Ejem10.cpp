#include <iostream>
#include <conio.h>

using namespace std;

struct Persona {
    char nombre [20];
    bool discapacidad;
}personas[100],disc[100],no_disc[100];

int main () {
    int n,xd,c1 = 0,c2 = 0;
    string d;
    char nm;

    cout<<"Introduzca la cantidad de personas a considerar:"<<endl;
    cin>>n;
    //Pedimos datos de las personas
    for (int i = 0; i < n; i++) {
        xd = 0;
        fflush(stdin);
        cout<<"Nombre de la Persona "<<i+1<<": "<<endl;
        cin.getline(personas[i].nombre,20,'\n');
        cout<<"¿Padece de algún tipo de discapacidad?"<<endl;
        while (xd == 0) {
            cout<<"Teclee [SI] o [NO] a continuación dependiendo de su respuesta: "<<endl;
            cin>>d;
            if (d == "SI" || d == "si") {
                personas[i].discapacidad = true;
                disc[c1] = personas[i];
                c1++;
                xd++;
            }
            else if (d == "NO" || d == "no") {
                personas[i].discapacidad = false;
                no_disc[c2] = personas[i];
                c2++;
                xd++;
            }
        }
    }

    //Imprimir personas con discapacidad
    cout<<"\nPersonas Con Discapacidad:"<<endl;
    for (int i = 0; i < c1; i++) {
        cout<<disc[i].nombre<<endl;
    }
    //Imprimir personas sin discapacidad
    cout<<"\nPersonas Sin Discapacidad:"<<endl;
    for (int i = 0; i < c2; i++) {
        cout<<no_disc[i].nombre<<endl;
    }

    getch();
    return 0;
}