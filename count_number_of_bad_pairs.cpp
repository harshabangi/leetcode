//
// Created by Harsha Vardhan on 22/08/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 0, 1, 2, 3
 * 4, 1, 3, 3
 *
 * 4, 0, 1, 0
 * */

long long nc2(int n) {
    long long t = n * (n - 1);
    return t / 2;
}

long long countBadPairs(vector<int> &nums) {
    int n = nums.size();
    long long count = 0;
    unordered_map<int, int> umap;
    umap[nums[0]] = 1;
    for (int i = 1; i < n; i++) {
        int l = nums[i] - i;
        if (umap.find(l) != umap.end()) {
            count += umap[l];
            umap[l]++;
        } else {
            umap[l] = 1;
        }
    }
    return nc2(n) - count;
}

int main() {
    vector<int> nums{4, 1, 3, 3};
    cout << countBadPairs(nums) << "\n";
    return 0;
}
