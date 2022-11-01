//
// Matricula: A00831719
// Nombre: Alberto Horacio Orozco Ramos
//


#include <iostream>
#include <vector>
#include <climits>

#define MAX 10

using namespace std;

struct edge {
	int from, to, time;
	edge(int a, int b, int t){
		from = a;
		to = b;
		time = t;
	}
};

struct comm {
	char query;
	int from, to;
	comm(char q, int a, int b){
		query = q;
		from = a; 
		to = b;
	}
};

void leeArcos (int mat[MAX][MAX], int matAux[MAX][MAX], int m, vector<edge> &edges) {
    // int a, b, c; // de Nodo a <-> b con costo
    // Incialización de matriz
    for (int i = 0; i < MAX; i++) {
        mat[i][i] = 0;
		matAux[i][i] = 0;
        for (int j = i + 1; j < MAX; j++){
            mat[i][j] = mat[j][i] = INT_MAX; // INT_MAX = infinito
			matAux[i][j] = matAux[j][i] = INT_MAX;
        }
    }
    for (int i = 0; i < m; i++) {
        //  Recordar que la base es 0 para los arreglos
        // base1 para la entrada del programa
        // cin >> a >> b >> c;
        mat[edges[i].from - 1][edges[i].to - 1] = mat[edges[i].to - 1][edges[i].from - 1] = edges[i].time;
		matAux[edges[i].from - 1][edges[i].to - 1] = matAux[edges[i].to - 1][edges[i].from - 1] = edges[i].time;
    }
}

// Complejidad: O(n^3)
void floyd(int mat[MAX][MAX], int matAux[MAX][MAX], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                /* Se comprueba que exista una conexión entre nodos corroborando que tanto
                 mat[i][k] como mat[k][j] no contengan un valor infinito. Además, si la suma de los
                 elementos contenidos en mat[i][k] y mat[k][j] es menor al valor contenido en mat[i][j],
                 actualizamos el valor de mat[i][j] al de esta sumatoria. */
                if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX && mat[i][k] + mat[k][j] < mat[i][j]) {
                    mat[i][j] = mat[i][k] + mat[k][j];
					matAux[i][j] = matAux[i][k] + matAux[k][j];
                    // p[i][j] = k;
                }
            }
        }
    }
}

// Complejidad: O(k)
void ejecuta_comandos(int n, vector<edge> &edges, vector<comm> &commands, vector<int> &salida){

	int mat[MAX][MAX], matAux[MAX][MAX];;

	leeArcos(mat, matAux, edges.size(), edges);
	floyd(mat, matAux, n);

	for (int i = 0; i < commands.size(); i++) {
		if (commands[i].query == 'c') {
			if (mat[commands[i].from - 1][commands[i].to - 1] == INT_MAX) {
				cout << "no path" << endl;
			}
			else {
				cout << mat[commands[i].from - 1][commands[i].to - 1] << endl;
			}
		}
		else if (commands[i].query == 'a') {
			mat[commands[i].from - 1][commands[i].to - 1] = INT_MAX;
		}
		else if (commands[i].query == 'l') {
			mat[commands[i].from - 1][commands[i].to - 1] = matAux[commands[i].from - 1][commands[i].to - 1];
		}
	}
}

int main(){
	int n, m, k, a, b, t;
	char q;
	vector<edge> edges;
	vector<comm> commands;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> a >> b >> t;
		edge nuevo(a, b, t);
		edges.push_back(nuevo);
	}
	cin >> k;
	for (int i = 1; i <= k; i++){
		cin >> q >> a >> b;
		comm nuevo(q, a, b);
		commands.push_back(nuevo);
	}
	vector<int> salida;
	ejecuta_comandos(n, edges, commands, salida);
	for (int i=0;i<salida.size(); i++){
		cout << salida[i]<< endl;
	}
}

/*

Ejemplo de Entrada:

5 8
1 2 4
1 3 2
1 4 4
2 3 1
2 5 3
3 4 7
3 5 1
4 5 4
7
c 1 5
c 4 2
a 3 5
c 5 3
c 3 5
l 5 3
c 5 3
 

Ejemplo de Salida:

3
6
4
4
1

*/
