#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

template<class T>
class BinaryHeap {

    public:
        //explicit BinaryHeap(int size = 100);
        explicit BinaryHeap(int size);

        bool isEmpty() const;
        const T& getMinimum() const;

        void insert(const T &item);
        T deleteMinimum();
        void makeEmpty();
        void display();

    private:
        int heapSize; // Number of elements in the heap.
        int arraySize; // Capacity of the array.
        T *heapArray;
        
        void print(int index, int indent = 0);
        void buildHeap();
        void trickleDown(int hole);
        void bubbleUp(int index);
};

#endif
