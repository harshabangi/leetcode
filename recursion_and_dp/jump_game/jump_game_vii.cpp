//
// Created by Harsha Vardhan on 22/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool canReachHelper(string &s, int &minJump, int &maxJump, int idx, int n, vector<int> &dp) {
    if (idx == n) return true;
    if (dp[idx] != -1) return dp[idx];
    for (int i = idx + minJump; i <= min((idx + maxJump), n); i++) {
        cout << i << "\n";
        if (s[i] == '0') {
            if (canReachHelper(s, minJump, maxJump, i, n, dp)) return true;
        }
    }
    return dp[idx] = false;
}

bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();
    vector<int> dp(n + 1, -1);
    return canReachHelper(s, minJump, maxJump, 0, n - 1, dp);
}

int main() {
    string s = "011010";
    int minJump = 2, maxJump = 3;
    cout << canReach(s, minJump, maxJump) << "\n";
    return 0;
}
