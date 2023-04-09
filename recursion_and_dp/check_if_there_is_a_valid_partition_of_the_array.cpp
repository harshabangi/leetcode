//
// Created by Harsha Vardhan on 20/08/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool validPartitionHelper(vector<int> &nums, int idx, vector<int> &dp) {
    if (idx == nums.size()) return true;
    if (idx > nums.size()) return false;
    if (dp[idx] != -1) return dp[idx];
    bool ans = false;

    if (idx + 1 < nums.size()) {
        if (nums[idx] != nums[idx + 1]) {
            ans |= false;
        } else ans |= validPartitionHelper(nums, idx + 2, dp);
    }
    if (idx + 2 < nums.size()) {
        if (!((nums[idx] == nums[idx + 1] && nums[idx + 1] == nums[idx + 2]) ||
              ((nums[idx + 1] == (nums[idx] + 1)) && (nums[idx + 2] == (nums[idx + 1] + 1))))) {
            ans |= false;
        } else {
            ans |= validPartitionHelper(nums, idx + 3, dp);
        }
    }
    return dp[idx] = ans;
}

bool validPartition(vector<int> &nums) {
    vector<int> dp(nums.size() + 1, -1);
    return validPartitionHelper(nums, 0, dp);
}


int main() {
    vector<int> nums{4, 4, 4, 5, 6};
    cout << validPartition(nums) << "\n";
    return 0;
}
