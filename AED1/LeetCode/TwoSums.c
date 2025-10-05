/**/

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
