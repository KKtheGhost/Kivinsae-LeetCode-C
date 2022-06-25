/*
 * @lc app=leetcode id=665 lang=c
 *
 * [665] Non-decreasing Array
 *
 * https://leetcode.com/problems/non-decreasing-array/description/
 *
 * algorithms
 * Medium (21.62%)
 * Likes:    3798
 * Dislikes: 671
 * Total Accepted:    179.5K
 * Total Submissions: 820.1K
 * Testcase Example:  '[4,2,3]'
 *
 * Given an array nums with n integers, your task is to check if it could
 * become non-decreasing by modifying at most one element.
 * 
 * We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for
 * every i (0-based) such that (0 <= i <= n - 2).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,2,3]
 * Output: true
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing
 * array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,2,1]
 * Output: false
 * Explanation: You can't get a non-decreasing array by modify at most one
 * element.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start


bool checkPossibility(int* nums, int numsSize){
    if (numsSize < 3) {return 1;}

    int x = 0;
    int i = 0;
    while (i < numsSize - 1)
    {
        if (nums[i] > nums[i+1]) {
            x++;
            if (i > 0 && i < numsSize - 2 && nums[i] > nums[i+2] && nums[i-1] > nums[i+1]) {
                x++;
            }
        }
        if (x > 1) {return 0;}
        i++;
    }
    return 1;
}
// @lc code=end
// @lc MEDIUM