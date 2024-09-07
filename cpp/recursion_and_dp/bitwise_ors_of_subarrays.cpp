//
// Created by Harsha Vardhan on 21/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int subarrayBitwiseORsHelper(vector<int> &arr, int idx, unordered_set<int> &uset, int k) {
    for (int i = idx; i < arr.size(); i++) {
        if (abs(i - idx) <= 1) {
            cout << (k | arr[i]) << "\n";
            uset.insert(k | arr[i]);
            subarrayBitwiseORsHelper(arr, i + 1, uset, k | arr[i]);
        }
    }
    return 0;
}

int subarrayBitwiseORs(vector<int> &arr) {
    unordered_set<int> uset;
    subarrayBitwiseORsHelper(arr, 0, uset, 0);
    return uset.size();
}

int main() {
    vector<int> arr{1, 2, 4};
    cout << subarrayBitwiseORs(arr) << "\n";
    return 0;
}
