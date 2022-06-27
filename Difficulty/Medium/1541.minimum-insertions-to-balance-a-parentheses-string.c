/*
 * @lc app=leetcode id=1541 lang=c
 *
 * [1541] Minimum Insertions to Balance a Parentheses String
 *
 * https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/
 *
 * algorithms
 * Medium (49.37%)
 * Likes:    666
 * Dislikes: 149
 * Total Accepted:    30.8K
 * Total Submissions: 62.3K
 * Testcase Example:  '"(()))"'
 *
 * Given a parentheses string s containing only the characters '(' and ')'. A
 * parentheses string is balanced if:
 * 
 * 
 * Any left parenthesis '(' must have a corresponding two consecutive right
 * parenthesis '))'.
 * Left parenthesis '(' must go before the corresponding two consecutive right
 * parenthesis '))'.
 * 
 * 
 * In other words, we treat '(' as an opening parenthesis and '))' as a closing
 * parenthesis.
 * 
 * 
 * For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))"
 * and "(()))" are not balanced.
 * 
 * 
 * You can insert the characters '(' and ')' at any position of the string to
 * balance it if needed.
 * 
 * Return the minimum number of insertions needed to make s balanced.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "(()))"
 * Output: 1
 * Explanation: The second '(' has two matching '))', but the first '(' has
 * only ')' matching. We need to add one more ')' at the end of the string to
 * be "(())))" which is balanced.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "())"
 * Output: 0
 * Explanation: The string is already balanced.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "))())("
 * Output: 3
 * Explanation: Add '(' to match the first '))', Add '))' to match the last
 * '('.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of '(' and ')' only.
 * 
 * 
 */

// @lc code=start


int minInsertions(char * s){
    int res = 0,len = strlen(s);
    char *new = (char *)malloc(sizeof(char) * 3 * len);
    memset(new, '\0', 3*len);

    for (int i=0,j=0; i < len; ++i, ++j) {
        if (s[i] == 40) {new[j] = s[i];}
        else {
            if (i != len - 1 && s[i + 1] == 41) {new[j] = ')'; ++i;} 
            else {new[j] = ')'; ++res;}
        }
    }
    int i = 0, status = 0;
    while (new[i] != '\0')
    {
        if (new[i] == 40) {++status;}
        else {
            if (status > 0) {--status;}
            else {++res;}
        }
        ++i;
    }
    
    return res + status*2;
}
// @lc code=end
// @lc MEDIUM