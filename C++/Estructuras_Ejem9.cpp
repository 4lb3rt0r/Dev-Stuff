#include <iostream>
#include <conio.h>

using namespace std;

struct Etapas {
    int horas;
    int minutos;
    int segundos;
}etapas[100];

int main () {
    int n,hT = 0,mT = 0,sT = 0;

    cout<<"Introduzca el número de etapas:"<<endl;
    cin>>n;

    for (int i = 0; i < n; i++) {
        //Pidiendo datos al usuario
        cout<<"Etapa "<<i+1<<endl;
        cout<<"Introduzca las Horas:"<<endl;
        cin>>etapas[i].horas;
        cout<<"Introduzca los Minutos:"<<endl;
        cin>>etapas[i].minutos;
        cout<<"Introduzca los segundos:"<<endl;
        cin>>etapas[i].segundos;

        hT += etapas[i].horas;
        mT += etapas[i].minutos;
        if (mT >= 60) {
            mT -= 60;
            hT++;
        }
        sT += etapas[i].segundos;
        if (sT >= 60) {
            sT -= 60;
            mT++;
        }
        cout<<"========================"<<endl;
    }
    //Tiempo total empleado en toda la carrera
    cout<<"\nTiempo total:"<<endl;
    cout<<"Horas: "<<hT<<endl;
    cout<<"Minutos: "<<mT<<endl;
    cout<<"Segundos: "<<sT<<endl;

    getch();
    return 0;
}