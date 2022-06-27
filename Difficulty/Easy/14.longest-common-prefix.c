/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (39.63%)
 * Likes:    8289
 * Dislikes: 3054
 * Total Accepted:    1.6M
 * Total Submissions: 4.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lower-case English letters.
 * 
 * 
 */

// @lc code=start


char * longestCommonPrefix(char ** strs, int strsSize){
    int MAX = 200;
    if (strsSize == 1) {return strs[0];}

    char *res = (char *)malloc(sizeof(char)*MAX);
    memset(res, '\0', sizeof(char)*MAX);

    for (int i = 0; i < 200; ++i) {
        for (int j = 1; j < strsSize; ++j) {
            if (strlen(strs[j]) <= i || strs[j][i] - strs[j - 1][i] != 0) {
                goto end;
            }
        }
        res[i] = strs[0][i];
    }
    end:;
    return res;
}
// @lc code=end
// @lc EASY