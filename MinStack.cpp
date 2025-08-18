#include<iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
private:
      stack<int> st, minSt;
public:
    MinStack() {
    
    }
    
    void push(int val) {
        if(st.empty()){
            minSt.push(val);
        } 
        else {
            minSt.push(min(minSt.top(), val));
        }
        st.push(val);
    }
    
    void pop() {
           st.pop(); minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

int main(){

    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-1);
    cout<<obj->getMin();
    cout<<obj->top();
    obj->pop();
    cout<<obj->getMin();
}