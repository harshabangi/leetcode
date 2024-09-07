//
// Created by Harsha Vardhan on 24/08/22.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

bool withinBoundary(int p, int q, int m, int n) {
    return p >= 0 && p < m && q >= 0 && q < n;
}

int maxDistance(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> dir{0, 1, 0, -1};
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) q.push({i, j});
        }
    }
    int count = 0;
    while (!q.empty()) {
        int size = q.size();
        count++;

        for (int i = 0; i < size; i++) {
            pair<int, int> front = q.front();
            q.pop();

            for (int j = 0; j < dir.size(); j++) {
                int a = front.first + dir[j % 4];
                int b = front.second + dir[(j + 1) % 4];
                if (withinBoundary(a, b, m, n) && grid[a][b] == 0) {
                    q.push({a, b});
                    grid[a][b] = 1;
                }
            }
        }
    }
    return count;
}

int main() {
    return 0;
}
