/*
 * @lc app=leetcode id=1354 lang=c
 *
 * [1354] Construct Target Array With Multiple Sums
 *
 * https://leetcode.com/problems/construct-target-array-with-multiple-sums/description/
 *
 * algorithms
 * Hard (31.20%)
 * Likes:    1347
 * Dislikes: 107
 * Total Accepted:    42.4K
 * Total Submissions: 124.5K
 * Testcase Example:  '[9,3,5]'
 *
 * You are given an array target of n integers. From a starting array arr
 * consisting of n 1's, you may perform the following procedure :
 * 
 * 
 * let x be the sum of all elements currently in your array.
 * choose index i, such that 0 <= i < n and set the value of arr at index i to
 * x.
 * You may repeat this procedure as many times as needed.
 * 
 * 
 * Return true if it is possible to construct the target array from arr,
 * otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: target = [9,3,5]
 * Output: true
 * Explanation: Start with arr = [1, 1, 1] 
 * [1, 1, 1], sum = 3 choose index 1
 * [1, 3, 1], sum = 5 choose index 2
 * [1, 3, 5], sum = 9 choose index 0
 * [9, 3, 5] Done
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: target = [1,1,1,2]
 * Output: false
 * Explanation: Impossible to create target array from [1,1,1,1].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: target = [8,5]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == target.length
 * 1 <= n <= 5 * 10^4
 * 1 <= target[i] <= 10^9
 * 
 * 
 */

// @lc code=start
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

bool isPossible(int* target, int targetSize){
	long int sum = 0;
    qsort(target, targetSize, sizeof(int), cmp);
	int max = target[targetSize - 1];
	int min = target[0];
    if (max == 1 & min == 1) {return 1;}
    
    for (int i = 0; i < targetSize; i++){
			sum += target[i];
	}
	while(max > 1 && min >= 1)
	{
		sum -= max;
		if (max - sum <= 0 || sum == 0) return 0;
		if (sum == 1) {
			target[targetSize - 1] = 1;
            sum += 1;
		}
        else {
			target[targetSize - 1] = max % sum;
            sum += target[targetSize - 1];
		}
		qsort(target, targetSize, sizeof(int), cmp);
		max = target[targetSize - 1];
		min = target[0];
	    if (max == 1 & min == 1) {return 1;}
    }
	return 0;
}
// @lc code=end
// @lc HARD