/*
 * @lc app=leetcode id=695 lang=c
 *
 * [695] Max Area of Island
 */

// @lc code=start
int DFS(int **grid, int grs, int gcs, int r, int c, int **visited){
    if (r < 0 || grs <= r || c < 0 || gcs <= c) return 0;
    if (visited[r][c] == 1 || grid[r][c] == 0) return 0;
    
    visited[r][c] = 1;
    int up = DFS(grid, grs, gcs, r + 1, c, visited);
    int down = DFS(grid, grs, gcs, r - 1, c, visited);
    int left = DFS(grid, grs, gcs, r, c - 1, visited);
    int right = DFS(grid, grs, gcs, r, c + 1, visited);
    return up + down + left + right + 1;
}

int maxAreaOfIsland(int **grid, int gridSize, int* gridColSize){
    int i, j, temp, **visited, max = 0;
    visited = (int **) malloc(gridSize*sizeof(int *));
    for (i = 0; i < gridSize; i++)
        visited[i] = (int *) malloc(*gridColSize*sizeof(int));
    
    for (i = 0; i < gridSize; i++)
        for (j = 0; j < *gridColSize; j++)
            visited[i][j] = 0;
    
    for (i = 0; i < gridSize; i++){
        for (j = 0; j < *gridColSize; j++){
            temp = DFS(grid, gridSize, *gridColSize, i, j, visited);
            max = (max < temp) ? temp : max;}}
    
    for (i = 0; i < gridSize; i++)
        free(visited[i]);
    free(visited);
    return max;
}
// @lc code=end
// @lc MEDIUM