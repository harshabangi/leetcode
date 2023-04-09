//
// Created by Harsha Vardhan on 29/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minAbsDifferenceHelper1(vector<int> &nums, int goal, int idx) {
    if (idx >= nums.size()) return 0;
    int ans = 1e9;
    for (int i = idx; i < nums.size(); i++) {
        ans = min(ans, abs(goal - (nums[i] + minAbsDifferenceHelper1(nums, goal, i + 1))));
        cout << ans << "\n";
    }
    return ans;
}

int minAbsDifferenceHelper(vector<int> &nums, int goal, int idx, unordered_map<string, int> &umap) {
    if (idx >= nums.size()) return goal;
    string key = to_string(goal) + to_string(idx);
    if (umap.find(key) != umap.end()) return umap[key];
    int ans = 1e9;
    ans = min(ans, abs(minAbsDifferenceHelper(nums, goal - nums[idx], idx + 1, umap)));
    ans = min(ans, abs(minAbsDifferenceHelper(nums, goal, idx + 1, umap)));
    return umap[key] = ans;
}

int minAbsDifference(vector<int> &nums, int goal) {
    unordered_map<string, int> umap;
    return minAbsDifferenceHelper(nums, goal, 0, umap);
}

int main() {
    vector<int> nums{1, 2, 3};
    cout << minAbsDifference(nums, -7) << "\n";
    return 0;
}
