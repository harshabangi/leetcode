//
// Created by Harsha Vardhan on 25/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int nC2(int n) {
    return (n * (n - 1)) / 2;
}

int numIdenticalPairs(vector<int> &nums) {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
        umap[nums[i]]++;
    }
    int ans = 0;
    for (auto it: umap) {
        if (it.second >= 2) {
            ans += nC2(it.second);
        }
    }
    return ans;
}

int main() {
    return 0;
}
