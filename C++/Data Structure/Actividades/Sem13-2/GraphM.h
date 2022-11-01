#ifndef Graph_h
#define Graph_h

template <class T>
class GraphM {
    private:
        bool matrix [10] [10] {false};
        T vertices [10];
        int nVertices;
        int findFromVertex(T vertex);
    public:
        GraphM();
        void insert(T fromVertex, T toVertex);
        void remove(T fromVertex, T toVertex);
        void insertVertex(T vertices[10], int nVertices);
        void print();
};

template <class T>
GraphM<T> :: GraphM() {
    nVertices = 0;
}

template <class T>
int GraphM<T> :: findFromVertex (T vertex) {
    for (int i = 0; i < nVertices; i++) {
        if (vertices[i] == vertex) {
            return i;
        }
    }
    return -1;
}

template <class T>
void GraphM<T>:: insertVertex(T vertices[10], int nVertices) {
    for (int i = 0; i < nVertices; i++) {
        this->vertices[i] = vertices[i];
    }
    this->nVertices = nVertices;
}

template <class T>
void GraphM<T> :: insert(T fromVertex, T toVertex) {
    //Verificamos que el vértice "fromVertex" no sea igual a "toVertex"
    if (fromVertex != toVertex) {
        //Buscamos en qué posición de la lista está el vertice de origen
        int posFromVertex = findFromVertex(fromVertex);
        //Validamos si ya se encuentra en la lista de vértices
        if (posFromVertex == -1) {
            if (nVertices < 10) {
                //Si no se encuentra, lo agregamos
                vertices[nVertices] = fromVertex;
                posFromVertex = nVertices;
                nVertices++;
            }
            else {
                return;
            }
        }
        
        int posToVertex = findFromVertex(toVertex);
        //Validamos si ya se encuentra en la lista de vértices
        if (posToVertex == -1) {
            if (nVertices < 10) {
                //Si no se encuentra, lo agregamos
                vertices[nVertices] = toVertex;
                posToVertex = nVertices;
                nVertices++;
            }
            else {
                return;
            }
        }
        //Actualizamos a "true" la posición correspondiente en la matriz
        matrix[posFromVertex] [posToVertex] = true;
    }
}
    
template <class T>
void GraphM<T> :: remove(T fromVertex, T toVertex) {
    //Verificamos que el vértice "fromVertex" no sea igual a "toVertex"
    if (fromVertex != toVertex) {
        //Buscamos en qué posición de la lista está el vertice de origen
        int posFromVertex = findFromVertex(fromVertex);
        //Validamos si ya se encuentra en la lista de vértices
        if (posFromVertex == -1) {
            return;
        }
        //Buscamos en qué posición de la lista está el vertice de origen
        int posToVertex = findFromVertex(toVertex);
        //Validamos si ya se encuentra en la lista de vértices
        if (posToVertex == -1) {
            return;
        }
        //Actualizamos a "true" la posición correspondiente en la matriz
        matrix[posFromVertex] [posToVertex] = false;
    }
}

template <class T>
void GraphM<T> :: print() {
    cout<<"  ";
    for (int i = 0; i < nVertices; i++) {
        cout<<vertices[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < nVertices; i++) {
        cout<<vertices[i]<<" ";
        for (int j = 0; j < nVertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

#endif