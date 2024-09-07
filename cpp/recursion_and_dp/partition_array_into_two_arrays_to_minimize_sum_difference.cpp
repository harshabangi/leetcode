//
// Created by Harsha Vardhan on 02/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int minimumDifferenceHelper(vector<int> nums, int idx, int sum, int k, int totalSum) {
    if (k == 0) {
        return abs(2 * sum - totalSum);
    }
    if (idx == nums.size()) {
        return INT_MAX;
    }
    return min(minimumDifferenceHelper(nums, idx + 1, sum + nums[idx], k - 1, totalSum),
               minimumDifferenceHelper(nums, idx + 1, sum, k, totalSum));
}

int minimumDifferenceHelper1(unordered_map<string, int>& umap, vector<int> nums, int idx, int sum, int k, int totalSum) {
    if (k == 0) {
        return abs(2 * sum - totalSum);
    }
    if (idx == nums.size()) {
        return INT_MAX;
    }
    string key = to_string(sum) + "," + to_string(idx);
    if (umap.find(key) != umap.end()) return umap[key];
    return umap[key] = min(minimumDifferenceHelper1(umap, nums, idx + 1, sum + nums[idx], k - 1, totalSum),
                              minimumDifferenceHelper1(umap, nums, idx + 1, sum, k, totalSum));
}

int minimumDifference(vector<int> &nums) {
    int totalSum = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        totalSum += nums[i];
    }
    unordered_map<string, int> umap;
    return minimumDifferenceHelper1(umap, nums, 0, 0, n / 2, totalSum);
}

int main() {
    vector<int> nums{39379,-27588,70637,72773,-15113,-34670,-61342,78147,13237,-51363,-39801,68635,38370,77151,8434,-70276};
    cout << minimumDifference(nums) << "\n";
    return 0;
}
