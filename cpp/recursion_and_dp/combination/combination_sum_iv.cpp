//
// Created by Harsha Vardhan on 06/05/22.
//


#include <iostream>
#include <vector>

using namespace std;

int combinationSum4Helper(vector<int> &dp, vector<int> &nums, int target) {
    if (target < 0) return 0;
    if (target == 0) return 1;
    if (dp[target] != -1) return dp[target];
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans += combinationSum4Helper(dp, nums, target - nums[i]);
    }
    return dp[target] = ans;
}

int combinationSum4(vector<int> &nums, int target) {
    vector<int> dp(target + 1, -1);
    return combinationSum4Helper(dp, nums, target);
}

int main() {
    vector<int> nums{1, 2, 3};
    int target = 4;
    cout << combinationSum4(nums, target);
    return 0;
}
