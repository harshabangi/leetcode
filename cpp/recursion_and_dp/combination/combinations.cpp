//
// Created by Harsha Vardhan on 10/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void combine(int n, int k, int idx, vector<int> tmp, vector<vector<int> > &ans) {
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }
    while (idx <= n) {
        tmp.push_back(idx);
        combine(n, k - 1, idx + 1, tmp, ans);
        tmp.pop_back();
        idx++;
    }
}

vector<vector<int> > combine(int n, int k) {
    vector<int> tmp;
    vector<vector<int> > ans;
    combine(n, k, 1, tmp, ans);
    return ans;
}

int main() {
    vector<vector<int> > ans = combine(1, 1);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}