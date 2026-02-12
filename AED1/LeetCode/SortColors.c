/*
A solution to the LeetCode problem "Sort Colors".
Description:

"Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Implemented using a one-pass algorithm."

*/

void swap( int* a, int* b ) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int start = 0, mid = 0, end = numsSize - 1;

    while ( mid <= end ) {
        if ( nums[mid] == 0 ) {
            swap( &nums[start], &nums[mid] );
            start++;
            mid++;
        } else if ( nums[mid] == 1 ) {
            mid++;
        } else {
            swap( &nums[mid], &nums[end] );
            end--;
        }
    }
}
