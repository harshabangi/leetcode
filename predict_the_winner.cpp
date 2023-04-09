//
// Created by Harsha Vardhan on 22/01/22.
//

#include <iostream>
#include <vector>

using namespace std;

int predict_the_winner_helper(vector<int> &nums, int i, int j) {
    if (i == j) return nums[i];
    int first = nums[i] - predict_the_winner(nums, i + 1, j);
    int second = nums[j] - predict_the_winner(nums, i, j - 1);
    return max(first, second);
}

int predict_the_winner(vector<int> &nums, int i, int j) {
    if (i == j) return nums[i];
    int first = nums[i] - predict_the_winner(nums, i + 1, j);
    int second = nums[j] - predict_the_winner(nums, i, j - 1);
    return max(first, second);
}

int main() {
    vector<int> v{1, 5, 233, 7};
    cout << predict_the_winner(v, 0, v.size() - 1);
    return 0;
}
