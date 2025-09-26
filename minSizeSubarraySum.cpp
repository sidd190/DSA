#include <iostream>
using namespace std;
#include <vector>

int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        // int leftminIndex{0}, rightminIndex{0};
        int sum = 0;
        int minLength = __INT_MAX__;
        while(right < n){
            if(sum >= target){
                minLength = min(minLength, right - left + 1);
                // leftminIndex = left; rightminIndex = right;
                sum -= nums[left];
                left++;
            }
            else{
                // if(right == n-1) return 0;
                right++;
                sum+=nums[right];
            }
        }
        // cout<< minLength << " "<<leftminIndex<<" "<<rightminIndex<< " "<< sum;
        return (minLength == __INT_MAX__) ? 0 : minLength;
}

int main() {
    vector<int> x = {1,1,4,1,1,1};
    minSubArrayLen(11, x);
    return 0;
}