#include <iostream>
using namespace std;

int calcular(int y, int x)
{
	int suma;
	cout<<y<<" - Valor recibido 1\n"<<x<<" - Valor recibido 2\n";
	suma = y + x;
	return suma;
}

int division(int y, int x){
	int divis;
	divis = y/x;
	return divis;
}

int main()
{

int a,b,recibido,retdiv;
a = 20;
b = 10;
recibido = calcular(a,b);
retdiv = division(a,b);
cout<<recibido<<" - Valor Recibido en Calcular\n";
cout<<retdiv<<" - Valor de la Division";
}
