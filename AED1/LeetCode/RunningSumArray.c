#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize) { 
    *returnSize = numsSize;
    for(int i = 1; i < numsSize; i++){
        *(nums + i) += *(nums + (i - 1));
    }
    return nums;
} 

int main(){ /*Caso queira executar o programa no terminal ou no Visual Studi*/
    int *nums = NULL;
    printf("Defina o tamanho do vetor: ");

    int numsSize;
    scanf("%d", &numsSize);

    nums = (int*)malloc(sizeof(int) * numsSize);

    for(int i = 0; i < numsSize; i++){
        printf("%d° número para o vetor:  ", i + 1);
        scanf("%d", (nums + i));
        printf("\n");
    }

    runningSum(nums, numsSize, &numsSize);
    for(int i = 0; i < numsSize; i++){
        printf("[%d] ", *(nums + i));
    }
    printf("\n");
    free(nums);
    return 0;
}
