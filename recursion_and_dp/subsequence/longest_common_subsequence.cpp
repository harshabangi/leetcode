//
// Created by Harsha Vardhan on 29/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequenceHelper(string& text1, string& text2, int idx1, int idx2, vector<vector<int>> &dp) {
    if (idx1 >= text1.size() || idx2 >= text2.size()) return 0;
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    int ans = 0;
    if (text1[idx1] == text2[idx2]) {
        ans = 1 + longestCommonSubsequenceHelper(text1, text2, idx1 + 1, idx2 + 1, dp);
    }
    return dp[idx1][idx2] = max(ans, max(longestCommonSubsequenceHelper(text1, text2, idx1 + 1, idx2, dp),
                                         longestCommonSubsequenceHelper(text1, text2, idx1, idx2 + 1, dp)));
}

int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
    return longestCommonSubsequenceHelper(text1, text2, 0, 0, dp);
}

int main() {
    string text1 = "abc", text2 = "def";
    cout << longestCommonSubsequence(text1, text2) << "\n";
    return 0;
}
