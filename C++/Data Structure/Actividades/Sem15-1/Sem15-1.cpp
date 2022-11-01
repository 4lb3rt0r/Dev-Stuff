#include <iostream>
#include <conio.h>
#include <time.h>
#include <string>
#include <vector>
using namespace std;

int selDigitos(int n) {
    //n = 123456789
    int d7, d8, d7d8;
    d7 = n / 10 % 10;
    d8 = n / 1 % 10;
    d7d8 = d7 * 10 + d8;
    return d7d8;
}

int residual(int n) {
    return n % 101; //37 es el primer número primo después del 34
}

int cuadratica (long long int n) {
    long long int c = n * n;
    int d10, d11, d10d11;
    //12345678, d2 = 2, si elevas al cuadrado se vuelbven 16 digitos
    d10 = c / 100000000 % 10;
    d11 = c / 10000000 % 10;
    d10d11 = d10 * 10 + d11;
    return d10d11;
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
    return d8 + d4 + d5 + d5 + d6 + d7 + d8;
}

int main() {
    
    //int n = 12345678;
    vector<string> matriculas = {"A01197647","A00832188","A01284477","A01570751","A01720346","A00830052","A00831138","A01721540","A01197705","A01197782","A01283809","A00827269","A00830576","A01284179","A01383532","A00827461","A01731549","A01570748","A00829748","A00831719","A01351746","A01284469","A01025335","A01721299","A01197898","A01284329","A01721245","A01721208","A01197723","A01245418","A00829771","A01611427","A01384195","A01383057","A01655080"};
    vector<string> hashDigitos(100,"-");
    vector<string> hashResidual(101,"-");
    vector<string> hashCuadratica(100,"-");
    vector<string> hashFolding(64,"-");
    //srand(time(NULL));

    for (auto mat : matriculas) {
        //int n = rand() % 100000000 + 1;
        int a = stoi(mat.substr(1,8));
        // cout<<"Número:"<<n<<endl;
        // Selección de Dígitos
        hashDigitos[selDigitos(a)] = mat;
        // cout<<"Selección de Dígitos: "<<selDigitos(n)<<endl;
        // Residual
        hashResidual[residual(a)] = mat;
        // cout<<"Residual: "<<residual(n)<<endl;
        // Cuadrática
        hashCuadratica[cuadratica(a)] = mat;
        // cout<<"Cuadrática: "<<cuadratica(n)<<endl;
        // Folding
        hashFolding[folding(a)] = mat;
        // cout<<"Folding: "<<folding(n)<<endl;
        // cout<<"---------------------------"<<endl;
    }
    
    int digitosCount = 0;
    int residualCount = 0;
    int cuadraticaCount = 0;
    int foldingCount = 0;
    
    for (auto mat : hashDigitos) {
        if (mat != "-") {
            digitosCount++;
        }
    }

    for (auto mat : hashResidual) {
        if (mat != "-") {
            residualCount++;
        }
    }

    for (auto mat : hashCuadratica) {
        if (mat != "-") {
            cuadraticaCount++;
        }
    }

    for (auto mat : hashFolding) {
        if (mat != "-") {
            foldingCount++;
        }
    }

    //Cantidad de matrículas por hash almacenadas
    cout<<"Digitos: "<<digitosCount<<endl;
    cout<<"Residual: "<<residualCount<<endl;
    cout<<"Cuadrática: "<<cuadraticaCount<<endl;
    cout<<"Folding: "<<foldingCount<<endl;

    getch();
    return 0;
}

