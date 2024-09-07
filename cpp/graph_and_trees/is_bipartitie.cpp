//
// Created by Harsha Vardhan on 03/04/22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> graph, vector<int> &colour, int vertex) {
    queue<int> q;
    q.push(vertex);
    colour[vertex] = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int front = q.front();
            q.pop();
            for (int j = 0; j < graph[front].size(); j++) {
                if (colour[graph[front][j]] == colour[front]) return false;
                if (colour[graph[front][j]] == -1) {
                    q.push(graph[front][j]);
                    colour[graph[front][j]] = !colour[front];
                }
            }
        }
    }
    return true;
}

bool dfs(vector<vector<int>> graph, vector<int> &colour, int vertex) {
    for (int i = 0; i < graph[vertex].size(); i++) {
        if (colour[graph[vertex][i]] == colour[vertex]) return false;
        if (colour[graph[vertex][i]] == -1) {
            colour[graph[vertex][i]] = !colour[vertex];
            if (!dfs(graph, colour, graph[vertex][i])) return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph) {
    int numberOfVertices = graph.size();
    vector<int> colour(numberOfVertices, -1);
    for (int i = 0; i < numberOfVertices; i++) {
        if (colour[i] == -1) {
            if (!bfs(graph, colour, i)) return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> edges{
            {1},
            {0, 3},
            {3},
            {1, 2}
    };
    cout << isBipartite(edges) << "\n";
    return 0;
}
