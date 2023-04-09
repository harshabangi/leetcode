//
// Created by Harsha Vardhan on 27/04/22.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


int maxScoreHelper(vector<int> cardPoints, vector<vector<int>> dp, int k, int startIdx, int endIdx) {
    if (k == 0) return 0;
    if (startIdx > endIdx && k < 0) return 0;
    if (dp[startIdx][endIdx] != -1) return dp[startIdx][endIdx];
    int a = cardPoints[startIdx] + maxScoreHelper(cardPoints, dp, k - 1, startIdx + 1, endIdx);
    int b = cardPoints[endIdx] + maxScoreHelper(cardPoints, dp, k - 1, startIdx, endIdx - 1);
    return dp[startIdx][endIdx] = max(a, b);
}

int maxScore(vector<int> &cardPoints, int k) {
    int n = cardPoints.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return maxScoreHelper(cardPoints, dp, k, 0, n - 1);
}

int main() {
//    vector<int> nums1{1, 2, 3, 4, 5, 6, 1};
//    int k1 = 3;
//
//    vector<int> nums2{2, 2, 2};
//    int k2 = 2;

    vector<int> nums3{9, 7, 7, 9, 7, 7, 9};
    int k3 = 7;

//    cout << maxScore(nums1, k1) << "\n";
//    cout << maxScore(nums2, k2) << "\n";
    cout << maxScore(nums3, k3) << "\n";
    return 0;
}
