//
// Created by Harsha Vardhan on 11/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool isMatchHelper(string &a, string &b, int idx1, int idx2, vector<vector<int>> &dp) {
    if (idx1 >= a.size() && idx2 >= b.size()) return true;
    if (idx1 < a.size() && idx2 >= b.size()) return false;
    if (idx1 == a.size()) {
        return b[idx2] == '*' && isMatchHelper(a, b, idx1, idx2 + 1, dp);
    }
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

    bool ans = false;
    if (b[idx2] == '*') {
        ans |= (isMatchHelper(a, b, idx1, idx2 + 1, dp)
                || isMatchHelper(a, b, idx1 + 1, idx2 + 1, dp)
                || isMatchHelper(a, b, idx1 + 1, idx2, dp));
    } else if (b[idx2] == '?') {
        ans |= isMatchHelper(a, b, idx1 + 1, idx2 + 1, dp);
    } else {
        ans |= (a[idx1] == b[idx2]) && isMatchHelper(a, b, idx1 + 1, idx2 + 1, dp);
    }
    return dp[idx1][idx2] = ans;
}

bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
    return isMatchHelper(s, p, 0, 0, dp);
}

int main() {
    cout << isMatch("adceb", "*a*b") << "\n";
    return 0;
}
