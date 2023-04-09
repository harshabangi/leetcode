//
// Created by Harsha Vardhan on 29/07/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<int> &color, int node, int &c) {
    color[node] = c;
    for (int i = 0; i < graph[node].size(); i++) {
        if (color[graph[node][i]] != c) {
            dfs(graph, color, graph[node][i], c);
        }
    }
}

long long countPairs(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for (int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> color(n, 0);
    int c = 1;
    for (int i = 0; i < color.size(); i++) {
        if (color[i] == 0) {
            dfs(graph, color, i, c);
        }
        c++;
    }
    unordered_map<long long, long long> umap;
    for (int i = 0; i < color.size(); i++) {
        umap[color[i]]++;
    }
    long long ans = 0;
    for (auto it: umap) {
        ans += it.second * (n - it.second);
    }
    return ans / 2;
}

int main() {
    return 0;
}
