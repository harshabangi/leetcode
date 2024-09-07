//
// Created by Harsha Vardhan on 06/05/22.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int maxSumAfterPartitioningHelper(vector<int> &dp, vector<int> &arr, int k, int idx) {
    if (idx >= arr.size()) {
        return 0;
    }
    if (dp[idx] != -1) return dp[idx];
    int mx = INT_MIN, ans = INT_MIN, c = 1;
    for (int i = idx; i < arr.size() && i < (idx + k); i++) {
        mx = max(mx, arr[i]);
        ans = max(ans, (c * mx) + maxSumAfterPartitioningHelper(dp, arr, k, i + 1));
        c++;
    }
    return dp[idx] = ans;
}

int maxSumAfterPartitioning(vector<int> &arr, int k) {
    vector<int> dp(arr.size() + 1, -1);
    return maxSumAfterPartitioningHelper(dp, arr, k, 0);
}

int main() {
    vector<int> arr{1, 15, 7, 9};
    int k = 3;
    cout << maxSumAfterPartitioning(arr, k) << "\n";
    return 0;
}
