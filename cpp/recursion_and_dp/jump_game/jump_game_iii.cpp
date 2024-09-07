//
// Created by Harsha Vardhan on 08/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool canReachHelper(vector<int> &arr, int start, vector<int> visited) {
    if (start < 0 || start >= arr.size()) return false;
    if (arr[start] == 0) return true;
    if (visited[start]) return false;
    visited[start] = true;
    return canReachHelper(arr, start + arr[start], visited) || canReachHelper(arr, start - arr[start], visited);
}

bool canReach(vector<int> &arr, int start) {
    vector<int> visited(arr.size(), false);
    return canReachHelper(arr, start, visited);
}

int main() {
    vector<int> arr{0, 1};
    int start = 1;
    cout << canReach(arr, start) << "\n";
    return 0;
}
