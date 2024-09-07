//
// Created by Harsha Vardhan on 09/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool canJumpHelper(vector<int> &dp, vector<int> &nums, int idx) {
    if (idx >= nums.size()) return false;
    if (idx == nums.size() - 1) return true;
    if (dp[idx] != -1) return dp[idx];
    bool ans = false;
    for (int i = 1; i <= nums[idx]; i++) {
        ans = canJumpHelper(dp, nums, idx + i);
        if (ans) {
            dp[idx] = true;
            break;
        }
    }
    return dp[idx] = ans;
}

bool canJump(vector<int> &nums) {
    vector<int> dp(nums.size() + 1, -1);
    return canJumpHelper(dp, nums, 0);
}

int main() {
    vector<int> nums1{2, 3, 1, 1, 4};
    vector<int> nums2{3, 2, 1, 0, 4};
    cout << canJump(nums1) << "\n";
    cout << canJump(nums2) << "\n";
    return 0;
}
