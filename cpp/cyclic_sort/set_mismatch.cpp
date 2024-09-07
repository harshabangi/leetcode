//
// Created by Harsha Vardhan on 16/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> findErrorNums(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
        int idx = nums[i] - 1;
        if (nums[idx] != nums[i]) {
            int t = nums[idx];
            nums[idx] = nums[i];
            nums[i] = t;
        } else {
            i++;
        }
    }
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i + 1) {
            ans.push_back(i + 1);
        }
    }
    return ans;
}

int main() {
    vector<int> nums{4, 2, 2, 1};
    vector<int> ans = findErrorNums(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
