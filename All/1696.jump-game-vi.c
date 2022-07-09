/*
 * @lc app=leetcode id=1696 lang=c
 *
 * [1696] Jump Game VI
 */

// @lc code=start 
int maxResult (int* nums, int numsSize, int k) {
    int i = 1, head = 0, tail = 1;
    int dp[100001] = {0};
    while (i < numsSize) {
        if (i - dp[head] > k) {
            head++;
        }
        nums[i] += nums[dp[head]];
        while (tail > head && nums[i] >= nums[dp[tail-1]]) {
            tail--;
        }
        dp[tail++] = i;
        i++;
    }
    return nums[numsSize-1];
}
// @lc code=end
// @lc MEDIUM