//
// Created by Harsha Vardhan on 18/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void print(vector<string> tmp) {
    for (int i = 0; i < tmp.size(); i++) {
        cout << tmp[i] << " ";
    }
    cout << "\n";
}

void wordBreakHelper(string s, vector<string> &wordDict, vector<string> &ans, vector<string> tmp, int idx) {
    if (idx == s.size()) {
        string z;
        for (int j = 0; j < tmp.size(); j++) {
            z += tmp[j];
            if (j != tmp.size() - 1) {
                z += " ";
            }
        }
        ans.push_back(z);
    }
    for (int i = 0; i < wordDict.size(); i++) {
        string m = wordDict[i];
        int c = 0;
        int idx_tmp = idx;
        for (int j = 0; j < m.size(); j++, idx_tmp++) {
            if (m[j] != s[idx_tmp]) {
                break;
            }
            c++;
        }
        if (c == m.size()) {
            tmp.push_back(m);
            wordBreakHelper(s, wordDict, ans, tmp, idx_tmp);
            tmp.pop_back();
        }
    }
}

vector<string> wordBreak(string s, vector<string> &wordDict) {
    vector<string> ans;
    vector<string> tmp;
    wordBreakHelper(s, wordDict, ans, tmp, 0);
    return ans;
}

int main() {
    string s = "catsandog";
    vector<string> word_dict{"cats", "dog", "sand", "and", "cat"};
    vector<string> ans = wordBreak(s, word_dict);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << "";
        }
        cout << "\n";
    }
    return 0;
}
