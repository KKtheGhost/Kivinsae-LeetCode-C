/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (42.29%)
 * Likes:    8262
 * Dislikes: 424
 * Total Accepted:    1.5M
 * Total Submissions: 3.6M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array of distinct integers and a target value, return the
 * index if the target is found. If not, return the index where it would be if
 * it were inserted in order.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,5,6], target = 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,3,5,6], target = 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,3,5,6], target = 7
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums contains distinct values sorted in ascending order.
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start

int searchInsert(int* nums, int numsSize, int target){
    int left = 0, right = numsSize;
    while(right - left > 1) {
        int mid = (left + right)/2;
        if(target < nums[mid]) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left + ((target>nums[left])? 1 : 0);
}
// @lc code=end
// @lc EASY