// Matricula: A00831719
// Nombre: Alberto Horacio Orozco Ramos
#include <iostream>

using namespace std;

// Complejidad: 
int cuantos(int inf, int sup){
// aquí va tu código
int count = 0;
	for (int i = inf; i <= sup; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			count += 1;
		}
	}
	return count;
}

int main(){
	int inf, sup;
	cin >> inf >> sup;
	cout << cuantos(inf, sup) << endl;
}