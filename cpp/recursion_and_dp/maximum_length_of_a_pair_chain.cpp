//
// Created by Harsha Vardhan on 18/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool comparator(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

int findLongestChainHelper(vector<vector<int>> &pairs, int idx, vector<int> &memo) {
    if (idx >= pairs.size()) return 0;
    if (memo[idx] != -1) return memo[idx];
    int ans = 0;
    for (int i = idx + 1; i < pairs.size(); i++) {
        if (pairs[idx][1] < pairs[i][0]) {
            ans = max(ans, 1 + findLongestChainHelper(pairs, i, memo));
        }
    }
    return memo[idx] = ans;
}

int findLongestChain(vector<vector<int>> &pairs) {
    vector<int> memo(pairs.size() + 1, -1);
    sort(pairs.begin(), pairs.end(), comparator);
    return 1 + findLongestChainHelper(pairs, 0, memo);
}

int main() {
    vector<vector<int>> pairs{
            {1, 2},
            {2, 3},
            {3, 4}
    };
    cout << findLongestChain(pairs) << "\n";
    return 0;
}
