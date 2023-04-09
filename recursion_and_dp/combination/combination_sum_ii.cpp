//
// Created by Harsha Vardhan on 12/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void combinationSum2Helper(vector<int> &candidates, vector<int> tmp, int target, int idx, vector<vector<int>> &ans) {
    if (target == 0) {
        ans.push_back(tmp);
        return;
    }
    if (target < 0) {
        return;
    }
    for (int i = idx; i < candidates.size(); i++) {
        if (i != idx && candidates[i] == candidates[i-1]) continue;
        tmp.push_back(candidates[i]);
        combinationSum2Helper(candidates, tmp, target - candidates[i], i + 1, ans);
        tmp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    vector<int> tmp;
    combinationSum2Helper(candidates, tmp, target, 0, ans);
    return ans;
}

int main() {
    // 1, 1, 2, 5, 6, 7, 10
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> ans = combinationSum2(candidates, 8);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
