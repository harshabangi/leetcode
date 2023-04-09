//
// Created by Harsha Vardhan on 26/08/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool withinBoundary(int p, int q, int m, int n) {
    return p >= 0 && p < m && q >= 0 && q < n;
}

vector<int> dir{0, 1, 0, -1};

int shortestPathHelper(vector<vector<int>> &grid, int x, int y, int k, vector<vector<vector<int>>> &dp) {
    if (dp[x][y][k] != -1) return dp[x][y][k];

    if (x == grid.size() - 1 && y == grid[0].size() - 1) return 0;

    int t = grid[x][y];
    grid[x][y] = -1;
    int ans = INT_MAX;



    for (int i = 0; i < 4; i++) {
        int a = x + dir[i % 4], b = y + dir[(i + 1) % 4];

        if (withinBoundary(a, b, grid.size(), grid[0].size()) && grid[a][b] != -1) {
            if (grid[a][b] == 0) {
                int l = shortestPathHelper(grid, a, b, k, dp);
                if (l < INT_MAX) {
                    ans = min(ans, 1 + l);
                }
            } else if (grid[a][b] == 1 && k > 0) {
                int l = shortestPathHelper(grid, a, b, k - 1, dp);
                if (l < INT_MAX) {
                    ans = min(ans, 1 + l);
                }
            }
        }
    }
    grid[x][y] = t;
    return dp[x][y][k] = ans;
}

int shortestPath(vector<vector<int>> &grid, int k) {
    vector<vector<vector<int>>> dp(grid.size() + 1, vector<vector<int>>(grid[0].size() + 1, vector<int>(k + 1, -1)));
    int ans = shortestPathHelper(grid, 0, 0, k, dp);
    return ans == INT_MAX ? -1 : ans;
}

int main() {
//    vector<vector<int>> grid{
//            {0, 1, 1, 0}
//    };
    vector<vector<int>> grid{
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
            {0, 1, 0, 1, 1, 1, 1, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
    };

//    vector<vector<int>> grid{
//            {0, 0, 0},
//            {1, 1, 0},
//            {0, 0, 0},
//            {0, 1, 1},
//            {0, 0, 0}
//    };
    cout << shortestPath(grid, 1) << "\n";
    return 0;
}
