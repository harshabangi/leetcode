//
// Created by Harsha Vardhan on 17/02/22.
//

#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < nums.size(); i++) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        int k = -nums[i];
        int p = i + 1, q = nums.size() - 1;
        while (p < q) {
            if (nums[p] + nums[q] == k) {
                vector<int> tmp{nums[i], nums[p], nums[q]};
                ans.push_back(tmp);
                while (p < q && nums[p] == nums[p + 1]) p++;
                while (p < q && nums[q] == nums[q - 1]) q--;
                p++;
                q--;
            } else if (nums[p] + nums[q] > k) {
                q--;
            } else {
                p++;
            }
        }
    }
    return ans;
}


int main() {
    vector<int> nums{0, 0, 0, 0};
    vector<vector<int>> ans = threeSum(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
