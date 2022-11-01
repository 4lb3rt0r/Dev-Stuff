#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool status (string x) { 
    if (x == "xd") {
        return true;
    } 
    else {
        return false;
    }
}

int main () {
    int a;
    float b;
    string c = "xd";
    vector<string> d = {"hola", "como", "estas"};
    string e = "xd";

    cout<<"Escribe el valor de a: ";
    cin>>a;
    cout<<"\nEscribe el valor de b: ";
    cin>>b;
    
    if (a >= b) {
        cout<<"a es mayor que b"<<endl;
    } 
    else if (a <= b) {
        for (int i = 0; i < a; i++) {
            cout<<d[i]<<endl;
        }
    }

    cout<<"Multiplicación de a * b"<<endl;

    while (c == e) {
        cout<<"Cómo estás?"<<endl;
        cin>>c;
        if (status(c)) {
            cout<<"Ya no escribas xd"<<endl;
        } else {
            cout <<"Programa finalizado :D" << endl;
        }
    }


}