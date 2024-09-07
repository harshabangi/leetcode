//
// Created by Harsha Vardhan on 01/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

int findSecondMaxElement(vector<int> &nums) {
    int firstMax = INT_MIN;
    int secondMax = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > firstMax) {
            secondMax = firstMax;
            firstMax = nums[i];
        } else {
            if (nums[i] > secondMax) secondMax = nums[i];
        }
    }
    return secondMax;
}

int main() {
    vector<int> nums{4, 3, 6, 2, 7, 9, 6, 3};
    cout << findSecondMaxElement(nums) << "\n";
    return 0;
}
