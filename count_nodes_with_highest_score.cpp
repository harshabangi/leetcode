//
// Created by Harsha Vardhan on 28/07/22.
//

#include<iostream>
#include <vector>

using namespace std;

long long dfs(vector<vector<int>> &graph, int node, vector<long long> &dp) {
    if (dp[node] != -1) return dp[node];
    int ans = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        ans += dfs(graph, graph[node][i], dp);
    }
    return dp[node] = ans;
}

int countHighestScoreNodes(vector<int> &parents) {
    int n = parents.size();
    vector<vector<int>> graph(n);
    long long ans = n - 1;
    for (int i = 1; i < n; i++) {
        graph[parents[i]].push_back(i);
    }

    vector<long long> scores(n);
    vector<int> innerNodes;
    for (int i = 0; i < graph.size(); i++) {
        if (!graph[i].empty()) {
            innerNodes.push_back(i);
        } else {
            scores[i] = n - 1;
        }
    }

    vector<long long> dp(n, -1);

    for (int i = 0; i < innerNodes.size(); i++) {
        int node1 = graph[innerNodes[i]][0];
        long long a = dfs(graph, node1, dp);
        long long b = 0;

        if (graph[innerNodes[i]].size() > 1) {
            int node2 = graph[innerNodes[i]][1];
            b = dfs(graph, node2, dp);
        }
        long long score;
        if (b == 0) {
            if (parents[innerNodes[i]] == -1) {
                score = a;
            } else {
                score = a * (n - 1 - a);
            }
        } else {
            if (parents[innerNodes[i]] == -1) {
                score = a * b;
            } else {
                score = a * b * (n - 1 - (a + b));
            }
        }
        scores[innerNodes[i]] = score;
        ans = max(ans, score);
    }

    int f = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] == ans) f += 1;
    }
    return f;
}

int main() {
    vector<int> parents{-1, 2, 0};
    cout << countHighestScoreNodes(parents) << "\n";
    return 0;
}
