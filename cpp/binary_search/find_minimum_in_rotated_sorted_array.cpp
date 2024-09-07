//
// Created by Harsha Vardhan on 03/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int> &nums) {
    int n = nums.size();
    int i = 0, j = nums.size() - 1;
    if (nums[j] >= nums[i]) {
        return nums[0];
    }
    while (i <= j) {
        int mid = (i + j) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;
        if (nums[mid] < nums[prev] && nums[mid] < nums[next]) {
            return nums[mid];
        } else if (nums[mid] >= nums[i]) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return nums[i];
}

int main() {
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums) << "\n";
    return 0;
}
