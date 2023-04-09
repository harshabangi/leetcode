//
// Created by Harsha Vardhan on 18/05/22.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 4, 6, 7, 7

void findSubsequencesHelper(vector<int> &nums, int idx, vector<int> tmp, set<vector<int>> &set) {
    if (tmp.size() >= 2) set.insert(tmp);
    for (int i = idx + 1; i < nums.size(); i++) {
        if (nums[i] >= nums[idx]) {
            tmp.push_back(nums[i]);
            findSubsequencesHelper(nums, i, tmp, set);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<vector<int>> ans;
    set<vector<int>> set;
    for (int i = 0; i < nums.size(); i++) {
        vector<int> tmp;
        tmp.push_back(nums[i]);
        findSubsequencesHelper(nums, i, tmp, set);
    }
    for (auto t: set) ans.push_back(t);
    return ans;
}

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

int lengthOfLISHelper1(vector<int> &memo, vector<int> &nums, int idx, int val) {
    if ((idx + 1) >= nums.size()) return 0;
    if (memo[idx] != -1) return memo[idx];
    int ans = 0;
    if (nums[idx + 1] > val) {
        ans = 1 + lengthOfLISHelper1(memo, nums, idx + 1, nums[idx + 1]);
    }
    return memo[idx] = max(ans, lengthOfLISHelper1(memo, nums, idx + 1, nums[idx]));
}

int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    vector<int> memo(n + 1, -1);
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        ans = max(ans, 1 + lengthOfLISHelper(memo, nums, i, nums[i]));
    }
    return ans;
}

int main() {
    vector<int> nums{4, 6, 7, 7};
    vector<vector<int>> ans = findSubsequences(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
