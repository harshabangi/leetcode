//
// Created by Harsha Vardhan on 21/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool is_palindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i <= j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

void partitionHelper(string s, vector<string> tmp, vector<vector<string>> &ans) {
    if (s.empty()) {
        ans.push_back(tmp);
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        string left_part = s.substr(0, i + 1);
        if (is_palindrome(left_part)) {
            tmp.push_back(left_part);
            partitionHelper(s.substr(i+1), tmp, ans);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> tmp;
    partitionHelper(s, tmp, ans);
    return ans;
}

int main() {
    vector<vector<string>> ans = partition("aaab");
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
