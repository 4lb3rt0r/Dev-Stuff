#include <iostream>
#include <conio.h>

using namespace std;

int main () {

    int a = 5;
    int *p;

    p = &a; //p apunta a "a" 

    cout<<"a = "<<a<<endl;
    cout<<"*p = "<<*p<<endl;
    cout<<"p = "<<p<<endl;
    cout<<"&a = "<<&a<<endl;
    cout<<"&p = "<<&p<<endl;

    int a = 10;
    p = new int(20); //p apunta a direccion de memoria de 20
    //p = &b; //p apunta a "b" 

    cout<<"a = "<<a<<endl;
    cout<<"*p = "<<*p<<endl;
    cout<<"p = "<<p<<endl;
    cout<<"&a = "<<&a<<endl;
    cout<<"&p = "<<&p<<endl;




    getch();
    return 0;
}