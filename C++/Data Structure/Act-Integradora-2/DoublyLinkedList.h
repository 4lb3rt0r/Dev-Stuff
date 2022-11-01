#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "NodeD.h"

template<class T>
class DoublyLinkedList {
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;
public:
    DoublyLinkedList(); //ok
    void operator=(DoublyLinkedList<T> list);
    T& operator[](int index); //ok
    void addFirst(T data); //ok
    void addLast(T data); //ok
    bool deleteData(T data); //ok
    bool deleteAt(int index); //ok
    T getData(int index); //ok
    void updateAt(int index, T newData); //ok
    void updateData(T data, T newData); //ok
    void insertAt(int index, T newData); //ok
    int findData(T data); //ok
    void clear(); //ok
    void print(); //ok
    void printReverse(); //ok
    bool isEmpty(); //ok
    int getSize(); //ok
    void quickSort(DoublyLinkedList<T>&lista, int inicio, int final);
    int partition(DoublyLinkedList<T>&lista, int inicio, int final);
    void sort();
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
void DoublyLinkedList<T>::addFirst(T data) {
    // Validamos si la lista esta vacia
    if (isEmpty()) {
        head = new NodeD<T>(data);
        tail = head;
    } else {
        // Creamos el nuevo nodo
        head->prev = new NodeD<T>(data, head, nullptr);
        head = head->prev;
    }
    // incrementamos el tamaño
    size++;
}

template<class T>
void DoublyLinkedList<T>::addLast(T data) {
    // Validamos si la lista esta vacia
    if (isEmpty()) {
        tail = new NodeD<T>(data);
        head = tail;
    } else {
        // Creamos el nuevo nodo
        tail->next = new NodeD<T>(data, nullptr, tail);
        tail = tail->next;
    }
    // incrementamos el tamaño
    size++;
}

template<class T>
T DoublyLinkedList<T>::getData(int index) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar
        NodeD<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente nodo
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente nodo
                aux = aux->prev;
                // Decrementamos el índice auxiliar
                auxIndex--;
            }
        }
        return aux->data;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}

template<class T>
T& DoublyLinkedList<T>::operator[](int index) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar
        NodeD<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente nodo
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente nodo
                aux = aux->prev;
                // Decrementamos el índice auxiliar
                auxIndex--;
            }
        }
        return aux->data;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}

template<class T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> list) {
    clear();
    if (!list.isEmpty()) {
        // creamos un apuntador auxliar para recorrer la lista que apunte a list
        NodeD<T>* aux = list.head;
        // Recorremos la lista hasta llegar al final
        while (aux != nullptr) {
            // Agregamos el elemento al final
            addLast(aux->data);
            // Avanzamos al siguiente nodo
            aux = aux->next;
        }
        // actualizamos el tamaño de la lista
        size = list.size;
    } 
}

template<class T>
int DoublyLinkedList<T>::findData(T data) {
    // creamos un nodo auxiliar que apunte a head
    NodeD<T>* aux = head;
    // creamos un índice auxiliar que empezará en 0
    int auxIndex = 0;
    // Recorremos la lista hasta llegar al ultimo nodo
    while(aux != nullptr) {
        // Validamos si el elemento a buscar es el elemento donde apunta aux
        if (aux->data == data) {
            // regremos el índice
            return auxIndex;
        } else {
            // Recorremos el apuntador aux
            aux = aux->next;
            // incrementamos el índice auxiliar
            auxIndex++;
        }
    }
    // No encontramos el dato
    return -1;
}

