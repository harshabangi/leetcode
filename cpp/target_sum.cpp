//
// Created by Harsha Vardhan on 12/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

int findTargetSumWaysHelper(vector<vector<int>> dp, vector<int> nums, int p, int c, int target) {
    if (p == nums.size()) {
        if (c == target) return 1;
        else return 0;
    }
    if (dp[p][c] != -1) {
        return dp[p][c];
    }
    dp[p][c] = findTargetSumWaysHelper(dp, nums, p + 1, c + nums[p], target) +
               findTargetSumWaysHelper(dp, nums, p + 1, c - nums[p], target);
    return dp[p][c];
}

int findTargetSumWays(vector<int> &nums, int target) {
    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
    return findTargetSumWaysHelper(dp, nums, 0, 0, target);
}

int main() {
    vector<int> nums1{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    vector<int> nums2{1, 1, 1, 1, 1};
    cout << findTargetSumWays(nums2, 3);
    return 0;
}
