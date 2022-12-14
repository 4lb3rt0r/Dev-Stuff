#ifndef Queue_h
#define Queue_h

#include "NodoL.h"

template<class T>
class Queue{
private:
    NodoL<T>* head;
    NodoL<T>* tail;
    int size;
public:
    Queue();
    void push(T Data);
    T pop();
    T front();
    T back();
    int getSize();
    void clear();
    void print();
    bool isEmpty();
};

template<class T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
void Queue<T>::push(T data) {
    NodoL<T>* aux = new NodoL<T>(data);
    if (isEmpty()) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
    size++;
}

template<class T>
T Queue<T>::pop() {
    if (!isEmpty()) {
        NodoL<T>* aux = head;
        T data = aux->data;
        head = aux->next;
        delete aux;
        size--;
        if (head == nullptr) {
            tail = nullptr;
        }
        return data;
    } else {
        throw runtime_error("The Queue is empty");
    }
}

template<class T>
T Queue<T>::front() {
    if (!isEmpty()) {
        return head->data;
    }
    throw runtime_error("The Queue is empty");
}

template<class T>
T Queue<T>::back() {
    if (!isEmpty()) {
        return tail->data;
    }
    throw runtime_error("The Queue is empty");
}

template<class T>
int Queue<T>::getSize() {
    return size;
}

template<class T>
void Queue<T>::clear() {
    while (head != NULL) {
        NodoL<T>* aux = head;
        head = aux->next;
        delete aux;
    }
    size = 0;
    tail = NULL;
}

template<class T>
void Queue<T>::print() {
    NodoL<T>* aux = head;
    while (aux != NULL) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}


template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}
#endif