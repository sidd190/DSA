#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int characterReplacement(string s, int k) {
    int size = s.length();
    if(size<=k) return size;
    int temp = k;
    int left = 0; int right = 1; int maxl=0;


    for(int i = 0; i< size; i++){
        if(s[left] == s[right]){
            if(right< size-1) right++;
        }
        else{
            temp--;
            if(temp < 0){
                left++;
                right = left + 1;
                temp = k;
            }
            else{
                right++;
           }
        }
        maxl = max(right - left, maxl);
    }
    return maxl;
}

int main() {
    int x = characterReplacement("AAAA",2);
    cout<<x;
    return 0;
}