from collections import Counter
import timeit

def q1():
    def quicksort(l):
        if not l:
            return l
        else:
            pivot = l[0]
            lesser = quicksort([i for i in l[1:] if i < pivot])
            greater = quicksort([i for i in l[1:] if i >= pivot])
            return lesser + [pivot] + greater
    
    quicksort(myList)

def q2():
    # This method is my attempt at multisets
    # in order to allow for duplicate values
    # to be preserved, but still use fast set
    # operations. It ended up being a lot slower
    # probably because of the overhead of creating
    # Counter objects.
    #c = Counter
    def quicksort(l):
        if not l:
            return l
        else:
            pivot = l[0]
            a = [i for i in l[1:] if i < pivot]
            lesser = quicksort(a)
            greater = quicksort(list(\
                (Counter(l[1:]) - Counter(a)).elements()))
            return lesser + [pivot] + greater
    quicksort(myList)

def q3():
    # This method of quicksort is very fast,
    # but it only works correctly on lists
    # that do not have duplicate values.
    def quicksort(l):
        if not l:
            return l
        else:
            pivot = l[0]
            a = [i for i in l[1:] if i < pivot]
            lesser = quicksort(a)
            greater = quicksort(list(set(l[1:]).symmetric_difference(set(a))))
            return lesser + [pivot] + greater
    quicksort(myList)

def q4():
    # This quicksort rivals and sometimes beats
    # the classic version, but it is usally a bit
    # slower. It is also less-elegant in my opinion.
    def quicksort(l):
        quickSortHelper(l, 0, len(l)-1)

    def quickSortHelper(l, first, last):
        if first < last:
            splitpoint = partition(l, first, last)
            quickSortHelper(l, first, splitpoint - 1)
            quickSortHelper(l, splitpoint + 1, last)

    def partition(l, first, last):
        pivot = l[first]
        leftmark = first + 1
        rightmark = last
        done = False
        while not done:
            while leftmark <= rightmark and l[leftmark] <= pivot:
                leftmark = leftmark + 1
            while l[rightmark] >= pivot and rightmark >= leftmark:
                rightmark = rightmark -1
            if rightmark < leftmark:
                done = True
            else:
                temp = l[leftmark]
                l[leftmark] = l[rightmark]
                l[rightmark] = temp

        temp = l[first]
        l[first] = l[rightmark]
        l[rightmark] = temp
        return rightmark 

    quicksort(myList)








