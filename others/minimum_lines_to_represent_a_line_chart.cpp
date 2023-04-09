//
// Created by Harsha Vardhan on 04/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

int minimumLines(vector<vector<int>> &stockPrices) {
    sort(stockPrices.begin(), stockPrices.end());
    double prevSlope = INT_MIN;
    int ans = 0;
    for (int i = 0; i < stockPrices.size() - 1; i++) {
        double slope = (stockPrices[i + 1][1] - stockPrices[i][1]) / double(stockPrices[i + 1][0] - stockPrices[i][0]);
        if (slope != prevSlope) {
            ans += 1;
            prevSlope = slope;
        }
    }
    return ans;
}

int main() {
    return 0;
}
