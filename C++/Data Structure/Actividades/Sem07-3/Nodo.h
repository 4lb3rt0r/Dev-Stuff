#pragma once

template <class T>
struct Nodo {
    T data;
    Nodo <T> *next;
    Nodo();
    Nodo(T data);
    Nodo(T data,Nodo <T> *next);
};

template <class T>
Nodo<T> :: Nodo () {
    next = nullptr;
}

template <class T>
Nodo<T> :: Nodo(T data) {
    this->data = data;
    this->next = nullptr;
}

template <class T>
Nodo<T> :: Nodo (T data, Nodo <T> *next) {
    this->data = data;
    this->next = next;
}