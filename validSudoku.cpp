#include<iostream>
#include<map>
#include<vector>
using namespace std;

void isValidSudoku(vector<vector<char>>& board){
    
    //Check rows
    for(int i =0; i<9;i++){
        for(int j = 0; j<9; j++){
            char current = board[i][j];
            if(current == '.') continue;
            for( int k = 0;k<9;k++){
                if(k != j && board[i][k] == current){
                    cout << "Invalid Sudoku: Duplicate in row " << i << endl;
                    return;
                }
            }
        }
    }

    //Check columns
    for(int j = 0; j<9; j++){
        for(int i = 0; i<9; i++){
            char current = board[i][j];
            if(current == '.') continue;
            for(int k = 0; k<9; k++){
                if(k != i && board[k][j] == current){
                    cout << "Invalid Sudoku: Duplicate in column " << j << endl;
                    return;
                }
            }
        }
    }

    //Check for duplicate in each 3x3 sub-box
    map<char, bool> subBox;
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            subBox.clear();
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    char current = board[i + k][j + l];
                    if (current == '.') continue;
                    if (subBox[current]) {
                        cout << "Invalid Sudoku: Duplicate '" << current << "' in sub-box starting at (" << i << ", " << j << ")" << endl;
                        return;
                    }
                    subBox[current] = true;
                }
            }
        }
    }

    // Alternative approach using bitset (commented out)
        // bitset<9> rows[9], cols[9], boxes[9];
        // for (int i = 0; i < 9; ++i) {
        //     for (int j = 0; j < 9; ++j) {
        //         if (!isdigit(board[i][j])) continue;
        //         int num = board[i][j] - '1';
        //         int box = (i / 3) * 3 + (j / 3);
        //         if (rows[i][num] || cols[j][num] || boxes[box][num]) return false;
        //         rows[i][num] = cols[j][num] = boxes[box][num] = 1;
        //     }
        // }
        // return true;
    cout<<"Valid Sudoku" << endl;
}

int main(){
    vector<vector<char>> board = {
        {'.','.','.','.','.','.','5','.','.'}
        ,{'.','.','.','.','.','.','.','.','.'}
        ,{'.','.','.','.','.','.','.','.','.'}
        ,{'9','3','.','.','2','.','4','.','.'}
        ,{'.','.','7','.','.','.','3','.','.'}
        ,{'.','.','.','.','.','.','.','.','.'}
        ,{'.','.','.','3','4','.','.','.','.'}
        ,{'.','.','.','.','.','3','.','.','.'}
        ,{'.','.','.','.','.','5','2','.','.'}
    };


    isValidSudoku(board);
}