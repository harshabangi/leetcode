//
// Created by Harsha Vardhan on 10/05/22.
//

#include <iostream>
#include <queue>

using namespace std;

int minCostToConnectRopes(vector<int> &nums) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
    }
    int ans = 0;
    while (pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += (a + b);
        pq.push(a + b);
    }
    return ans;
}

int main() {
    vector<int> nums{1, 2, 5, 10, 35, 89};
    cout << minCostToConnectRopes(nums) << "\n";
    return 0;
}