template<class T>
bool DoublyLinkedList<T>::deleteAt(int index) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar
        NodeD<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente nodo
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente nodo
                aux = aux->prev;
                // Decrementamos el índice auxiliar
                auxIndex--;
            }
        }
        // Borramos el nodo auxiliar
        // solo existe un nodo
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            if (aux == head) { // Borramos el primer nodo
                // asignamos head al siguiente nodo
                head = head->next;
                // asignamos el prev de head a nulo
                head->prev = nullptr;
            } else {
                if (aux == tail) { // Borramos el ultimo nodo
                    // asignamos tail al anterior nodo
                    tail = tail->prev;
                    // asignamos el next de tail a nulo
                    tail->next = nullptr;
                } else { // Borramos un nodo intermedio
                    // asignamos al next del prev de aux el valor de next de aux
                    aux->prev->next = aux->next;
                    // asignamos al prev del next de aux el valor de prev de aux
                    aux->next->prev = aux->prev;
                }
            }
        }
        // Borrar el nodo auxiliar
        delete aux;
        // decrementamos el tamaño de la lista
        size--;
        // regresamos true
        return true;
    } else {
        return false;
    }
}

template<class T>
bool DoublyLinkedList<T>::deleteData(T data) {
    // Validamos que la lista no este vacía
    if (!isEmpty()) {
        // creamos un nodo auxiliar que apunte a head
        NodeD<T>* aux = head;
        // Recorremos la lista hasta llegar al ultimo nodo
        while(aux->data != data && aux != nullptr) {
            // Recorremos el apuntador aux
            aux = aux->next;
        }
        // Validamos que si lo encontramos
        if (aux != nullptr) {
            // Borramos el nodo auxiliar
            // solo existe un nodo
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            } else {
                if (aux == head) { // Borramos el primer nodo
                    // asignamos head al siguiente nodo
                    head = head->next;
                    // asignamos el prev de head a nulo
                    head->prev = nullptr;
                } else {
                    if (aux == tail) { // Borramos el ultimo nodo
                        // asignamos tail al anterior nodo
                        tail = tail->prev;
                        // asignamos el next de tail a nulo
                        tail->next = nullptr;
                    } else { // Borramos un nodo intermedio
                        // asignamos al next del prev de aux el valor de next de aux
                        aux->prev->next = aux->next;
                        // asignamos al prev del next de aux el valor de prev de aux
                        aux->next->prev = aux->prev;
                    }
                }
            }
            // Borrar el nodo auxiliar
            delete aux;
            // decrementamos el tamaño de la lista
            size--;
            // regresamos true
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

template<class T>
void DoublyLinkedList<T>::updateAt(int index, T newData) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar
        NodeD<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente nodo
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente nodo
                aux = aux->prev;
                // Decrementamos el índice auxiliar
                auxIndex--;
            }
        }
        // Actualizamos el nodo auxiliar
        aux->data = newData;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}

template<class T>
void DoublyLinkedList<T>::updateData(T data, T newData) {
    // Validamos que la lista no este vacia
    if (!isEmpty()) {
        // creamos un nodo auxiliar que apunte a head
        NodeD<T>* aux = head;
        // Recorremos la lista hasta llegar al ultimo nodo
        while(aux->data != data && aux != nullptr) {
            // Recorremos el apuntador aux
            aux = aux->next;
        }
        // Validamos que si lo encontramos
        if (aux != nullptr) {
            // actualizamos el nodo auxiliar
            aux->data = newData;
        } else {
            throw out_of_range("Dato no encontrado");
        }
    } else {
        throw out_of_range("Lista vacia");
    }
}

template<class T>
void DoublyLinkedList<T>::insertAt(int index, T newData) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar
        NodeD<T>* aux;
        // Buscar el elemento cuando el indice sea menor a la mitad
        if (index < size / 2) {
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = head;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = 0;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex < index) {
                // Avanzamos al siguiente nodo
                aux = aux->next;
                // Incrementamos el índice auxiliar
                auxIndex++;
            }
        } else { // Buscamos de atras hacia adelante
            // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
            aux = tail;
            // Creamos un índice auxliar que empezará en 0
            int auxIndex = size - 1;
            // Recorremos la lista hasta llegar al nodo que se desea obtener
            while (auxIndex > index) {
                // Avanzamos al siguiente nodo
                aux = aux->prev;
                // Decrementamos el índice auxiliar
                auxIndex--;
            }
        }
        // Validamos si vamos a insertar el elemento en la posición 0 o al principio de la lista
        if (aux == head) {
            head->prev = new NodeD<T>(newData, head, nullptr);
            head = head->prev;
        } else { // Insertamos un elemento después del primer elemewnto de la lista
            // asignamos el next de aux prev igual al nuevo nodo
            aux->prev->next = new NodeD<T>(newData, aux, aux->prev);
            // asignamos el prev de aux al nuevo nodo
            aux->prev = aux->prev->next;
        }
        // incrementamos el tamaño de la lista
        size++;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}


