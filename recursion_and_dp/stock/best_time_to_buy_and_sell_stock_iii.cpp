//
// Created by Harsha Vardhan on 24/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int dp[100001][4][2] = {-1};

int maxProfitHelper(vector<int> &prices, int idx, int n, bool hasStock) {
    if (n == 0 || idx >= prices.size()) return 0;
    if (dp[idx][n][hasStock] != -1) return dp[idx][n][hasStock];
    int profit = 0;
    if (!hasStock) {
        profit = -prices[idx] + maxProfitHelper(prices, idx + 1, n - 1, true);
    } else {
        profit = prices[idx] + maxProfitHelper(prices, idx + 1, n - 1, false);
    }
    return dp[idx][n][hasStock] = max(profit, maxProfitHelper(prices, idx + 1, n, hasStock));
}

int maxProfit(vector<int> &prices) {
    return maxProfitHelper(prices, 0, 4, false);
}

int main() {
    vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << "\n";
    return 0;
}
