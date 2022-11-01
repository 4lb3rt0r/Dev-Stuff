#ifndef LinkedList_h
#define LinkedList_h

#include "Nodo.h"

template <class T>
class LinkedList {
    private:
        Nodo <T>* head;
        int size;
    public:
    LinkedList();
    void insertarDato(Nodo<T> *&lista, T n);
    int getSize();
    void print();
    T getData(int index);
};

template <class T>
T LinkedList<T> :: getData(int index) {
    if (index >= 0 && index > size) {
        Node<T>* aux = head;
    }
    int auxIndex = 0;
    while (auxIndex < index) {
        aux = aux->next;
        auxIndex++;
    }
    return aux->data;
    else {
        throw out_of_range("Índice fuera de rango");
    }
};


template <class T>
LinkedList<T> :: LinkedList() {
    head = nullptr;
    size = 0;
}

template <class T>
void insertarDato(Nodo<T> *&lista, T n) {
    Nodo<T> *new_node = new Nodo<T> ();
    new_node -> data = n;

    Nodo<T> *aux1 = lista;
    Nodo<T> *aux2; 

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

    std::cout<<"\nElemento "<<n<<" añadido correctamente"<<std::endl;
};

template <class T>
void LinkedList<T> :: print() {
    Nodo<T>* aux = head;
    //Recorremos la lista hasta llegar al último Nodo
    while (aux != nullptr) {
        std::cout<<aux->data<<" ";
        //Pasamos al siguiente nodo
        aux = aux->next;
    }
    std::cout<<std::endl;
}

#endif