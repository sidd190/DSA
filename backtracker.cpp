#include <iostream>
using namespace std;
#include <vector>


void printhu(int i,vector<int> &n, vector<int> arr){
    if(i==arr.size()){
        for(auto x:n){
            cout<<x;
        }
        cout<<endl;
        return;
    }
    n.push_back(arr[i]);
    printhu(i+1, n, arr);
    n.pop_back();
    printhu(i+1, n, arr);
};

int main() {
    vector<int> x = {1,2,3,4};
    vector<int> n;
    printhu(0, n, x);
    return 0;
}