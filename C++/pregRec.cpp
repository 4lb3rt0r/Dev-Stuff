// Matricula: A00831719
// Nombre: Alberto Horacio Orozco Ramos
#include <iostream>

using namespace std;

// Complejidad: 
int sumaRecursivaCuadrada(int n){
// aquí va tu código
if (n == 1) {
	return 1;
}
else {
	return (n*n) + sumaRecursivaCuadrada(n-1);
}
}

int main(){
	int n;
	cin >> n;
	cout << sumaRecursivaCuadrada(n) << endl;
}