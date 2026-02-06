#include <bits/stdc++.h>
using namespace std;

int maxArea = 0;
void dfs(int r, int c, int& area, vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
        return;

    area++; 
    grid[r][c] = 0;
    // mark visited

    dfs(r + 1, c,area, grid);
    dfs(r - 1, c,area, grid);
    dfs(r, c + 1,area, grid);
    dfs(r, c - 1,area, grid);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rows = grid.size();
    int maax = 0;
    int cols = grid[0].size();

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(grid[i][j] == 1){
                int area = 0;
                dfs(i,j,area,grid);
                maax = max(maax, area);
            }
        }
    }
    return maax;
}

int main() {
    vector<vector<int>> gr = {{1,1,1,1,0},{0,1,1,1,0},{1,1,0,0,0},{0,0,0,1,1}};
    cout<<maxAreaOfIsland(gr);
    return 0;
}