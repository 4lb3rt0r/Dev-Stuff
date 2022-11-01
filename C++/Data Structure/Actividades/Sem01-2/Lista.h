#ifndef Lista_h
#define lista_h

#include <vector>

template <class T>
class Lista {
private:
    vector <T> data; //vector de datos vacío
    int size;
    int max;
public:
    Lista(); //constructor por default
    void insert(T dataToInsert);
    void erase();
    T getData(int index);
    int getSize();
    void print();
};

//Constructor por default
template <class T>
Lista <T>::Lista() {
    size = 0;
    max = 100;
    data.resize(max); //vector de 100 elementos
}

//Inserta un elemento de la lista
template <class T> 
void Lista <T> :: insert (T dataToInsert) {
    if (size < max) {
        data[size] = dataToInsert;
        size++;
    } 
}

//Elimina el último elemento de la lista 
template <class T>
void Lista <T> :: erase () { 
    if (size > 0) { //Valida que hay elementos en la lista
        cout<<"El elemento a borrar es: "<<data[size-1]<<endl;
        size --;
    }
    else {
        cout<<"NO HAY ELEMENTOS"<<endl;
    }
}

//Devuelve el elemento de la posición index
template <class T>
T Lista <T> :: getData (int index) {
    if (index < size) { //Valida que el índice sea válido
        return data[index];
    }
    else {
        // Genera una excepcion
        throw out_of_range("Index out of range");
    }
}

//Devuelve el valor de la lista
template <class T>
int Lista <T> :: getSize() {
    return size;
}

//Imprime la lista
template <class T>
void Lista <T> :: print() {
    for (int i = 0; i < size; i++) {
        cout<<"["<<i<<"] - "<<data[i]<<endl;
    }
} 

#endif


