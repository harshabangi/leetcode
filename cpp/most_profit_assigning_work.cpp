//
// Created by Harsha Vardhan on 01/08/22.
//

#include<iostream>
#include <vector>

using namespace std;


int getProfit(vector<pair<int, int>> &dp, int x) {
    int i = 0, j = dp.size() - 1;
    int index;
    while (i <= j) {
        int mid = i + (j - i) / 2;
        if (dp[mid].first < x && dp[mid + 1].first > x) return dp[mid].second;
        if (dp[mid].first > x && dp[mid - 1].first < x) return dp[mid - 1].second;
        if (dp[mid].first < x) {
            i = mid + 1;
        } else if (dp[mid].first > x) {
            j = mid - 1;
        } else {
            index = mid;
            i = mid + 1;
        }
    }
    return dp[index].second;
}

int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
    int n = profit.size();
    vector<pair<int, int>> dp(n + 2);

    dp[0] = {INT_MIN, INT_MIN};
    for (int i = 1; i <= n; i++) {
        dp[i] = {difficulty[i - 1], profit[i - 1]};
    }
    dp[n + 1] = {INT_MAX, INT_MAX};

    sort(dp.begin(), dp.end());

    int u = INT_MIN;
    for (int i = 1; i <= n; i++) {
        u = max(u, dp[i].second);
        dp[i] = {dp[i].first, u};
    }

    int ans = 0;
    for (int i = 0; i < worker.size(); i++) {
        int l = getProfit(dp, worker[i]);
        if (l != INT_MIN) {
            ans += l;
        }
    }
    return ans;
}

int main() {
//    [23,30,35,35,43,46,47,81,83,98]
//    [8,11,11,20,33,37,60,72,87,95]
//    [95,46,47,97,11,35,99,56,41,92]
    vector<int> difficulty{23, 30, 35, 35, 43, 46, 47, 81, 83, 98};
    vector<int> profit{8, 11, 11, 20, 33, 37, 60, 72, 87, 95};
    vector<int> worker{95, 46, 47, 97, 11, 35, 99, 56, 41, 92};
    cout << maxProfitAssignment(difficulty, profit, worker) << "\n";
    return 0;
}
