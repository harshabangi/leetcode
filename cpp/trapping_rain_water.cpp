//
// Created by Harsha Vardhan on 06/03/22.
//

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int trap_1(vector<int> height) {
    int n = height.size();
    vector<int> left(n);
    vector<int> right(n);
    left[0] = height[0];
    right[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], height[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], height[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += min(left[i], right[i]) - height[i];
    }
    return ans;
}

int trap_2(vector<int> &height) {
    int l = 0, r = height.size() - 1, left_max = 0, right_max = 0;
    int ans = 0;
    while (l <= r) {
        if (height[l] <= height[r]) {
            if (height[l] > left_max) left_max = height[l];
            else {
                ans += left_max - height[l];
            }
            l++;
        } else {
            if (height[r] >= right_max) right_max = height[r];
            else {
                ans += right_max - height[r];
            }
            r--;
        }
    }
    return ans;
}

int main() {
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap_2(height) << "\n";
    return 0;
}
