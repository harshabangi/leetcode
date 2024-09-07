//
// Created by Harsha Vardhan on 10/05/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool underBoundary(int p, int q, int m, int n) {
    return (p >= 0 && p < m && q >= 0 && q < n);
}

int dfs(vector<vector<int>> &arr, vector<vector<bool>> visited, int p, int q) {
    if (arr[p][q] == 9) return 0;
    int left = 1e9, right = 1e9, top = 1e9, down = 1e9;
    int m = arr.size(), n = arr[0].size();
    if (underBoundary(p, q - 1, m, n) && !visited[p][q - 1] && arr[p][q - 1] != 0) {
        visited[p][q - 1] = true;
        left = 1 + dfs(arr, visited, p, q - 1);
    }
    if (underBoundary(p, q + 1, m, n) && !visited[p][q + 1] && arr[p][q + 1] != 0) {
        visited[p][q + 1] = true;
        right = 1 + dfs(arr, visited, p, q + 1);
    }
    if (underBoundary(p - 1, q, m, n) && !visited[p - 1][q] && arr[p - 1][q] != 0) {
        visited[p - 1][q] = true;
        top = 1 + dfs(arr, visited, p - 1, q);
    }
    if (underBoundary(p + 1, q, m, n) && !visited[p + 1][q] && arr[p + 1][q] != 0) {
        visited[p + 1][q] = true;
        down = 1 + dfs(arr, visited, p + 1, q);
    }
    return min(left, min(right, min(top, down)));
}

int bfs(vector<vector<int>> &arr, int m, int n) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    q.push({0, 0});
    visited[0][0] = true;
    int count = 0;
    while (!q.empty()) {
        int size = q.size();
        count += 1;
        for (int i = 0; i < size; i++) {
            pair<int, int> t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            if (underBoundary(x + 1, y, m, n) && !visited[x + 1][y] && arr[x + 1][y] != 0) {
                if (arr[x + 1][y] == 9) {
                    return count;
                }
                visited[x + 1][y] = true;
                q.push({x + 1, y});
            }
            if (underBoundary(x - 1, y, m, n) && !visited[x - 1][y] && arr[x - 1][y] != 0) {
                if (arr[x - 1][y] == 9) {
                    return count;
                }
                visited[x - 1][y] = true;
                q.push({x - 1, y});
            }
            if (underBoundary(x, y + 1, m, n) && !visited[x][y + 1] && arr[x][y + 1] != 0) {
                if (arr[x][y + 1] == 9) {
                    return count;
                }
                visited[x][y + 1] = true;
                q.push({x, y + 1});
            }
            if (underBoundary(x, y - 1, m, n) && !visited[x][y - 1] && arr[x][y - 1] != 0) {
                if (arr[x][y - 1] == 9) {
                    return count;
                }
                visited[x][y - 1] = true;
                q.push({x, y - 1});
            }
        }
    }
    return -1;
}

int demolitionRobotBfs(vector<vector<int>> &arr) {
    return bfs(arr, arr.size(), arr[0].size());
}

int demolitionRobotDfs(vector<vector<int>> &arr) {
    vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));
    visited[0][0] = true;
    int ans = dfs(arr, visited, 0, 0);
    return ans >= 1e9 ? -1 : ans;
}

int main() {
    vector<vector<int>> arr{
            {1, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 9}
    };
    cout << demolitionRobotBfs(arr) << "\n";
    return 0;
}
