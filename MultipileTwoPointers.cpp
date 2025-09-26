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

bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        unordered_map<char, int> teller2;
        unordered_map<char, int> teller1;
        if(n< s1.length()) return false;

        for(int i = 0; i<s1.length(); i++){
            teller1[s1[i]]++;
        }

        for(int i =0; i<n; i++){
            if(teller1.count(s2[i])){
                if (i + s1.length() > n) break;
                for(int j = i; j< i+ s1.length(); j++){
                    teller2[s2[j]]++;
                }
                if(teller1 ==  teller2){
                    return true;
                }
                teller2.clear();                
            }
        }

        for(auto x:teller1)
        {
            cout<<x.first<<" "<<x.second;cout<<"\n";
        }

        for(auto x:teller2)
        {
            cout<<x.first<<" "<<x.second;cout<<"\n";
        }
        return false;
}

int main() {
    // mergeAlternately("abcd","efghij");
    // vector<int> nums1 = {1,2,3,0,0,0,0};
    // vector<int> nums2 = {3,2,2,1};
    // int m = 3;
    // int n = 3;
    // MergeSortedArray(nums1, m, nums2, n);
    // numRescueBoats(nums2,3);

    checkInclusion("ab", "aosjfasakbjfow");

    return 0;
}