#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// vector<int> getSneakyNumbers(vector<int>& nums) {
//         unordered_map<int,int> counter;
//         vector<int> tbr;
//         for(int i = 0; i<nums.size(); i++){
//             counter[nums[i]]++;
//         }
//         for(auto& p:counter){
//             cout<<p.first<<" : "<<p.second<<endl;
//             if(p.second == 2){
//                 tbr.push_back(p.first);
//             }
//         }
//         return tbr;
// }

bool hasCycle(ListNode* head){
    
}

int main() {
    // vector<int> x= {7,1,5,4,3,4,6,0,9,5,8,2};
    // getSneakyNumbers(x);
    return 0;
}