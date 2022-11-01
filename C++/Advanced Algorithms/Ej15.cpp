/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 10/Octubre/2022
Ejem 15. Algoritmo de Prim, Algoritmo de Kruskal*/

// Minumum Spanning Treen (Prim, Kruskal)
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>

using namespace std;

typedef pair<int,int> iPair;

struct Graph {
	// V = Cantidad de nodos (Vertex)
	// E = Cantidaf de arcos (Edges)
	int V, E, costMSTPrim, costMSTKruskal;
	vector<pair<int, pair<int,int>>> edges; 	// Utilizar en Kruskal
	vector<vector<pair<int, int>>> adjList; 	// Se utilza en Prim
	vector<pair<int,int>> selectedEdgesK;		// Los arcos sel Kruskal
	vector<pair<int,int>> selectedEdgesP;		// Los arcos sel Prim;
	Graph(int V, int E){
		this->V = V;
		this->E = E;
		adjList.resize(V);
		costMSTKruskal = costMSTPrim = 0;
	}
	// u = salida del arco
	// v = llegada del arco
	// w = costo del arco
	void addEdge(int u, int v, int w){
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

void Graph::load () {
	int a, b, c;
	for (int i=0; i<E; i++){
		cin >> a >> b >> c;
		addEdge(a, b, c);
		addEdge(b, a, c);
	}
}

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

void Graph::printEdgesK () {
	cout << "Selected Edges Kruskal: ";
	for (auto it:selectedEdgesK){
		cout << "(" << it.first << "," << it.second << ") ";
	}
	cout << endl;
}

int main () {
	int V, E;
	cin >> V >> E;
	Graph g(V, E);
	g.load();
	g.print();
	g.primMST();
	cout << "El costo total del MST por Prim es: " << g.costMSTPrim << endl;
	g.printEdgesP();
	g.kruskalMST();
	cout << "El costo total del MST por Kruskal es: " << g.costMSTKruskal << endl;
	g.printEdgesK();
	return 0;
}

/*
Unidrected Graph
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/