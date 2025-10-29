#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int countSplits(vector<int>& entries, int acceptable){
    int n = entries.size();
    int splits = 1;
    long long currSum = 0;
    for(int i = 0; i<n; i++){
        if(currSum + entries[i] <= acceptable){
            currSum += entries[i];
        }
        else{
            splits++;
            currSum = entries[i];
        }
    }
    return splits;
};

int splitArray(vector<int>& nums, int k) {
    if(k>nums.size()) return -1;
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(),0);

    while(low<=high){
        int mid = low + (high-low)/2;
        int splits = countSplits(nums, mid);
        if(splits > k){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return low;
}

int main() {
    vector<int> x = {1,2,3,4,5};
    int splits = 2;
    cout<<splitArray(x, splits);
    return 0;
}