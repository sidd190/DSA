#include <bits/stdc++.h>
using namespace std;

void RecursionhiKehde(vector<int>& ds, vector<int> &nums, vector<vector<int>> ans, int freq[]){
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i<nums.size(); i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i] = 1;
            RecursionhiKehde(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> ds;
    int freq[nums.size()];
    for(int i =0; i<nums.size(); i++) freq[i] = 0;
    RecursionhiKehde(ds, nums, result, freq);
    return result;
}

int main() {
    
    return 0;
}