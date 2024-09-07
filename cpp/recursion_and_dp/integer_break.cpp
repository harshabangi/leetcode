//
// Created by Harsha Vardhan on 18/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int integerBreakHelper(int n, int k, vector<int> &dp) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];
    int ans = 1;
    for (int i = 1; i <= k; i++) {
        if (n - i >= 0) {
            ans = max(ans, i * integerBreakHelper(n - i, k, dp));
        }
    }
    return dp[n] = ans;
}

int integerBreak(int n) {
    vector<int> dp(n + 1, -1);
    return integerBreakHelper(n, n % 2 == 0 ? n / 2 : n / 2 + 1, dp);
}

int main() {
    cout << integerBreak(10) << "\n";
    return 0;
}
