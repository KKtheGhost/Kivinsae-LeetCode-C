/*
 * @lc app=leetcode id=215 lang=c
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (63.79%)
 * Likes:    9841
 * Dislikes: 513
 * Total Accepted:    1.4M
 * Total Submissions: 2.1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Given an integer array nums and an integer k, return the k^th largest
 * element in the array.
 * 
 * Note that it is the k^th largest element in the sorted order, not the k^th
 * distinct element.
 * 
 * 
 * Example 1:
 * Input: nums = [3,2,1,5,6,4], k = 2
 * Output: 5
 * Example 2:
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * Output: 4
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(nums[0]), cmp); return nums[numsSize - k];
}
// @lc code=end
// @lc MEDIUM