#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> result;
        int n = tasks.size();
        vector<array<int,3>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(v.begin(), v.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> quhu;

        vector<int> result;
        long long time = 0;
        int i = 0;

        while(result.size() < n){
            while(i<n && v[i][0]<=time){
                quhu.push({v[i][1], v[i][2]});
                i++;
            }

            if(quhu.empty()){
                time = v[i][0];
            }else{
                auto [proc, idx] = quhu.top();
                quhu.pop();
                time += proc;
                result.push_back(idx);
            }
        }
        return result;  
    }
};

int main() {
    
    return 0;
}