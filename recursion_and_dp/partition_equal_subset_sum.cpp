//
// Created by Harsha Vardhan on 01/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool canPartitionHelper(vector<vector<int>> &dp, vector<int> nums, int sum, int t, int idx) {
    if (idx >= nums.size() || t > sum / 2) return false;
    if (t == sum / 2) {
        return true;
    }
    if (dp[t][idx] != -1) {
        return dp[t][idx] == 1;
    }
    return dp[t][idx] == canPartitionHelper(dp, nums, sum, t + nums[idx], idx + 1) ||
           canPartitionHelper(dp, nums, sum, t, idx + 1);
}

bool canPartition(vector<int> &nums) {
    int sum = 0;
    cout << nums.size() << "\n";
    for (int i = 0; i < nums.size(); i++) sum += nums[i];
    cout << sum << "\n";
    if (sum % 2 != 0) return false;
    vector<vector<int>> dp(sum + 1, vector<int>(nums.size() + 1, -1));
    return canPartitionHelper(dp, nums, sum, 0, 0);
}

int main() {
    vector<int> nums1{1, 2, 3, 5};
    vector<int> nums2{1, 5, 11, 5};
    vector<int> nums3{10, 2, 3, 5, 6};
    vector<int> nums4{100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                      100, 100, 100, 100, 100, 100, 100, 100, 99, 97};
    cout << canPartition(nums4) << "\n";
    return 0;
}
