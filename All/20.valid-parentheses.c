/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.86%)
 * Likes:    13582
 * Dislikes: 614
 * Total Accepted:    2.3M
 * Total Submissions: 5.7M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 * 
 * 
 */

// @lc code=start

char left(char c) {
    if (c == 41) {return 40;}
    else if (c == 93) {return 91;}
    else {return 123;}
}

bool isValid(char * s){
    int len=strlen(s);
    if (len == 1) {return false;}
    int *status = (int *)malloc(sizeof(int) * 7002);
    memset(status, 0, 7002);
    int idx = 0;

    for (int i = 0; i < len; ++i) {
        if (s[i] == 40 || s[i] == 91 || s[i] == 123) {++idx; status[idx] = s[i];}
        else {
            if (left(s[i]) == status[idx]) {--idx;}
            else {return false;}
        }
    }
    bool res;
    return res = (idx == 0) ? true : false;
}
// @lc code=end
// @lc MEDIUM