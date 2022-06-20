/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (49.58%)
 * Likes:    21773
 * Dislikes: 1083
 * Total Accepted:    2.4M
 * Total Submissions: 4.9M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * A subarray is a contiguous part of an array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
int Max(int x, int y) {
    if (x > y) {return x;}
    return y;
}
int maxSubArray(int* nums, int numsSize){
    int res = -10000, dp = 0;
    if (numsSize == 1) {return nums[0];}

    for (int i = 0; i < numsSize; ++i) {
        dp = Max(nums[i], dp + nums[i]);
        res = Max(res, dp);
    } 
    return res;
}
// @lc code=end
// @lc EASY