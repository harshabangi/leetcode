//
// Created by Harsha Vardhan on 11/09/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool increasingTriplet(vector<int> &nums) {
    int n = nums.size();
    vector<int> left(n), right(n);

    int mn = nums[0];
    left[0] = nums[0];
    for (int i = 1; i < n; i++) {
        mn = min(mn, nums[i]);
        left[i] = mn;
    }

    int mx = nums[n - 1];
    right[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        mx = max(mx, nums[i]);
        right[i] = mx;
    }

    for (int i = 1; i < n - 1; i++) {
        if (nums[i] > left[i - 1] && nums[i] < right[i + 1]) return true;
    }
    return false;
}

int main() {
    vector<int> nums{1, 5, 0, 4, 1, 3};
    cout << increasingTriplet(nums) << "\n";
    return 0;
}
