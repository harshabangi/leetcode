//
// Created by Harsha Vardhan on 19/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool underBoundary(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

int updateMatrixHelper(vector<vector<int>> &mat, int i, int j, int m, int n, vector<vector<int>> &ans,
                       vector<vector<bool>> &visited) {
    if (!underBoundary(i, j, m, n)) return 0;
    if (visited[i][j]) return 0;
    if (mat[i][j] == 0) return 0;
    if (ans[i][j] != -1) return ans[i][j];
    visited[i][j] = true;
    int a = 1 + updateMatrixHelper(mat, i + 1, j, m, n, ans, visited);
    int b = 1 + updateMatrixHelper(mat, i - 1, j, m, n, ans, visited);
    int c = 1 + updateMatrixHelper(mat, i, j + 1, m, n, ans, visited);
    int d = 1 + updateMatrixHelper(mat, i, j - 1, m, n, ans, visited);
    return ans[i][j] = min(a, min(b, min(c, d)));
}

vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> ans(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                ans[i][j] = 0;
            } else {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                ans[i][j] = updateMatrixHelper(mat, i, j, m, n, ans, visited);
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> mat{
            {0, 1, 0, 1, 1},
            {1, 1, 0, 0, 1},
            {0, 0, 0, 1, 0},
            {1, 0, 1, 1, 1},
            {1, 0, 0, 0, 1}
    };
    vector<vector<int>> ans = updateMatrix(mat);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
