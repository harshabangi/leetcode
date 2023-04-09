//
// Created by Harsha Vardhan on 11/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void letterCombinationsHelper(vector<string> inputs, int n, int idx1, string k, vector<string> &ans) {
    if (n == 0) {
        ans.push_back(k);
        return;
    }
    for (int i = 0; i < inputs[idx1].size(); i++) {
        letterCombinationsHelper(inputs, n - 1, idx1 + 1, k + inputs[idx1][i], ans);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.empty()) return ans;
    int n = digits.size();
    vector<string> inputs(n);
    for (int i = 0; i < n; i++) {
        if (digits[i] == '2') {
            inputs[i] = "abc";
        } else if (digits[i] == '3') {
            inputs[i] = "def";
        } else if (digits[i] == '4') {
            inputs[i] = "ghi";
        } else if (digits[i] == '5') {
            inputs[i] = "jkl";
        } else if (digits[i] == '6') {
            inputs[i] = "mno";
        } else if (digits[i] == '7') {
            inputs[i] = "pqrs";
        } else if (digits[i] == '8') {
            inputs[i] = "tuv";
        } else if (digits[i] == '9') {
            inputs[i] = "wxyz";
        }
    }
    letterCombinationsHelper(inputs, n, 0, "", ans);
    return ans;
}

int main() {
    vector<string> ans = letterCombinations("23");
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}