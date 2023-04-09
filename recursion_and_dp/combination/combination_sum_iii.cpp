//
// Created by Harsha Vardhan on 11/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void combinationSum3Helper(int k, int n, int idx, vector<int> tmp, vector<vector<int>> &ans) {
    if (k == 0 && n == 0) {
        ans.push_back(tmp);
        return;
    }
    if (k < 0 || n < 0) {
        return;
    }
    for (int i = idx; i <= 9; i++) {
        tmp.push_back(i);
        combinationSum3Helper(k - 1, n - i, i + 1, tmp, ans);
        tmp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> tmp;
    combinationSum3Helper(k, n, 1, tmp, ans);
    return ans;
}

int main() {
    vector<vector<int>> ans = combinationSum3(3, 9);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
