//
// Created by Harsha Vardhan on 08/02/22.
//

#include <iostream>
#include <vector>

using namespace std;

void generateParenthesisHelper(string s, int o, int c, vector<string> &ans) {
    if (o == 0 && c == 0) {
        ans.push_back(s);
    } else if (o == c) {
        generateParenthesisHelper(s + "(", o - 1, c, ans);
    } else if (o == 0) {
        generateParenthesisHelper(s + ")", o, c - 1, ans);
    } else {
        generateParenthesisHelper(s + "(", o - 1, c, ans);
        generateParenthesisHelper(s + ")", o, c - 1, ans);
    }
}

vector<string> generateParenthesis2(int n) {
    vector<string> ans;
    generateParenthesisHelper("(", n - 1, n, ans);
    return ans;
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    generateParenthesisHelper("(", n - 1, n, ans);
    return ans;
}

int main() {
    vector<string> ans = generateParenthesis(4);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
