//
// Created by Harsha Vardhan on 15/05/22.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int toDigit(char c) {
    return c - '0';
}

int longestValidParentheses(string s) {
    int mx = 0;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < s.size(); i++) {
        int top = st.top();
        if (s[top] == '(' && s[i] == ')') {
            int newTop = st.top();
            st.pop();
            mx = max(mx, i - newTop);
        } else {
            st.push(i);
        }
    }
    return mx;
}

int main() {
    cout << longestValidParentheses("))((()()") << "\n";
    return 0;
}
