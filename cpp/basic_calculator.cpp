//
// Created by Harsha Vardhan on 29/01/22.
//

#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

int to_digit(char c) {
    return c - '0';
}

string helper(int &i, string &s) {
    string z;
    while (true) {
        if (s[i] == ' ') continue;
        if (!(s[i] >= '0' && s[i] <= '9')) {
            i -= 1;
            break;
        } else {
            z += s[i];
        }
        i++;
        cout << "HII\n";
    }
    return z;
}

int calculate(string s) {
    stack<string> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        else if (s[i] == '+') {
            i+=1;
            st.push(helper(i, s));
        } else if (s[i] == '-') {
            i+=1;
            st.push("-" + helper(i, s));
        } else if (s[i] == '(') {
            st.push(to_string(s[i]));
        } else if (s[i] == ')') {
            int k = 0;
            while (st.top() != "(") {
                string t = st.top();
                if (t[0] == '-') {
                    k += stoi(t.substr(1, t.size() - 1));
                } else {
                    k += stoi(t);
                }
                st.pop();
            }
            st.pop();
            st.push(to_string(k));
        } else {
            st.push(helper(i, s));
        }
    }

    int ans = 0;
    while (!st.empty()) {
        ans += stoi(st.top());
        st.pop();
    }
    return ans;
}

int main() {
    int index = 1;
    int lo = -~index;
    cout<< lo << "\n";
    return 0;
}