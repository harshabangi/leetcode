//
// Created by Harsha Vardhan on 29/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int minSwaps(vector<int> &arr) {
    vector<pair<int, int>> positions(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        positions[i] = {arr[i], i};
    }
    sort(positions.begin(), positions.end());
    vector<bool> vis(arr.size(), false);
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (vis[i] || positions[i].second == i) {
            continue;
        }
        int cycleSize = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = true;
            j = positions[j].second;
            cycleSize++;
        }
        if (cycleSize > 0) {
            ans += (cycleSize - 1);
        }
    }
    return ans;
}

int main() {
    vector<int> arr{1, 5, 4, 3, 2};
    cout << minSwaps(arr) << "\n";
    return 0;
}
