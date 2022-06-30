/*
 * @lc app=leetcode id=463 lang=c
 *
 * [463] Island Perimeter
 */

// @lc code=start
int DFS(int** grid, int i, int j, int rowsSize, int colSize) {
    if (i < 0 || j < 0 || i == rowsSize || j == colSize || grid[i][j] == 0) {return 1;}
    if (grid[i][j] == 2) {return 0;}
    grid[i][j] += 1;
    return DFS(grid, i+1, j, rowsSize, colSize) + 
           DFS(grid, i-1, j, rowsSize, colSize) +
           DFS(grid, i, j+1, rowsSize, colSize) + 
           DFS(grid, i, j-1, rowsSize, colSize);
}
int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[0]; ++j) {
            if (grid[i][j] == 1) {
                return DFS(grid, i, j, gridSize, gridColSize[0]);
            }
        }
    }
    return -1;
}
// @lc code=end
// @lc EASY