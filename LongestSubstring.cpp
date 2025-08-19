#include <iostream>
#include <deque>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> inWindow;     // presence as a set
    deque<char> window;
    int maxSize = 0;

    for (char c : s) {
        // if c is already inside the window, pop from the front
        // until that previous c is removed
        while (inWindow.count(c)) {
            char f = window.front();
            window.pop_front();
            inWindow.erase(f);
        }
        window.push_back(c);
        inWindow[c] = 1;

        if ((int)window.size() > maxSize)
            maxSize = (int)window.size();
    }
    return maxSize;
}

int main() {
    cout << lengthOfLongestSubstring("pwwkew") << "\n"; // 3
    cout << lengthOfLongestSubstring("abba")   << "\n"; // 2
    cout << lengthOfLongestSubstring("dvdf")   << "\n"; // 3
}
