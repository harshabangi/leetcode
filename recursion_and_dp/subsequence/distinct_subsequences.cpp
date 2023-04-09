//
// Created by Harsha Vardhan on 29/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int numDistinctHelper(string &s, string &t, int idx1, int idx2, vector<vector<int>> &dp) {
    if (idx1 >= s.size() && idx2 >= t.size()) return 1;
    if (idx2 >= t.size()) return 1;
    if (idx1 >= s.size()) return 0;

    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    int ans = 0;
    if (s[idx1] == t[idx2]) {
        ans += numDistinctHelper(s, t, idx1 + 1, idx2 + 1, dp);
    }
    ans += numDistinctHelper(s, t, idx1 + 1, idx2, dp);
    return dp[idx1][idx2] = ans;
}

int numDistinct(string s, string t) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
    return numDistinctHelper(s, t, 0, 0, dp);
}

int main() {
    cout << numDistinct("babgbag", "bag") << "\n";
    return 0;
}
