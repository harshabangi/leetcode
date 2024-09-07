//
// Created by Harsha Vardhan on 07/04/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasCycle(vector<vector<int>> graph, vector<bool> &visited, int node) {
//    if (visited[node]) return true;
//    else {
//        visited[node] = true;
//        for (int i = 0; i < graph[node].size(); i++) {
//            if (hasCycle(graph, visited, graph[node][i])) return true;
//        }
//    }
//    return false;

    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()) {
        for (int i = 0; i < q.size(); i++) {
            int t = q.front();
            q.pop();
            for (int j = 0; j < graph[t].size(); j++) {
                if (visited[graph[t][j]]) return true;
                else {
                    visited[graph[t][j]] = true;
                    q.push(graph[t][j]);
                }
            }
        }
    }
    return false;
}

void print(vector<vector<int>> graph) {
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << i << ": " << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> directedGraph(numCourses, vector<int>());
    vector<int> incomingEdges(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++) {
        directedGraph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        incomingEdges[prerequisites[i][0]]++;
    }
    queue<int> q;
    for (int i = 0; i < incomingEdges.size(); i++) {
        if (incomingEdges[i] == 0) q.push(i);
    }
    int res = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (incomingEdges[t] == 0) res++;
        for (int i = 0; i < directedGraph[t].size(); i++) {
            incomingEdges[directedGraph[t][i]]--;
            if (incomingEdges[directedGraph[t][i]] == 0) q.push(directedGraph[t][i]);
        }
    }
    return res == numCourses;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> directedGraph(numCourses, vector<int>());
    vector<int> incomingEdges(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++) {
        directedGraph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        incomingEdges[prerequisites[i][0]]++;
    }
    queue<int> q;
    for (int i = 0; i < incomingEdges.size(); i++) {
        if (incomingEdges[i] == 0) q.push(i);
    }
    vector<int> ans;
    int res = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (incomingEdges[t] == 0) {
            res++;
            ans.push_back(t);
        }
        for (int i = 0; i < directedGraph[t].size(); i++) {
            incomingEdges[directedGraph[t][i]]--;
            if (incomingEdges[directedGraph[t][i]] == 0) q.push(directedGraph[t][i]);
        }
    }
    vector<int> emptyArray;
    return res == numCourses ? ans : emptyArray;
}

int main() {
    vector<vector<int>>
    prerequisites1{
            {1, 0}, {2, 0{},[3, 1],[3, 2]]
            };
            cout << canFinish(2, prerequisites1) << "\n";
            return 0;
    }
