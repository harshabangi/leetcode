//
// Created by Harsha Vardhan on 31/08/22.
//

#include <iostream>
#include <vector>

using namespace std;

int maxResultHelper(vector<int> &nums, int k, int idx, vector<int> &dp) {
    if (idx >= nums.size()) return INT_MIN;
    if (idx == nums.size() - 1) return nums[idx];
    if (dp[idx] != -1) return dp[idx];
    int ans = INT_MIN;
    int l = nums.size() - 1;
    for (int i = idx + 1; i <= min(l, idx + k); i++) {
        ans = max(ans, nums[idx] + maxResultHelper(nums, k, i, dp));
    }
    return dp[idx] = ans;
}

int maxResult(vector<int> &nums, int k) {
    vector<int> dp(nums.size() + 1, -1);
    return maxResultHelper(nums, k, 0, dp);
}

int main() {
    vector<int> nums{1, -1, -2, 4, -7, 3};
    cout << maxResult(nums, 2) << "\n";
    return 0;
}
