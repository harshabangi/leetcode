//
// Created by Harsha Vardhan on 16/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
        int idx = nums[i] - 1;
        if (nums[i] != nums[idx]) {
            int tmp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tmp;
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
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = findDisappearedNumbers(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
