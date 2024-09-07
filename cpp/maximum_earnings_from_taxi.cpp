//
// Created by Harsha Vardhan on 07/08/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long
maxTaxiEarningsHelper(int n, vector<vector<int>> &rides, int i, int prevRide, unordered_map<string, int> &umap) {
    if (i >= rides.size()) return 0;
    string k = to_string(i) + "-" + to_string(prevRide);
    if (umap.find(k) != umap.end()) return umap[k];
    long long ans = 0;
    if (prevRide == -1 || rides[i][0] >= rides[prevRide][1]) {
        ans = max(ans, (rides[i][1] - rides[i][0]) + rides[i][2] + maxTaxiEarningsHelper(n, rides, i + 1, i, umap));
    }
    return umap[k] = max(ans, maxTaxiEarningsHelper(n, rides, i + 1, prevRide, umap));
}

long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
    sort(rides.begin(), rides.end());
    unordered_map<string, int> umap;
    return maxTaxiEarningsHelper(n, rides, 0, -1, umap);
}

int main() {
    vector<vector<int>> rides{
            {1,  6,  1}, // 6
            {3,  10, 2}, // 9
            {10, 12, 3}, // 5
            {11, 12, 2}, // 3
            {12, 15, 2}, // 7
            {13, 18, 1}, // 6
    };
    cout << maxTaxiEarnings(20, rides) << "\n";
    return 0;
}
