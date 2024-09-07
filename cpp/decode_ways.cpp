//
// Created by Harsha Vardhan on 11/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int toDigit(char c) {
    return c - '0';
}

int numDecodingsHelper(vector<int>& dp, string& s, int index) {
    if (index == s.size()) return 1;
    if (dp[index] != -1) return dp[index];
    int ans = 0;
    if (s[index] != '0') {
        ans = numDecodingsHelper(dp, s, index + 1);
    }
    if (index + 1 < s.size() && s[index] != '0') {
        int t = toDigit(s[index]) * 10 + toDigit(s[index + 1]);
        if (t <= 26) {
            ans = ans + numDecodingsHelper(dp, s, index + 2);
        }
    }
    return dp[index] = ans;
}

int numDecodings(string s) {
    vector<int> dp(s.size() + 1, -1);
    return numDecodingsHelper(dp, s, 0);
}

int main() {
    cout << numDecodings("07") << "\n";
    return 0;
}
