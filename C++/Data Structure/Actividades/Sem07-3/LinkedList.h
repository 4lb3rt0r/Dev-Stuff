#ifndef LinkedList_h
#define LinkedList_h

#include "Nodo.h"

template <class T>
class LinkedList {
private:
    Nodo<T>* head;
    int size;
public:
    LinkedList();
    void addLast(T data);
    //~LinkedList();
    void addFirst(T data);
    T getData(int index);
    int getSize();
    void deleteData(T data);
    void deleteAt(int index);
    void updateData(T data, T New);
    void updateAt(int index, T New);
    void print();
    bool isEmpty();
    int findData(T data);
    T& operator[](int index);
    void operator= (LinkedList<T> list);
    void clear();
};

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template <class T>
void LinkedList<T>::addLast(T data) {
    // Validamos si la lista esta vacia
    if (isEmpty()) {
        // Asignamos el nuevo nodo al head
        head = new Nodo<T>(data);
    } else {
        // Creamos una apuntador auxiliar para recorrer la lista que apunte a head
        Nodo<T>* aux = head;
        // Recorremos la lista hasta llegar al ultimo nodo
        while (aux->next != nullptr) {
            // Avanzamos al siguiente nodo
            aux = aux->next;
        }
        // Creamos un nuevo nodo con el dato que se desea agregar
        aux->next = new Nodo<T>(data);
    }
    // Incrementamos el tamaño de la lista
    size++;
}

template <class T>
void LinkedList<T>::addFirst(T data) {
    // Creamos un nuevo nodo con el dato que se desea agregar
    head = new Nodo<T>(data, head);
    // Incrementamos el tamaño de la lista
    size++;
}

template <class T>
void LinkedList<T> :: deleteData(T data) {
    // Validamos si la lista esta vacia
    if (head != nullptr) {
        // Creamos una apuntador auxiliar para recorrer la lista que apunte a head
        Nodo<T>* auxErase = head;
        //Creamos un apuntador auxiliar que apunte a nulo, pero que recorra la lista con un ciclo
        Nodo<T>* last = nullptr;
        //Mientras auxErase no haya llegado al final y n no sea igual al dato dentro del apuntador auxErase
        while ((auxErase != nullptr) && (auxErase->data != data)) {
            //Avanzamos al siguiente nodo con el apuntador last
            last = auxErase;
            //Recorremos auxErase un nodo
            auxErase = auxErase->next;
        }
        //Si se llega al final de la lista es porque no se encontró ninguna coincidencia con n
        if (auxErase == nullptr) {
            cout<<"Elemento no encontrado :/"<<endl;
        }
        //Si last mantiene su valor inicial "nullptr", significa que no entramos al while,
        //por lo tanto n se encuentra en la primera posición
        if (last == nullptr) {
            //Cedemos el valor de head al siguiente nodo ya que el head anterior se borrará
            head = head->next;
            //Eliminamos el primer nodo
            delete auxErase;
        }
        //Si ninguna de las condiciones anteriores se cumplió, significa que el nodo al que apunta auxErase coincide con el valor de n
        else {
            //el nodo siguiente a last es igual al que le sigue a auxErase
            last->next = auxErase->next;
            //Eliminamos el nodo
            delete auxErase;
        }
    } 
    // Decrementamos el tamaño de la lista
    size--;
    cout<<"Elemento borrado con éxito"<<endl;
}

template <class T>
void LinkedList<T> :: deleteAt(int index) {
    try {
        //Obtenemos el valor situado en el índice indicado por el usuario con la función getData
        int data = getData(index);
        //Ya obtenido el valor con la funcion, llamamos a la funcion deleteData para que elimine el nodo correspondiente 
        deleteData(data);
        //cout << "En el índice " << n << " esta el dato: " << data << endl;
        } 
        catch (out_of_range& e) {
            cout << e.what() << endl;
        }
}