template<class T>
void DoublyLinkedList<T>::clear() {
    if (!isEmpty()) {
        // creamos un apuntador auxiliar que apunte a head
        NodeD<T>* aux = head;
        // recorremos la lista hasta llegar al ultimo nodo
        while (aux != nullptr) {
            // apuntamos head al siguiente elemento
            head = aux->next;
            // Borramos el espacio de memoria del nodo
            delete aux;
            // Actualizamos el apuntador auxiliar
            aux = head;    
        }
        // Actualizamos el tamaño de la lista
        size = 0;
        tail = nullptr;
    }
}

template<class T>
void DoublyLinkedList<T>::print() {
    // Validamos que la lista no este vacia
    if (!isEmpty()) {
        // creamos un apuntador auxiliar que apunte a head
        NodeD<T>* aux = head;
        // Recorremos la lista hasta llegar al ultimo nodo
        while (aux != nullptr) {
            // Imprimimos el dato del nodo
            cout << aux->data << " ";   
            // Avanzamos al siguiente nodo
            aux = aux->next;
        }
        cout << endl;
    } else {
        cout << "Lista vacia" << endl;
    }
}

template<class T>
void DoublyLinkedList<T>::printReverse() {
    // Validamos que la lista no este vacia
    if (!isEmpty()) {
        // creamos un apuntador auxiliar que apunte a tail
        NodeD<T>* aux = tail;
        // Recorremos la lista hasta llegar al primer nodo  
        while (aux != nullptr) {    
            // Imprimimos el dato del nodo
            cout << aux->data << " ";
            // Avanzamos al siguiente nodo
            aux = aux->prev;        
        }
        cout << endl;
    } else {
        cout << "Lista vacia" << endl;
    }
}


template<class T>
bool DoublyLinkedList<T>::isEmpty() {
    return size == 0;
}

template<class T>
int DoublyLinkedList<T>::getSize() {
    return size;
}

template <class T>
int DoublyLinkedList<T>::partition(DoublyLinkedList<T>&lista, int inicio, int final){
    T pivote = lista[inicio];   //Pivote, primer elemento de la lista
    int i = inicio + 1; //Index en la posición inicio + 1
    for(int j = i; j<= final; j++){ //Se ejecuta siempre y cuando inicio sea mayor a final
        if(lista[j] < pivote){  //Si J es menor que el pivote, de ser menor hacemos swap entre pos j y pos i
            T aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
            i++;    //Incrementamos la variable i
        }
    }
    T aux = lista[inicio];    //Hacemos swap entre el pivote y el elemento i - 1, que sería el ultimo valor menor a pivote siendo intercambiado con el pivote
    lista[inicio] = lista[i-1];
    lista[i-1] = aux;
    return i-1;
}

template <class T>
void DoublyLinkedList<T>::quickSort(DoublyLinkedList<T>&lista, int inicio, int final){
    if(inicio < final){ //Caso base
        int pivote = partition(lista, inicio, final);   
        quickSort(lista, inicio, pivote-1); //Llamada recursiva lado izquierdo
        quickSort(lista, pivote+1, final);  //Llamada recursiva lado derecho
    }
}

//Sort, ordena la lista por valores
//Quicksort, complejidad: O(n^2)
template <class T>
void DoublyLinkedList<T>::sort(){
    this->quickSort(*this, 0, size-1);    
}

#endif