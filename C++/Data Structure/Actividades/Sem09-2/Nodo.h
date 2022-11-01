#pragma once

template <class T> 
struct Nodo{
    T data;
    Nodo <T>* left;
    Nodo <T>* right;
    Nodo<T> (T data);
    Nodo(T data, Nodo<T>* left, Nodo<T>* right);
};

template <class T> 
Nodo <T> :: Nodo(T data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

template <class T> 
Nodo <T> :: Nodo(T data, Nodo<T>* left, Nodo<T>* right) {
    this->data = data;
    this->left = left;
    this->right = right;
}
