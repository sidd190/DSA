#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int cheapest{prices[0]};
    int maxProfit{0};
    if(prices.size()<=1){
        return 0;
    }
    for(int i = 0;i <prices.size();i++){
        if(prices[i]<cheapest){
            cheapest = prices[i];
        }
        if(prices[i] - cheapest> maxProfit){
            maxProfit = prices[i] - cheapest;
        }
    }
    return maxProfit;
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices);
}