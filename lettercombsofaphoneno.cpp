#include <bits/stdc++.h>
using namespace std;

vector<string> result;

unordered_map<char, string> mapp = {
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
};

void dfs(const string& digits, string& currentt, int index){
    if(index == digits.size()){
        result.push_back(currentt);
        return;
    }
    const string& letters = mapp[digits[index]];

    for(char c:letters){
        currentt.push_back(c);
        dfs(digits,currentt, index+1);
        currentt.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    result.clear();
    if (digits.empty()) return {};

    string currentt = "";
    dfs(digits, currentt, 0);
    return result;
}

int main() {
    string x = "2928473";
    result = letterCombinations(x);
    for(auto y:result){
        cout<<y<<" ";
    }
    return 0;
}