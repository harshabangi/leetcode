//
// Created by Harsha Vardhan on 23/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfitHelper(vector<int> &prices, bool hasStock, int idx, vector<vector<int>> &dp) {
    if (idx >= prices.size()) return 0;
    if (dp[idx][hasStock] != -1) return dp[idx][hasStock];
    int profit;
    if (hasStock) {
        profit = prices[idx] + maxProfitHelper(prices, false, idx + 1, dp);
    } else {
        profit = -prices[idx] + maxProfitHelper(prices, true, idx + 1, dp);
    }
    return dp[idx][hasStock] = max(profit, maxProfitHelper(prices, hasStock, idx + 1, dp));
}

int maxProfit(vector<int> &prices) {
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
    return maxProfitHelper(prices, false, 0, dp);
}

int main() {
    return 0;
}
