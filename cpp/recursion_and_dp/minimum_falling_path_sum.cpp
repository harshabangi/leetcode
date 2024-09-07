//
// Created by Harsha Vardhan on 28/04/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool under_boundary(int m, int n, int p, int q) {
    return p >= 0 && p < m && q >= 0 && q < n;
}

int minFallingPathSumHelper(vector<vector<int>> &dp, vector<vector<int>> matrix, int m, int n, int p, int q) {
    if (dp[p][q] != -1) return dp[p][q];
    if (p == m - 1) return matrix[p][q];
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;

    if (under_boundary(m, n, p + 1, q - 1)) {
        a = minFallingPathSumHelper(dp, matrix, m, n, p + 1, q - 1);
    }
    if (under_boundary(m, n, p + 1, q)) {
        b = minFallingPathSumHelper(dp, matrix, m, n, p + 1, q);
    }
    if (under_boundary(m, n, p + 1, q + 1)) {
        c = minFallingPathSumHelper(dp, matrix, m, n, p + 1, q + 1);
    }
    return dp[p][q] = matrix[p][q] + min(a, min(b, c));
}

int minFallingPathSum(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, minFallingPathSumHelper(dp, matrix, m,n, 0, i));
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix{
            {2, 1, 3},
            {6, 5, 4},
            {7, 8, 9}
    };
    cout << minFallingPathSum(matrix) << "\n";
    return 0;
}
