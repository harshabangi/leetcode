//
// Created by Harsha Vardhan on 27/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

void subsequences(vector<int> arr, int idx, vector<int> tmp, vector<vector<int>> &ans) {
    if (idx > arr.size()) {
        return;
    }
    ans.push_back(tmp);
    for (int i = idx; i < arr.size(); i++) {
        tmp.push_back(arr[i]);
        subsequences(arr, i + 1, tmp, ans);
        tmp.pop_back();
    }
}

void subsequences1(vector<int> arr, int idx, vector<int> tmp, vector<vector<int>> &ans) {
    if (idx >= arr.size()) return;
    tmp.push_back(arr[idx]);
    ans.push_back(tmp);
    subsequences1(arr, idx + 1, tmp, ans);
    tmp.pop_back();
    subsequences1(arr, idx + 1, tmp, ans);
}

int main() {
    vector<int> arr{1, 2, 3};
    vector<vector<int>> ans;
    vector<int> tmp;
    subsequences(arr, 0, tmp, ans);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
