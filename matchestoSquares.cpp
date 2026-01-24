#include <bits/stdc++.h>
using namespace std;

vector<int> matches = {1,1,2,2,2,1,3,1,4};

bool backtrack (int i, vector<int>& matches, int sides[4], int side){
    if(i == matches.size()){
        return true;
    }
    for(int j=0; j<4; j++){
        if(sides[j] + matches[i] <= side){
            sides[j] += matches[i];
            if(backtrack(i+1, matches, sides, side)){
                return true;
            }
            sides[j] -= matches[i];
        }
    }
    return false;
}

bool makesquare(vector<int>& matchsticks) {
    sort(matchsticks.begin(),matchsticks.end(),greater<int>());
    float sum = 0;
    for(auto x:matchsticks){
        sum += x;
    }
    float side = sum/4;
    int sides[4] = {side};
    backtrack(0, matchsticks, sides, side);
}

int main() {
    makesquare(matches);
    return 0;
}