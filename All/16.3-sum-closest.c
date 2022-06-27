/*
 * @lc app=leetcode id=16 lang=c
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (47.06%)
 * Likes:    6046
 * Dislikes: 256
 * Total Accepted:    817.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an integer array nums of length n and an integer target, find three
 * integers in nums such that the sum is closest to target.
 * 
 * Return the sum of the three integers.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,0,0], target = 1
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int threeSumClosest(int* nums, int numsSize, int target){
    if (numsSize ==  3) {return nums[0]+nums[1]+nums[2];}
    int res = 9999,middle,right; /* bigger than 1000 will do */
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    for (int i = 0; i < numsSize - 2; ++i) {
        middle = i + 1;
        right = numsSize - 1;
        while (middle < right)
        {
            int sum = nums[i] + nums[middle] + nums[right];
            if (sum > target)
                right--;
            else if (sum < target)
                middle++;
            else
            {
                res = target;
                goto end;
            }
            res = (abs(sum - target) < abs(res - target)) ? sum : res;
        }
    }
    end:;
    return res;
}
// @lc code=end
// @lc MEDIUM