#include <iostream>
#include <vector>

int ITERATIONS = 0;

// Iterative binary search.
int binarySearch(std::vector<int> a, int x) {
    
    int low = 0;
    int high = a.size() - 1; 
    int mid;
    
    while (low <= high) {
        ITERATIONS++;
        mid = (low + high) / 2;
        if (a[mid] < x) low = mid + 1;
        else if (a[mid] > x) high = mid - 1;
        else return mid; // Found.
    }
    return -1; // Not found.

}

// Recursive version of binary search.
int binarySearch(std::vector<int> a, int x, int low, int high) {
    ITERATIONS++; 
    
    if (low > high) return -1; // Not found.
    int mid = (low + high) / 2;

    if (a[mid] == x) return mid; // Found.
    else if (a[mid] < x) return binarySearch(a, x, mid + 1, high);
    else return binarySearch(a, x, low, mid - 1);
}

int main(int argc, char *argv[]) {

    std::vector<int> a {-4, -1, 0, 3, 5, 6, 7, 10, 13, 20 };
    std::cout << "Number at index " << binarySearch(a, 10) << std::endl;
    std::cout << "Iterations: " << ITERATIONS << std::endl;
    std::cout << "Number at index " << binarySearch(a, 10, 0, a.size() - 1) << std::endl;
    std::cout << "Iterations: " << ITERATIONS << std::endl;

    return 0;
}