template <class T>
void LinkedList<T> :: updateData (T data, T New) {
    // Validamos si la lista no esta vacia
    if (head != nullptr) {
        // Creamos una apuntador auxiliar para recorrer la lista que apunte a head
        Nodo<T>* auxReplace = head;
        //Ceamos un apuntador auxiliar para recorrer la lista que apunte a nulo
        Nodo<T>* last = nullptr;
        //Mientras que auxReplace no sea nulo (no haya llegado al final), y el dato al que apunta auxReplace no sea
        // igual a n, entramos al while
        while ((auxReplace != nullptr) && (auxReplace->data != data)) {
            // Last avanza al siguiente nodo
            last = auxReplace;
            // auxReplace avanza al siguiente nodo
            auxReplace = auxReplace->next;
        }
        //Si se cumple esta condición, significa que el recorrido llego a su final y no encontró ninguna coincidencia
        if (auxReplace == nullptr) {
            cout<<"Elemento no encontrado :/"<<endl;
        }
        //Si se cumple esta condicion, nunca se entró al while, por lo tanto el valor de last nunca cambió,
        // por ende el elemento a reemplazar es el primero
        if (last == nullptr) {
            //El valor al que apunta auxReplace es cambiado al nuevo valor
            auxReplace->data = New;
        }
        //Si no se cumplieron las condicionales anteriores, el valor se encuentra en algún nodo de la lista
        else {
            //Se reemplaza el valor al que apunta auxReplace por el nuevo
            auxReplace->data = New;
        }
    } 
    cout<<"Elemento actualizado con éxito"<<endl;
}

template <class T>
void LinkedList<T> :: updateAt(int index, T New) {
    try {
        //Obtenemos con la funcion getData el valor del index proporcionado por el usuario
        int data = getData(index);
        //Ya obtenido el valor, llamamos a la función updateData para que reemplace el valor con el nuevo
        updateData(data, New);
        //cout << "En el índice " << n << " esta el dato: " << data << endl;
    } 
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }
}

template <class T> 
int LinkedList<T> :: findData(T data) {
    //nodo auziliar que apunte a head
    Nodo<T>* aux = head;
    //creamos un auxiliar que empezará en 0
    int auxIndex = 0;
    //Recorremos la lista hasta llegar al ultimo elemento 
    while (aux != nullptr) {
        if (aux->data = data) {
            return auxIndex;
        }
        else {
            aux = aux->next;
            auxIndex++;
        }
    }
    return -1;
} 

template <class T>
T LinkedList<T>::getData(int index) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
        Nodo<T>* aux = head;
        // Creamos un índice auxliar que empezará en 0
        int auxIndex = 0;
        // Recorremos la lista hasta llegar al nodo que se desea obtener
        while (auxIndex < index) {
            // Avanzamos al siguiente nodo
            aux = aux->next;
            // Incrementamos el índice auxiliar
            auxIndex++;
        }
        return aux->data;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}

template <class T>
T& LinkedList<T>:: operator[](int index) {
    // Validamos que el indice sea valido
    if (index >= 0 && index < size) {
        // Creamos un apuntador auxiliar para recorrer la lista que apunte a head
        Nodo<T>* aux = head;
        // Creamos un índice auxliar que empezará en 0
        int auxIndex = 0;
        // Recorremos la lista hasta llegar al nodo que se desea obtener
        while (auxIndex < index) {
            // Avanzamos al siguiente nodo
            aux = aux->next;
            // Incrementamos el índice auxiliar
            auxIndex++;
        }
        return aux->data;
    } else {
        throw out_of_range("Índice fuera de rango");
    }
}

template <class T> 
void LinkedList<T> :: operator=(LinkedList<T> list) {
    clear();
    if (head != nullptr) {
        Nodo<T>* auxList = list.head;
        int auxIndex = 0;
        head = new Nodo<T>* (auxList->data);
        auxList = list.head->next;
        Nodo<T>* aux = head;
        while (auxList != nullptr) {
            aux->next = new Nodo<T>(auxList->data);
            auxList = auxList->next;
            aux = aux->next;
        }
        size = list.size;
    }
}

template <class T>
void LinkedList<T> :: clear() {
    Nodo<T>* aux = head;
    while (aux->next != nullptr) {
        head = aux->next;
        delete aux;
        aux = head;

        size = 0;
        head = nullptr;
    }
}

template <class T>
void LinkedList<T>::print() {
    Nodo<T>* aux = head;
    // Recorremos la lista hasta llegar al ultimo nodo
    while (aux != nullptr) {
        cout << aux->data << " ";
        // Avanzamos al siguiente nodo
        aux = aux->next;
    }
    cout << endl;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}

#endif /* LinkedList_h */