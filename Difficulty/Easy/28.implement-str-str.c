/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (36.17%)
 * Likes:    4252
 * Dislikes: 3718
 * Total Accepted:    1.3M
 * Total Submissions: 3.5M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Given two strings needle and haystack, return the index of the first
 * occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack and needle consist of only lowercase English characters.
 * 
 * 
 */

// @lc code=start


int strStr(char * haystack, char * needle){
    int lenH = strlen(haystack), lenN = strlen(needle);
    if (lenH < lenN) {return -1;}

    for (int i = 0; i <= lenH - lenN; ++i) {
        if (haystack[i] == needle[0]) {
            for (int j = i, k = 0; k < lenN; ++j, ++k) {
                if (haystack[j] != needle[k]) {goto end;}
                if (k == lenN - 1) {return i;}
            }
            end:;
        }
    }
    return -1;
}
// @lc code=end
// @lc EASY