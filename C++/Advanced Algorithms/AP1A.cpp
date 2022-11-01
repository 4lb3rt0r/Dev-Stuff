/*
  Matricula: A00831719
  Nombre: Alberto Horacio Orozco Ramos
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Complejidad: O(n*m) o O(n^2) o bien O(d.size()*d.size())
bool iguales(vector<int> &d, int k){
  // Aquí va tu código.
	bool res = false;

	// int i = 0, j = i + 1, n = d.size();

	// while (i < n) {
	// 	if (d[i] == d[j]) {
	// 		if (abs(i - j) <= k) {
	// 			res = true;
	// 			i = n;
	// 		}
	// 		else {
	// 			i++;
	// 			j = i + 1;
	// 		}
	// 	}
	// 	j++;
	// }

	for (int i = 0; i < d.size(); i++) {
		for (int j = i + 1; j < d.size(); j++) {
			if (d[i] == d[j] && abs(i - j) <= k) {
				res = true;
			}
		}
	}
	
	return res;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> datos(n);
	for (int i=0; i<n; i++){
		cin>>datos[i];
	}
  cout << (iguales(datos, k)? "YES" : "NO") <<endl;
}

/*
Ejemplo 1
4 3
1 2 3 1

Ejemplo 2
4 1
1 0 1 1

Ejmplo 3
6 2
1 2 3 1 2 3
 
*/