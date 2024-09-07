//
// Created by Harsha Vardhan on 20/08/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
    unordered_set<int> uset;
    for (int i = 0; i < restricted.size(); i++) {
        uset.insert(restricted[i]);
    }
    vector<vector<int>> graph(n);
    for (int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;


    int count = 0;
    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            int t = q.front();
            q.pop();
            count++;

            for (int j = 0; j < graph[t].size(); j++) {
                int l = graph[t][j];
                if (!visited[l]) {
                    if (uset.find(l) == uset.end()) {
                        visited[l] = true;
                        q.push(l);
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    int n = 7;
    vector<vector<int>> edges {{0,1},{0,2},{0,5},{0,4},{3,2},{6,5}};
    vector<int> restricted{4, 2, 1};
    cout << reachableNodes(n, edges, restricted) << "\n";
    return 0;
}
