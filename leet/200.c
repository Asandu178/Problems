#include <stdlib.h>
#include <stdio.h>

void dfs(int i, int j, int n, int m, char **grid, char **visited) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0' || visited[i][j])
        return;
    
    visited[i][j] = 1;

    dfs(i - 1, j, n, m, grid, visited);
    dfs(i + 1, j, n, m, grid, visited);
    dfs(i, j + 1, n, m, grid, visited);
    dfs(i, j - 1, n, m, grid, visited);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    char **visited = malloc(sizeof(char*) * gridSize);
    int cnt = 0;
    for (int i = 0 ; i < gridSize ; i++)
        visited[i] = calloc(sizeof(char), gridColSize[0]);
    
    for (int i = 0 ; i < gridSize ; i++) {
        for (int j = 0 ; j < gridColSize[0] ; j++) {
            if (grid[i][j] != '0' && !visited[i][j]) {
                dfs(i, j, gridSize, gridColSize[0], grid, visited);
                cnt++;
            }
        }
    }
    return cnt;
}