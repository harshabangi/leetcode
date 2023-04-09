//
// Created by Harsha Vardhan on 27/07/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>


using namespace std;

int sumOfDigits(int num) {
    int ans = 0;
    while (num > 0) {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

int maximumSum(vector<int> &nums) {
    unordered_map<int, int> umap;
    int ans = -1;
    for (int i = 0; i < nums.size(); i++) {
        int l = sumOfDigits(nums[i]);
        if (umap.find(l) != umap.end()) {
            ans = max(ans, umap[l] + nums[i]);
            umap[l] = max(umap[l], nums[i]);
        } else {
            umap[l] = nums[i];
        }
    }
    return ans;
}

int main() {
    cout << sumOfDigits(208880324) << "\n";
    return 0;
}

