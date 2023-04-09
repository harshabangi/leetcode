//
// Created by Harsha Vardhan on 18/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int maxScoreSightseeingPair(vector<int> &values) {
    vector<int> tmp(values.size());
    for (int i = 0; i < values.size(); i++) {
        tmp[i] = values[i] - i;
    }
    int mx = values[0];
    int ans = INT_MIN;
    for (int i = 1; i < values.size(); i++) {
        ans = max(ans, mx + tmp[i]);
        mx = max(mx, values[i] + i);
    }
    return ans;
}

int main() {
    vector<int> values{2, 9, 5, 6, 3, 4};
    cout << maxScoreSightseeingPair(values) << "\n";
    return 0;
}
