/*A solution to the LeetCode problem "Two Sum", which, given an array of integers and a integer Target, return indices of the two numbers such that they add up to Target
(Disclaimer: this solution has an time complexity of O(n²)*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;
    for(int i = 0; i < numsSize; i++){
        for(int j = i+1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                *returnSize = 2;
                int *returnArray = (int*)malloc(sizeof(int) * *(returnSize));
                returnArray[0] = i;
                returnArray[1] = j;
                return returnArray;
            }
        }
    }
    	return 0;

}
