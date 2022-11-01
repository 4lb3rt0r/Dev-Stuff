#include <iostream>
#include <conio.h>  

using namespace std;

struct Nodo {
    int data;
    Nodo *next;
};

void insertarDato(Nodo *&lista,int n) {
    Nodo *new_node = new Nodo();
    new_node -> data = n;

    Nodo *aux1 = lista;
    Nodo *aux2; 

    while ((aux1 != NULL) && (aux1->data < n)) {
        aux2 = aux1;
        aux1 = aux1 -> next;
    }

    if (lista == aux1) {
        lista = new_node;
    }
    else {
        aux2 -> next = new_node;
    }
    new_node -> next = aux1;

    cout<<"\nElemento "<<n<<" añadido correctamente"<<endl;

}

int main () {
    int n;
    Nodo *lista = NULL;

    cout<<"Teclee el valor que quiere agregar a la lista: ";
    cin>>n;


    insertarDato(lista,n);

    getch();
    return 0;
}