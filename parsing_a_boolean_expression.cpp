//
// Created by Harsha Vardhan on 27/01/22.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

char parseBoolExpr(string expression) {
    stack<char> st;
    vector<char> c;
    for (int i = expression.size() - 1; i >= 0; i--) {
        if (expression[i] == ',') continue;
        else if (expression[i] == '(') {
            while (!st.empty() && st.top() != ')') {
                c.push_back(st.top());
                st.pop();
            }
            st.pop();
        } else if (expression[i] == ')') {
            st.push(expression[i]);
        } else if (expression[i] == 't' || expression[i] == 'f') {
            st.push(expression[i]);
        } else {
            if (expression[i] == '!') {
                assert(c.size() == 1);
                if (c[0] == 't') st.push('f');
                else st.push('t');
            } else if (expression[i] == '|') {
                bool flag = true;
                for (int i = 0; i < c.size(); i++) {
                    if (c[i] == 't') {
                        st.push('t');
                        flag = false;
                        break;
                    }
                }
                if (flag) st.push('f');
            } else {
                bool flag = true;
                for (int i = 0; i < c.size(); i++) {
                    if (c[i] == 'f') {
                        st.push('f');
                        flag = false;
                        break;
                    }
                }
                if (flag) st.push('t');
            }
            c.clear();
        }
    }
    assert(st.size() == 1);
    cout << "TOP: " << st.top() << "\n";
    if (st.top() == 'f') return false;
    else return true;
}

int main() {
    cout << parseBoolExpr("|(&(t,f,t),!(t))") << "\n";
    return 0;
}