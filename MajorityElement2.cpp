#include <iostream>
using namespace std;
#include <vector>

vector<int> majorityElement(vector<int>& nums) {
    vector<int> toBeReturned;

    if(nums.size()<=1) return nums;

    int c1 = 0, c2 = 1;
    int count1 = 0, count2 = 0;

    for(int n:nums){
        if(n == c1){
            count1++;
        }
        else if (n == c2)
        {
            count2++;
        }
        else if(count1 == 0){
            c1 = n;
            count1 = 1;
        }
        else if(count2 == 0){
            c2 = n;
            count2=1;
        }
        else{
            count1--;
            count2--;
        }
        
    }

    count1 = count2 = 0;
    for (int n : nums) {
        if (n == c1) count1++;
        else if (n == c2) count2++;
    }

    cout<<c1<<" "<<count1<<"\t"<<c2<<" "<<count2;
    if(count1 > (nums.size()/3)){
        toBeReturned.push_back(c1);
    }
    if(count2 > (nums.size()/3)){
        toBeReturned.push_back(c2);
    }
    return toBeReturned;
}

int main() {
    vector<int> nums = {2,2,1,3};
    vector<int> x= majorityElement(nums);
    for(int z:x){
        cout<<z<<" ";
    }
    return 0;
}