//
// Created by Harsha Vardhan on 28/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool comparator(string &a, string &b) {
    string s1 = a + b;
    string s2 = b + a;
    return s1 > s2;
}

string largestNumber(vector<int> &nums) {
    vector<string> a(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        a[i] = to_string(nums[i]);
    }
    sort(a.begin(), a.end(), comparator);
    string ans;
    for (int i = 0; i < a.size(); i++) {
        ans += a[i];
    }
    int numberOfZeroes = 0;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == '0') numberOfZeroes += 1;
    }
    if (numberOfZeroes == ans.size()) return "0";
    return ans;
}

int main() {
    vector<int> nums{0, 0};
    cout << largestNumber(nums) << "\n";
    return 0;
}
