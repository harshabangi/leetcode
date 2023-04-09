//
// Created by Harsha Vardhan on 13/05/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int minSwaps(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ']') {
            if (!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        } else {
            st.push(s[i]);
        }
    }
    int n = st.size();
    return n % 2 == 0 ? n / 2 : n / 2 + 1;
}

int main() {
    cout << minSwaps("][][") << "\n";
    return 0;
}
