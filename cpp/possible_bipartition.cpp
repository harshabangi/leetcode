//
// Created by Harsha Vardhan on 10/04/22.
//


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<vector<int>> dp) {
    for (int i = 1; i < dp.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < dp[i].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

bool hasCycle(vector<vector<int>> graph, vector<int> &color, int node) {
    queue<int> q;
    q.push(node);
    color[node] = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int parent = q.front();
            q.pop();
            for (int j = 0; j < graph[parent].size(); j++) {
                int child = graph[parent][j];
                if (color[parent] == color[child]) {
                    return false;
                } else if (color[child] == -1) {
                    color[child] = !color[parent];
                    q.push(child);
                }
            }
        }
    }
    return true;
}

bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
    vector<vector<int>> graph(n + 1, vector<int>());
    for (int i = 0; i < dislikes.size(); i++) {
        graph[dislikes[i][0]].push_back(dislikes[i][1]);
        graph[dislikes[i][1]].push_back(dislikes[i][0]);
    }
    vector<int> color(n + 1, -1);
    for (int i = 1; i < color.size(); i++) {
        if (color[i] == -1) {
            if (hasCycle(graph, color, i)) return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> dislikes{
            {1, 2},
            {1, 3},
            {2, 3}
    };
    cout << possibleBipartition(3, dislikes) << "\n";
    return 0;
}
