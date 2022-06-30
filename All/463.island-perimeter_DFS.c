/*
 * @lc app=leetcode id=463 lang=c
 *
 * [463] Island Perimeter
 */

// @lc code=start
int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int res = 0;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[0]; ++j) {
            if (grid[i][j] == 1) {
                res += 4;
                if (i > 0 && grid[i-1][j] == 1) {res--;}
                if (i < gridSize - 1 && grid[i+1][j] == 1) {res--;}
                if (j > 0 && grid[i][j-1] == 1) {res--;}
                if (j < gridColSize[0] - 1 && grid[i][j+1] == 1) {res--;}
            }
        }
    }
    return res;
}
// @lc code=end
// @lc EASY