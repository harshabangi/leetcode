//
// Created by Harsha Vardhan on 09/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int> &nums) {
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]) return nums[mid];
        if (nums[mid] == nums[mid + 1]) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    return nums[j];
}

int main() {
    vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(nums) << "\n";
    return 0;
}
