/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 12/Octubre/2022
Actividad 12: Freckles */

// Minumum Spanning Treen (Prim, Kruskal)
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <cstdio>

using namespace std;

// Declaración de variable tipo pair que incluye 2 datos
typedef pair<double, double> iPair;

/* Declaración de la estructura Grafo que contiene vértices (nodos), costos de Prim
y Krustal, vectores para almacenar arcos y adyacencias. También incluye métodos para
agregar arcos al grafo y desplegar sus valores.
*/
struct Graph {
	// V = Cantidad de nodos (Vertex)
	// E = Cantidaf de arcos (Edges)
	double V, costMSTPrim, costMSTKruskal;
	vector<pair<double, pair<int, int>>> edges; 	// Utilizar en Kruskal
	vector<vector<pair<int, int>>> adjList; 	// Se utilza en Prim
	vector<pair<int, int>> selectedEdgesK;		// Los arcos sel Kruskal
	vector<pair<int,int>> selectedEdgesP;		// Los arcos sel Prim;
	Graph(double V){
		this->V = V;
		// this->E = E;
		adjList.resize(V);
		costMSTKruskal = costMSTPrim = 0;
	}
	// u = salida del arco
	// v = llegada del arco
	// w = costo del arco
	void addEdge(int u, int v, double w){
		edges.push_back({w, {u, v}}); //First = costo, second conexión
		adjList[u].push_back({v, w});
	}
	void load();
	void print();
	void kruskalMST();
	void primMST();
	void printEdgesP();
	void printEdgesK();
};

// Disjont Sets (Union-Find)
struct DisjointSets{
	int *parent, *rnk;
	int n;
	DisjointSets(int n){
		this->n = n;
		parent = new int[n+1];
		rnk = new int[n+1];
		for (int i=0; i<=n; i++){
			rnk[i] = 0;
			parent[i] = i;
		}
	}
	// Para encontrar el parent de 'u'
	int find(int u){
		if (u != parent[u]){
			parent[u] = find(parent[u]);
		}
		return parent[u];
	}

	// Union por rank
	void merge(int x, int y){
		x = find(x);
		y = find(y);
		if (rnk[x] > rnk[y]){
			parent[y] = x;
		}
		else{
			parent[x] = y;
		}
		if (rnk[x] == rnk[y]){
			rnk[y]++;
		}
	}
};

/* Función parte de la estructura Grafo encargada de recopilar
todos los datos que conformarán el grafo a analizar*/
void Graph::load () {
	// Vector de tipo pair que servirá para almacenar las coordenadas de las pecas
	vector<pair<double, double>> freckles;
	// Variables de tipo double para almacenar las coordenadas de las pecas (a,b) y el costo (c)
	double a, b, c;
	// Por cada nodo dentro del Grafo:
	for (int i = 0; i < V; i++) {
		// Obtenemos sus coordenadas 
		cin >> a >> b;
		// Colocamos las coordenadas dentro del vector freckles de tipo pair
		freckles.push_back({a, b});
	}
	// Por cada nodo dentro del Grafo:
	for (int i = 0; i < V; i++){
		// Por cada nodo dentro del Grafo excepto el nodo i:
		for (int j = i + 1; j < V; j++) {
			// Calculamos la distancia (costo) que existe entre el nodo i y el nodo j
			c = sqrt(pow(freckles[j].first - freckles[i].first, 2) + pow(freckles[j].second - freckles[i].second, 2));
			// Guardamos esta adyacencia dentro del grafo de la forma i => j y j => i
			addEdge(i, j, c);
			addEdge(j, i, c);
		}
	}
}

/* Función encargada de desplegar los datos contenidos en
una lista de adyacencias (matriz) de las conexiones entre 
los nodos del grafo.
*/
void Graph::print () {
	cout << "Adjacent List:" << endl;
	for (int i=0; i<V; i++){
		cout << " " << i << ": ";
		for (int j=0; j<adjList[i].size(); j++){
			cout << "(" << adjList[i][j].first << "," << adjList[i][j].second << ") ";
		}
		cout << endl;
	}
}

// Complejidad: O(V^2)
void Graph::primMST () {
	int selSource = 0;
	costMSTPrim = 0;
	unordered_set<int> selected;
	unordered_set<int> missing;
	selected.insert(0);

	for (int i = 1; i < V; i++) {
		missing.insert(i);
	}

	int connected = V - 1, minCost, selVertex;

	while (connected) {
		minCost = INT_MAX;

		for (auto it:selected) {
			for (auto it2:adjList[it]) {
				if (missing.find(it2.first) != missing.end() && it2.second < minCost) {
					minCost = it2.second;
					selVertex = it2.first;
					selSource = it;

				}
			}
		}

		costMSTPrim += minCost;
		selected.insert(selVertex);
		missing.erase(selVertex);
		selectedEdgesP.push_back({selSource, selVertex});
		connected--;
	}
}

/* Función encargada de desplegar los arcos existentes
dentro del grafo
*/
void Graph::printEdgesP () {
	cout << "Selected Edges Prim: ";
	for (auto it:selectedEdgesP){
		cout << "(" << it.first << "," << it.second << ") ";
	}
	cout << endl;
}
/* Función que aplica el algoritmo de kruskal, analizando los
el costo de cada arco para encontrar los de menor costo y hacerlos
parte de pequeños conjuntos, que con cada iteración dichos conjuntos
van incluyendo más arcos con menor costo, de forma que se cubren todas
las adyacencias de menor costo para cada uno de los nodos existentes dentro del grafo.
*/
// Complejidad: P(E logE)
void Graph::kruskalMST () {
	sort(edges.begin(), edges.end());
	DisjointSets ds(V);
	costMSTKruskal = 0;

	for (auto it:edges) {
		int p1 = ds.find(it.second.first);
		int p2 = ds.find(it.second.second);

		if (p1 != p2) {
			costMSTKruskal += it.first;
			selectedEdgesK.push_back({it.second.first, it.second.second});
			ds.merge(it.second.first, it.second.second);
		}
	}
}
/*Función encargada de desplegar los resultados de aplicar el
algoritmo de Prim*/
void Graph::printEdgesK () {
	cout << "Selected Edges Kruskal: ";
	for (auto it:selectedEdgesK){
		cout << "(" << it.first << "," << it.second << ") ";
	}
	cout << endl;
}

int main () {
	// Declaración de variables iniciales
	int V;
	cin >> V;
	// Creación del grafo a analizar
	Graph g(V);
	// Cargamos los datos de los costos al grafo
	g.load();
	// g.print();
	// g.primMST();
	// Aplicamos el algoritmo de Kruskal
	g.kruskalMST();
	// Desplegamos el resultado
	printf("%.2f", g.costMSTKruskal);
	cout << endl;
	// g.printEdgesK();
	return 0;
}

/*
3
1.0 1.0
2.0 2.0
2.0 4.0
*/