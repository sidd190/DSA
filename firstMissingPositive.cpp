#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {

    // for(int i = 0; i<nums.size(); i++){
    //     while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i]) {
    //         swap(nums[i], nums[nums[i]-1]);
    //     }
    // }    
    // // for(auto x:nums){
    // //     cout<<x<<" ";
    // // }
    // // cout<<"\n";
    // for(int i = 0; i<nums.size(); i++){
    //     if(nums[i] == i+1){
    //         continue;
    //     }
    //     else{
    //         return i+1;
    //     }
    // }    
    // return nums.size() + 1;
    int n = nums.size();
        bool contains1 = false;
        for(int i=0;i<n;i++){
            if(nums[i] == 1) contains1 = true;
            if(nums[i]<=0 || nums[i]>n) nums[i]=1;
        }
        if(!contains1)return 1;
        for(int i=0;i<n;i++){
            int num = abs(nums[i]);
            int idx = num-1;
            if(nums[idx]<0) continue;
            nums[idx]*= -1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) return i+1;
        }
        return n+1;
}

int main() {
    vector<int> x = {10, 3, 5, 34, 9, 2,9,1,4};
    cout<<firstMissingPositive(x);
    return 0;
}