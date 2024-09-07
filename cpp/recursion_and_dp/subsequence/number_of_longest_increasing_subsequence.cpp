//
// Created by Harsha Vardhan on 05/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << "\n";
}

//int LISHelper(vector<int> &recursion_and_dp, vector<int> &nums, int idx, vector<int> &st) {
//    if (idx == nums.size()) return 0;
//    if (recursion_and_dp[idx] != -1) return recursion_and_dp[idx];
//    int ans = 0;
//    for (int i = idx + 1; i < nums.size(); i++) {
//        if (nums[i] > nums[idx]) {
//            int tmp = 1 + LISHelper(recursion_and_dp, nums, i, st);
//            st.push_back(1 + tmp);
//            ans = max(ans, tmp);
//        }
//    }
//    return recursion_and_dp[idx] = ans;
//}


int LISHelper1(vector<int> &nums, int idx, vector<int> &ans, int k) {
    if (idx >= nums.size() - 1) return 0;
    for (int i = idx + 1; i < nums.size(); i++) {
        if (nums[i] > nums[idx]) {
            int z = LISHelper1(nums, i, ans, 1 + k);
            ans.push_back(z);
        }
    }
    return 1 + k;
}

int findNumberOfLISHelper(vector<int> &nums, int idx) {
    int ans = 0;
    for (int i = idx + 1; i < nums.size(); i++) {
        if (nums[i] > nums[idx]) {
            ans += 1 + findNumberOfLISHelper(nums, i);
        }
    }
    return ans;
}

int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += findNumberOfLISHelper(nums, i);
    }
    return ans;
}


int main() {
//    vector<int> nums{1, 3, 5, 4, 7};
    vector<int> nums{1, 3, 5, 4, 7};
    cout << findNumberOfLIS(nums) << "\n";
    return 0;
}
