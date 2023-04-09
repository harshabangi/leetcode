//
// Created by Harsha Vardhan on 21/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfitHelper(vector<int> &prices, int i, bool hasStock, vector<vector<int>> &memo) {
    if (i >= prices.size()) return 0;
    if (memo[i][hasStock] != -1) return memo[i][hasStock];
    int profit = 0;
    if (!hasStock) {
        profit = max(profit, -prices[i] + maxProfitHelper(prices, i + 1, true, memo));
    } else {
        profit = max(profit, prices[i] + maxProfitHelper(prices, i + 2, false, memo));
    }
    return memo[i][hasStock] = max(profit, maxProfitHelper(prices, i + 1, hasStock, memo));
}

int maxProfit(vector<int> &prices) {
    vector<vector<int>> memo(prices.size() + 1, vector<int>(2, -1));
    return maxProfitHelper(prices, 0, false, memo);
}

int main() {
    vector<int> prices{1};
    cout << maxProfit(prices) << "\n";
    return 0;
}
