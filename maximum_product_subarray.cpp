//
// Created by Harsha Vardhan on 09/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProductHelper(vector<int> &nums, int i, int j) {
    if (i > j) return 0;
    if (i == j) return nums[i];
    int c = nums[i] * nums[j] * maxProductHelper(nums, i + 1, j - 1);
    return max(c, max(maxProductHelper(nums, i + 1, j), maxProductHelper(nums, i, j - 1)));
}

int maxProduct(vector<int> &nums) {
    return maxProductHelper(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums{2, 3, -2, 4};
    cout << maxProduct(nums) << "\n";
    return 0;
}