myList = [4,63,456,25,345,23,45,3657,567,89,89,4,3,2,3,6,7,9,9,7,56,3456,45,645,645,645,63,445,234,4,566,7,79,97,465,34,5234,2,3,34,34,34,34,34,23,23,23,34,23,34,2345,34,234,235,2345,2345,2345,345,63456,234,51,2341,235,2567,44,6,64,64,646,47,57,68,68,32345,5243,23,3456,23,45,23,45,32,24,56345634563465,3456345634563,23452354,111,111,111,345234,23452345234,678,5685678,5678,5678,5678,56785678,679,679,6758,4567,4536,23,23,45,23,6,32,56,32,23,65,7,56,68,345,63,45634,56,3245,2345,34,234,52345,2345,56,745,74567,2,352,3451,34,3456,567,86896,789,7980,567,6,6,6,6,6,456,32,31,3,24234,52,352,345,56,75,75,68,89,890,89,6,789,6789,6879,6789,54,63,456,25,345,23,45,3657,567,89,89,4,3,2,3,6,7,9,9,7,56,3456,45,645,645,645,63,445,234,4,566,7,79,97,465,34,5234,2,3,34,34,34,34,34,23,23,23,34,23,34,2345,34,234,235,2345,2345,2345,345,63456,234,51,2341,235,2567,44,6,64,64,646,47,57,68,68,32345,5243,23,3456,23,45,23,45,32,24,56345634563465,3456345634563,23452354,111,111,111,345234,23452345234,678,5685678,5678,5678,5678,56785678,679,679,6758,4567,4536,23,23,45,23,6,32,56,32,23,65,7,56,68,345,63,45634,56,3245,2345,34,234,52345,2345,56,745,74567,2,352,3451,34,3456,567,86896,789,7980,567,6,6,6,6,6,456,32,31,3,24234,52,352,345,56,75,75,68,89,890,89,6,789,6789,6879,6789,54,63,456,25,345,23,45,3657,567,89,89,4,3,2,3,6,7,9,9,7,56,3456,45,645,645,645,63,445,234,4,566,7,79,97,465,34,5234,2,3,34,34,34,34,34,23,23,23,34,23,34,2345,34,234,235,2345,2345,2345,345,63456,234,51,2341,235,2567,44,6,64,64,646,47,57,68,68,32345,5243,23,3456,23,45,23,45,32,24,56345634563465,3456345634563,23452354,111,111,111,345234,23452345234,678,5685678,5678,5678,5678,56785678,679,679,6758,4567,4536,23,23,45,23,6,32,56,32,23,65,7,56,68,345,63,45634,56,3245,2345,34,234,52345,2345,56,745,74567,2,352,3451,34,3456,567,86896,789,7980,567,6,6,6,6,6,456,32,31,3,24234,52,352,345,56,75,75,68,89,890,89,6,789,6789,6879,6789,54,63,456,25,345,23,45,3657,567,89,89,4,3,2,3,6,7,9,9,7,56,3456,45,645,645,645,63,445,234,4,566,7,79,97,465,34,5234,2,3,34,34,34,34,34,23,23,23,34,23,34,2345,34,234,235,2345,2345,2345,345,63456,234,51,2341,235,2567,44,6,64,64,646,47,57,68,68,32345,5243,23,3456,23,45,23,45,32,24,56345634563465,3456345634563,23452354,111,111,111,345234,23452345234,678,5685678,5678,5678,5678,56785678,679,679,6758,4567,4536,23,23,45,23,6,32,56,32,23,65,7,56,68,345,63,45634,56,3245,2345,34,234,52345,2345,56,745,74567,2,352,3451,34,3456,567,86896,789,7980,567,6,6,6,6,6,456,32,31,3,24234,52,352,345,56,75,75,68,89,890,89,6,789,6789,6879,6789,54,63,456,25,345,23,45,3657,567,89,89,4,3,2,3,6,7,9,9,7,56,3456,45,645,645,645,63,445,234,4,566,7,79,97,465,34,5234,2,3,34,34,34,34,34,23,23,23,34,23,34,2345,34,234,235,2345,2345,2345,345,63456,234,51,2341,235,2567,44,6,64,64,646,47,57,68,68,32345,5243,23,3456,23,45,23,45,32,24,56345634563465,3456345634563,23452354,111,111,111,345234,23452345234,678,5685678,5678,5678,5678,56785678,679,679,6758,4567,4536,23,23,45,23,6,32,56,32,23,65,7,56,68,345,63,45634,56,3245,2345,34,234,52345,2345,56,745,74567,2,352,3451,34,3456,567,86896,789,7980,567,6,6,6,6,6,456,32,31,3,24234,52,352,345,56,75,75,68,89,890,89,6,789,6789,6879,6789,54,63,456,25,345,23,45,3657,567,89,89,4,3,2,3,6,7,9,9,7,56,3456,45,645,645,645,63,445,234,4,566,7,79,97,465,34,5234,2,334,34,34,34,34,23,23,23,34,23,34,2345,34,234,235,2345,2345,2345,345,63456,234,51,2341,235,2567,44,6,64,64,646,47,57,68,68,32345,5243,23,3456,23,45,23,45,32,24,56345634563465,3456345634563,23452354,111,111,111,345234,23452345234,678,5685678,5678,5678,5678,56785678,679,679,6758,4567,4536,23,23,45,23,6,32,56,32,23,65,7,56,68,345,63,45634,56,3245,2345,34,234,52345,2345,56,745,74567,2,352,3451,34,3456,567,86896,789,7980,567,6,6,6,6,6,456,32,31,3,24234,52,352,345,56,75,75,68,89,890,89,6,789,6789,6879,6789,54,63,456,25,345,23,45,3657,567,89,89,4,3,2,3,6,7,9,9,7,56,3456,45,645,645,645,63,445,234,4,566,7,79,97,465,34,5234,2,3]

#print "Quicksort other:", timeit.timeit(q4, number=1000)
#print "Quicksort classic:", timeit.timeit(q1, number=1000)
#print "Quicksort set:", timeit.timeit(q3, number=1000)
print "Quicksort multiset:", timeit.timeit(q2, number=100)
