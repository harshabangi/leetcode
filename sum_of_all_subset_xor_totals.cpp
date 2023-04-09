//
// Created by Harsha Vardhan on 20/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void subsetXORSumHelper(vector<int> &nums, int &sum, int idx, int xor_value) {
    sum += xor_value;
    for (int i = idx; i < nums.size(); i++) {
        subsetXORSumHelper(nums, sum, i + 1, xor_value ^ nums[i]);
    }
}

int subsetXORSum(vector<int> &nums) {
    int sum = 0;
    subsetXORSumHelper(nums, sum, 0, 0);
    return sum;
}

int main() {
    vector<int> nums{3,4,5,6,7,8};
    cout << subsetXORSum(nums) << "\n";
    return 0;
}

