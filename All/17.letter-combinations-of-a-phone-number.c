/*
 * @lc app=leetcode id=17 lang=c
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (54.44%)
 * Likes:    10969
 * Dislikes: 707
 * Total Accepted:    1.2M
 * Total Submissions: 2.3M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 * 
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = ""
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char * digits, int* returnSize){
    char *phone[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **result = (char **)malloc(sizeof(char *) * 4000);
    char tmp[strlen(digits) + 1];
    int resLen = 0;
    if (strlen(digits) == 0) {
        *returnSize = resLen;
        return result;
    }
    catRes(result, phone, digits, tmp, 0, &resLen);
    *returnSize = resLen;
    return result;
}

void catRes(char **result, char **phone, char *digits, char *tmp, int nowIndex, int *resLen) {
    if (nowIndex == strlen(digits)) {
        tmp[nowIndex] = 0;
        result[(*resLen)] = (char *)malloc(strlen(tmp) + 1);
        strcpy(result[(*resLen)], tmp);
        (*resLen)++;
        return;        
    }
    char *phoneData = phone[digits[nowIndex] - '0' - 2];
    for (int i = 0; i < strlen(phoneData); i++) {
        tmp[nowIndex] = phoneData[i];
        catRes(result, phone, digits, tmp, nowIndex + 1, resLen);
    }
}
// @lc code=end
// @lc MEDIUM