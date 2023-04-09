//
// Created by Harsha Vardhan on 25/07/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

long long zeroFilledSubarray(vector<int> &nums) {
    int i = 0, j = 0;
    long long ans = 0;
    while (j < nums.size()) {
        if (nums[j] == 0) {
            ans += (j - i + 1);
            j++;
        } else {
            j++;
            i = j;
        }
    }
    return ans;
}

int main() {
    vector<int> nums{0, 0, 0, 2, 0, 0};
    cout << zeroFilledSubarray(nums) << "\n";
    return 0;
}
