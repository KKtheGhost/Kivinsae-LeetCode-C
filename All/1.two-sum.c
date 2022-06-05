/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *Res = malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < numsSize; ++i) {
        for (int j = numsSize - 1; j > i; --j) {
            if (nums[i] + nums[j] == target) {
                Res[0] = i;
                Res[1] = j;
                goto end;
            }
        }
    }

    end:return Res;
}
// @lc code=end
// @lc EASY