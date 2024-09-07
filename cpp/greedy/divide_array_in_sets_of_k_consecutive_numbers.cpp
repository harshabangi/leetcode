//
// Created by Harsha Vardhan on 25/06/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isPossibleDivide(vector<int> &nums, int k) {
    int n = nums.size();
    if (n % k != 0) return false;
    unordered_map<int, int> umap;
    int count = 0;
    for (int i = 0; i < n; i++) {
        umap[nums[i]]++;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        int t = nums[i];
        int g = 0;
        for (int j = t; j < nums[i] + k; j++) {
            if (umap.find(j) != umap.end()) {
                umap[j]--;
                if (umap[j] == 0) umap.erase(j);
                g++;
            } else {
                break;
            }
        }
        if (g == k) count++;
    }
    return count == (n / k);
}

int main() {
    vector<int> nums{3, 2, 1, 2, 3, 4, 3, 4, 5, 9, 10, 11};
    int k = 3;
    cout << isPossibleDivide(nums, k) << "\n";
    return 0;
}
