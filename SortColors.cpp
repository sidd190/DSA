#include <iostream>
using namespace std;
#include <vector>

//Approach 1- One pass and better(O(n) time, O(1) space)
// Couldn't figure out the Moore's algo but at that time figured out this DNF algo, lmao
void sortColors(vector<int>& nums) {
    int right = nums.size()-1;
    int left,i = 0;
    while (i <= right) {
        if (nums[i] == 0) {
            swap(nums[i], nums[left]);
            left++;
            i++;
        }
        else if (nums[i] == 2) {
            swap(nums[i], nums[right]);
            right--;
        }
        else {
            i++;
        }
    }   
    for(auto x:nums){
        cout<<x<<" ";
    }
}

//Approach 2 - Two pass hai ji (O(2n) time, and O(1) space)
// void sortColors(vector<int>& nums){
//     int count0 = 0, count1 = 0, count2 = 0;
//     // First pass: count each number
//     for (int num : nums) {
//         if (num == 0) count0++;
//         else if (num == 1) count1++;
//         else count2++;
//     }
//     // Second pass: overwrite the array with as much values counted for each
//     int i = 0;
//     while (count0--) nums[i++] = 0;
//     while (count1--) nums[i++] = 1;
//     while (count2--) nums[i++] = 2;
//     for (int x : nums) cout << x << " ";
//     cout << endl;
// }

int main() {
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    return 0;
}