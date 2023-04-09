//
// Created by Harsha Vardhan on 18/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

enum occurence {
    FIRST,
    LAST
};

int binarySearch(vector<int> &nums, int target, occurence occur) {
    int l = 0, r = nums.size() - 1;
    int index = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > target) {
            r = mid - 1;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            index = mid;
            if (occur == FIRST) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    return index;
}

vector<int> searchRange(vector<int> &nums, int target) {
    int first = binarySearch(nums, target, FIRST);
    int last = binarySearch(nums, target, LAST);
    vector<int> ans(2);
    ans[0] = first;
    ans[1] = last;
    return ans;
}

int main() {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 8;
    searchRange(nums, target);
    return 0;
}
