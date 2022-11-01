/* Análisis y Diseño de Algoritmos Avanzados
Profesor: Luis Humberto González Guerra
Nombre: Alberto Horacio Orozco Ramos
Matrícula: A00831719
Fecha: 21/Octubre/2022
Ejem 19. Algoritmo de Welsh Powell para coloreo de grafos*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define MAX 100

struct color{
	int conex; 	// Cant de conexiones
	int vtx;	// El número de vertice
};
// Ordenamiento sea descentente en cant de conexiones 
// y en empate el menor número de vertice
bool my_cmp(const color &a, const color &b){
	if (a.conex == b.conex){
		return a.vtx <= b.vtx;
	}
	return a.conex > b.conex;
}

bool canColor(bool matAdj[MAX][MAX], unordered_set<int> &conj, int j){
	for (auto it:conj){
		if (matAdj[it][j]){
			return false;
		}
	}
	return true;
}

// Complejidad: O(n^2)
vector<int> colorGraph(bool matAdj[MAX][MAX], vector<color> &vtxColor){
	int colNum = 0;
	int n = vtxColor.size();
	vector<int> colored(n, 0);
	// Aquí va tu código

	for (int a = 0; a < n; a++) {
		int i = vtxColor[a].vtx;
		if (!colored[i]) {
			colored[i] = ++colNum;
			unordered_set<int> conj;
			conj.insert(i);
			for (int b = a + 1; b < n; b++) {
				int j = vtxColor[b].vtx;
				/*Verificar:
				j NO haya sido coloreado
				j No tenga conexión (adyacencia) con alguien que haya sido coloreado con conNum*/
				if (!colored[j] && !matAdj[i][j] && canColor(matAdj, conj, j)) {
					colored[j] = colNum;
					conj.insert(j);
				}
			}
		}
	}

	return colored;
}

int main(){
	// n = número de vertices
	// m = número de arcos
	int n, m, a, b;
	cin >> n >> m;
	bool matAdj[MAX][MAX];
	for (int i=0; i<MAX; i++){
		for (int j=0; j<MAX; j++){
			matAdj[i][j] = false;
		}
	}
	// vector de grados de los vertices
	vector<color> vtxColor;
	color c;
	for (int i=0; i<n; i++){
		c.conex = 0;
		c.vtx = i;
		vtxColor.push_back(c);
	}
	for (int i=0; i<m; i++){
		cin >> a >> b;
		matAdj[a-1][b-1] = matAdj[b-1][a-1] = true;
		vtxColor[a-1].conex++;
		vtxColor[b-1].conex++;
	}
	sort(vtxColor.begin(), vtxColor.end(), my_cmp);
	for (int i=0; i<n; i++){
		cout << vtxColor[i].vtx << " " << vtxColor[i].conex << endl;
	}
	vector<int> colored = colorGraph(matAdj, vtxColor);
	for (int i=0; i<n; i++){
		cout << (i+1) << " color " << colored[i] << endl;
	}
}



/*
7 11
1 2
1 3
1 4
2 3  
2 5
3 4
3 5
4 5
4 6
5 7
6 7
*/







