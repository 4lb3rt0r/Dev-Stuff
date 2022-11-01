//Estructuras Anidadas en C++
#include <iostream>
#include <conio.h>

using namespace std;

struct info_direccion {
    char direccion [30];
    char ciudad [20];
    char provincia [20];
};

struct empleado {
    char nombre [20];
    struct info_direccion dir_empleado;
    double salario;
} empleados[2]
;

int main () {
    for (int i = 0; i < 2;i++) {
        fflush(stdin);
        cout<<"Digite su nombre: "<<endl;
        cin.getline(empleados[i].nombre,20,'\n');
        cout<<"Digite su dirección: "<<endl;
        cin.getline(empleados[i].dir_empleado.direccion,30,'\n');
        cout<<"Digite su Ciudad: "<<endl;
        cin.getline(empleados[i].dir_empleado.ciudad,20,'\n');
        cout<<"Digite su provincia: "<<endl;
        cin.getline(empleados[i].dir_empleado.provincia,20,'\n');
        cout<<"Digite su salario: "<<endl;
        cin>>empleados[i].salario;
        cout<<endl;
    }
    //Imprimiendo todos los datos
    for (int i = 0; i < 2; i++) {
        cout<<"Nombre del Empleado: "<<empleados[i].nombre<<endl;
        cout<<"Dirección del Empleado: "<<empleados[i].dir_empleado.direccion<<endl;
        cout<<"Ciudad del Empleado: "<<empleados[i].dir_empleado.ciudad<<endl;
        cout<<"Provincia del Empleado: "<<empleados[i].dir_empleado.provincia<<endl;
        cout<<"Salario del Empleado: "<<empleados[i].salario<<endl;
        cout<<"==================================="<<endl;
    }
    getch();
    return 0;
}