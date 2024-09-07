//
// Created by Harsha Vardhan on 01/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<char> VOWELS{'a', 'e', 'i', 'o', 'u'};

//void countVowelStringsHelper(int n, int idx, int &ans, string s) {
//    if (n == 0) {
//        ans += 1;
//        cout << s << "\n";
//        return;
//    }
//    for (int i = idx; i < 5; i++) {
//        countVowelStringsHelper(n - 1, i, ans, s + VOWELS[i]);
//    }
//}

int countVowelStringsHelper(vector<vector<int>> &dp, int n, int idx) {
    cout << n << ", " << idx << "\n";
    if (n == 0) {
        return 1;
    }
    if (dp[n][idx] != -1) {
        return dp[n][idx];
    }
    int ans = 0;
    for (int i = idx; i < 5; i++) {
        ans += countVowelStringsHelper(dp, n - 1, i);
    }
    return dp[n][idx] = ans;
}

int countVowelStrings(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(5, -1));
    int ans = countVowelStringsHelper(dp, n, 0);
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return ans;
}

int main() {
//    cout << countVowelStrings(1) << "\n";
//    cout << countVowelStrings(2) << "\n";
    cout << countVowelStrings(3) << "\n";
    return 0;
}
