//
// Created by Harsha Vardhan on 31/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int longestMountain(vector<int> &arr) {
    int n = arr.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            left[i] = 1 + left[i - 1];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            right[i] = 1 + right[i + 1];
        }
    }
    for (int i = 1; i < n-1 ; i++) {
        cout << left[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i < n-1 ; i++) {
        cout << right[i] << " ";
    }
    cout << "\n";
    int mx = 0;
    for (int i = 1; i < n - 1; i++) {
        if (left[i] != 0 && right[i] != 0) {
            mx = max(mx, left[i] + right[i] + 1);
        }
    }
    return mx;
}

int main() {
    vector<int> arr{2,2,2};
    cout << longestMountain(arr) << "\n";
    return 0;
}
