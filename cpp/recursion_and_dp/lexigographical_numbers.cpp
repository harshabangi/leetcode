//
// Created by Harsha Vardhan on 18/07/22.
//

#include <iostream>
#include <vector>

using namespace std;

void lexicalOrderHelper(int t, int n, vector<int> &ans) {
    if (t > n) return;
    ans.push_back(t);
    for (int i = 0; i <= 9; i++) {
        lexicalOrderHelper(t * 10 + i, n, ans);
    }
}

vector<int> lexicalOrder(int n) {
    vector<int> ans;
    for (int i = 1; i <= 9; i++) {
        vector<int> t;
        lexicalOrderHelper(i, n, t);
        for (int i = 0; i < t.size(); i++) {
            ans.push_back(t[i]);
        }
    }
    return ans;
}

int main() {
    vector<int> ans = lexicalOrder(13);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
