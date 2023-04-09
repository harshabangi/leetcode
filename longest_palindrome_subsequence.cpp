//
// Created by Harsha Vardhan on 07/05/22.
//

#include <iostream>
#include <vector>

using namespace std;


int longestPalindromeSubseqHelper(vector<vector<int>> &dp, string &s, int i, int j) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    if (s[i] == s[j]) {
        ans = max(ans, 2 + longestPalindromeSubseqHelper(dp, s, i + 1, j - 1));
    }
    return dp[i][j] = max(ans, max(longestPalindromeSubseqHelper(dp, s, i + 1, j),
                                   longestPalindromeSubseqHelper(dp, s, i, j - 1)));
}

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return longestPalindromeSubseqHelper(dp, s, 0, s.size() - 1);
}

int main() {
    cout << longestPalindromeSubseq("bbbab") << "\n";
    return 0;
}
