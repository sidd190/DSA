#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// int minEatingSpeed(vector<int>& piles, int h) {
//     int low = 1;
//     int high=0;
//     for(auto x:piles){
//         high = max(high, x);
//     }
//     while(low < high){
//         long long hours=0;  
//         int mid = low + (high-low)/2;
//         for(auto x:piles){
//             hours += (x+mid-1)/mid; 
//         }
//         if(hours <= h){
//             high = mid;
//         }     
//         else{
//             low = mid +1;
//         }   
//     }
//     return low;
// }

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = 0,mid=0;
    for(auto x:weights){
        high+=x;
    }
    while(low < high){
        mid = low + (high-low)/2;
        int dDays = 0;
        int currSum = 0;
        for(auto x:weights){
            if(currSum+x > mid){
                dDays++;
                currSum=0;
            }
            currSum += x;
        }
        dDays++;
        if(dDays <= days){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int main() {
    // vector<int> piles = {3, 6, 7, 11};
    // int h = 8;
    // cout << minEatingSpeed(piles, h) << endl;

    vector<int> weights = {1,2,3,1,1};
    int days = 4;
    cout << shipWithinDays(weights, days) << endl;
    
    return 0;
}