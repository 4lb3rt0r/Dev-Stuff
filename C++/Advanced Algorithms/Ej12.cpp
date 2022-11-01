/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 26/Septiembre/2022
Ejem 12. Algoritmo de Dijkstra*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits> // INT_MAX ==> Infinito

using namespace std;

#define INF INT_MAX
#define Edge pair<int, int> // A donde llego y su costo
#define Graph vector<vector <Edge>> // Grafo representado en una lista de adyacencias
#define Vertex pair<int, int> // Disctancia (Costo), ID (nodo al que llego), sirve para la fila priorizada

void print(Graph &G) {
    for (int i = 0; i < G.size(); i++) {
        cout << i + 1 << " ==> ";
        for (int j = 0; j < G[i].size(); j++) {
            cout << "(" << G[i][j].first + 1 << "," << G[i][j].second << ")";
        }
        cout << endl;
    }
}

vector<int> dijkstra(Graph &G, int source) {
    vector<int> dist(G.size(), INF);
    dist[source] = 0;
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> queue; // Fila priorizada, con prioridad valor menor del primer elemento de Vertex (par)
    Vertex vs(0, source);
    queue.push(vs);

    while (!queue.empty()) {
        int u = queue.top().second;
        queue.pop();

        for (int i = 0; i < G[u].size(); i++) {
            Edge e = G[u][i];
            int v = e.first; // Hacia donde llego
            int w = e.second; // Con que costo llego

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                Vertex vtx(dist[v], v);
                queue.push(vtx);
            }
        }
    }

    return dist;
}

int main () {
    int nodes, edges, source, u, v, w;
    cin >> nodes >> edges >> source;
    Graph G(nodes);

    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> w;
        // Arco de u->v con un costo w
        Edge edge1(v-1, w);
        G[u-1].push_back(edge1);
        // Arco de v->u con un costo w
        Edge edge2(u-1, w);
        G[v-1].push_back(edge2);
    }
    //print(G);

    vector<int> distances = dijkstra(G, source-1);
    cout << "Distancias: " << endl;

    for (int i = 0; i < nodes; i++) {
        if (i != source-1){
            cout << source << "-->" << (i + 1) << " : ";
            if (distances[i] == INF) {
                cout << "INF" << endl;
            }
            else {
                cout << distances[i] << endl;
            }
        }
    }
    return 0;
}

// Cantidad de nodos, cantidad de arcos, nodo origen
// arcos punto origen punto destino y costo.

/*
5 8 1
1 2 2
1 3 12
1 4 10
2 3 9
2 5 5
3 4 6
3 5 3
4 5 7

5 7 1
1 2 5
1 3 8
1 4 7
1 5 10
2 3 1
3 4 9
4 5 2
*/