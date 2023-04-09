//
// Created by Harsha Vardhan on 31/08/22.
//

#include <iostream>
#include <vector>

using namespace std;

int dp[1001][1001][2];

int wiggleMaxLengthHelper(vector<int> &nums, int idx, int prevIdx, bool isPositive) {
    if (idx >= nums.size()) return 1;
    if (dp[idx][prevIdx][isPositive] != -1) return dp[idx][prevIdx][isPositive];
    int ans = 0;
    if ((nums[idx] - nums[prevIdx] != 0) && !((nums[idx] - nums[prevIdx] > 0) & isPositive)) {
        ans = 1 + wiggleMaxLengthHelper(nums, idx + 1, idx, !isPositive);
    }
    return dp[idx][prevIdx][isPositive] = max(ans, wiggleMaxLengthHelper(nums, idx + 1, prevIdx, isPositive));
}

int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() == 1) return 1;
    memset(dp, -1, sizeof(dp));
    int i = 0, j = 1;
    while (j < nums.size()) {
        if (nums[j] == nums[i]) {
            i++;
            j++;
        } else break;
    }
    if (j == nums.size()) return 1;
    bool isPositive;
    bool l = nums[j] - nums[i] > 0;
    if (l) isPositive = true;
    else isPositive = false;
    return wiggleMaxLengthHelper(nums, 1, 0, !isPositive);
}

int main() {
    vector<int> nums{33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60,1,40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15};
    cout << wiggleMaxLength(nums) << "\n";
    return 0;
}
