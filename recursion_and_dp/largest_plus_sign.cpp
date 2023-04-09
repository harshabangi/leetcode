//
// Created by Harsha Vardhan on 03/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int memo[500][500][4] = {};
int DIR[5] = {0, 1, 0, -1, 0};

bool underBoundary(int n, int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

int dp(vector<vector<int>> &grid, int p, int q, int n, int d) {
    if (!underBoundary(n, p, q) || grid[p][q] == 0) return 0;
    if (memo[p][q][d] != 0) return memo[p][q][d];
    return memo[p][q][d] = 1 + dp(grid, p + DIR[d], q + DIR[d + 1], n, d);
}

int
orderOfLargestPlusSignHelper(const int n, vector<vector<int>> &grid, int p, int q) {
    if (!underBoundary(n, p, q) || grid[p][q] == 0) return 0;
    int ans = INT_MAX;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, dp(grid, p, q, n, i));
    }
    return ans;
}

int orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
    vector<vector<int>> grid(n, vector<int>(n, 1));
    for (int i = 0; i < mines.size(); i++) {
        grid[mines[i][0]][mines[i][1]] = 0;
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, orderOfLargestPlusSignHelper(n, grid, i, j));
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> mines1{
            {0, 0}
    };
    vector<vector<int>> mines2{
            {0, 0}
    };
    cout << orderOfLargestPlusSign(1, mines2) << "\n";
    return 0;
}

