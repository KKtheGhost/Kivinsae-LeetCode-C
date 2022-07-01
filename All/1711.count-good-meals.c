/*
 * @lc app=leetcode id=1711 lang=c
 *
 * [1711] Count Good Meals
 */

// @lc code=start
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int powAdd(int x){
    int p = 1;
    while(x > p){p <<= 1;}
    return p - x;
}
int countPairs(int* deliciousness, int deliciousnessSize){
    qsort(deliciousness, deliciousnessSize, sizeof(int), cmp);
    int *hash = calloc(deliciousness[deliciousnessSize - 1]+1, sizeof(int));
    long long res = 0;
    long MOD = 1000000007;
    int delta = 0;
    for (int i = 0; i < deliciousnessSize; ++i) {
        if(deliciousness[i]!=0) {
            delta = powAdd(deliciousness[i]);
            if(delta != 0){
                res += hash[delta];
            }
            else{
                res += hash[deliciousness[i]];
                res += hash[0];
            }
            res %= MOD;
        }
        hash[deliciousness[i]]++;
    }
    return res;
}
// @lc code=end
// @lc MEDIUM