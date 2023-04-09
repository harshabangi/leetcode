//
// Created by Harsha Vardhan on 09/06/22.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[i] > nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);
    for (int i = k; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() < (i - k + 1)) {
            dq.pop_front();
        }
        while (!dq.empty() && nums[i] > nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main() {
    return 0;
}
