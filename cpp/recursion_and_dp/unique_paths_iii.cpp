//
// Created by Harsha Vardhan on 12/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void uniquePathsIIIHelper(vector<vector<int>> grid, vector<vector<bool>> visited, int i, int j, int &ans, int len,
                          int obstacles) {
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] != -1 && !visited[i][j]) {
        visited[i][j] = true;
        if (grid[i][j] == 2) {
            if ((len + 1) == (grid.size() * grid[0].size() - obstacles)) ans += 1;
            return;
        }
        uniquePathsIIIHelper(grid, visited, i, j + 1, ans, len + 1, obstacles);
        uniquePathsIIIHelper(grid, visited, i, j - 1, ans, len + 1, obstacles);
        uniquePathsIIIHelper(grid, visited, i + 1, j, ans, len + 1, obstacles);
        uniquePathsIIIHelper(grid, visited, i - 1, j, ans, len + 1, obstacles);
    }
}

int uniquePathsIII(vector<vector<int>> &grid) {
    int ans = 0;
    int m = grid.size(), n = grid[0].size();
    int p, q;
    int obstacles = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                p = i;
                q = j;
            }
            if (grid[i][j] == -1) {
                obstacles += 1;
            }
        }
    }
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    uniquePathsIIIHelper(grid, visited, p, q, ans, 0, obstacles);
    return ans;
}

int main() {
    vector<vector<int>> grid1{{1, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 2, -1}};

    vector<vector<int>> grid2{{1, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 2}};

    vector<vector<int>> grid3{{0, 1},
                              {2, 0}};
    cout << uniquePathsIII(grid3) << "\n";
    return 0;
}
