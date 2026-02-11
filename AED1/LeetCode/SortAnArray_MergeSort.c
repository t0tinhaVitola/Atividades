/*
A solution to the LeetCode problem "Sort an Array", which, given an array of integers, sort the array in ascending order and returns it.
I've tried to implement this solution using Merge Sort.
*/

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge( int* nums, int start, int middle, int end, int* aux ) {
    for ( int i = start; i <= end; i++)
        aux[i] = nums[i];
    
    int i = start, j = middle + 1, k = start;

    while ( i <= middle && j <= end ) {
        if ( aux[i] <= aux[j] ) {
            nums[k] = aux[i];
            i++;
        } else {
            nums[k] = aux[j];
            j++;
        }
        k++;
    }

    while ( i <= middle )
        nums[k++] = aux[i++];
    while ( j <= end )
        nums[k++] = aux[j++];
    return;
}

void mergeSort( int* nums, int start, int end, int* aux ) {
    if ( start >= end ) {
        return;
    }

    int middleIndex = start + (end - start) / 2;

    mergeSort( nums, start, middleIndex, aux );
    mergeSort( nums, middleIndex + 1, end, aux );

    merge( nums, start, middleIndex, end, aux );
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    if ( nums == NULL ) {
        return nums;
    }

    int* aux = malloc( numsSize * sizeof(int) );
    mergeSort(nums, 0, numsSize - 1, aux);

    free(aux);
    return nums;
}
