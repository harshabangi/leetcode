//
// Created by Harsha Vardhan on 03/10/22.
//

#include <iostream>
#include <vector>

using namespace std;

int minDifference(vector<int> &nums) {
    if (nums.size() <= 4) {
        return 0;
    } else {
        sort(nums.begin(), nums.end(), greater<int>());
        return min(nums[3] - nums[nums.size() - 1], min(nums[0] - nums[nums.size() - 4],
                                                        min(nums[2] - nums[nums.size() - 2],
                                                            nums[1] - nums[nums.size() - 3])));
    }
}

int main() {
    return 0;
}
