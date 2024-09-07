//
// Created by Harsha Vardhan on 08/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int jumpHelper(vector<int>& dp, vector<int> &nums, int index) {
    if (index == nums.size() - 1) return 0;
    if (dp[index] != -1) return dp[index];
    int ans = 1e9;
    for (int i = 1; i <= nums[index]; i++) {
        if (index + i < nums.size()) {
            ans = min(ans, 1 + jumpHelper(dp, nums, index + i));
        }
    }
    return dp[index] = ans;
}

int jump(vector<int> &nums) {
    vector<int> dp(nums.size() + 1, -1);
    return jumpHelper(dp,nums, 0);
}

int main() {
    vector<int> nums1{2, 3, 1, 1, 4};
    vector<int> nums2{2, 3, 0, 1, 4};
    cout << jump(nums2) << "\n";
    return 0;
}
