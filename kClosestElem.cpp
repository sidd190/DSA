#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        unordered_map<int, int> teller;
        for(int i = 0; i< arr.size(); i++){
            teller[arr[i]]++;
        }
        
        return arr;
}

int main() {
    vector<int> x = {1,1,2,2,3,4,4,5};
    findClosestElements(x,2, 4);
    return 0;
}