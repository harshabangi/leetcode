//
// Created by Harsha Vardhan on 15/02/22.
//

#include <iostream>
#include <vector>

using namespace std;


bool isRightNumberInCell(vector<vector<char>> board, int p, int q, char c) {
    for (int k = 0; k < 9; k++) {
        if (board[p][k] == c) return false;
        if (board[k][q] == c) return false;
    }
    int sr = (p / 3) * 3;
    int sc = (q / 3) * 3;
    for (int m = 0; m < sr + 3; m++) {
        for (int n = 0; n < sc + 3; n++) {
            if (board[m][n] == c) return false;
        }
    }
    return true;
}

vector<vector<char>> solveSudokuHelper(vector<vector<char>> board, int p, int q) {
    if (q == 9) {
        p += 1;
        q = 0;
        solveSudokuHelper(board, p, q);
    }
    if (p == 8 && q == 8) {
        return board;
    }
    for (int i = p; i < 9; i++) {
        for (int j = q; j < 9; j++) {
            if (board[i][j] == '.') {
                for (int l = 1; l <= 9; l++) {
                    char c = l + '0';
                    if (isRightNumberInCell(board, i, j, c)) {
                        board[i][j] = c;
                        solveSudokuHelper(board, i, j + 1);
                        board[i][j] = '.';
                    }
                }
            }
        }
    }
    return board;
}

void solveSudoku(vector<vector<char>> &board) {
    vector<vector<char>> ans = solveSudokuHelper(board, 0, 0);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    return 0;
}
