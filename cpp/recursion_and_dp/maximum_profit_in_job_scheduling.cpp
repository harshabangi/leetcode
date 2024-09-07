//
// Created by Harsha Vardhan on 29/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

struct job {
    int startTime;
    int endTime;
    int profit;
};


bool comparator(job &j1, job &j2) {
    if (j1.startTime == j2.startTime) {
        if (j1.endTime == j2.endTime) {
            return j1.profit < j2.profit;
        } else {
            return j1.endTime < j2.endTime;
        }
    } else {
        return j1.startTime < j2.startTime;
    }
}

int jobSchedulingHelper(vector<job> &jobs, int idx, int currEndTime,
                        vector<vector<int>> &dp) {
    if (idx >= jobs.size()) return 0;
    if (dp[idx][currEndTime] != -1) return dp[idx][currEndTime];
    int ans = 0;
    for (int i = idx; i < jobs.size(); i++) {
        if (jobs[i].startTime >= currEndTime) {
            ans = max(ans, jobs[i].profit + jobSchedulingHelper(jobs, i + 1, jobs[i].endTime, dp));
        }
    }
    return dp[idx][currEndTime] = ans;
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
    int n = startTime.size();
    vector<job> jobs(n);
    for (int i = 0; i < n; i++) {
        jobs[i] = job{startTime[i], endTime[i], profit[i]};
    }
    sort(jobs.begin(), jobs.end(), comparator);
//    for (int i = 0; i < jobs.size(); i++) {
//        cout << jobs[i].startTime << ", " << jobs[i].endTime << ", " << jobs[i].profit << "\n";
//    }
    int maxEndTime = *max_element(endTime.begin(), endTime.end());
    vector<vector<int>> dp(startTime.size() + 1, vector<int>(maxEndTime + 1, -1));
    return jobSchedulingHelper(jobs, 0, 0, dp);
}

int jobSchedulingHelper1(vector<vector<int>> &jobs, int idx, int currEndTime,
                         vector<vector<int>> &dp) {
    if (idx >= jobs.size()) return 0;
    if (dp[idx][currEndTime] != -1) return dp[idx][currEndTime];
    int ans = 0;
    for (int i = idx; i < jobs.size(); i++) {
        if (jobs[i][0] >= currEndTime) {
            ans = max(ans, jobs[i][2] + jobSchedulingHelper1(jobs, i + 1, jobs[i][1], dp));
        }
    }
    return dp[idx][currEndTime] = ans;
}

int jobScheduling1(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
    int n = startTime.size();
    vector<vector<int>> jobs(n);
    for (int i = 0; i < n; i++) {
        vector<int> tmp(3);
        tmp[0] = startTime[i];
        tmp[1] = endTime[i];
        tmp[2] = profit[i];
        jobs[i] = tmp;
    }
    sort(jobs.begin(), jobs.end());
    int maxEndTime = *max_element(endTime.begin(), endTime.end());
    vector<vector<int>> dp(startTime.size() + 1, vector<int>(maxEndTime + 1, -1));
    return jobSchedulingHelper1(jobs, 0, 0, dp);
}

int main() {
    vector<int> startTime{1, 2, 3, 3};
    vector<int> endTime{3, 4, 5, 6};
    vector<int> profit{50, 10, 40, 70};
    cout << jobScheduling1(startTime, endTime, profit) << "\n";
    return 0;
}
