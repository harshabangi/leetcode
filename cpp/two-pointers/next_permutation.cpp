//
// Created by Harsha Vardhan on 28/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void reverse(vector<int> &nums, int i, int j) {
    while (i < j) {
        swap(nums, i, j);
        i++;
        j--;
    }
}

void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int i = nums.size() - 2;
    while (i >= 0) {
        if (nums[i] < nums[i + 1]) {
            break;
        }
        i--;
    }
    if (i < 0) {
        reverse(nums, 0, n - 1);
        return;
    }
    int j = nums.size() - 1;
    while (j >= 0) {
        if (nums[j] > nums[i]) {
            break;
        }
        j--;
    }
    swap(nums, i, j);
    reverse(nums, i + 1, n - 1);
}

int main() {
    return 0;
}

