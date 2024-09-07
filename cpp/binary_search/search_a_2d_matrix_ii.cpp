//
// Created by Harsha Vardhan on 28/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int getBinaryIndexSearch(vector<int> &nums, int &target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int t = getBinaryIndexSearch(matrix[0], target);
    if (matrix[0][t] == target) return true;

    cout << t << "\n";
    int l = 0, r = matrix.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (matrix[mid][t] == target) {
            return true;
        } else if (matrix[mid][t] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix{
            {1, 4},
            {2, 5},
    };
    cout << searchMatrix(matrix, 2) << "\n";
    return 0;
}
