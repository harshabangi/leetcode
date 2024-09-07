//
// Created by Harsha Vardhan on 30/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int shortestCommonSupersequenceHelper(string str1, string str2, int idx1, int idx2, vector<vector<int>> &dp) {
    if (idx1 >= str1.size() || idx2 >= str2.size()) return 0;
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    int ans = 0;
    if (str1[idx1] == str2[idx2]) {
        ans = 1 + shortestCommonSupersequenceHelper(str1, str2, idx1 + 1, idx2 + 1, dp);
    }
    return dp[idx1][idx2] = max(ans, max(
            shortestCommonSupersequenceHelper(str1, str2, idx1 + 1, idx2, dp),
            shortestCommonSupersequenceHelper(str1, str2, idx1, idx2 + 1, dp)));
}

string shortestCommonSupersequence(string str1, string str2) {
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, -1));
    int t = shortestCommonSupersequenceHelper(str1, str2, 0, 0, dp);
    int p, q;
    bool flag = false;
    for (int i = dp.size() - 1; i >= 0; i--) {
        for (int j = dp[i].size() - 1; j >= 0; j--) {
            if (dp[i][j] == t) {
                p = i;
                q = j;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    if (p > q) return
    return "";
}

int main() {
    cout << shortestCommonSupersequence("abac", "cab") << "\n";
    return 0;
}
