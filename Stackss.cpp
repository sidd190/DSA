#include <iostream>
using namespace std;
#include <vector>
#include <queue>

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

class MyStack {
    public:
            queue<int> sta1, sta2;
        MyStack() {}
        
        void push(int x) {
            sta2.push(x);
            while (!sta1.empty()) {
                sta2.push(sta1.front());
                sta1.pop();
            }
            swap(sta1, sta2);
        }
        
        int pop() {
            int topVal = sta1.front();
            sta1.pop();
            return topVal;
        }
        
        int top() {
            return sta1.front();
        }
        
        bool empty() {
            return sta1.empty();
        }
};

int main() {
    // vector<string> calc = {"1","C"};
    // calPoints(calc);
    return 0;
}