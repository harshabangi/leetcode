//
// Created by Harsha Vardhan on 02/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minimumXORSumHelper(vector<int> nums1, vector<int> nums2, vector<bool> b, int idx) {
    if (idx == nums2.size()) return 0;
    int ans = INT_MAX;
    for (int k = 0; k < nums2.size(); k++) {
        if (!b[k]) {
            b[k] = true;
            ans = min(ans, nums1[idx] ^ nums2[k] + minimumXORSumHelper(nums1, nums2, b, idx + 1));
            b[k] = false;
        }
    }
    return ans;
}

int minimumXORSum(vector<int> &nums1, vector<int> &nums2) {
    vector<bool> b(nums2.size(), false);
    return minimumXORSumHelper(nums1, nums2, b, 0);
}

int main() {
    vector<int> nums1{1, 0, 3};
    vector<int> nums2{5, 3, 4};
    cout << minimumXORSum(nums1, nums2) << "\n";
    return 0;
}
