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

bool wordBreakHelper(vector<vector<int>> &dp, string &s, vector<string> &wordDict, int m, int n) {
    if (m == n) return true;
    if (dp[m][n] != -1) return dp[m][n];
    for (int i = 0; i < wordDict.size(); i++) {
        string t = wordDict[i];
        int size = t.size();
        if (m + size < n && equal(t.begin(), t.end(), s.begin() + m, s.begin() + m + size) &&
            wordBreakHelper(dp, s, wordDict, m + size, n))
            return dp[m][n] = 1;
    }
    return dp[m][n] = 0;
}


bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return wordBreakHelper(dp, s, wordDict, 0, n - 1);
}

int main() {
    /*
     * aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab
        ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
     * */
    string s = "aaaaaaaaaaab";
    vector<string> word_dict{"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa",
                             "aaaaaaaaaa"};
    bool ans = wordBreak(s, word_dict);
    cout << ans << "\n";
    return 0;
}
