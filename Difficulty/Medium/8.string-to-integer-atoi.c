/*
 * @lc app=leetcode id=8 lang=c
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start


int myAtoi(char * s){
    #include <limits.h>
    long res = 0;
    int sig, length = strlen(s);
    if (length == 0) {return res;}
    
    int i = 0; sig = 0; 
    while (i < length) {
        if (sig == 0 && s[i] == ' ') {sig = 0;}
        else if (sig == 0 && s[i] == '+') {sig = 1;}
        else if (sig == 0 && s[i] == '-') {sig = -1;}
        else if (47 < s[i] && s[i] < 58) {
            res = res*10 + (s[i] - 48);
            if (res < INT_MIN || res > INT_MAX) {goto jump;}
            sig = (sig < 0) ? sig : 1;
        }
        else {goto jump;}
        
        ++i;
    }
    jump:i = 0;
    res = res * sig;
    res = (res < INT_MIN) ? INT_MIN : res;
    res = (res > INT_MAX) ? INT_MAX : res;
    return res;
}
// @lc code=end
// @lc MEDIUM