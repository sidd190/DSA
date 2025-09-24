#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
    unordered_map<int, vector<pair<int,int>>> x;

    for(int i=0; i<nums.size(); i++){
        for(int j = i+1; j<nums.size(); j++){
            int pairSum = nums[i] + nums[j];
            x[pairSum].push_back({i,j});
        }
    }
    set<vector<int>> result;
    for(auto &[sum, pairs] : x){
        int complement = target - sum;
        if(x.find(complement) != x.end()){
            auto &otherPairs = x[complement];
            for(auto &[i1, j1] : pairs){
                for(auto &[i2, j2] : otherPairs){
                    if(i1 != i2 && i1 != j2 && j1 != i2 && j1 != j2){
                        vector<int> quad = {nums[i1], nums[j1], nums[i2], nums[j2]};
                        sort(quad.begin(), quad.end());
                        result.insert(quad);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(result.begin(), result.end());
};

int main() {
    vector<int> x = {1,0,-1,0,-2,2};
    auto quads = fourSum(x, 0);

    for(auto &quad : quads){
        for(int num : quad) cout << num << " ";
        cout << endl;
    }
    return 0;
}