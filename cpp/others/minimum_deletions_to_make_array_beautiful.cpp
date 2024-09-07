//
// Created by Harsha Vardhan on 20/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int minDeletion(vector<int> &nums) {
    int ans = 0, pivot = 0, curr = pivot + 1, k = nums.size(), a = 0;
    while (curr < nums.size()) {
        if (a % 2 == 0 && nums[pivot] == nums[curr]) {
            ans++;
            k--;
            curr++;
            continue;
        }
        pivot = curr;
        a++;
        curr++;
    }
    return k % 2 == 0 ? ans : ans + 1;
}

int main() {
    vector<int> nums{1, 1, 2, 2, 3, 3};
    cout << minDeletion(nums) << "\n";
    return 0;
}