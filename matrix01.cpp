//
// Created by Harsha Vardhan on 09/07/22.
//

#include <iostream>
#include <vector>
#include <queue>


using namespace std;

bool underBoundary(int p, int q, int m, int n) {
    return p >= 0 && p < m && q >= 0 && q < n;
}

struct Node {
    int x;
    int y;
    int level;

    Node(int x, int y, int level) : x(x), y(y), level(level) {}
};

vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));
    queue<Node> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                ans[i][j] = 0;
                q.push(Node(i, j, 0));
                visited[i][j] = true;
            }
        }
    }

    vector<int> dir{0, -1, 0, 1};
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node front = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int x = front.x + dir[j % 4];
                int y = front.y + dir[(j + 1) % 4];
                if (underBoundary(x, y, m, n) && !visited[x][y]) {
                    q.push({x, y, front.level + 1});
                    ans[x][y] = front.level + 1;
                    visited[x][y] = true;
                }
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}
