//
// Created by Harsha Vardhan on 04/06/22.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct comparator {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.first < b.first;
    }
};

long long maximumImportance(int n, vector<vector<int>> &roads) {
    vector<int> incomingEdges(n, 0);
    for (int i = 0; i < roads.size(); i++) {
        incomingEdges[roads[i][0]] += 1;
        incomingEdges[roads[i][1]] += 1;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
    for (int i = 0; i < incomingEdges.size(); i++) {
        pq.push({incomingEdges[i], i});
    }

    unordered_map<int, int> umap;
    int count = n;
    while (!pq.empty()) {
        umap[pq.top().second] = count;
        pq.pop();
        count--;
    }
    long long ans = 0;
    for (int i = 0; i < roads.size(); i++) {
        ans += umap[roads[i][0]] + umap[roads[i][1]];
    }
    return ans;
}

int main() {
    vector<vector<int>> roads{
            {0, 1},
            {1, 2},
            {2, 3},
            {0, 2},
            {1, 3},
            {2, 4}
    };
    int n = 5;
    return 0;
}
