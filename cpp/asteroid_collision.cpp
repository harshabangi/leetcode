//
// Created by Harsha Vardhan on 15/10/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> st;

    for (int i = 0; i < asteroids.size(); i++) {
        if (st.empty()) {
            st.push(asteroids[i]);
        } else {
            if (st.top() > 0 && asteroids[i] < 0) {
                int l = abs(asteroids[i]);
                while (!st.empty() && (st.top() * asteroids[i] < 0) && st.top() < l) {
                    st.pop();
                }
                if (!st.empty() && (st.top() * asteroids[i] < 0) && (st.top() == l)) {
                    st.pop();
                } else if (!st.empty() && st.top() > l) {
                    //
                } else {
                    st.push(asteroids[i]);
                }
            } else {
                st.push(asteroids[i]);
            }
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> asteroids{-2, -2, 1, -2};
    vector<int> ans = asteroidCollision(asteroids);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
