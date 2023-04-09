//
// Created by Harsha Vardhan on 25/07/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findCheapestPriceHelper(vector<vector<pair<int, int>>> &graph, vector<vector<int>> &dp, int src, int dst, int k) {
    if (src == dst) {
        return 0;
    }
    if (k < 0) {
        return INT_MAX;
    }
    if (dp[src][k] != -1) return dp[src][k];
    int ans = INT_MAX;

    for (int i = 0; i < graph[src].size(); i++) {
        int nextStop = graph[src][i].first;
        int cost = graph[src][i].second;
        int currCost = findCheapestPriceHelper(graph, dp, nextStop, dst, k - 1);
        if (currCost < INT_MAX) {
            ans = min(ans, cost + currCost);
        }
    }
    return dp[src][k] = ans;
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < flights.size(); i++) {
        graph[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    int t = findCheapestPriceHelper(graph, dp, src, dst, k);
    return t == INT_MAX ? -1 : t;
}

int main() {
    int n = 4;
    vector<vector<int>> flights{
            {0, 1, 100},
            {1, 2, 100},
            {2, 0, 100},
            {1, 3, 600},
            {2, 3, 200}
    };
    int src = 0, dst = 3, k = 1;
    cout << findCheapestPrice(n, flights, src, dst, k) << "\n";
    return 0;
}
