#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int &c, vector<vector<int> > &grid, queue<pair<int, int> > &q, vector<vector<bool> > &visited) {
    int n = grid.size();
    int m = grid[0].size();
    int k = 0;
    while (!q.empty()) {
        int size = q.size();
        if (k != 0) c++;
        k++;
        for (int s = 0; s < size; s++) {
            pair<int, int> t = q.front();
            q.pop();
            if (t.first < n && t.first >= 0 && t.second + 1 < m && t.second + 1 >= 0 &&
                grid[t.first][t.second + 1] == 1 && !visited[t.first][t.second + 1]) {
                visited[t.first][t.second + 1] = true;
                grid[t.first][t.second + 1] = 2;
                q.push(make_pair(t.first, t.second + 1));
            }
            if (t.first < n && t.first >= 0 && t.second - 1 < m && t.second - 1 >= 0 &&
                grid[t.first][t.second - 1] == 1 && !visited[t.first][t.second - 1]) {
                visited[t.first][t.second - 1] = true;
                grid[t.first][t.second - 1] = 2;
                q.push(make_pair(t.first, t.second - 1));
            }
            if (t.first + 1 < n && t.first + 1 >= 0 && t.second < m && t.second >= 0 &&
                grid[t.first + 1][t.second] == 1 && !visited[t.first + 1][t.second]) {
                visited[t.first + 1][t.second] = true;
                grid[t.first + 1][t.second] = 2;
                q.push(make_pair(t.first + 1, t.second));
            }
            if (t.first - 1 < n && t.first - 1 >= 0 && t.second < m && t.second >= 0 &&
                grid[t.first - 1][t.second] == 1 && !visited[t.first - 1][t.second]) {
                visited[t.first - 1][t.second] = true;
                grid[t.first - 1][t.second] = 2;
                q.push(make_pair(t.first - 1, t.second));
            }
        }
    }
}

int orangesRotting(vector<vector<int> > &grid) {
    int n = grid.size();
    int m = grid[0].size();
    int c = 0;
    queue<pair<int, int> > q;
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }
    bfs(c, grid, q, visited);
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                flag = true;
                c = -1;
                break;
            }
        }
        if (flag) break;
    }
    return c;
}

int main() {
    vector<vector<int> > v1 = {
            {2, 1, 1},
            {1, 1, 1},
            {0, 1, 2}
    };
    vector<vector<int> > v2 = {
            {0, 2}
    };
    vector<vector<int> > v3 = {
            {2, 1, 1},
            {0, 1, 1},
            {1, 0, 1}
    };
    vector<vector<int> > v4 = {
            {2, 1, 1},
            {1, 1, 0},
            {0, 1, 1}
    };
    vector<vector<int> > v5 = {
            {2, 2},
            {1, 1},
            {0, 0},
            {2, 0}
    };
    cout << orangesRotting(v4);
    return 0;
}

/*
 2, 1, 1
 1, 1, 1
 0, 1, 2

 2, 2, 1
 2, 1, 2
 0, 2, 2
 2, 2, 1
 2, 1, 1
 0, 1, 2

 2, 2, 2
 2, 2, 1
 0, 1, 2
 * */