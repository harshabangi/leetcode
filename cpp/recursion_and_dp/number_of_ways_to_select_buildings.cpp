//
// Created by Harsha Vardhan on 29/08/22.
//

#include <iostream>
#include <vector>

using namespace std;

long long numberOfWaysHelper(string &s, int idx, int prev, int l, vector<vector<vector<long long>>> &dp) {
    if (l == 0) return 1;
    if (idx >= s.size()) {
        return 0;
    }

    if (dp[idx][prev][l] != -1) return dp[idx][prev][l];
    long long ans = 0;
    if (s[idx] - '0' != prev) {
        ans += numberOfWaysHelper(s, idx + 1, s[idx] - '0', l - 1, dp);
    }
    ans += numberOfWaysHelper(s, idx + 1, prev, l, dp);
    return dp[idx][prev][l] = ans;
}

long long numberOfWays(string s) {
    int n = s.size();
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(3, vector<long long>(4, -1)));
    return numberOfWaysHelper(s, 0, 2, 3, dp);
}

int main() {
    cout << numberOfWays("0001100100") << "\n";
    return 0;
}
