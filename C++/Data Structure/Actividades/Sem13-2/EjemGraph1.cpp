#include <iostream>
#include <conio.h>

using namespace std;

#include "GraphM.h"

int main () {

    //GraphM<int> g;
    GraphM<char> g;

    char vertices[10];
    vertices[0] = 'A';
    vertices[1] = 'B';
    vertices[2] = 'C';
    vertices[3] = 'D';
    vertices[4] = 'E';
    vertices[5] = 'F';
    vertices[6] = 'G';
    vertices[7] = 'H';

    // vertices[0] = 0;
    // vertices[1] = 1;
    // vertices[2] = 2;
    // vertices[3] = 3;
    // vertices[4] = 4;
    // vertices[5] = 5;
    // vertices[6] = 6;
    // vertices[7] = 7;

    g.insertVertex(vertices,8);

    g.insert('A','E');
    g.insert('B','D');
    g.insert('B','D');
    g.insert('B','G');
    g.insert('C','E');
    g.insert('D','H');
    g.insert('F','D');
    g.insert('G','E');

    g.print();
    
    cout<<endl;

    // g.insert(0,4);
    // g.insert(1,3);
    // g.insert(1,3);
    // g.insert(1,6);
    // g.insert(2,4);
    // g.insert(3,7);
    // g.insert(5,3);
    // g.insert(6,4);

    g.remove('C','E');

    g.print();

    getch();
    return 0;
}