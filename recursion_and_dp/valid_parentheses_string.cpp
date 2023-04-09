//
// Created by Harsha Vardhan on 28/08/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool checkValidStringHelper(string s, int idx, int count, vector<vector<int>> &dp) {
    if (idx >= s.size()) {
        if (count == 0) return true;
        else return false;
    }
    if (dp[idx][count] != -1) return dp[idx][count];
    bool ans = false;
    if (s[idx] == '(') {
        ans = checkValidStringHelper(s, idx + 1, count + 1, dp);
    } else if (s[idx] == ')') {
        if (count != 0) {
            ans = checkValidStringHelper(s, idx + 1, count - 1, dp);
        }
    } else {
        bool a = checkValidStringHelper(s, idx + 1, count + 1, dp);
        if (a) ans = true;
        else {
            bool c = checkValidStringHelper(s, idx + 1, count, dp);
            if (c) ans = true;
            else {
                if (count == 0) {
                    ans = false;
                } else {
                    bool b = checkValidStringHelper(s, idx + 1, count - 1, dp);
                    if (b) ans = true;
                }
            }
        }
    }
    return dp[idx][count] = ans;
}

bool checkValidString(string s) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
    return checkValidStringHelper(s, 0, 0, dp);
}

int main() {
    string s = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()";
    cout << checkValidString(s) << "\n";
    return 0;
}
