//
// Created by Harsha Vardhan on 04/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

//int dp[101][101][201] = {-1};

bool
isInterleaveHelper(string &s1, string &s2, string &s3, int idx1, int idx2, int idx3, vector<vector<vector<int>>> &dp) {
    if (idx3 >= s3.size()) return true;
    if (dp[idx1][idx2][idx3] != -1) return dp[idx1][idx2][idx3];
    bool ans = false;
    if (idx1 < s1.size() && s1[idx1] == s3[idx3]) {
        ans |= isInterleaveHelper(s1, s2, s3, idx1 + 1, idx2, idx3 + 1, dp);
    }
    if (idx2 < s2.size() && s2[idx2] == s3[idx3]) {
        ans |= isInterleaveHelper(s1, s2, s3, idx1, idx2 + 1, idx3 + 1, dp);
    }
    return dp[idx1][idx2][idx3] = ans;
}

bool isInterleave(string s1, string s2, string s3) {
    vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -1)));
    if ((s1 + s2).size() != s3.size()) return false;
    return isInterleaveHelper(s1, s2, s3, 0, 0, 0, dp);
}

int main() {
    cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << "\n";
    return 0;
}
