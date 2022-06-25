/*
 * @lc app=leetcode id=125 lang=c
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (42.02%)
 * Likes:    3968
 * Dislikes: 5427
 * Total Accepted:    1.3M
 * Total Submissions: 3.2M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 * 
 * Given a string s, return true if it is a palindrome, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric
 * characters.
 * Since an empty string reads the same forward and backward, it is a
 * palindrome.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 * 
 * 
 */

// @lc code=start


bool isPalindrome(char * s){
    int len = strlen(s); 
    if (len == 1) {return 1;}

    char *conv = (char *)malloc(sizeof(char)*len);
    memset(conv, '\0', sizeof(char)*len);

    int convidx = 0;
    for (int i = 0; i < len; ++i) {
        if ('0' <= s[i] && s[i] <= '9') {conv[convidx] = s[i]; convidx++;}
        if ('a' <= s[i] && s[i] <= 'z') {conv[convidx] = s[i]; convidx++;}
        if ('A' <= s[i] && s[i] <= 'Z') {conv[convidx] = s[i] - 'A' + 'a'; convidx++;}
    }
    int i = 0, j = convidx - 1;
    while (i < j)
    {
        if (conv[i] != conv[j]) {return 0;}
        i++; j--;
    }
    return 1;
}
// @lc code=end
// @lc EASY