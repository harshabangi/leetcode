//
// Created by Harsha Vardhan on 09/02/22.
//

#include <iostream>
#include <vector>

using namespace std;


int
getMaximumGoldHelper(vector<vector<int>> &dp, vector<vector<int>> grid, vector<vector<bool>> visited, int i, int j) {
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != 0 && !visited[i][j]) {
        if (dp[i][j] != -1) return dp[i][j];
        visited[i][j] = true;
        int a = getMaximumGoldHelper(dp, grid, visited, i - 1, j);
        int b = getMaximumGoldHelper(dp, grid, visited, i + 1, j);
        int c = getMaximumGoldHelper(dp, grid, visited, i, j - 1);
        int d = getMaximumGoldHelper(dp, grid, visited, i, j + 1);
        return dp[i][j] = grid[i][j] + max(a, max(b, max(c, d)));
    }
    return 0;
}

void print(vector<vector<int>> dp) {
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

int getMaximumGold(vector<vector<int>> &grid) {
    int mx = INT_MIN;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 0 && i == 4 && j == 2) {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
                int k = getMaximumGoldHelper(dp, grid, visited, i, j);
                cout << i << ", " << j << ": " << k << "\n";
                mx = max(mx, k);
                cout << "===============\n";
                print(dp);
            }
        }
    }
    return mx;
}

int main() {
    vector<vector<int>> grid1{{0,  12, 18, 0,  10, 2, 28, 28},
                              {6,  21, 38, 35, 36, 3, 22, 28},
                              {34, 4,  33, 0,  14, 0, 29, 13},
                              {25, 28, 7,  0,  10, 0, 31, 0}};

    vector<vector<int>> grid2{{0, 6, 0},
                              {5, 8, 7},
                              {0, 9, 0}};

    vector<vector<int>> grid3{{1, 0, 7},
                              {2, 0, 6},
                              {3, 4, 5},
                              {0, 3, 0},
                              {9, 0, 20}};

    vector<vector<int>> grid4{
            {1, 0, 7, 0, 0,  0},
            {2, 0, 6, 0, 1,  0},
            {3, 5, 6, 7, 4,  2},
            {4, 3, 1, 0, 2,  0},
            {3, 0, 5, 0, 20, 0}
    };
    cout << getMaximumGold(grid4) << "\n";
    return 0;
}