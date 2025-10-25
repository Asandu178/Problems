#include <stdlib.h>
#include <stdio.h>

void dfs(int i, int j, int n, int m, int visited[50][50], int **grid, int *size) {
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || !grid[i][j])
        return ;
    (*size)++;
    visited[i][j] = 1;
    
    dfs(i - 1, j, n, m, visited, grid, size);
    dfs(i + 1, j, n, m, visited, grid, size);
    dfs(i, j - 1, n, m, visited, grid, size);
    dfs(i, j + 1, n, m, visited, grid, size);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int m = gridColSize[0];
    int size = 0;
    int maxSize = 0;
    int visited[50][50] = {0};

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            size = 0;
            if (grid[i][j] && !visited[i][j])
                dfs(i, j, n, m, visited, grid, &size);
            if (maxSize < size)
                maxSize = size;
        }
    }
    return maxSize;
}