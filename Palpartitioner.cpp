#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> result;
vector<string> temp;

bool isPalindrome(const string &s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

void dfs(int index, const string& s){

    if(index == s.size()){
        result.push_back(temp);
        return;
    }

    for(int end = index; end < s.size(); end++){
        if(isPalindrome(s, index, end)){
            temp.push_back(s.substr(index, end - index + 1));
            dfs(end + 1, s);
            temp.pop_back();
        }
    }
}


vector<vector<string>> partition(string s) {
        dfs(0, s);
        return result;
}


int main(){
    string s = "abcaacba";
    partition(s);
    for(auto x:result){
        for(auto y:x){
            cout<<y<<",";
        }
        cout<<"\n";
    }
}