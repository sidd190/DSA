#include <bits/stdc++.h>
using namespace std;

bool recur(vector<vector<char>> &board, string& word, int i, int j, int curr){
    if(curr == word.size()) return true;
    
    if(i<0 || j < 0 || i >= board.size() || j >= board[0].size()){
        return false;
    }
    if(board[i][j] != word[curr]){
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '#';

    bool found = recur(board, word, i+1, j, curr + 1) || 
                 recur(board, word, i-1, j, curr + 1) || 
                 recur(board, word, i, j+1, curr + 1) || 
                 recur(board, word, i, j-1, curr + 1);

    board[i][j] = temp;
    return found;
};

bool exist(vector<vector<char>>& board, string& word){
    unordered_map<char,int> cnt;
    for (auto& row : board)
        for (char c : row)PalP
            cnt[c]++;

    for (char c : word)
        if (--cnt[c] < 0)
            return false;

    for(int i = 0; i<board.size(); i++){
        for(int j= 0; j<board[0].size(); j++){
            if(recur(board, word, i, j, 0)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    
    return 0;
}