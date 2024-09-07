//
// Created by Harsha Vardhan on 11/02/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void findDifferentBinaryStringHelper(string s, int n, vector<string> nums, string &ans, bool &flag) {
    if (n == 0) {
        bool k = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == s) {
                k = false;
            }
        }
        if (k) {
            ans = s;
            flag = false;
        }
        return;
    }
    if (flag) {
        findDifferentBinaryStringHelper(s + "0", n - 1, nums, ans, flag);
        findDifferentBinaryStringHelper(s + "1", n - 1, nums, ans, flag);
    }
}

string findDifferentBinaryString(vector<string> &nums) {
    int n = nums[0].size();
    bool flag = true;
    string ans;
    findDifferentBinaryStringHelper("", n, nums, ans, flag);
    return ans;
}

int main() {
    vector<string> nums{"00", "01"};
    cout << findDifferentBinaryString(nums);
    return 0;
}
