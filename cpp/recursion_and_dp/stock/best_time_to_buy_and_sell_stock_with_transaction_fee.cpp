//
// Created by Harsha Vardhan on 22/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfitHelper(vector<int> &prices, int &fee, int idx, bool hasStock, vector<vector<int>> &dp) {
    if (idx >= prices.size()) return 0;
    if (dp[idx][hasStock] != -1) return dp[idx][hasStock];
    int profit;
    if (hasStock) {
        profit = prices[idx] - fee + maxProfitHelper(prices, fee, idx + 1, false, dp);
    } else {
        profit = -prices[idx] + maxProfitHelper(prices, fee, idx + 1, true, dp);
    }
    return dp[idx][hasStock] = max(profit, maxProfitHelper(prices, fee, idx + 1, hasStock, dp));
}

int maxProfit(vector<int> &prices, int fee) {
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
    return maxProfitHelper(prices, fee, 0, false, dp);
}

int main() {
    vector<int> prices{1, 3, 4, 7, 3, 4, 6, 8};
    int fee = 2;
    cout << maxProfit(prices, fee) << "\n";
    return 0;
}
