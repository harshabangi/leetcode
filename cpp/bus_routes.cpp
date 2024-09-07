//
// Created by Harsha Vardhan on 31/03/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool node_exists_in_graph(int node, unordered_map<int, vector<int>> graph) {
    return graph.find(node) != graph.end();
}

void print_array(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << ", ";
}

void construct_graph(vector<vector<int>> &routes, unordered_map<int, vector<int>> &graph) {
    for (int i = 0; i < routes.size(); i++) {
        int number_of_nodes = routes[i].size();
        if (number_of_nodes == 1) {
            graph[routes[i][0]] = vector<int>{};
        } else {
            for (int j = 0; j < number_of_nodes - 1; j++) {
                if (node_exists_in_graph(routes[i][j], graph)) {
                    graph[routes[i][j]].push_back(routes[i][j + 1]);
                } else {
                    graph[routes[i][j]] = vector<int>{routes[i][j + 1]};
                }
                if (node_exists_in_graph(routes[i][j + 1], graph)) {
                    graph[routes[i][j + 1]].push_back(routes[i][j]);
                } else {
                    graph[routes[i][j + 1]] = vector<int>{routes[i][j]};
                }
            }
            if (number_of_nodes != 2) {
                graph[routes[i][0]].push_back(routes[i][number_of_nodes - 1]);
                graph[routes[i][number_of_nodes - 1]].push_back(routes[i][0]);
            }
        }
    }
}

void set_all_nodes_visited_to_false(unordered_map<int, bool> &visited, unordered_map<int, vector<int>> graph) {
    for (auto k: graph) {
        visited[k.first] = false;
    }
}

int bfs(unordered_map<int, vector<int>> graph, int source, int target) {
    unordered_map<int, bool> visited;
    set_all_nodes_visited_to_false(visited, graph);
    queue<int> q;
    if (!node_exists_in_graph(source, graph)) return -1;
    q.push(source);
    visited[source] = true;
    int depth = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int front = q.front();
            q.pop();
            for (int j = 0; j < graph[front].size(); j++) {
                if (!visited[graph[front][j]]) {
                    if (graph[front][j] == target) return depth;
                    q.push(graph[front][j]);
                    visited[graph[front][j]] = true;
                }
            }
        }
        
        depth++;
    }
    return -1;
}

int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
    unordered_map<int, vector<int>> graph;
    construct_graph(routes, graph);
    for (auto k: graph) {
        cout << k.first << ": ";
        print_array(k.second);
        cout << "\n";
    }
    return bfs(graph, source, target);
}

int main() {
    vector<vector<int>> routes1{
            {1, 2, 7},
            {3, 6, 7}
    };
    vector<vector<int>> routes2{
            {7,  12},
            {4,  5,  15},
            {6},
            {15, 19},
            {9,  12, 13}
    };
    vector<vector<int>> routes3{
            {24},
            {3, 6,  11, 14, 22},
            {1, 23, 24},
            {0, 6,  14},
            {1, 3,  8,  11, 20}
    };
    cout << numBusesToDestination(routes1, 1, 6) << "\n";
    cout << numBusesToDestination(routes2, 15, 12) << "\n";
    cout << numBusesToDestination(routes3, 20, 8) << "\n";
    return 0;
}