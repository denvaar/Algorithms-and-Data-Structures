#include "binaryHeap.h"

#include <iomanip>
#include <iostream>
#include <string>

template<class T>
BinaryHeap<T>::BinaryHeap(int size) {
    heapArray = new T[size];
    heapSize = 0;
    arraySize = size;

}

template<class T>
void BinaryHeap<T>::display() {
   
    print(1);
    /*for (int i = 1; i < heapSize+1; i++) {
        std::cout << heapArray[i] << " ";
    }
    std::cout << "\n";
    */
}


template<class T>
void BinaryHeap<T>::print(int index, int indent) {
    if (index < heapSize) {
        if (heapArray[index*2]) print(index*2, indent+4);
        if (heapArray[(index*2)+1]) print((index*2)+1, indent+4);
        if (indent) std::cout << std::setw(indent) << ' ';
        std::cout << heapArray[index] << std::endl;
    }
}

template<class T>
void BinaryHeap<T>::buildHeap() {
    /*
    for (int i = size/2; i > 0; i--)
        trickleDown(i);
    */
}

template<class T>
void BinaryHeap<T>::bubbleUp(int index) {
    // If the heap is not empty...
    if (index != 0) {
        // The parent is always the index
        // of the child divided by two.
        int parentIndex = index/2;
        // If the parent node is greater than
        // the child, then do a swap and recurse.
        if (heapArray[parentIndex] > heapArray[index]) {
            T temp = heapArray[parentIndex];
            heapArray[parentIndex] = heapArray[index];
            heapArray[index] = temp;
            // Recurse with parent's index.
            bubbleUp(parentIndex);
        }
    }
}

template<class T>
void BinaryHeap<T>::insert(const T &item) {
    heapArray[++heapSize] = item;
    bubbleUp(heapSize);
}

template<class T>
bool BinaryHeap<T>::isEmpty() const {

//    if (heapArray.size() == 0)
//        return true;
    return false;

}

template<class T>
T BinaryHeap<T>::deleteMinimum() {
  /*  
    if (isEmpty()) throw std::string("Empty Heap");
    T minItem = heapArray.front();
    heapArray[0] = heapArray[size-1];
    size--;
    if (size > 0)
        trickleDown(0);
    return minItem;*/
    T minItem;
    return minItem;
}

template<class T>
void BinaryHeap<T>::trickleDown(int hole) {
/*    
    int child;
    T temp = heapArray[hole];

    for (; hole * 2 <= size; hole = child) {
        child = hole * 2;
        if (child != size && heapArray[child+1] < heapArray[child])
            child++;
        else if (heapArray[child] < temp)
            heapArray[hole] = heapArray[child];
        else break;
    }

    heapArray[hole] = temp;
*/
}
