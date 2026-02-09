/*
A solution to the LeetCode problem "Sort an Array", which, given an array of integers numbers, sort the array in ascending order and returns it.
Implemented using QuickSort.

*/

void swap( int* num1, int* num2 ) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void quickSort ( int* nums , int start, int end ) {
    if ( end <= start )
        return;
    
    int pivot = ( rand() % ( end - start) ) + start;
    int pivotValue = nums[pivot];
    int i = start, j = end;
    
    while( i <= j ) {
        while ( nums[i] < pivotValue )
            i++;
        while ( nums[j] > pivotValue )
            j--;

        if ( i <= j ) {
            swap( &nums[i], &nums[j] );
            i++;
            j--;
        }
    }

    quickSort( nums, start, j);
    quickSort( nums, i, end);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if ( numsSize <= 1 )
        return nums;
    
    quickSort( nums, 0, numsSize - 1);

    return nums;
}
