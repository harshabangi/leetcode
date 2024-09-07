//
// Created by Harsha Vardhan on 12/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool underBoundary(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

vector<int> dir = {0, 1, 0, -1};

bool
existHelper(vector<vector<char>> &board, string &word, int i, int j, int idx) {
    if (idx == word.size()) {
        return true;
    }
    if (!underBoundary(i, j, board.size(), board[0].size()) || board[i][j] != word[idx]) return false;
    char tmp = board[i][j];
    board[i][j] = '*';
    bool a = existHelper(board, word, i, j + 1, idx + 1);
    if (a) return true;
    bool b = existHelper(board, word, i, j - 1, idx + 1);
    if (b) return true;
    bool c = existHelper(board, word, i + 1, j, idx + 1);
    if (c) return true;
    bool d = existHelper(board, word, i - 1, j, idx + 1);
    if (d) return true;
    board[i][j] = tmp;
    return false;
}

bool
existHelper1(vector<vector<char>> &board, string &word, int i, int j, int idx) {
    if (idx == word.size()) {
        return true;
    }
    if (!underBoundary(i, j, board.size(), board[0].size()) || board[i][j] != word[idx]) return false;
    char tmp = board[i][j];
    board[i][j] = '*';
    for (int k = 0; k < 4; k++) {
        if (existHelper(board, word, i + dir[k], j + dir[(k + 1) % 4], idx + 1)) return true;
    }
    board[i][j] = tmp;
    return false;
}

bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0] && existHelper(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board1{
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    vector<vector<char>> board2{
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    vector<vector<char>> board3{
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    vector<vector<char>> board4{
            {'A', 'A', 'A', 'A', 'A', 'A'},
            {'A', 'A', 'A', 'A', 'A', 'A'},
            {'A', 'A', 'A', 'A', 'A', 'A'},
            {'A', 'A', 'A', 'A', 'A', 'A'},
            {'A', 'A', 'A', 'A', 'A', 'A'},
            {'A', 'A', 'A', 'A', 'A', 'A'}
    };
    cout << exist(board4, "AAAAAAAAAAAAAAB") << '\n';
    return 0;
}
