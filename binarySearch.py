
# Binary Search : Divide and conquer algorithm 
# to efficiently search sorted lists for given index.


def binarySearch(a, x):
    low = 0
    high = len(a) - 1

    while (low <= high):
        mid = (low + high) / 2
        if a[mid] < x:
            low = mid + 1
        elif a[mid] > x:
            high = mid - 1
        else:
            return mid # Found.
    return -1 # Not found.

def binarySearch2(a, x, low, high):
    if low > high:
        return -1 # Not found.
    
    mid = (low + high) / 2

    if a[mid] < x:
        return binarySearch2(a, x, mid + 1, high)
    elif a[mid] > x:
        return binarySearch2(a, x, low, mid - 1)
    else:
        return mid # Found.


l = [-10, -2, -1, 0, 5, 6, 8, 10, 14]
print "Number found at", binarySearch(l, 10)
print "Number found at", binarySearch2(l, 10, 0, len(l) - 1)

