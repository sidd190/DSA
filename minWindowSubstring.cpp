#include <bits/stdc++.h>
using namespace std;

// string minWindow(string s, string t) {
    // if(s.empty() || t.empty()) return "";

    // unordered_map<char,int> teller_t;
    // for(char c : t) teller_t[c]++;

    // int left = 0, right = 0;
    // int minLength = INT_MAX;
    // string copier = "";

    // int required = t.size();  
    // int formed = 0;            

    // while(right < s.size()) {
    //     char curr = s[right];
    //     if(teller_t.count(curr)) {
    //         if(teller_t[curr] > 0) formed++;  
    //         teller_t[curr]--;
    //     }

    //     while(formed == required) {
    //         if(right - left + 1 < minLength) {
    //             minLength = right - left + 1;
    //             copier = s.substr(left, minLength);
    //         }

    //         char leftChar = s[left];
    //         if(teller_t.count(leftChar)) {
    //             teller_t[leftChar]++;
    //             if(teller_t[leftChar] > 0) formed--;  
    //         }
    //         left++;
    //     }

    //     right++;
    // }

    // return copier;

// string minWindow(string s, string t) {
//         if(s.empty() || t.empty()) return "";
//         unordered_map<char,int> teller_t;
//         for(char c : t) teller_t[c]++;
//         unordered_map<char,int> window_counts;
//         int required = teller_t.size(); // number of unique chars in t
//         int formed = 0;
//         int left = 0, right = 0;
//         int minLength = INT_MAX;
//         int minLeft = 0;
//         while(right < s.size()) {
//             char curr = s[right];
//             window_counts[curr]++;
//             if(teller_t.count(curr) && window_counts[curr] == teller_t[curr]) {
//                 formed++;
//             }
//             while(left <= right && formed == required) {
//                 if(right - left + 1 < minLength) {
//                     minLength = right - left + 1;
//                     minLeft = left;
//                 }
//                 char leftChar = s[left];
//                 window_counts[leftChar]--;
//                 if(teller_t.count(leftChar) && window_counts[leftChar] < teller_t[leftChar]) {
//                     formed--;
//                 }
//                 left++;
//             }
//             right++;
//         }
//
//         return minLength == INT_MAX ? "" : s.substr(minLeft, minLength);
// 
//     };

string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for(auto c : t) map[c]++;
        int counter = t.size(), begin = 0 ,  end= 0, d = INT_MAX, head=0;
        while(end < s.size()){
            if(map[s[end++]]-- > 0) counter--;
             while(counter==0){ 
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  
            }  
        }
        return d == __INT_MAX__ ? "" : s.substr(head, d);
}

int main() {
    string x = minWindow("ABDEFGHIBANC","ABC");
    cout << x;
    return 0;
}
