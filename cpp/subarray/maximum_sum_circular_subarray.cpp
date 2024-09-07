//
// Created by Harsha Vardhan on 18/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int totalSum = 0;

    int curr_max_sum = 0;
    int mx_sum = INT_MIN;

    int curr_min_sum = 0;
    int mn_sum = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
        totalSum += nums[i];

        curr_max_sum += nums[i];
        mx_sum = max(mx_sum, curr_max_sum);
        if (curr_max_sum < 0) {
            curr_max_sum = 0;
        }

        curr_min_sum += nums[i];
        mn_sum = min(mn_sum, curr_min_sum);
        if (curr_min_sum > 0) {
            curr_min_sum = 0;
        }
    }

    if (mn_sum == totalSum) return mx_sum;
    return max(mx_sum, totalSum-mn_sum);

}

int main() {
    return 0;
}
