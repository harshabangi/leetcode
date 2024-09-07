//
// Created by Harsha Vardhan on 03/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool underBoundary(int m, int n, int i, int j) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

int countSquaresHelper(vector<vector<int>> &dp, vector<vector<int>> &matrix, int p, int q) {
    if (!underBoundary(matrix.size(), matrix[0].size(), p, q) || matrix[p][q] == 0) return 0;
    if (dp[p][q] != -1) return dp[p][q];

    int a = countSquaresHelper(dp, matrix, p, q + 1);
    int b = countSquaresHelper(dp, matrix, p + 1, q);
    int c = countSquaresHelper(dp, matrix, p + 1, q + 1);
    cout << a << b << c << "\n";
    return dp[p][q] = 1 + min(a, min(b, c));
}

int countSquares(vector<vector<int>> &matrix) {
    int ans = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                if (dp[i][j] != -1) {
                    ans += dp[i][j];
                } else {
                    ans += countSquaresHelper(dp, matrix, i, j);
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix1{
            {0, 1, 1, 1},
            {1, 1, 1, 1},
            {0, 1, 1, 1}
    };
    vector<vector<int>> matrix2{
            {1, 0, 1},
            {1, 1, 0},
            {1, 1, 0}
    };
    vector<vector<int>> matrix3{
            {1, 1},
            {1, 1}
    };
    cout << countSquares(matrix3) << "\n";
    return 0;
}
