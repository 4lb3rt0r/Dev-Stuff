#pragma once

template <class T>
struct NodoL {
    T data;
    NodoL <T> *next;
    NodoL();
    NodoL(T data);
    NodoL(T data,NodoL <T> *next);
};

template <class T>
NodoL<T> :: NodoL () {
    next = nullptr;
}

template <class T>
NodoL<T> :: NodoL(T data) {
    this->data = data;
    this->next = nullptr;
}

template <class T>
NodoL<T> :: NodoL (T data, NodoL <T> *next) {
    this->data = data;
    this->next = next;
}