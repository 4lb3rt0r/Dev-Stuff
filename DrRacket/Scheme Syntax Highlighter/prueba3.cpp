#include < iostream >
using namespace std ;

int main () {
    double v, c, p, t ;
    float ejemplo = 7.7 ;
    int i ;

    cin >> v ;
    cin >> c ;
    cin >> p ;

    int counter = 0 ;

    if ( ( v < 0 ) || ( c < 1 || c > 99999 ) || ( p < 2 || p > 10 ) )
    {
    cout << "Error" << endl ;
    }
    else
    {
        while ( counter < c )
    {
        t = ( ( ( 9 * v ) / 5 ) ) + 32 ;
        cout << v << " " << t << endl ;
        v = v + p ;
        counter = counter + 1 ;
    }

    }

    for ( i = 0 ; i < 2 ; i ++ ) {
        cout << i ;
    }
}
