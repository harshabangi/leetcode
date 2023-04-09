//
// Created by Harsha Vardhan on 11/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void combinationSumHelper(vector<int> &candidates, int target, int idx, vector<int> tmp, vector<vector<int> > &ans) {
    if (target == 0) {
        ans.push_back(tmp);
        return;
    }
    if (target < 0) {
        return;
    }
    for (int i = idx; i < candidates.size(); i++) {
        tmp.push_back(candidates[i]);
        combinationSumHelper(candidates, target - candidates[i], i, tmp, ans);
        tmp.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<int> tmp;
    vector<vector<int> > ans;
    combinationSumHelper(candidates, target, 0, tmp, ans);
    return ans;
}

int main() {
    vector<int> input{2, 3, 6, 7};
    vector<vector<int> > ans = combinationSum(input, 7);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
