//
// Created by Harsha Vardhan on 25/07/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool withinBoundary(int p, int q, int m, int n) {
    return p >= 0 && p < m && q >= 0 && q < n;
}

vector<int> dRow{0, 1, 0, -1};
vector<int> dCol{-1, 0, 1, 0};

int minimumEffortPathHelper1(vector<vector<int>> &heights, int i, int j, vector<vector<int>> &dp) {
    cout << i << ", " << j << "\n";
    if (i == heights.size() - 1 && j == heights[0].size() - 1) return INT_MIN;
    if (dp[i][j] != -1) return dp[i][j];

    int tmp = heights[i][j];
    heights[i][j] = -1;
    int ans = INT_MAX;
    for (int k = 0; k < 4; k++) {
        int x = i + dRow[k];
        int y = j + dCol[k];
        if (withinBoundary(x, y, heights.size(), heights[0].size()) && heights[x][y] != -1) {
            int l = minimumEffortPathHelper1(heights, x, y, dp);
            int t = max(abs(heights[i][j] - heights[x][y]), l);
            ans = min(ans, t);
        }
    }
    heights[i][j] = tmp;
    return dp[i][j] = ans;
}

int minimumEffortPath(vector<vector<int>> &heights) {
//    int ans = INT_MAX;
//    vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
//    minimumEffortPathHelper(heights, 0, 0, ans, visited, INT_MIN);
//    return ans;
    vector<vector<int>> dp(heights.size() + 1, vector<int>(heights[0].size() + 1, -1));
    return minimumEffortPathHelper1(heights, 0, 0, dp);
}

void
minimumEffortPathHelper(vector<vector<int>> &heights, int i, int j, int &ans, vector<vector<bool>> visited, int t) {
    if (i == heights.size() - 1 && j == heights[0].size() - 1) {
        ans = min(ans, t);
        return;
    }
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int x = i + dRow[k];
        int y = j + dCol[k];

        if (withinBoundary(x, y, heights.size(), heights[0].size()) && !visited[x][y]) {
            minimumEffortPathHelper(heights, x, y, ans, visited, max(t, abs(heights[x][y] - heights[i][j])));
        }
    }
}


int main() {
    vector<vector<int>> heights{
            {1, 2, 2},
            {3, 8, 2},
            {5, 3, 5}
    };
    cout << minimumEffortPath(heights) << "\n";
    return 0;
}
