//
// Created by Harsha Vardhan on 12/02/22.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void subsetsWithDupHelper(int idx, vector<int> nums, vector<int> tmp, vector<vector<int>> &ans) {
    ans.push_back(tmp);
    for (int i = idx; i < nums.size(); i++) {
        if (i != idx && nums[i] == nums[i - 1]) continue;
        tmp.push_back(nums[i]);
        subsetsWithDupHelper(i + 1, nums, tmp, ans);
        tmp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    subsetsWithDupHelper(0, nums, tmp, ans);
    return ans;
}

int main() {
    vector<int> nums{1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
