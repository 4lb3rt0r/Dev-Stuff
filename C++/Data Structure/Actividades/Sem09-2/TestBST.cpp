#include <iostream>
//#include <conio.h>

using namespace std;

#include "BST.h"

int main () {

    BST<int> bst;

    bst.add(21);
    bst.add(13);
    bst.add(33);
    bst.add(10);
    bst.add(18);
    bst.add(25);
    bst.add(40);
    bst.add(50);
    bst.add(60);
    bst.add(7);
    bst.add(6);
    bst.add(5);
    bst.print();

    
    bst.visit(1);
    bst.visit(2);
    bst.visit(3);
    bst.visit(4);

    cout << "La altura del arbol es: " << bst.height() << endl;

    cout << "ancestros de: 5" << endl;
    bst.ancestors(5);

    int dato;
    cout<<"Introduzca el dato a buscar: ";
    cin>>dato;
    int level = bst.whatLvl(dato);;
    if (level > 0) {
        cout<<"el dato "<<dato<<" esta en el nivel: "<<level<<endl;
    } else {
        cout<< "no se encontró el "<<dato<<endl;
    }

    // bst.add(20);
    // bst.add(30);
    // bst.add(10);
    // bst.add(25);
    // bst.add(35);
    // bst.add(15);
    // bst.add(5);

    // bst.print();

    // bst.find(55) ? cout<<"Nodo encontrado!!"<<endl : cout<<"No se encontró el nodo :/"<<endl;

    // cout<<endl;
    // bst.remove(5);
    // bst.print();
    // bst.remove(10);
    // bst.print();
    // bst.remove(15);
    // bst.print();
    // bst.add(28);
    // bst.print();
    // bst.remove(30);
    // bst.print();

    // bst.visit(0);
    // bst.add(18);
    // bst.visit(4);
    // bst.height();
    // bst.ancestors(20);

    //getch();
    return 0;
}