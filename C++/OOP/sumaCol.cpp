// Escribe aquí tu programa que soluciona el ejercicio

#include <iostream>
#include <fstream>
using namespace std;

#include "Fraccion.h"

int main () {
    Fraccion resF,listaFracciones[10][10];
    int sizeRen,sizeColum,count = 0;
    int num,den;
    
    ifstream archFracc;
    archFracc.open("matrizFracciones.txt");
    archFracc>>sizeRen>>sizeColum;
    
    for (int i = 0;i < sizeRen;i++) {
        for (int j = 0;j < sizeColum;j++) {
            archFracc>>num>>den; 
            Fraccion fracc(num,den);
            fracc.simplifica();
            listaFracciones[i][j] = fracc;
            listaFracciones[i][j].muestra();
        }
        cout<<endl;
    }
    archFracc.close();
    
    int columnaS;
    cin>>columnaS;
    for (int k = 0;k < sizeRen;k++) {
        resF = resF.suma(listaFracciones[k][columnaS]);
    }
    cout<<"Total: ";
    resF.simplifica();
    resF.muestra();
    
    return 0;
}
