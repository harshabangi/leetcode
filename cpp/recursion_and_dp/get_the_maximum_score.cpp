//
// Created by Harsha Vardhan on 26/07/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


// nums1 -> flag - true

const int M = 1000000007;

long
maxSumHelper(vector<int> &nums1, vector<int> &nums2, unordered_map<int, int> &umap1, unordered_map<int, int> &umap2,
             int idx,
             bool flag, vector<vector<long>> &dp) {
    if (idx >= nums1.size() && idx >= nums2.size()) return 0;
    if (dp[idx][flag] != -1) return dp[idx][flag];
    long ans = 0;
    if (flag && idx < nums1.size()) {
        ans = max(ans, nums1[idx] + maxSumHelper(nums1, nums2, umap1, umap2, idx + 1, flag, dp));
        if (umap2.find(nums1[idx]) != umap2.end()) {
            int l = umap2[nums1[idx]];
            ans = max(ans, nums1[idx] + maxSumHelper(nums1, nums2, umap1, umap2, l + 1, !flag, dp));
        }
    } else if (!flag && idx < nums2.size()) {
        ans = max(ans, nums2[idx] + maxSumHelper(nums1, nums2, umap1, umap2, idx + 1, flag, dp));
        if (umap1.find(nums2[idx]) != umap1.end()) {
            int l = umap1[nums2[idx]];
            ans = max(ans, nums2[idx] + maxSumHelper(nums1, nums2, umap1, umap2, l + 1, !flag, dp));
        }
    }
    return dp[idx][flag] = ans;
}

int maxSum(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> umap1, umap2;
    for (int i = 0; i < nums1.size(); i++) {
        umap1[nums1[i]] = i;
    }
    for (int i = 0; i < nums2.size(); i++) {
        umap2[nums2[i]] = i;
    }
    int n = max(nums1.size(), nums2.size());
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));
    return max(maxSumHelper(nums1, nums2, umap1, umap2, 0, true, dp) % M,
               maxSumHelper(nums1, nums2, umap1, umap2, 0, false, dp) % M);
}

int main() {
    vector<int> nums1{1, 2, 3, 4, 5};
    vector<int> nums2{6, 7, 8, 9, 10};
    cout << maxSum(nums1, nums2) << "\n";
    return 0;
}
