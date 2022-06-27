/*
 * @lc app=leetcode id=12 lang=c
 *
 * [12] Integer to Roman
 */

// @lc code=start

char * intToRoman(int num){
    int MAX = 26;
    char *Thousand[4]   = {"E", "M", "MM", "MMM"};
    char *Hundred[10]   = {"E", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *Ten[10]       = {"E", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *Single[10]    = {"E", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char *res = (char *)malloc(sizeof(char)*MAX);
    memset(res, '\0', sizeof(char)*MAX);

    int k = num/1000;
    int h = (num%1000)/100;
    int t = (num%100)/10;
    int s = num%10;
    
    if (Thousand[k] != "E") {strcat(res, Thousand[k]);}
    if (Hundred[h]  != "E") {strcat(res, Hundred[h]);}
    if (Ten[t]      != "E") {strcat(res, Ten[t]);}
    if (Single[s]   != "E") {strcat(res, Single[s]);}
    /* 
    free(Thousand);
    free(Hundred);
    free(Ten);
    free(Single); 
    Thousand = Hundred = Ten = Single = NULL;
    */

    return res;
}
// @lc code=end
// @lc MEDIUM