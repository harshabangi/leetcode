//
// Created by Harsha Vardhan on 21/02/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int get_min_oper(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '(' && s[i] != ')') continue;
        else if (s[i] == '(') {
            st.push('(');
        } else {
            if (!st.empty() && st.top() == '(') st.pop();
            else st.push(')');
        }
    }
    return st.size();
}

void removeInvalidParenthesesHelper(string s, int k, vector<string> &ans, int idx) {
    if (k < 0) return;
    if (k == 0) {
        if (get_min_oper(s) == 0) {
            ans.push_back(s);
        }
        return;
    }
    for (int i = idx; i < s.size(); i++) {
        if (i != idx && s[i] == s[i - 1]) continue;
        string tmp = s.substr(0, i) + s.substr(i + 1);
        removeInvalidParenthesesHelper(tmp, k - 1, ans, i);
    }
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    removeInvalidParenthesesHelper(s, get_min_oper(s), ans, 0);
    return ans;
}

int main() {
    vector<string> ans = removeInvalidParentheses("((((()))))(((");
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
