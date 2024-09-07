//
// Created by Harsha Vardhan on 10/05/22.
//

#include <iostream>
#include <queue>

using namespace std;

int minDifficultyHelper(vector<vector<int>> &dp, vector<int> &jobDifficulty, int d, int index) {
    if (index >= jobDifficulty.size() && d == 0) return 0;
    if (index >= jobDifficulty.size() || d == 0) return INT_MAX;

    if (dp[index][d] != -1) return dp[index][d];
    int maxVal = 0, minSum = INT_MIN;
    for (int i = index; i < jobDifficulty.size(); i++) {
        maxVal = max(maxVal, jobDifficulty[i]);
        minSum = min(minSum, maxVal + minDifficultyHelper(dp, jobDifficulty, d - 1, index + 1));
    }
    return dp[index][d] = minSum;
}

int minDifficulty(vector<int> &jobDifficulty, int d) {
    if (d > jobDifficulty.size()) return -1;
    vector<vector<int>>dp(jobDifficulty.size()+1, vector<int>(d+1, -1));
    return minDifficultyHelper(dp, jobDifficulty, d, 0);
}

int main() {
    return 0;
}