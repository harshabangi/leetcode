//
// Created by Harsha Vardhan on 22/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

long long M = 1e9 + 7;


long long numRollsToTargetHelper(int n, int k, int target, vector<vector<long long>> &dp) {
    cout << target << "\n";
    if (target == 0) return 1;
    if (n == 0) return 0;
    if (dp[n][target] != -1) return dp[n][target];
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
        if (target >= i) {
            ans += numRollsToTargetHelper(n - 1, k, target - i, dp);
        }
    }
    return dp[n][target] = ans;
}

long long numRollsToTarget(int n, int k, int target) {
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));
    return numRollsToTargetHelper(n, k, target, dp);
}

int main() {
    cout << numRollsToTarget(30, 30, 500);
    return 0;
}
