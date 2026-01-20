#include <bits/stdc++.h>
using namespace std;

// string reorganizeString(string s) {
//     vector<int> freq(26);

//     for(auto x:s){
//         freq[(toascii(x) - 97)]++;
//     }; 

//     priority_queue<pair<int, char>> stringinqueue;
//     for(int i = 0; i<26; i++){
//         if(freq[i] > 0){
//             stringinqueue.push({freq[i], char('a' + i)});
//         }
//     }

//     string result = "";
//     pair<int, char> prev = {0, '#'};
    
//     while(!stringinqueue.empty()){
//         auto[count, ch] = stringinqueue.top();
//         stringinqueue.pop();

//         result += ch;
//         count--;
//         if(prev.first > 0){
//             stringinqueue.push(prev);
//         }

//         prev = {count, ch};
//     }

//     return result.size() == s.size()? result : "";
// }

string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int, char>> haha;
    string result = "";
    if(a>0)haha.push({a,'a'});
    if(b>0)haha.push({b,'b'});
    if(c>0)haha.push({c,'c'});
    
    while(!haha.empty()){
        auto [val, str] = haha.top();
        haha.pop();
        int n = result.size();
        if (n >= 2 && result[n - 1] == str && result[n - 2] == str) {
            if(haha.empty()) break;

            auto [val2, str2] = haha.top();
            haha.pop();

            result.push_back(str2);
            val2--;

            if(val2 > 0) haha.push({val2, str2});
            haha.push({val, str});
        }
        else{
            result.push_back(str);
            val--;

            if(val > 0) haha.push({val, str});
        }
    }

    return result;
}

int main() {
    cout<<longestDiverseString(0,7,1);
    return 0;
}