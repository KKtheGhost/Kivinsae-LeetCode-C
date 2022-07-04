/*
 * @lc app=leetcode id=135 lang=c
 *
 * [135] Candy
 */

// @lc code=start

int candy(int* ratings, int ratingsSize){
    if (ratingsSize == 1) {return 1;}
    int* candy = (int*)malloc(sizeof(int)*ratingsSize);
    candy[0] = 1;
    int res = 1, current = 1;

    for (int i = 1; i < ratingsSize; ++i) {
        if (ratings[i] > ratings[i-1]) {
            current++;
            candy[i] = current;
        } else {
            candy[i] = 1;
            current = 1;
        }
        res += current;
    }
    current = 0;
    for (int j = ratingsSize - 2; j >= 0; --j) {
        if (ratings[j] > ratings[j+1]) {
            if (candy[j+1] + 1 - candy[j] > 0) {
                res += candy[j+1] + 1 - candy[j];
                candy[j] = candy[j+1] + 1;
            }
        }
    }
    return res;
}
// @lc code=end
// @lc HARD