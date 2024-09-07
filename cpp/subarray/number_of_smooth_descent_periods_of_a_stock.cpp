//
// Created by Harsha Vardhan on 12/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

long long getDescentPeriods(vector<int> &prices) {
    long long ans = 0, prev = prices[0] + 1;
    for (int i = 0, j = 0; i < prices.size(); i++) {
        if (prev - prices[i] != 1) {
            j = i;
        }
        prev = prices[i];
        ans += (i - j + 1);
    }
    return ans;
}

int main() {
    vector<int> prices{3, 2, 1, 4};
    cout << getDescentPeriods(prices) << "\n";
    return 0;
}
