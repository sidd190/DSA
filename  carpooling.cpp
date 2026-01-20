#include <bits/stdc++.h>
using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> tracker;
    sort(trips.begin(), trips.end(), [](const vector<int> a, const vector<int> b)
    {
        return a[1] < b[1];
    });

    int distancereached = trips[0][1]; // 2
    int remainingCap;
    tracker.push({trips[0][2], trips[0][0]}); // 5,2
    int i =1;
    while(!tracker.empty()){
        auto [to, pass] = tracker.top(); // to = 5, pass = 2
        if(capacity - pass >= 0){
            remainingCap = capacity - pass; // RC = 3
        }
        else{
            return false;
        }
        distancereached = trips[i][1]; // dr = 3

        if(to <= distancereached){  // 5 ! <= 3
            tracker.pop();
            capacity += pass;
        }
        tracker.push({trips[i][2], trips[i][0]}); 
        i++;
    }
    return true;
}

int main() {
    return 0;
}