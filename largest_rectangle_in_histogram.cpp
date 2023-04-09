//
// Created by Harsha Vardhan on 19/06/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> leftSmall(n), rightSmall(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[i] <= heights[st.top()]) {
            st.pop();
        }
        leftSmall[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[i] <= heights[st.top()]) {
            st.pop();
        }
        rightSmall[i] = st.empty() ? n - 1 : st.top() - 1;
        st.push(i);
    }
    int mx = INT_MIN;

    for (int i = 0; i < heights.size(); i++) {
        mx = max(mx, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
    }
    return mx;
}

int main() {
    vector<int> heights{2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights) << "\n";
    return 0;
}
