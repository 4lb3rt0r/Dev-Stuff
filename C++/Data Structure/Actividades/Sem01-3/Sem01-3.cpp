/* Programaci�n de Estructura de Datos y Algoritmos Fundamentales
Nombre: Alberto Horacio Orozco Ramos
Matr�cula: A00831719
Fecha: 09/Sep/2021
Actividad: Actividad Integradora 1*/

#include <iostream>
#include <conio.h>

using namespace std;

int sumaIterativa (int a) { //Básicamente trabaja en base a un ciclo for/while
    int sum = 0;
    for (int i = 0; i < a; i++) {
        sum += i + 1;
    }

    return sum;
}

int sumaRecursiva (int a) { //Ejemplo de una "Recursion Function"
    if (a == 1) {
        return 1; //Base Case; es el valor de retorno que terminará con el ciclo generado por el return recursivo
    }
    else {
        return a + sumaRecursiva(a - 1); //"Return Recursivo"; este generará un ciclo que se detendrá gracias al Base Case
    }

}

int sumaDirecta (int a) {
    int sum = (a*(a+1))/2;

    return sum;
}

int factorial (int a) { //Ejemplo de una "Recursion Function"
    
    if (a == 1) {
        return 1; //Esta es la respuesta de todas las veces que se genera el bucle. Se le llama "Base Case" o Caso Base 
    }
    else {
        return a * factorial(a-1); //Aquí se genera un bucle de uno en uno el cual terminara hasta llegar al número 1 y finalmente irá retornando todos los factoriales hasta calcular el deseado
    }

}

int main () {
    int n = 0;

    cout<<"Introduzca un número: ";
    cin>>n;

    cout<<"Resultado de Suma Iterativa: "<<sumaIterativa(n)<<endl;
    cout<<"Resultado de Suma Recursiva: "<<sumaRecursiva(n)<<endl;
    cout<<"Resultado de Suma Directa: "<<sumaDirecta(n)<<endl;
    cout<<"Resultado de Factorial: "<<factorial(n)<<endl;

    getch();

    return 0;
}