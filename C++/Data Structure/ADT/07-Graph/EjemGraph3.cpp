#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#include "Edge.h"
#include "Graph.h"

int main () {

    vector<char> vertices = {'A','B','C','D','E','F','G','H','I','J'};
    Graph<char> graph(vertices);

    graph.insert(Edge<char>('A','B',0));
    graph.insert(Edge<char>('A','E',0));
    graph.insert(Edge<char>('A','H',0));
    graph.insert(Edge<char>('B','A',0));
    graph.insert(Edge<char>('B','C',0));
    graph.insert(Edge<char>('B','E',0));
    graph.insert(Edge<char>('C','B',0));
    graph.insert(Edge<char>('C','D',0));
    graph.insert(Edge<char>('C','E',0));
    graph.insert(Edge<char>('C','F',0));
    graph.insert(Edge<char>('D','C',0));
    graph.insert(Edge<char>('E','A',0));
    graph.insert(Edge<char>('E','B',0));
    graph.insert(Edge<char>('E','C',0));
    graph.insert(Edge<char>('E','G',0));
    graph.insert(Edge<char>('E','H',0));
    graph.insert(Edge<char>('F','C',0));
    graph.insert(Edge<char>('F','J',0));
    graph.insert(Edge<char>('G','E',0));
    graph.insert(Edge<char>('G','J',0));
    graph.insert(Edge<char>('H','A',0));
    graph.insert(Edge<char>('H','E',0));
    graph.insert(Edge<char>('H','I',0));
    graph.insert(Edge<char>('H','J',0));
    graph.insert(Edge<char>('I','H',0));
    graph.insert(Edge<char>('J','F',0));
    graph.insert(Edge<char>('J','G',0));
    graph.insert(Edge<char>('J','H',0));
 
    graph.print();
    graph.breadthFirstSearch('A');
    graph.depthFirstSearch('A');
    graph.depthFirstSearch('I');
 
    // vector <int> vertices = {0,1,2,3,4,5,6,7};

    // Graph<int> g(vertices);

    // g.insert(Edge<int>(0,3,8)); 
    // g.insert(Edge<int>(0,4,9)); 
    // g.insert(Edge<int>(1,3,1)); 
    // g.insert(Edge<int>(1,5,3)); 
    // g.insert(Edge<int>(1,6,5)); 
    // g.insert(Edge<int>(2,5,2)); 
    // g.insert(Edge<int>(3,0,8)); 
    // g.insert(Edge<int>(3,1,1)); 
    // g.insert(Edge<int>(3,5,3)); 
    // g.insert(Edge<int>(4,0,9)); 
    // g.insert(Edge<int>(5,1,3)); 
    // g.insert(Edge<int>(5,2,2)); 
    // g.insert(Edge<int>(5,3,3)); 
    // g.insert(Edge<int>(5,6,3)); 
    // g.insert(Edge<int>(6,1,5)); 
    // g.insert(Edge<int>(6,5,3)); 
    // g.insert(Edge<int>(6,7,6)); 
    // g.insert(Edge<int>(7,6,6));
    
    // g.print();

    getch();
    return 0;
}