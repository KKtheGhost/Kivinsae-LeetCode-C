/*
 * @lc app=leetcode id=45 lang=c
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (37.40%)
 * Likes:    8411
 * Dislikes: 313
 * Total Accepted:    632.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers nums, you are initially positioned
 * at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * You can assume that you can always reach the last index.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump
 * 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

// @lc code=start
int jump(int* nums, int numsSize){
    if (numsSize == 1) {return 0;}
    int res = 0, curPos = 0, curFar = 0;
    for (int i = 0; i < numsSize - 1; ++i) {
        curFar = (curFar < i + nums[i])? i + nums[i] : curFar;
        if (i == curPos) {
            res++;
            curPos = curFar;
        }
    }
    return res;
}
// @lc code=end
// @lc MEDIUM