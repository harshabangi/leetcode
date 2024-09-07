//
// Created by Harsha Vardhan on 26/07/22.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 * 2 1 1 1
 * 1 1 2 1
 * */

int countServers(vector<vector<int>> &grid) {
    int ans = 0, m = grid.size(), n = grid[0].size();
    vector<int> row(m, 0);
    vector<int> col(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                row[i] += 1;
                col[j] += 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                if (row[i] > 1 || col[j] > 1) ans += 1;
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> grid{
            {1, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
    };
    cout << countServers(grid) << "\n";
    return 0;
}
