//
// Created by Harsha Vardhan on 18/05/22.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int calculateMax(vector<int> &prefixSum, vector<int> &nums, int firstLen, int secondLen) {
    int i = 0, j = firstLen - 1;
    int mx = INT_MIN;
    while (j < nums.size()) {
        int t;
        if (i == 0) t = prefixSum[j];
        else t = prefixSum[j] - prefixSum[i - 1];
        int p = j + 1, q = p + secondLen - 1;
        while (q < nums.size()) {
            mx = max(mx, t + prefixSum[q] - prefixSum[p - 1]);
            p++;
            q++;
        }
        i++;
        j++;
    }
    return mx;
}

int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    vector<int> prefixSum(nums.size(), 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        prefixSum[i] = nums[i] + prefixSum[i - 1];
    }
    return max(calculateMax(prefixSum, nums, firstLen, secondLen),
               calculateMax(prefixSum, nums, secondLen, firstLen));
}

int main() {
    vector<int> nums{0, 6, 5, 2, 2, 5, 1, 9, 4};
    int firstLen = 1, secondLen = 2;
    cout << maxSumTwoNoOverlap(nums, firstLen, secondLen) << "\n";
    return 0;
}
