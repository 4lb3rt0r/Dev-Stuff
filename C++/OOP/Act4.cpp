#include <iostream>
using namespace std;

int main(){
	
	string cars[4]={"Volvo","BMW","Ford","Mazda"};
	//                 0      1      2      3
	cout<<cars[0]<<" Columna = 0\n";
	cout<<cars[1]<<" Columna = 1\n";
	cout<<cars[3]<<" Columna = 3\n";
	
	cars[1] = "Mercedes";
	cout<<cars[1]<<" es el nuevo valor en columna 1";
	
	
	
}
