/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 09/Sep/2021
Actividad: Actividad Integradora 1*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
//#include <conio.h>
using namespace std;
#include "Bitacora.hpp"

int Middle(vector<Bitacora> &vector, int start, int end){
    int mid = end, x = start;
    for (int i = start; i < end; i++){
        if (vector[i] < vector[mid]){
            swap(vector[i], vector[x]);
            x++;
        }
    }
    swap(vector[x], vector[mid]);
    return x;
}

void quickSort(vector<Bitacora> &vector, int start, int end){

    if (start < end){
        //Creamos una variable para guardar el valor del pivote
        int pivot = Middle(vector, start, end);
        //Ordenamos la lista original desde start hasta el indice del pivote
        quickSort(vector, start, pivot - 1);
        //Ordenamos la lista original desde el indice del pivote +1 hasta end
        quickSort(vector, pivot + 1, end);
    }
}

int busquedaBinaria(vector<Bitacora> list, int data) {
    int l = 0,m;
    int r = list.size() - 1;
    while (l <= r) {
        //Obtenemos punto medio
        m = (l + r) / 2; // formula para calcular el punto medio del vector
        //IF para verificar si el dato es igual al de en medio
        if (list[m].key == data) {
            //Retornamos m si es cierto
            return m;
        } 
        else {
            //Verificamos si el dato seleccionado es menor al dato de en medio
            if (data < list[m].key) { 
                //De ser así, modificamos el límite derecho
                r = m - 1;
            } else {
                //Modificamos el límite izquierdo
                l = m + 1;
            }
        }
    }
    //Retornamos m
    return m;
}

int main()
{
    ifstream fileIn("bitacora.txt");
    //ofstream fileOut("bitacora.out");
    string line;
    string palabra;
    char delim = ' '; 
    string mes, hora, ip, msg;
    int dia,cont = 0;
    vector <Bitacora> linea;

    while (getline(fileIn,line)) { 
        stringstream ss(line);
        ss>>mes>>dia>>hora>>ip>>msg;
        while (ss>>palabra) {
            msg += " " + palabra;
        }
        Bitacora temp(mes, dia, hora, ip, msg);
        linea.push_back(temp); //Append al vector
        cont++;
    }

    fileIn.close();

    quickSort(linea, 0, linea.size() - 1);

    cout<<endl;
    
    cout<<"A continuación, introduzca la fecha inicial de búsqueda" << endl;
    cout<<"Mes de Inicio:"<<endl;
    string mes0;
    cin>>mes0;
    cout<<"Día de Inicio: "<<endl;
    int dia0;
    cin >> dia0;
    cout<<"Hora Inicial de Búsqueda [HH:MM:SS]"<<endl;
    string hora0;
    cin>>hora0;
    Bitacora f0;
    f0.month = mes0;
    f0.day = dia0;
    f0.time = hora0;
    f0.key = f0.createKey();
    cout<<"Key correspondiente a  la fecha inicial: "<<f0.key<<endl;
    cout<<endl;

    cout<<"A continuación, introduzca la fecha final de búsqueda" << endl;
    cout<<"Mes de Fin:"<<endl;
    string mesF;
    cin>>mesF;
    cout<<"Día de Fin: "<<endl;
    int diaF;
    cin>>diaF; 
    cout<<"Hora final de Busqueda [HH:MM:SS]"<<endl;
    string horaF;
    cin>>horaF;
    Bitacora fF;
    fF.month = mesF;
    fF.day = diaF;
    fF.time = horaF;
    fF.key = fF.createKey();
    cout<<"Key correspondiente a  la fecha final: " << fF.key << endl;
    cout<<endl;
    cout<<endl;

    int i0 = busquedaBinaria(linea, f0.key) + 1;
    int iF = busquedaBinaria(linea, fF.key) - 1;
    cout << "Indice inicial: "<<i0<< endl;
    cout << "Indice final: "<<iF<<endl;
    cout<< endl;

	cout<<"Resultados de la Búsqueda: "<<endl;
	cout<<"Desde: "<<f0.month<<" "<<f0.day<<" "<<f0.time<<endl;
	cout<<"Hasta: "<<fF.month<< " " <<fF.day <<" "<<fF.time <<endl;
    
    for(int i=i0; i<=iF; i++){
        cout <<linea[i].month <<" "<<linea[i].day<<" "<<linea[i].time <<" "<<linea[i].ip <<" "<<linea[i].message<<endl;
	}

    cout<<"\n";
	cout<<"Archivo \"bitacora2.txt\" generado con exito"<<endl;
	

	ofstream fileOut("bitacora2.txt");

	fileOut<<"Resultados de la Búsqueda: "<<endl;
    cout<<endl;
	fileOut << "Desde: "<<f0.month<<" "<<f0.day<<" "<< f0.time<<endl;
	fileOut<<"Hasta: "<<fF.month<<" "<<fF.day<<" "<<fF.time<<endl<<endl;
	for(int i = i0; i <= iF; i++){
		fileOut<<linea[i].month<<" "<<linea[i].day<<" "<<linea[i].time<<" "<<linea[i].ip<<" "<<linea[i].message<<endl;
	}

    fileOut.close();
    //getch();
    return 0;
}

