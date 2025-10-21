#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>

// int calPoints(vector<string>& operations) {
//     int top = 0;
//     vector<int> entries{0};
//     for(string x : operations){
//         if(x == "C"){
//             top--;
//             entries.pop_back();
//         }
//         else if(x == "D"){
//             entries.push_back(entries[top]*2);
//             top++;
//         }
//         else if (x == "+")
//         {
//             entries.push_back(entries[top] + entries[top -1]);
//             top++;
//         }
//         else{
//             entries.push_back(stoi(x));
//             top++;
//         }
//     }
//     int sum = 0;
//     for(auto x:entries){
//         sum+=x;
//     }
//     return sum;
// }

// class MyStack {
//     public:
//             queue<int> sta1, sta2;
//         MyStack() {}
// 
//         void push(int x) {
//             sta2.push(x);
//             while (!sta1.empty()) {
//                 sta2.push(sta1.front());
//                 sta1.pop();
//             }
//             swap(sta1, sta2);
//         }
// 
//         int pop() {
//             int topVal = sta1.front();
//             sta1.pop();
//             return topVal;
//         }
// 
//         int top() {
//             return sta1.front();
//         }
// 
//         bool empty() {
//             return sta1.empty();
//         }
// };

// vector<int> asteroidCollision(vector<int>& asteroids) {
//     int n = asteroids.size();
//     vector<int> tobeReturned;
//     for(int i = 0; i<n; i++){
//         if(asteroids[i]>0){
//             if(asteroids[i+1] < 0){
//                 if(asteroids[i] > abs(asteroids[i+1])){
//                     tobeReturned.push_back(asteroids[i]);
//                 }
//                 else{
//                     tobeReturned.push_back(asteroids[i+1]);
//                 }
//             }
//             else{
//                 tobeReturned.push_back(asteroids[i]);
//             }
//         }
//         else{
//             if(asteroids[i-1] > 0){
//                 if(abs(asteroids[i]) > asteroids[i-1]){
//                     tobeReturned.push_back(asteroids[i]);
//                 }
//                 else{
//                     tobeReturned.push_back(asteroids[i-1]);
//                 }
//             }
//             else{
//                 tobeReturned.push_back(asteroids[i]);
//             }
//         }
//     }
//     return tobeReturned;
// }

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for (int a : asteroids) {
        bool destroyed = false;
        while (!st.empty() && a < 0 && st.top() > 0) {
            if (abs(a) > st.top()) {
                st.pop(); 
            } else if (abs(a) == st.top()) {
                st.pop(); 
                destroyed = true;
                break;
            } else {
                destroyed = true;
                break;
            }
        }
        if (!destroyed) st.push(a);
    }
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        result[i] = st.top();
        st.pop();
    }
    return result;
}

int main() {
    // vector<string> calc = {"1","C"};
    // calPoints(calc);
    vector<int> x = {5,10,-5};
    vector<int> returned = asteroidCollision(x);
    for(auto x:returned){
        cout<<x<<" ";
    }
    return 0;
}