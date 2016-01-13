void quicksort(int array[], int left, int right) {
    
    int i = left;
    int j = right;
    int temp;
    int pivot = array[(left + right) / 2];

    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(array, left, j);
    if (i < right)
        quicksort(array, i, right);

}
