//
// Created by Harsha Vardhan on 03/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void letterCasePermutationHelper(string s, int idx, vector<string> &ans) {
    if (idx < s.size()) {
        if (isalpha(s[idx])) {
            string tmp = s;
            tmp[idx] = tolower(s[idx]);
            letterCasePermutationHelper(tmp, idx + 1, ans);
            tmp = s;
            tmp[idx] = toupper(s[idx]);
            letterCasePermutationHelper(tmp, idx + 1, ans);
        } else {
            letterCasePermutationHelper(s, idx + 1, ans);
        }
    } else {
        ans.push_back(s);
    }
}


int main() {
    vector<string> ans;
    letterCasePermutationHelper("a1b2", 0, ans);

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}