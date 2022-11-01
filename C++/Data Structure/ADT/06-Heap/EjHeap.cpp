#include <iostream>
#include <vector>

using namespace std;
#include "Heap.h"

int main () {

    //vector<int> list = {25,19,64,59,78,88,31,49,90,7};
    vector<int> list = {5,14,53,47,8,56,39,22,18,1};
    Heap<int> heap (list);
    heap.print();
    
    cout<<heap.pop()<<" "<<endl;
    heap.print();
    // cout<<heap.top()<<" "<<endl;
    // heap.print();

    // heap.heapSort("desc");
    // heap.heapSort("asc");
    heap.push(60);
    // heap.print();
    cout<<heap.pop()<<endl;
    heap.print();
    cout<<heap.top()<<endl;
    heap.print();

    if (heap.isEmpty() == 0) {
        cout<<"La lista contiene datos :D"<<endl;
    }
    else {
        cout<<"La lista se encuentra vacía :o"<<endl;
    }

    return 0;
}
