//
// Created by Harsha Vardhan on 12/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void subsetsHelper(int idx, vector<int> nums, vector<int> tmp, vector<vector<int>> &ans) {
    ans.push_back(tmp);
    for (int i = idx; i < nums.size(); i++) {
        tmp.push_back(nums[i]);
        subsetsHelper(i + 1, nums, tmp, ans);
        tmp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> tmp;
    subsetsHelper(0, nums, tmp, ans);
    return ans;
}

int main() {
    vector<int> nums{1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
