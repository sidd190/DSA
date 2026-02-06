#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
// WRANNGGG WRANNGGG WRAANNNGG HAII SARRRR
//         vector<vector<int>> result;
//         int rows = heights.size();
//         int cols = heights[0].size();
//         queue<vector<int>> q;
//         for(int i = 0; i<rows; i++){
//             int maxi = INT_MIN;
//             vector<int> maxcor;
//             for(int j = 0; j<cols; j++){
//                 maxi = max(maxi, heights[i][j]);
//                 if(maxi == heights[i][j]){
//                     maxcor.clear();
//                     maxcor.push_back(i);
//                     maxcor.push_back(j);
//                 }
//             }
//             q.push(maxcor);
//             result.push_back(maxcor);
//         }
//         while(!q.empty()){
//             // to check up and down if any element is greater than or equal to the max element we're doing bfs on
//             vector<int> curr = q.front();
//             q.pop();          
//         }
//         for(auto x:result){
//             for(auto z:x){
//                 cout<<z<< " ";
//             }
//             cout<<endl;
//         }
//         return result;
// }

int m, n;
vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
    ocean[r][c] = true;
    for(auto& d : dirs){
        int nr = r + d[0], nc = c + d[1];
        if(nr<0 || nc<0 || nr >= m || nc >= n) continue;
        if(ocean[nr][nc]) continue;
        if(heights[nr][nc] < heights[r][c]) continue;
        dfs(nr,nc, ocean, heights);
    }
};

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    m = heights.size();
    n = heights[0].size();

    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(n, vector<bool>(n, false));

    for(int i = 0; i<m; i++){
        dfs(i, 0, pacific, heights);
    }
    for(int j = 0; j<n; j++){
        dfs(j, 0, pacific, heights);
    }
    for(int i = 0; i<m; i++){
        dfs(i, n-1, atlantic, heights);
    }
    for(int j = 0; j<n; j++){
        dfs(m-1, j, pacific, heights);
    }

    vector<vector<int>> res;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j])
                res.push_back({i, j});
        }
    }

    // for(auto x:res){
    //     for(auto z:x){
    //         cout<<z<< " ";
    //     }
    //     cout<<endl;
    // }
    // return res;
    
}

int main(){
    vector<vector<int>> ques = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    pacificAtlantic(ques);
}