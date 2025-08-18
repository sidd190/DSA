#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int evalRPN(vector<string>& tokens){
    stack<int> main;
    for(string x:tokens){
        if(x=="+"){
            int a = main.top(); main.pop();
            int b = main.top(); main.pop();
            main.push(b+a);
        } else if(x=="-") {
            int a = main.top(); main.pop();
            int b = main.top(); main.pop();
            main.push(b-a);
        }
        else if(x=="*"){
            int a = main.top(); main.pop();
            int b = main.top(); main.pop();
            main.push(b*a);
        }
        else if(x=="/"){
            int a = main.top(); main.pop();
            int b = main.top(); main.pop();
            main.push(b/a);
        } else {
            main.push(stoi(x));
        }
    }
    return main.top();
}

int main(){
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    evalRPN(tokens);
}