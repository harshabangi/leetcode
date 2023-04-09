//
// Created by Harsha Vardhan on 18/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool comparator(string &word1, string &word2) {
    if (word1.size() == word2.size()) return word1 < word2;
    else return word1.size() < word2.size();
}

bool isPredecessor(string &word1, string &word2) {
    int n1 = word1.size(), n2 = word2.size();
    if (n1 + 1 != n2) return false;
    int i = 0, j = 0, count = 0;
    while (i < n1 && j < n2) {
        if (word1[i] != word2[j]) {
            j++;
            count++;
        } else {
            i++;
            j++;
        }
    }
    if (count == 0 && j == n2 - 1) return true;
    return count == 1 && i == n1 && j == n2;
}

int longestStrChainHelper(vector<string> &words, int idx, vector<int> &dp) {
    int ans = 0;
    if (dp[idx] != -1) return dp[idx];
    for (int i = idx + 1; i < words.size(); i++) {
        if (isPredecessor(words[idx], words[i])) {
            ans = max(ans, 1 + longestStrChainHelper(words, i, dp));
        }
    }
    return dp[idx] = ans;
}

int longestStrChain(vector<string> &words) {
    int n = words.size();
    sort(words.begin(), words.end(), comparator);
    vector<int> dp(n + 1, -1);
    int ans = 0;
    for (int i = 0; i < words.size(); i++) {
        ans = max(ans, 1 + longestStrChainHelper(words, i, dp));
    }
    return ans;
}

int main() {
    vector<string> words{"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    cout << longestStrChain(words) << "\n";
    return 0;
}
