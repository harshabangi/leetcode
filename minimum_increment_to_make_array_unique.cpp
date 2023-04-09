//
// Created by Harsha Vardhan on 04/08/22.
//

#include <iostream>
#include <vector>

using namespace std;

int minIncrementForUnique(vector<int> &nums) {
    int maxVal = 0;
    for (int x: nums) {
        maxVal = max(x, maxVal);
    }
    vector<int> count(maxVal + nums.size());
    for (int x: nums) {
        count[x]++;
    }
    int moves = 0, taken = 0;
    for (int i = 0; i < maxVal + nums.size(); i++) {
        if (count[i] >= 2) {
            taken += count[i] - 1;
            moves -= ((count[i] - 1) * i);
        } else if (taken > 0 && count[i] == 0) {
            taken--;
            moves += i;
        }
    }
    return moves;
}

int main() {
    return 0;
}
