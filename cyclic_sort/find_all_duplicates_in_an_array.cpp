//
// Created by Harsha Vardhan on 16/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 * [4,3,2,7,8,2,3,1]
 * [7,3,2,4,8,2,3,1]
 * [3,2,3,4,1,2,7,8]
 *
 * */

vector<int> findDuplicates(vector<int> &nums) {
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
        if (nums[i] != i+1) {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main() {
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = findDuplicates(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
