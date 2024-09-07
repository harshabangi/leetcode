//
// Created by Harsha Vardhan on 19/07/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

bool underBoundary(int p, int q, int m, int n) {
    return p >= 0 && p < m && q >= 0 && q < n;
}

vector<int> dir{-1, 0, 1, 0};

void dfs(vector<vector<int>> &grid, int i, int j, queue<pair<int, int>> &q) {
    for (int k = 0; k < 4; k++) {
        int x = i + dir[k % 4];
        int y = j + dir[(k + 1) % 4];
        if (underBoundary(x, y, grid.size(), grid[0].size()) && grid[x][y] == 1) {
            grid[x][y] = -1;
            q.push({x, y});
            dfs(grid, x, y, q);
        }
    }
}

int bfs(queue<pair<int, int>> &q, vector<vector<int>> &grid, int m, int n) {
    int res = 0;

    while (!q.empty()) {
        int size = q.size();
        res++;
        for (int i = 0; i < size; i++) {
            pair<int, int> front = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int x = front.first + dir[j % 4];
                int y = front.second + dir[(j + 1) % 4];
                if (underBoundary(x, y, m, n) && grid[x][y] != -1) {
                    if (grid[x][y] == 1) return res - 1;
                    q.push({x, y});
                    grid[x][y] = -1;
                }
            }
        }
    }
    return res - 1;
}

int shortestBridge(vector<vector<int>> &grid) {
    bool flag = false;
    queue<pair<int, int>> q;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m && !flag; i++) {
        for (int j = 0; j < n && !flag; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = -1;
                q.push({i, j});
                dfs(grid, i, j, q);
                flag = true;
            }
        }
    }
    print(grid);
    return bfs(q, grid, m, n);
}

// 0110101
// 1, 2, 3, 4

int main() {
    vector<vector<int>> grid{
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1},
            {1, 0, 1, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
    };
    cout << shortestBridge(grid) << "\n";
    return 0;
}
