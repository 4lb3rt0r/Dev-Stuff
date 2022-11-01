#include <iostream>
#include <conio.h>
using namespace std;

struct Empleado {
    char nombre [20];
    float salario;
}emp[100];

int main () {
    int cant_empleado,posM = 0, posm = 0;
    float mayor = 0, menor = 0;

    cout<<"Teclee a continuación el número de empleados: "<<endl;
    cin>>cant_empleado;

    for (int i = 0; i < cant_empleado; i++) {
        fflush(stdin);
        cout<<i+1<<". Digite el nombre: "<<endl;
        cin.getline(emp[i].nombre,20,'\n');
        cout<<i+1<<". Digite el salario: "<<endl;
        cin>>emp[i].salario;

        // Calculando el salario mayor actualizando por cada iteración del bucle
        if (emp[i].salario > mayor) {
            mayor = emp[i].salario;
            posM = i;
        }
        // Calculando el salario menor actualizando por cada iteración del bucle
        if (emp[i].salario < menor) {
            menor = emp[i].salario;
            posm = i;
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Datos del Empleado con Mayor Salario: "<<endl;
    cout<<"Nombre: "<<emp[posM].nombre <<endl;
    cout<<"Salario: "<<emp[posM].salario<<endl;
    cout<<"================================";
    cout<<"\nDatos del Empleado con Menor Salario: "<<endl;
    cout<<"Nombre: "<<emp[posm].nombre <<endl;
    cout<<"Salario: "<<emp[posm].salario<<endl;

    getch();
    return 0;
}