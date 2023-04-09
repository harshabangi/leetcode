//
// Created by Harsha Vardhan on 09/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int robHelper(vector<int> &dp, vector<int> &nums, int idx) {
    if (idx >= nums.size()) return 0;
    if (dp[idx] != -1) return dp[idx];
    int ans = 0;
    for (int i = idx + 2; i < nums.size(); i++) {
        ans = max(ans, nums[i] + robHelper(dp, nums, i));
    }
    return dp[idx] = ans;
}

int rob(vector<int> &nums) {
    if (nums.size() == 1) return nums[0];
    vector<int> dp(nums.size() + 1, -1);
    return max((nums[0] + robHelper(dp, nums, 0)), (nums[1] + robHelper(dp, nums, 1)));
}

int main() {
    vector<int> nums{1, 1};
    cout << rob(nums) << "\n";
    return 0;
}
