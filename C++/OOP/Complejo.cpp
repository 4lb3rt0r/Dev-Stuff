#include <iostream>
using namespace std;

#include "Complejo.h"

int main () {
    Complejo uno(2,3),dos(5,1),tres,cuatro(5,1);
    //tres = uno.suma(dos);
    cout<<"la suma de los complejos 1 y 2 es:"<<endl;
    tres = uno + dos;

    cout<<"Complejo 1:"<<endl;
    uno.muestra();
    cout<<"Complejo 2:"<<endl;
    dos.muestra();
    cout<<"Complejo 3:"<<endl;
    tres.muestra();

    cout<<"la resta de los complejos 1 y 2 es:"<<endl;
    tres = uno - dos;

    cout<<"Complejo 1:"<<endl;
    uno.muestra();
    cout<<"Complejo 2:"<<endl;
    dos.muestra();
    cout<<"Complejo 3:"<<endl;
    tres.muestra();

    cout<<"La comparación de los complejos 1 y 2:"<<endl;
    if (uno == dos) {
        cout<<"uno y dos son iguales"<<endl;
    }
    else {
        cout<<"uno y dos no son iguales"<<endl;
    }

    //int a = 3,b;
    //b = ++a;
    //cout<<" "<<endl;
    
    cout<<"operador++ con el objeto cuatro:"<<endl;

    tres = ++cuatro;
    cout<<"Complejo 3:"<<endl;
    tres.muestra();
    cout<<"Complejo 4:"<<endl;
    cuatro.muestra();

    return 0;
}