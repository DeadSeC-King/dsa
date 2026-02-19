int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = 0;
    
    int max_sum = nums[0], cur_max = 0;
    int min_sum = nums[0], cur_min = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        
        cur_max = (cur_max > 0) ? cur_max + x : x;
        max_sum = (cur_max > max_sum) ? cur_max : max_sum;
        
        cur_min = (cur_min < 0) ? cur_min + x : x;
        min_sum = (cur_min < min_sum) ? cur_min : min_sum;
        
        total += x;
    }
    
    // all numbers negative
    if (max_sum < 0)
        return max_sum;
    
    int circular = total - min_sum;
    return (max_sum > circular) ? max_sum : circular;
}
