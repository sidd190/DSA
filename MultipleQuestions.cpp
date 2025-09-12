#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

// std::vector<int> getConcatenation(std::vector<int>& nums) {
//     std::vector<int> ans(nums.begin(), nums.end());
//     ans.insert(ans.end(), nums.begin(), nums.end());
//     return ans;
// }

// std::string longestCommonPrefix(std::vector<std::string>& strs) {
//     if(strs.empty()) return "";
//     std::string prefix = strs[0];
//     for(int i =1; i<strs.size(); i++){
//         int j = 0;
//         while(j<prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]){
//             j++;
//         }
//         prefix = prefix.substr(0,j);
//         if(prefix.empty()){
//             return "";
//         }
//     }
//     return prefix;
// }

int removeElement(std::vector<int>& nums, int val){
    int k = nums.size()-1;
    int i =0;
    while(i<=k){
        if(nums[i] == val){
            nums[i] = nums[k];
            k--;
        }
        else{
            i++;
        }
    }
    return k+1;
}

int main() {

    // std::vector<int> x = {1,2,4,5};
    // std::vector<int> result = getConcatenation(x);
    // for(auto a:result){
    //     std::cout<<a<<" ";
    // }

    // std::vector<std::string> x= {"","","",""};
    // std::cout<<longestCommonPrefix(x);

    std::vector<int> nums = {7,8,9,9,8,7,6,5,3,2,7};
    removeElement(nums, 7);
    
    return 0;
}