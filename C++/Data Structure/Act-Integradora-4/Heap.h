#ifndef Heap_h
#define Heap_h

#include <stack>

template <class T>
class Heap {
    private:
        vector<T> heap;
        int size;
        void swap(int a, int b);
        void upSort(int pos);
        void downSort(int pos);
    public:
        Heap();
        Heap(vector<T> list);
        T pop();
        T top();
        void push(T data);
        void print();
        bool isEmpty();
        int getSize();
        void heapSort(string order); //Imprime los elementos del árbol en base al parámetro de order
};

template <class T>
Heap<T> :: Heap() {
    size = 0;
}

template <class T>
void Heap<T> :: swap(int a, int b) {
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void Heap<T> :: upSort(int pos) {

}

template <class T>
void Heap<T> :: downSort(int pos) {
    // Recorremos los hijos hasta que ya no tenga hijos o no tengamos que intercambiar nada
    while (pos * 2 + 1 < size) {
        // Buscamos los hijos
        int son1 = pos * 2 + 1;
        int son2 = pos * 2 + 2;
        int bigSon;
        if (son2 < size) {
            // Comparamos cual de los dos hijos es mayor
            heap[son1] >= heap[son2] ? bigSon = son1 : bigSon = son2;
        } else {
            bigSon = son1;
        }
        // Comparamos el valor de bigSon con el el valor de pos
        if (heap[bigSon] > heap[pos]) {
            // Intercambiomo bigson con pos
            swap(pos, bigSon);
            // Cambiamos el valor de pos por el de bigSon
            pos = bigSon;
        } else {
            // Me salgo del ciclo
            pos = size;
        }
    }
}

template<class T>
Heap<T> :: Heap(vector<T> list) {
    //Validamos si la lista que obtuvimos esta vacia
    if (list.size() > 0) {
        //Asignamos el valor de la lista al vector heap
        heap = list;
        //Asignamos el valor de size al tamaño de la lista
        size = list.size();
        //Calculamos el primero de los nodos padre
        int index = size/2 -1;
        //DownSort - Ordenamiento hacia abajo
        //Recorremos desde el último de los padres hasta el primero de los hijos
        while (index >= 0) {
            int pos = index;
            //Llamamos a la función downSort 
            downSort(pos);
            //Disminuimos el valor de index
            index--;
        }
    }
}

template <class T>
T Heap<T> :: pop() {
    //Guardamos el valor del primer elemento del heap en una variable au0xiliar
    T aux = heap[0];
    //Intercambiamos la última posición del árbol con la raíz
    swap(0,size-1);
    //Eliminamos el último elemento del heap
    heap.pop_back();
    //Decrementamos el tamaño de la lista
    size--;
    //downSort
    downSort(0);
    //Retornamos 
    return aux;   
}

template <class T>
T Heap<T> :: top() {
    //Guardamos el valor del primer elemento del heap en una variable au0xiliar
    T aux = heap[0];
    //Intercambiamos la última posición del árbol con la raíz
    swap(0,size-1);
    //downSort
    downSort(0);
    //Retornamos 
    return aux;
}

template <class T> 
void Heap<T> :: push(T data) {
    //insertar un nuevo elemento al árbol
    heap.push_back(data);
    //Incrementamos el tamaño del heap
    size++;
    //Definimos una variable pos con la posición del elemento insertado
    int pos = size-1;
    //Realizamos el upSort
    while (pos != 0) {
        //Obtenemos la posición del nodo padre 
        int parent = (pos-1)/2;
        //comparamos el valor de pos con el valor de parent 
        if (heap[parent] < heap[pos]) {
            //Intercambiamos los lugares de parent y pos
            swap(parent,pos);
            //Intercambiamos los valores de parent y pos
            pos = parent;
        }
        else {
            //Rompemos el ciclo
            pos = 0;
        }
    }
}

template <class T>
void Heap<T> :: heapSort(string order) {
    Heap<T> auxHeap(heap);
    if (order == "asc") {
        //Ordenar de forma ascendente
        stack<T> auxStack;
        //Recorremos con el auxHeap y hacemos pop de cada uno de los elementos 
        while(!auxHeap.isEmpty()) {
            auxStack.push(auxHeap.pop());
        }
        while(!auxStack.empty()) {
            cout<<auxStack.top()<<" ";
            auxStack.pop();
        }
        cout<<endl;
    }
    else {
        //Ordenar de forma descendente
        while(!auxHeap.isEmpty()) {
            cout<<auxHeap.pop()<<" ";
        }
        cout<<endl;
    }
}



template <class T>
void Heap<T> :: print() {
    for (auto el : heap) {
        cout<<el<<" ";
    }
    cout<<endl;
}

template<class T>
bool Heap<T>::isEmpty() {
    return size == 0;
}

#endif