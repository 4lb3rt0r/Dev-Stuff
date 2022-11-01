#include <iostream>
#include <vector>

using namespace std;

int main () {

    //vector <int> lista (5,6); //5 espacios con el número 6 en cada uno de esos 5 espacios
    vector <int> lista = {1,2,3,4,5};

    lista.push_back(25); //append en c++
    lista.push_back(115);
    lista.push_back(48);

    cout<<lista[6]<<endl;
    lista[6] = 777;
    cout<<lista[6]<<endl;
    cout<<lista.size()<<endl;



    return 0;
}