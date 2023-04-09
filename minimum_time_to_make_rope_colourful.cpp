//
// Created by Harsha Vardhan on 27/05/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int minCost(string colors, vector<int> &neededTime) {
    stack<pair<char, int>> st;
    st.push(make_pair(colors[0], neededTime[0]));
    int f = 0;
    for (int i = 1; i < colors.size(); i++) {
        if (st.top().first != colors[i]) {
            int n = st.size(), mx = INT_MIN, ans = 0;
            while (!st.empty()) {
                pair<int, int> top = st.top();
                ans += top.second;
                mx = max(mx, top.second);
                st.pop();
            }
            if (n > 1) {
                f += (ans - mx);
            }
            st.push(make_pair(colors[i], neededTime[i]));
        } else {
            st.push(make_pair(colors[i], neededTime[i]));
        }
    }
    if (st.size() > 1) {
        int ans = 0, mx = INT_MIN;
        while (!st.empty()) {
            pair<int, int> top = st.top();
            ans += top.second;
            mx = max(mx, top.second);
            st.pop();
        }
        f += (ans - mx);
    }
    return f;
}

int minCost1(string colors, vector<int> &neededTime) {
    stack<pair<char, int>> st;
    int ans = 0;
    for (int i = 0; i < colors.size(); i++) {
        if (st.empty() || st.top().first != colors[i]) {
            st.push({colors[i], neededTime[i]});
        } else {
            if (neededTime[i] > st.top().second) {
                ans += st.top().second;
                st.pop();
                st.push({colors[i], neededTime[i]});
            } else {
                ans += neededTime[i];
            }
        }
    }
    return ans;
}

int main() {
    string colors = "abaac";
    vector<int> neededTime{1, 2, 3, 4, 5};
    cout << minCost1(colors, neededTime) << "\n";
    return 0;
}
