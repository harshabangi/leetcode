//
// Created by Harsha Vardhan on 09/04/22.
//

#include <iostream>
#include <vector>

using namespace std;



//void longestIncreasingPathHelper(int p, int q, const vector<vector<int>> &matrix, int distance, int &maxDistance,
//                                 vector<vector<bool>> visited) {
//    if (isUnderBoundary(p + 1, q, matrix.size(), matrix[0].size()) && matrix[p + 1][q] > matrix[p][q] &&
//        !visited[p + 1][q]) {
//        longestIncreasingPathHelper(p + 1, q, matrix, distance + 1, maxDistance, visited);
//    }
//    if (isUnderBoundary(p - 1, q, matrix.size(), matrix[0].size()) && matrix[p - 1][q] > matrix[p][q] &&
//        !visited[p - 1][q]) {
//        longestIncreasingPathHelper(p - 1, q, matrix, distance + 1, maxDistance, visited);
//    }
//    if (isUnderBoundary(p, q + 1, matrix.size(), matrix[0].size()) && matrix[p][q + 1] > matrix[p][q] &&
//        !visited[p][q + 1]) {
//        longestIncreasingPathHelper(p, q + 1, matrix, distance + 1, maxDistance, visited);
//    }
//    if (isUnderBoundary(p, q - 1, matrix.size(), matrix[0].size()) && matrix[p][q - 1] > matrix[p][q] &&
//        !visited[p][q - 1]) {
//        longestIncreasingPathHelper(p, q - 1, matrix, distance + 1, maxDistance, visited);
//    }
//
//    if (distance > maxDistance) {
//        maxDistance = distance;
//    }
//}

//int longestIncreasingPath(vector<vector<int>> &matrix) {
//    int ans = INT_MIN;
//    int m = matrix.size();
//    int n = matrix[0].size();
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            int l = 1;
//            vector<vector<bool>> visited(m, vector<bool>(n, false));
//            visited[i][j] = true;
//            longestIncreasingPathHelper(i, j, matrix, l, l, visited);
//            ans = max(ans, l);
//        }
//    }
//    return ans;
//}

void print(vector<vector<int>>dp) {
    for (int i = 0; i < dp.size(); i++)
        for (int j = 0; j < dp[i].size(); j++)
            cout << dp[i][j] << " ";
        cout << "\n";
}

bool isUnderBoundary(int p, int q, int m, int n) {
    return (p >= 0 && p < m && q >= 0 && q < n);
}

int longestIncreasingPathHelper(int p, int q, const vector<vector<int>> &matrix, int lastVal,
                                vector<vector<int>>& dp) {
    int m = matrix.size();
    int n = matrix[0].size();
    if (!isUnderBoundary(p, q, m, n)) return -1;
    if (matrix[p][q] <= lastVal) return -1;
    if (dp[p][q] != -1) return dp[p][q];

    int currVal = matrix[p][q];
    int a = 1 + longestIncreasingPathHelper(p + 1, q, matrix, currVal, dp);
    int b = 1 + longestIncreasingPathHelper(p - 1, q, matrix, currVal, dp);
    int c = 1 + longestIncreasingPathHelper(p, q + 1, matrix, currVal, dp);
    int d = 1 + longestIncreasingPathHelper(p, q - 1, matrix, currVal, dp);

    dp[p][q] = max(max(max(a, b), c), d);
    return dp[p][q];
}

int longestIncreasingPath(vector<vector<int>> &matrix) {
    int ans = INT_MIN;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -1) {
                ans = max(ans, longestIncreasingPathHelper(i, j, matrix, INT_MIN, dp) + 1);
                print(dp);
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix1{
            {9, 9, 4},
            {6, 6, 8},
            {2, 1, 1}
    };
    vector<vector<int>> matrix2{
            {3, 4, 5},
            {3, 2, 6},
            {2, 2, 1}
    };
    vector<vector<int>> matrix3{
            {1, 2, 3}
    };
    cout << longestIncreasingPath(matrix1) << "\n";
    cout << longestIncreasingPath(matrix2) << "\n";
    cout << longestIncreasingPath(matrix3) << "\n";
    return 0;
}
