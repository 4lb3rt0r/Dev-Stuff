#include < iostream >
#include < vector >

using namespace std ;

void funcion ( int i ) {
    cout << i << endl ;
}

int main ( ) {
    string variableString = "jfkhskj1" ;
    float variableFloat = 2.2 ;
    double variableDouble = 4.4 ;

    int n = 5 ;
    for ( int i = 0; i < n ; i ++ ) {
        cout << "hola" << endl ;
        funcion ( i ) ;
    }

    int res1 = 1 + 1 ;
    int res2 = 2 - 2 ;
    int res3 = 3 * 3 ;
    int res4 = 4 / 4 ;

    int x = 1 ;
    while ( 5 > x ) {
        x = x + 1 ;
    }
}