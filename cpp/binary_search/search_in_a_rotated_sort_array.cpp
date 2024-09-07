//
// Created by Harsha Vardhan on 27/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

int getMinElementIndex(vector<int> &nums) {
    int n = nums.size();
    int i = 0, j = n - 1;
    if (nums[j] >= nums[i]) return 0;
    while (i <= j) {
        int mid = i + (j - i) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;
        if (nums[prev] > nums[mid] && nums[next] > nums[mid]) return mid;
        else if (nums[mid] >= nums[j]) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return -1;
}

int binarySearch(vector<int> &nums, int target, int i, int j) {
    while (i <= j) {
        int mid = i + (j - i) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    return -1;
}

int search(vector<int> &nums, int target) {
    int k = getMinElementIndex(nums);
    assert(k != -1);
    int f = binarySearch(nums, target, 0, k - 1);
    if (f != -1) return f;
    int l = binarySearch(nums, target, k, nums.size() - 1);
    if (l != -1) return l;
    return -1;
}

int main() {
    return 0;
}
