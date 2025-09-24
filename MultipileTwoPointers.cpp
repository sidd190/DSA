#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

// string mergeAlternately(string word1, string word2) {
//         int sizee = max(word1.length(), word2.length());
//         string newString;
//         for(int i = 0; i < sizee; i++){
//             if(i < word1.length()) newString += word1[i];
//             if(i < word2.length()) newString += word2[i];
//         }
//         return newString;
// }

// vector<int> MergeSortedArray(vector<int> &nums1,int m, vector<int> &nums2, int n){
//     // int bigg1 = nums1[m-1];
//     // int c = 0;
//     // for(int i=0; i<n; i++){
//     //     if(nums2[i] >= bigg1){
//     //         nums1[m+c] = nums2[i];
//     //         bigg1 = nums2[i];
//     //         c++;
//     //     }
//     // }
//     while(n>0){
//         if(m>0 && nums1[m-1] > nums2[n-1]){
//             nums1[m+n-1] = nums1[m-1];
//             m--;
//         }
//         else{
//             nums1[m+n-1] = nums2[n-1];
//             n--;
//         }
//     }
//     for(auto x:nums1){
//         cout<<x<<" ";
//     }
//     cout<<"\n";
//     return nums1;
// };

// int numRescueBoats(vector<int> &people, int limit){
//     int count{0};
//     int j = 0;
//     sort(people.begin(), people.end());
//     int k = people.size()-1;
//     while(j<=k){
//         if(people[j] + people[k] <= limit){
//             count++;
//             j++; k--;
//         }
//         else{
//             count++;
//             k--;
//         }
//     }
//     cout<<count;
//     return count;
// }

int main() {
    // mergeAlternately("abcd","efghij");
    // vector<int> nums1 = {1,2,3,0,0,0,0};
    // vector<int> nums2 = {3,2,2,1};
    // int m = 3;
    // int n = 3;
    // MergeSortedArray(nums1, m, nums2, n);
    // numRescueBoats(nums2,3);
    return 0;
}