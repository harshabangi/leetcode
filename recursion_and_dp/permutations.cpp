//
// Created by Harsha Vardhan on 28/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void permuteHelper(vector<int> nums, vector<int> tmp, vector<vector<int>> &ans, vector<bool> b, int idx) {
    if (tmp.size() == nums.size()) {
        ans.push_back(tmp);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (i != idx && nums[i] == nums[idx]) continue;
        if (!b[i]) {
            b[i] = true;
            tmp.push_back(nums[i]);
            permuteHelper(nums, tmp, ans, b, i+1);
            tmp.pop_back();
            b[i] = false;
        }
    }
}


vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<bool> b(nums.size(), false);
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    permuteHelper(nums, tmp, ans, b, 0);
    return ans;
}


int main() {
    vector<int> nums{1, 1, 2};
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}