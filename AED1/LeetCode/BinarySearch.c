/*
A solution to the LeetCode Problem "Search Insert Position", which, performs a search on a sorted array for a given target.

*/

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize, mid;

    while    ( left < right )    {
        mid = ( left + right ) / 2;
        if    ( target <= nums[ mid ] )    {
            right = mid;
        }    else    {
            left = mid + 1;
        }

    }

    return left;
}
