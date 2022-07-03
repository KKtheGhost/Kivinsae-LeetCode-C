/*
 * @lc app=leetcode id=1465 lang=c
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */

// @lc code=start

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
#define MAX(a,b) a>b ? a:b
#define MOD 1000000007
int maxArea(int h, int w, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize){
    qsort(horizontalCuts, horizontalCutsSize, sizeof(int), cmp);
    qsort(verticalCuts, verticalCutsSize, sizeof(int), cmp);
    
    int max_h = MAX(horizontalCuts[0], h-horizontalCuts[horizontalCutsSize-1]);
    int max_w = MAX(verticalCuts[0], w-verticalCuts[verticalCutsSize-1]);
    
    
    for(int i=0;i<horizontalCutsSize-1;++i){
        max_h = MAX(max_h, horizontalCuts[i+1]-horizontalCuts[i]);
    }
    for(int i=0;i<verticalCutsSize-1;++i){
        max_w = MAX(max_w, verticalCuts[i+1]-verticalCuts[i]);
    }
    
    return (long)max_h*max_w%MOD;
    
}
// @lc code=end
// @lc MEDIUM