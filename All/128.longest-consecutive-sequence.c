/*
 * @lc app=leetcode id=128 lang=c
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int longestConsecutive(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    if (numsSize < 2) {return numsSize;}
    int max = 1, current = 1;
    for (int i = 0; i < numsSize; ++i) {
        if (i > 0 && nums[i] - nums[i-1] == 1) {
            current++;
            max = (current > max)? current : max;
        } 
        else if (i > 0 && nums[i] == nums[i-1]) {}
        else {
            current = 1;
        }
    }
    return max;
}
// @lc code=end
// @lc MEDIUM