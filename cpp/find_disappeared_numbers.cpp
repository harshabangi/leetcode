//
// Created by Harsha Vardhan on 30/01/22.
//

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

void swap(vector<int> &nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

vector<int> find_disappeared_numbers(vector<int> &nums) {
    int n = nums.size();

    int i = 0;
    while (i < n) {
        if (nums[i] != nums[nums[i] - 1]) {
            swap(nums, i, nums[i] - 1);
        } else {
            i++;
        }
    }
    vector<int> ans;
    print(nums);
    for (int k = 0; k < n; k++) {
        if (nums[k] != k + 1) {
            ans.push_back(k + 1);
        }
    }
    return ans;
}

int main() {
    vector<int> input{2, 3, 4, 5, 6, 7, 8, 1};
    vector<int> result = find_disappeared_numbers(input);
    print(result);
    return 0;
}