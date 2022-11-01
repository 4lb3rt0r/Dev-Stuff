#include <iostream>
#include <conio.h>

using namespace std;

struct Atleta {
    char nombre [20];
    char pais [30];
    int num_medallas;
} atl[100];

int main () {
    int num_atl,mayor = 0,menor = 0,posM = 0, posm = 0;

    cout<<"¿Cuántos Atletas están concursando?"<<endl;
    cin>>num_atl;

    for (int i = 0; i < num_atl; i++) {
        fflush(stdin);
        cout<<"Atleta "<<i+1<<endl;
        cout<<"Nombre: "<<endl;
        cin.getline(atl[i].nombre,20,'\n');
        cout<<"País: "<<endl;
        cin.getline(atl[i].pais,30,'\n');
        cout<<"Número de Medallas Ganadas: "<<endl;
        cin>>atl[i].num_medallas;

        //Calculando el Número Mayor de Medallas Ganado por Atleta
        if (atl[i].num_medallas > mayor) {
            mayor = atl[i].num_medallas;
            posM = i;
        }
        //Calculando el Número Menor de Medallas Ganado por Atleta
        if (atl[i].num_medallas < mayor) {
            menor = atl[i].num_medallas;
            posm = i;
        }
        cout<<endl;
    }

    cout<<"Atleta que ha ganado el MAYOR número de medallas: "<<endl;
    cout<<"Nombre: "<<atl[posM].nombre<<endl;
    cout<<"Pais: "<<atl[posM].pais<<endl;
    cout<<"=============================="<<endl;
    cout<<"Atleta que ha ganado el MENOR número de medallas: "<<endl;
    cout<<"Nombre: "<<atl[posm].nombre<<endl;
    cout<<"Pais: "<<atl[posm].pais<<endl;

    getch();
    return 0;
}