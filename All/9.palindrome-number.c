/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 */

// @lc code=start


bool isPalindrome(int x){
    if (x < 0) {return 0;}
    long long rev = 0, org = x;
    while (x != 0) {rev = rev*10 + x%10; x /= 10;}
    return (org == rev)? 1 : 0;
}
// @lc code=end
// @lc MEDIUM