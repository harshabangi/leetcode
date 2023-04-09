//
// Created by Harsha Vardhan on 16/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums) {
    int maxSoFar = INT_MIN, maxEndingHere = 0;
    int s, start, end;
    for (int i = 0; i < nums.size(); i++) {
        maxEndingHere += nums[i];
        if (maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
            start = s;
            end = i;
        }
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
            s = i + 1;
        }
    }
    cout << start << "\n";
    cout << end << "\n";
    return maxSoFar;
}

int main() {
    return 0;
}
