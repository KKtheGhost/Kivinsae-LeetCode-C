/*
 * @lc app=leetcode id=376 lang=c
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start


int wiggleMaxLength(int* nums, int numsSize){
    int* dpUp = malloc(sizeof(int)*numsSize);
    int* dpDown = malloc(sizeof(int)*numsSize);
    dpUp[0] = dpDown[0] = 1;
    if (numsSize == 1) {return 1;}
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i-1]) {
            dpUp[i] = dpDown[i-1]+1;
            dpDown[i] = dpDown[i-1];
        }
        else if (nums[i] < nums[i-1]) {
            dpDown[i] = dpUp[i-1]+1;
            dpUp[i] = dpUp[i-1];
        }
        else {
            dpDown[i] = dpDown[i-1]; dpUp[i] = dpUp[i-1];
        }
    }
    return (dpUp[numsSize - 1] > dpDown[numsSize - 1])? dpUp[numsSize - 1] : dpDown[numsSize - 1];
}
// @lc code=end
// @lc MEDIUM