
#include <iostream>
#include <vector>
#include "binaryHeap.h"
#include "binaryHeap.cpp"

int main(int argc, char *argv[]) {
    
    std::vector<int> v { 10, 22, 32, 11, 23, 23, 100, 1, 0 };
    
    BinaryHeap<double> *binaryHeap = new BinaryHeap<double>(15);
    binaryHeap->insert(10);
    binaryHeap->insert(1);
    binaryHeap->insert(3);
    binaryHeap->insert(1);
    binaryHeap->insert(2);
    binaryHeap->insert(3);
    binaryHeap->insert(33);
    binaryHeap->insert(0);
    binaryHeap->display();

    return 0;
}
