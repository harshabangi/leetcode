//
// Created by Harsha Vardhan on 04/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLISHelper(vector<int> &memo, vector<int> &nums, int idx, int val) {
    if (idx == nums.size()) return 0;
    if (memo[idx] != -1) return memo[idx];
    int ans = 0;
    for (int i = idx + 1; i < nums.size(); i++) {
        if (nums[i] > val) {
            ans = max(ans, 1 + lengthOfLISHelper(memo, nums, i, nums[i]));
        }
    }
    return memo[idx] = ans;
}

int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> memo(n + 1, -1);
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (memo[i] != -1) {
            ans = max(ans, memo[i]);
        } else {
            ans = max(ans, 1 + lengthOfLISHelper(memo, nums, i, nums[i]));
        }
    }
    return ans;
}

int main() {
    vector<int> nums{5, 7, -24, 12, 13, 2, 3, 12, 5, 6, 35};
    cout << lengthOfLIS(nums) << "\n";
    return 0;
}
