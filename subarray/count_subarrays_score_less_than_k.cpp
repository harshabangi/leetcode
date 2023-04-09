//
// Created by Harsha Vardhan on 12/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

long long countSubarrays(vector<int> &nums, long long k) {
    long long sums = 0, res = 0;
    for (int i = 0, j = 0; i < nums.size(); i++) {
        sums += nums[i];
        while (sums * (i - j + 1) >= k) {
            sums -= nums[j++];
        }
        res += (i - j + 1);
    }
    return res;
}

int main() {
    return 0;
}
