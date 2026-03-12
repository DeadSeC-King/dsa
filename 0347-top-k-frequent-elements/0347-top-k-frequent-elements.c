#include <stdlib.h>

struct pair{
    int num;
    int freq;
};

int cmp(const void *a, const void *b){
    struct pair *p1 = (struct pair*)a;
    struct pair *p2 = (struct pair*)b;
    return p2->freq - p1->freq;   // descending order
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
    struct pair arr[numsSize];
    int size = 0;

    for(int i = 0; i < numsSize; i++){
        int found = 0;

        for(int j = 0; j < size; j++){
            if(arr[j].num == nums[i]){
                arr[j].freq++;
                found = 1;
                break;
            }
        }

        if(!found){
            arr[size].num = nums[i];
            arr[size].freq = 1;
            size++;
        }
    }

    qsort(arr, size, sizeof(struct pair), cmp);

    int *result = (int*)malloc(sizeof(int) * k);

    for(int i = 0; i < k; i++){
        result[i] = arr[i].num;
    }

    *returnSize = k;
    return result;
}