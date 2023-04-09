//
// Created by Harsha Vardhan on 12/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int ans = 0, product = 1;
    for (int i = 0, j = 0; i < nums.size(); i++) {
        product *= nums[i];
        while (product >= k && j <= i) {
            product = product / nums[j++];
        }
        ans += (i - j + 1);
    }
    return ans;
}

int main() {
    vector<int> nums{1, 1, 1};
    int k = 1;
    cout << numSubarrayProductLessThanK(nums, k) << "\n";
    return 0;
}
