/*
 * @lc app=leetcode id=1710 lang=c
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
int cmp(const void *a, const void *b) {
    return (*(int **)b)[1] - (*(int **)a)[1];
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){
    qsort(boxTypes, boxTypesSize, sizeof(int*), cmp);
    long res = 0;
    for (int i = 0; i < boxTypesSize; ++i) {
        printf("Current box is [%d, %d]\n", boxTypes[i][0], boxTypes[i][1]);
        if (truckSize >= boxTypes[i][0]) {
            truckSize -= boxTypes[i][0];
            res += boxTypes[i][0] * boxTypes[i][1];
            if (truckSize == 0) {return res;}
        }
        else {
            for (int j = 0; j < boxTypes[i][0]; ++j) {
                truckSize--;
                res += boxTypes[i][1];
                printf("Left truckSize is %d, current res is %d\n", truckSize, res);
                if (truckSize == 0) {return res;}
        }
        }
    }
    return res;
}
// @lc code=end
// @lc EASY