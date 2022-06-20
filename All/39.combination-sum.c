/*
 * @lc app=leetcode id=39 lang=c
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (65.92%)
 * Likes:    11487
 * Dislikes: 245
 * Total Accepted:    1.1M
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 * 
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 * 
 * It is guaranteed that the number of unique combinations that sum up to
 * target is less than 150 combinations for the given input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: candidates = [2], target = 1
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void AddSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int* temp, int step, int start,int** res){
	if (target == 0){
		res[*returnSize] = malloc(sizeof(int)*step);
		for (int i = 0; i < step; i++){
			res[*returnSize][i] = temp[i];
		}
		returnColumnSizes[0][(*returnSize)++] = step;
		return;

	}
	if (start >= candidatesSize ||  target < 0){return;}    

	temp[step] = candidates[start];
	if (target - candidates[start] >= 0){

		AddSum(candidates, candidatesSize, target - candidates[start], returnSize, returnColumnSizes, temp, step + 1, start, res);        
	}    
	AddSum(candidates, candidatesSize, target , returnSize, returnColumnSizes, temp, step, start + 1, res);
	if (target - candidates[start] < 0){return;}
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
	int* temp = malloc(sizeof(int)*150);
	*returnSize = 0;
	returnColumnSizes[0] = malloc(sizeof(int)*200);
	int** res = malloc(sizeof(int*)*200);
	AddSum(candidates, candidatesSize, target, returnSize, returnColumnSizes, temp, 0, 0, res);
	return res;
}
// @lc code=end
// @lc MEDIUM