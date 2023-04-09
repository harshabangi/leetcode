//
// Created by Harsha Vardhan on 24/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int dp[1001][201][2];

int maxProfitHelper(vector<int> &prices, int idx, int k, bool hasStock) {
    if (k == 0 || idx >= prices.size()) return 0;
    if (dp[idx][k][hasStock] != -1) return dp[idx][k][hasStock];
    int profit = 0;
    if (!hasStock) {
        profit = -prices[idx] + maxProfitHelper(prices, idx + 1, k - 1, true);
    } else {
        profit = prices[idx] + maxProfitHelper(prices, idx + 1, k - 1, false);
    }
    return dp[idx][k][hasStock] = max(profit, maxProfitHelper(prices, idx + 1, k, hasStock));
}

int maxProfit(int k, vector<int> &prices) {
    memset(dp, -1, sizeof(dp));
    return maxProfitHelper(prices, 0, 2 * k, false);
}

int main() {
    vector<int> prices{3, 2, 6, 5, 0, 3};
    cout << maxProfit(2, prices) << "\n";
    return 0;
}