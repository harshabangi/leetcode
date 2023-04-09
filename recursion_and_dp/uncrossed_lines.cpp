//
// Created by Harsha Vardhan on 04/07/22.
//

#include <iostream>
#include <vector>

using namespace std;

int maxUncrossedLinesHelper(vector<int> &nums1, vector<int> &nums2, int idx1, int idx2, vector<vector<int>> &dp) {
    if (idx1 >= nums1.size() || idx2 >= nums2.size()) return 0;
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    int ans = 0;
    if (nums1[idx1] == nums2[idx2]) {
        ans = 1 + maxUncrossedLinesHelper(nums1, nums2, idx1 + 1, idx2 + 1, dp);
    }
    return dp[idx1][idx2] = max(ans, max(maxUncrossedLinesHelper(nums1, nums2, idx1 + 1, idx2, dp),
                                         maxUncrossedLinesHelper(nums1, nums2, idx1, idx2 + 1, dp)));
}

int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, -1));
    return maxUncrossedLinesHelper(nums1, nums2, 0, 0, dp);
}

int main() {
    return 0;
}
