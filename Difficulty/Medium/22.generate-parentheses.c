/*
 * @lc app=leetcode id=22 lang=c
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (70.40%)
 * Likes:    13414
 * Dislikes: 511
 * Total Accepted:    1.1M
 * Total Submissions: 1.6M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int ansSize(int n) {
    int ans = 1;
    for(int i = 0; i < n; i++)
        ans *= (2 * n - i);
    for(int i = 0; i < n; i++)
        ans /= (n + 1 - i);
    return ans;
}

char ** generateParenthesis(int n, int* returnSize){
    *returnSize = ansSize(n);
    printf("returnSize is %d", *returnSize);
    char** res = (char**)malloc(sizeof(char*) * (*returnSize));
    memset(res, 0, sizeof(char*) * (*returnSize));

    int valid, j, k = 0;
    
    for(int i = 0; i < (1 << (2 * n)); i++) {
        // Check Validity
        valid = 0;
        for(j = 0; j < 2 * n; j++) {
            valid += (i&(1<<j)) ? 1 : -1;
            if(valid < 0)
                break;
        }
        
        // If Valid then Output
        if(!valid) {
            res[k] = (char*)malloc(sizeof(char) * 2 * n + 1);
            for(j = 0; j < 2 * n; j++)
                res[k][j] = ((i&(1<<j)) ? 40 : 41);
            res[k][j] = 0;
            k++;
        }
    }
    
    return res;
}
// @lc code=end
// @lc MEDIUM