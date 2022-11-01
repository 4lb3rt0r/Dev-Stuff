#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct Corredor {
    char nombre [20];
    int edad;
    char sexo [10];
    char club [20];
}corr1;

int main () {
    char categoria[20];

    cout<<"Introduzca el nombre del corredor: "<<endl;
    cin.getline(corr1.nombre,20,'\n');
    cout<<"Introduzca la edad del corredor: "<<endl;
    cin>>corr1.edad;
    fflush(stdin);
    cout<<"Introduzca el sexo del corredor: "<<endl;
    cin.getline(corr1.sexo,10,'\n');
    cout<<"Introduzca el club del corredor: "<<endl;
    cin.getline(corr1.club,20,'\n');

    if (corr1.edad <= 18) {
        strcpy(categoria,"Juvenil");
    }
    else if (corr1.edad <= 40) {
        strcpy(categoria,"Senior");
    }
    else {
        strcpy(categoria,"Veterano");
    }

    //Imprimimos datos del corredor
    cout<<"\nDatos del Corredor: "<<endl;
    cout<<"Nombre: "<<corr1.nombre<<endl;
    cout<<"Edad: "<<corr1.edad<<endl;
    cout<<"Sexo: "<<corr1.sexo<<endl;
    cout<<"Club: "<<corr1.club<<endl;
    cout<<"Categoría: "<<categoria<<endl;
    

    getch();
    return 0;
}