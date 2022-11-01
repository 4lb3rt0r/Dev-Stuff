#include <iostream>

using namespace std;

int Encuentra_Factorial (int a) { //Ejemplo de una "Recursion Function"
    
    if (a == 1) {
        return 1; //Esta es la respuesta de todas las veces que se genera el bucle. Se le llama "Base Case" o Caso Base 
    }
    else {
        return a * Encuentra_Factorial(a-1); //Aquí se genera un bucle de uno en uno el cual terminara hasta llegar al número 1 y finalmente irá retornando todos los factoriales hasta calcular el deseado
    }

}

int main () {

    int n = 0;

    cout<<"CALCULADORA DE FACTORIALES"<<endl;
    cout<<"Teclee a continuación el número a calcular: ";
    cin>>n;
    cout<<"El resultado del factorial "<<n<<"! es: "<<Encuentra_Factorial(n)<<endl;


    cout<<endl;

    return 0;
}