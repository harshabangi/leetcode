//
// Created by Harsha Vardhan on 12/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int minOperationsHelper(vector<vector<int>> &dp, vector<int> &nums, int x, int i, int j) {
    if (x == 0) return 0;
    if (i > j) return 1e9;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = min(1 + minOperationsHelper(dp, nums, x - nums[i], i + 1, j),
                          1 + minOperationsHelper(dp, nums, x - nums[j], i, j - 1));
}

int minOperations(vector<int> &nums, int x) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = minOperationsHelper(dp, nums, x, 0, n - 1);
    return ans >= 1e9 ? -1 : ans;
}

int main() {
    vector<int> nums{3, 2, 20, 1, 1, 3};
    int x = 10;
    cout << minOperations(nums, x) << "\n";
    return 0;
}
