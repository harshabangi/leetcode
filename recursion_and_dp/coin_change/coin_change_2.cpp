//
// Created by Harsha Vardhan on 14/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int changeHelper(vector<vector<int>> &dp, int amount, vector<int> &coins, int idx) {
    if (amount < 0) return 0;
    if (amount == 0) {
        return 1;
    }
    if (dp[amount][idx] != -1) return dp[amount][idx];
    int ans = 0;
    for (int i = idx; i < coins.size(); i++) {
        ans += changeHelper(dp, amount - coins[i], coins, i);
    }
    return dp[amount][idx] = ans;
}


int change(int amount, vector<int> &coins) {
    vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, -1));
    return changeHelper(dp, amount, coins, 0);
}

int main() {
    vector<int> coins{1, 2, 5};
    int amount = 5;
    cout << change(amount, coins) << "\n";
    return 0;
}
