#ifndef Graph_h
#define Graph_h

template <class T>
class Graph {
    private:
        vector<T> vertices;
        int nVertex;
        vector <vector <Edge<T>>> adjList;
        int findFromVertex(T vertex);
        void depthFirstSearchR(int vertexIndex, vector<bool> &status);
    public:
        Graph();
        Graph(vector<T> vertices);
        void insert(Edge<T> edge);
        void remove(Edge <T> edge);
        void insertVertex(T vertices[10], int nVertices);
        void breadthFirstSearch(T vertex);
        void depthFirstSearch(T vertex);
        void print();
};

template <class T>
Graph<T> :: Graph() {
    nVertex = 0;
}

template <class T>
Graph<T> :: Graph(vector<T> vertices) {
    this->vertices = vertices;
    nVertex = vertices.size();
    vector<Edge<T> > temp;
    //Inicializamos el vector adjList con vectores tipo Edge vacíos
    for (int i = 0; i < nVertex; i++) {
        adjList.push_back(temp);
    }
    //Creamos un vector con vectores del tipo Edge
    // vector <vector<Eedge<T>>> adjListAux;
    // adjList = adjListAux;
}

template <class T>
int Graph<T> :: findFromVertex(T vertex) {
    //Buscamos el vértice dentro de la lista de vértices
    auto it = find(vertices.begin(), vertices.end(), vertex);
    //Validamos si lo encontramos
    if (it != vertices.end()) {
        //Si lo encontramos, retornamos la posición
        return it - vertices.begin();
    }
    else {
        //Si no lo encontramos, retornamos -1
        return -1;
    }
}

template <class T>
void Graph<T> :: insert (Edge<T> edge) {
    //Buscamos el índice del vértice origen
    int indexSource = findFromVertex(edge.source);
    if (indexSource == -1) {
        vertices.push_back(edge.source);
        indexSource = nVertex;
        nVertex++;
        vector <Edge<T>> edgeAux;
        adjList.push_back(edgeAux);
    }
    //Buscamos el índice del vértice origen
    int indexTarget = findFromVertex(edge.target);
    if (indexTarget == -1) {
        vertices.push_back(edge.target);
        indexTarget = nVertex;
        nVertex++;
        vector <Edge<T>> edgeAux;
        adjList.push_back(edgeAux);
    }
    adjList[indexSource].push_back(edge);
}

template <class T>
void Graph<T> :: breadthFirstSearch(T vertex) {
    //Comprobamos si el índice existe
    int vertexIndex = findFromVertex(vertex);
    if (vertexIndex == -1) {
        cout << "El vértice no existe" << endl;
        return;
    }
    else if (vertexIndex >= 0) {
        //Creamos una lista de estados con todos los vértices
        vector<bool> status(nVertex, false);
        //Creamos uan fila vacía de los vértices visitados
        queue<int> visited;
        //Insetar a la fila el vértice inicial
        visited.push(vertexIndex);
        //Marcamos el vértice como visitado
        status[vertexIndex] = true;
        //Mientras la fila no esté vacía
        while (!visited.empty()) {
            //Recorremos todos los vértices adyacentes del vértice procesado
            //Actualizamos el vértice a procesar
            vertexIndex = visited.front();
            for (auto adj : adjList[vertexIndex]) {
                //Buscamos los vértices adyacentes en la lista de vértices
                int adjIndex = findFromVertex(adj.target);
                //Validamos si el vértice adyacente existe
                //if (adjIndex >= 0) {
                    //Revisamos el status del vértice adyacente
                    if (!status[adjIndex]) {
                        //Si no está visitado, lo insertamos a la fila
                        visited.push(adjIndex);
                        //Marcamos el vértice como visitado
                        status[adjIndex] = true;
                    }

                //}
            }
            //Imprimimos el vértice procesado
            cout<<vertices[visited.front()]<<" ";
            //removemos el vértice procesado de la lista
            visited.pop();
            //Actualizamos el ´vertice a procesar
            //vertexIndex = visited.front();
        }
        cout<<endl;
    }
}

template <class T>
void Graph<T> :: depthFirstSearchR(int vertexIndex, vector<bool> &status){
    // Validamos el status del vértice
    if (!status[vertexIndex]){
        cout<<vertices[vertexIndex]<<" ";
        //Cambiamos su estado
        status[vertexIndex] = true;
        //Recorremos cada uno de los vértices adyacentes
        for (auto adj : adjList[vertexIndex]){
            //Buscamos el índice del vértice adyacente
            int adjIndex = findFromVertex(adj.target);
            //Validamos si el vértice existe
            if (!status[adjIndex]){
                //Llamamos recursivamente a la función
                depthFirstSearchR(adjIndex, status);
            }
        }
    }
}

template <class T>
void Graph<T> :: depthFirstSearch(T vertex) {
    //Comprobamos si el índice existe
    int vertexIndex = findFromVertex(vertex);
    if (vertexIndex >= 0) {
        // Creamos una lista de estados con todos los vértices en falso
        vector<bool> status(nVertex, false);
        // Llamamos a la función recursiva
        depthFirstSearchR(vertexIndex, status);
    }
    else {
        cout << "El vértice no existe" << endl;
    }
    cout<<endl;
}

template <class T>
void Graph<T> :: print() {
    for (int i = 0; i < nVertex; i++) {
        cout << vertices[i] << "-> ";
        // for (int j = 0; j < adjList[i].size(); j++) {
        //     cout << adjList[i][j].target << ";" << adjList[i][j].weight;
        // }
        for (auto edge : adjList[i]) {
            cout<<edge.target<<" : "<<edge.weight<<" - ";
        }
        cout << endl;
    }
}

#endif