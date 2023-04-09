//
// Created by Harsha Vardhan on 27/05/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int maxEnvelopesHelper(vector<vector<int>> &envelopes, int idx, vector<int> &dp) {
    if (idx >= envelopes.size()) return 0;
    if (dp[idx] != -1) return dp[idx];
    int ans = 0;
    for (int i = idx + 1; i < envelopes.size(); i++) {
        if (envelopes[i][0] > envelopes[idx][0] && envelopes[i][1] > envelopes[idx][1]) {
            ans = max(ans, 1 + maxEnvelopesHelper(envelopes, i, dp));
        }
    }
    return dp[idx] = ans;
}

int maxEnvelopes(vector<vector<int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end());
    int n = envelopes.size();
    vector<int> dp(n + 1, -1);
    int ans = 0;
    for (int i = 0; i < envelopes.size(); i++) {
        ans = max(ans, 1 + maxEnvelopesHelper(envelopes, i, dp));
    }
    return ans;
}

int main() {
    vector<vector<int>> envelopes{
            {5, 4},
            {6, 4},
            {6, 7},
            {2, 3}
    };
    cout << maxEnvelopes(envelopes);
    return 0;
}
