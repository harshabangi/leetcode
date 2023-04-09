//
// Created by Harsha Vardhan on 31/12/21.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

string evaluate(string s, vector<vector<string>> &knowledge) {
    unordered_map<string, string> umap;
    for (int i = 0; i < knowledge.size(); i++) {
        umap[knowledge[i][0]] = knowledge[i][1];
    }
    bool flag = false;
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            flag = true;
        } else if (s[i] == ')') {
            string t = "";
            while (!st.empty()) {
                t += st.top();
                st.pop();
            }
            reverse(t.begin(), t.end());
            if (umap.find(t) != umap.end()) {
                ans += umap[t];
            } else {
                ans += "?";
            }
            flag = false;
        } else if (flag) {
            st.push(s[i]);
        } else {
            ans += s[i];
        }
    }
    return ans;
}

int main() {
    string s = "hi(name)";
    vector<vector<string>> knowledge = {{"a", "b"},
                                        {"age",  "two"}};
    cout << evaluate(s, knowledge);
}