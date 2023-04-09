//
// Created by Harsha Vardhan on 03/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool underBoundary(int m, int n, int i, int j) {
    return (i >= 0 && i < m && j >= 0 && j < n);
}

int maximalSquareHelper(vector<vector<int>>& dp, vector<vector<char>> &matrix, int p, int q) {
    if (!underBoundary(matrix.size(), matrix[0].size(), p, q) || matrix[p][q] == '0') return 0;
    if (dp[p][q] != -1) return dp[p][q];
    int a = maximalSquareHelper(dp, matrix, p + 1, q);
    int b = maximalSquareHelper(dp, matrix, p, q + 1);
    int c = maximalSquareHelper(dp, matrix, p + 1, q + 1);
    return dp[p][q] = 1 + min(a, min(b, c));
}

int maximalSquare(vector<vector<char>> &matrix) {
    int ans = INT_MIN;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                if (dp[i][j] != -1) {
                    ans = max(ans, dp[i][j]);
                } else {
                    ans = max(ans, maximalSquareHelper(dp, matrix, i, j));
                }
            }
        }
    }
    return ans * ans;
}

int main() {
    vector<vector<char>> matrix{
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'}
    };
    cout << maximalSquare(matrix) << "\n";
    return 0;
}
