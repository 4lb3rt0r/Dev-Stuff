/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 28/Septiembre/2022
Actividad 09: Rocky the Beagle */

/* Descripción breve del programa:
El algoritmo de Rocky The Beagle utiliza el algoritmo de Dijkstra para indicar al dueño 
de un perro sabueso dónde colocar la comida para su perro, de forma que el perro, de todos los
caminos cortos posibles para llegar a su comida, elija el camino más largo.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits> // INT_MAX ==> Infinito

using namespace std;

#define INF INT_MAX
#define Edge pair<int, int> // A donde llego y su costo
#define Graph vector<vector <Edge>> // Grafo representado en una lista de adyacencias
#define Vertex pair<int, int> // Disctancia (Costo), ID (nodo al que llego), sirve para la fila priorizada

/* Función Dijkstra encargada de elaborar un vector dónde se almacenen los
datos de los menores costos/distancias por cada camino posible dentro de un grafo.
*/
//Complejidad: O(n log n)
vector<int> dijkstra(Graph &G, int source) {
    // Vector de costos/distancias de tamaño G.size() conteniendo datos infinitos (infinito indica nodos sin conexión)
    vector<int> dist(G.size(), INF);
    // Declaramos el primer elementos del vector con un 0, correspondiente al costo del nodo inicial
    dist[source] = 0;
    // Inicializamos una lista priorizada que servirá de apoyo para comparar las/los menores costos/distancias entre nodos vecinos
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> queue; // Fila priorizada, con prioridad valor menor del primer elemento de Vertex (par)
    // Inicializamos un vértice con los datos del nodo inicial y su costo/distancia 
    Vertex vs(0, source);
    // Introducimos el vértice anterior dentro de la lista priorizada
    queue.push(vs);

    // Mientras que la lista priorizada no se encuentre vacía:
    while (!queue.empty()) {
        // Obtenemos el primer elemento de la lista priorizada
        int u = queue.top().second;
        // Quitamos dicho elemento de la lista priorizada
        queue.pop();

        // Por cada vecino del nodo "u" obtenido de la lista priorizada:
        for (int i = 0; i < G[u].size(); i++) {
            // Declaramos un arco "e" con la info del nodo vecino (el nodo y su costo)
            Edge e = G[u][i];
            int v = e.first; // Hacia donde llego
            int w = e.second; // Con que costo llego

            /* Si el costo del nodo "v" es mayor que el costo del nodo "u" más
            el costo del arco entre ambos nodos:
            */
            if (dist[v] > dist[u] + w) {
                // Cambiamos el valor del costo por el de menos cantidad, osea dist[u] + w
                dist[v] = dist[u] + w;
                /* Declaramos un nuevo vértice con los datos del nuevo nodo que mejoró
                el camino, esto incluye su costo y el mismo nodo
                */
                Vertex vtx(dist[v], v);
                // Insertamos dicho nodo dentro de la lista priorizada
                queue.push(vtx);
            }
        }
    }
    /* Retornamos la lista de costos/distancias conteniendo los caminos
    más cortos del nodo inicial "source" a cada uno de los nodos con los
    que tiene conexión
    */
    return dist;
}

int main () {
    // Declaración de variables iniciales
    int n, nodes, edges, w;
    /* "source" es declarado como 'A' ya que al manejar nodos de tipo char,
    según el formato ASCII esta 'A' equivale a 1. Además Rocky siempre empieza
    su recorrido en el nodo 1.
    */
    char source = 'A', u, v, output;
    // Pedimos al usuario la cantidad de casos a evaluar
    cin >> n;

    // Por cada caso:
    for (int i = 0; i < n; i++) {
        // Pedimos cantidad de nodos y arcos del grafo correspondiente
        cin >> nodes >> edges;
        // Creamos el grafo en base a la cantidad de nodos
        Graph G(nodes);

        // Por cada arco del grafo:
        for (int i = 0; i < edges; i++) {
            // Pedimos al usuario 2 nodos que tengan conexión entre ambos y su costo/distancia
            cin >> u >> v >> w;
            // Arco de u -> v con un costo w
            Edge edge1(v - 'A', w);
            G[u - 'A'].push_back(edge1);
            // Arco de v -> u con un costo w
            Edge edge2(u - 'A', w);
            G[v - 'A'].push_back(edge2);
        }
        // Declaramos el vector de distancias que obtendrá su valor de la llamada a la función dijkstra
        vector<int> distances = dijkstra(G, source - 'A');
        // Obtenemos el nodo con el mayor costo de todos los caminos con menor costo
        output = max_element(distances.begin(), distances.end()) - distances.begin() + 'A';
        // Desplegamos el texto del caso y su resultado final
        cout << "Case " << i + 1 << ": " << output << endl;
    }

    return 0;
}

/*
2 
5 7 
A B 5 
A C 4 
A D 7 
B E 3 
C D 2 
C E 4 
D E 1 
4 6 
A B 1 
A C 1 
A D 1 
B C 1 
B D 1 
C D 1 
*/
