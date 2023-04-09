//
// Created by Harsha Vardhan on 15/05/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool checkValidStringHelper(string s, int idx, stack<char> st) {
    for (int i = idx; i < s.size(); i++) {
        if (s[i] == '*') {
            bool a = checkValidStringHelper(s, i + 1, st);
            s[i] = '(';
            bool b = checkValidStringHelper(s, i, st);
            s[i] = ')';
            bool c = checkValidStringHelper(s, i, st);
            return a || b || c;
        } else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        } else {
            st.push(s[i]);
        }
    }
    return st.empty();
}

bool checkValidString(string s) {
    int open = 0, closed = 0, special = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') open++;
        else if (s[i] == ')') closed++;
        else special++;
    }
    cout << open << ", " << closed << ", " << special << "\n";
    return 0;
}

int main() {
    cout << checkValidString(
            "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()")
         << "\n";
    return 0;
}
