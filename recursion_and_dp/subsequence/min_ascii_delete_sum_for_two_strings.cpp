//
// Created by Harsha Vardhan on 30/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int minimumDeleteSumHelper(string &s1, string &s2, int idx1, int idx2, vector<vector<int>> &dp) {
    if (idx1 >= s1.size() || idx2 >= s2.size()) return 0;
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    int ans = 0;
    if (s1[idx1] == s2[idx2]) {
        ans = s1[idx1] + minimumDeleteSumHelper(s1, s2, idx1 + 1, idx2 + 1, dp);
    }
    return dp[idx1][idx2] = max(ans, max(
            minimumDeleteSumHelper(s1, s2, idx1 + 1, idx2, dp),
            minimumDeleteSumHelper(s1, s2, idx1, idx2 + 1, dp)));
}

int minimumDeleteSum(string s1, string s2) {
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    int k = minimumDeleteSumHelper(s1, s2, 0, 0, dp);
    int ans = 0;
    string l = s1 + s2;
    for (int i = 0; i < l.size(); i++) {
        ans += l[i];
    }
    return ans - (2 * k);
}

int main() {
    cout << minimumDeleteSum("delete", "leet") << "\n";
    return 0;
}
