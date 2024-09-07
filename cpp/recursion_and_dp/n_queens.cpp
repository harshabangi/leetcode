//
// Created by Harsha Vardhan on 14/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool is_queen_in_attack(vector<string> board, int n, int r, int c) {
    // vertical attack
    for (int i = r - 1; i >= 0; i--) {
        if (board[i][c] == 'Q') return true;
    }
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return true;
    }
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return true;
    }
    return false;
}

void solveNQueensHelper(vector<string> board, int n, int r, vector<vector<string>> &ans) {
    if (r > n - 1) {
        ans.push_back(board);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (!is_queen_in_attack(board, n, r, j)) {
            board[r][j] = 'Q';
            solveNQueensHelper(board, n, r + 1, ans);
            board[r][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    solveNQueensHelper(board, n, 0, ans);
    return ans;
}

int main() {
    vector<vector<string>> ans = solveNQueens(4);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
