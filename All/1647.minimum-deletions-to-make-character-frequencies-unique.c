/*
 * @lc app=leetcode id=1647 lang=c
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

// @lc code=start
int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int minDeletions(char * s){
    int len = strlen(s);
    int *dict = malloc(sizeof(int)*26); memset(dict, 0, sizeof(int)*26);
    
    for (int i = 0; i < len; ++i) {
        dict[s[i] - 'a']++;
    }
    
    qsort(dict, 26, sizeof(int), cmp);
    int res = 0;
    for (int j = 0; j < 25; ++j) {
        if (dict[j] == 0 && dict[j+1] == 0) {break;}
        if (dict[j + 1] >= dict[j] && dict[j + 1] > 0) {
            res += (dict[j] == 0)? dict[j + 1] : dict[j + 1] - dict[j] + 1;
            dict[j + 1] = (dict[j] == 0)? 0 : dict[j] - 1;
        }
    }
    return res;
}
// @lc code=end
// @lc MEDIUM