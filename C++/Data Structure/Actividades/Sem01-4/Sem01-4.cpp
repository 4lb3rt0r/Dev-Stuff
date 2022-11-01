/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 09/Sep/2021
Actividad: Actividad Integradora 1*/

#include <iostream>
#include <conio.h>

using namespace std;

int fibonaccIterativo (int x) {
    int num = 1,ant = 0,aux;
    for (int i = 0; i < x; i++) {
        aux = num;
        num += ant;
        ant = aux;
    }
    return aux;
}

int fibonacciRecursivo(int x){
    if (x == 1 || x == 2) {
        return 1;
    }     
    else {
        return fibonacciRecursivo(x - 1) + fibonacciRecursivo(x - 2);
    }
}

int bacteriaIterativa (int x) {
    int bacterias = 1;
    for (int i = 1; i <= x; i++) {
        bacterias *= (1 + (3.78 - 2.34));
    }
    return bacterias;
}

int bacteriaRecursiva (int x) {
    if (x > 0) {
        return bacteriaRecursiva(x - 1) * (1 + (3.78 - 2.34));;
    }
    else {
        return 1;
    }
}

int inversionIterativa (int m, int s) {
    int saldo_f = s;
    for (int i = 0; i < m; i++) {
        saldo_f *= (1+(18.75/100));
    }
    return saldo_f;
}

int inversionRecursiva (int m, int s) {
    if (m > 0) {
        return inversionIterativa(m-1,s) * (1 + (18.75/100));
    }
    else {
        return s;
    }
}

int potenciaIterativa (int b, int e) {
    int r = 1;
    for (int i = 0; i < e; i++) {
        r *= b;
    }

    return r;
}

int potenciaRecursiva (int b, int e) {
    if (e < 1) {
        return 1;
    }
    else {
        return b * potenciaRecursiva(b, e - 1);
    }
}

int main () {
    int n = 0,meses = 0,saldo = 0,base,exp;

    cout<<"Teclee el número de iteraciones: ";
    cin>>n;

    cout<<"NÚMEROS FIBONACCI"<<endl;
    cout<<"Número fibonacci Iterativo correspondiente a "<<n<<": "<<fibonaccIterativo(n)<<endl;
    cout<<"Número fibonacci Recursivo correspondiente a "<<n<<": "<<fibonacciRecursivo(n)<<endl;
    cout<<endl;
    cout<<"BACTERIAS"<<endl;
    cout<<"Número de bacterias con método Iterativo: "<<bacteriaIterativa(n)<<endl;
    cout<<"Número de bacterias con método Recursivo: "<<bacteriaRecursiva(n)<<endl;
    cout<<endl;
    cout<<"INVERSIÓN"<<endl;
    cout<<"Teclee la cantidad de meses a considerar: ";
    cin>>meses;
    cout<<"Teclee el saldo inicial: ";
    cin>>saldo;
    cout<<"El valor del saldo final por método Iterativo es: "<<inversionIterativa(meses,saldo)<<endl;
    cout<<"El valor del saldo final por método Recursivo es: "<<inversionRecursiva(meses,saldo)<<endl;
    cout<<endl;
    cout<<"EXPONENCIAL"<<endl;
    cout<<"Teclee el valor de la base de la potencia: ";
    cin>>base;
    cout<<"Teclee el valor del exponente: ";
    cin>>exp;
    cout<<"El resultado del exponencial "<<base<<"^"<<exp<<" por método Iterativo es: "<<potenciaIterativa(base,exp)<<endl;
    cout<<"El resultado del exponencial "<<base<<"^"<<exp<<" por método Recursivo es: "<<potenciaRecursiva(base,exp)<<endl;


    getch();
    return 0;
}