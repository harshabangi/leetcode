//
// Created by Harsha Vardhan on 24/04/22.
//

#include <iostream>
#include <vector>

using namespace std;


int coinChangeHelper(vector<int> &coins, int amount) {
    if (amount < 0) return INT_MAX;
    if (amount == 0) return 0;
    int mn = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        mn = min(mn, 1 + coinChangeHelper(coins, amount - coins[i]));
    }
    return mn;
}

int coinChange(vector<int> &coins, int amount) {
    int ans = coinChangeHelper(coins, amount);
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    vector<int> coins1{1, 2, 5};
    vector<int> coins2{2};
    vector<int> coins3{1};
    cout << coinChange(coins2, 3) << "\n";
    return 0;
}
