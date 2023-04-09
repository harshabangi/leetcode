//
// Created by Harsha Vardhan on 09/05/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void constructGraph(vector<vector<int>> &graph, int n, vector<int> &manager) {
    for (int i = 0; i < manager.size(); i++) {
        if (manager[i] != -1) {
            graph[manager[i]].push_back(i);
        }
    }
}

int dfs(vector<vector<int>> &graph, int headId, vector<int> &informTime) {
    if (informTime[headId] == 0) return 0;
    int ans = INT_MIN;
    for (int i = 0; i < graph[headId].size(); i++) {
        ans = max(ans, informTime[graph[headId][i]] + dfs(graph, graph[headId][i], informTime));
    }
    return ans;
}

//void dfs(vector<vector<int>> &graph, int headId, vector<int> &informTime, vector<bool> visited, int curr, int &ans) {
//    if (informTime[headId] == 0) {
//        ans = max(ans, curr);
//        return;
//    }
//    for (int i = 0; i < graph[headId].size(); i++) {
//        if (!visited[graph[headId][i]]) {
//            visited[graph[headId][i]] = true;
//            dfs(graph, graph[headId][i], informTime, visited, curr + informTime[graph[headId][i]], ans);
//        }
//    }
//}
//
//int graph_and_trees(vector<vector<int>> &graph, int headId, vector<int> &informTime) {
//    int ans = 0;
//    queue<int> q;
//    vector<int> visited(graph.size(), false);
//    q.push(headId);
//    visited[headId] = true;
//    while (!q.empty()) {
//        int size = q.size();
//        int mx = INT_MIN;
//        for (int i = 0; i < size; i++) {
//            int t = q.front();
//            mx = max(mx, informTime[t]);
//            q.pop();
//            for (int j = 0; j < graph[t].size(); j++) {
//                if (!visited[graph[t][j]] && informTime[graph[t][j]] != 0) {
//                    q.push(graph[t][j]);
//                    visited[graph[t][j]] = true;
//                }
//            }
//        }
//        ans += mx;
//    }
//    return ans;
//}


int numOfMinutes(int n, int headId, vector<int> &manager, vector<int> &informTime) {
    vector<vector<int>> graph(n, vector<int>());
    constructGraph(graph, n, manager);
    vector<bool> visited(n, false);
    return informTime[headId] + dfs(graph, headId, informTime);
}

int main() {
    int n = 7, headId = 6;
    vector<int> manager{1, 2, 3, 4, 5, 6, -1};
    vector<int> informTime{0, 6, 5, 4, 3, 2, 1};
    cout << numOfMinutes(n, headId, manager, informTime) << "\n";
    return 0;
}
