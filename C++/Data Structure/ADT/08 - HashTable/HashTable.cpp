#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

int selDigitos(int n) {
    //n = 123456789
    int d2,d4,d6,d2d4d6;
    d2 = n / 1000000 % 10;
    d4 = n / 10000 % 10;
    d6 = n / 100 % 10;
    d2d4d6 = d2 * 100 + d4 * 10 + d6;
    cout<<d2<<" "<<d4<<" "<<d6<<endl;
    return d2d4d6;
}

int residual(int n) {
    return n % 1009; //1009 es el primer número primo después del 1000
}

int cuadratica (long long int n) {
    long long int c = n * n;
    int d7,d8,d9,d7d8d9;
    //12345678, d2 = 2, si elevas al cuadrado se vuelbven 16 digitos
    d7 = c / 10000000000 % 10;
    d8 = c / 1000000000 % 10;
    d9 = c / 100000000 % 10;
    d7d8d9 = d7 * 100 + d8 * 10 + d9;
    //cout<<d7<<" "<<d8<<" "<<d9<<endl;
    return d7d8d9;
}

int folding (int n) {
    int d1,d2,d3,d4,d5,d6,d7,d8;
    d1 = n / 10000000;
    d2 = n / 1000000 % 10;
    d3 = n / 100000 % 10;
    d4 = n / 10000 % 10;
    d5 = n / 1000 % 10;
    d6 = n / 100 % 10;
    d7 = n / 10 % 10;
    d8 = n / 1 % 10;
    return d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8;
}

int main() {
    
    //int n = 12345678;
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        int n = rand() % 100000000 + 1;
        cout<<"Número:"<<n<<endl;
        //Selección de Dígitos
        cout<<"Selección de Dígitos: "<<selDigitos(n)<<endl;
        //Residual
        cout<<"Residual: "<<residual(n)<<endl;
        //Cuadrática
        cout<<"Cuadrática: "<<cuadratica(n)<<endl;
        //Folding
        cout<<"Folding: "<<folding(n)<<endl;
        cout<<"---------------------------"<<endl;
    }
    
    getch();
    return 0;
}
