//
// Created by Harsha Vardhan on 16/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
        int idx = nums[i];
        if (nums[i] < nums.size() && nums[i] != i) {
            int tmp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tmp;
        } else {
            i++;
        }
    }
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] != i) {
            break;
        }
    }
    return i;
}

int main() {
    vector<int> nums{3, 0, 1};
    cout << missingNumber(nums) << "\n";
    return 0;
}
