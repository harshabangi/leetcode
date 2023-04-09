//
// Created by Harsha Vardhan on 10/05/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool comparator(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), comparator);
    for (int i = 0; i < intervals.size(); i++) {
        cout << intervals[i][0] << ", " << intervals[i][1] << "\n";
    }
    stack<pair<int, int>> st;
    st.push(make_pair(intervals[0][0], intervals[0][1]));
    int count = 0;
    for (int i = 1; i < intervals.size(); i++) {
        pair<int, int> t = st.top();
        if (intervals[i][0] < t.second) {
            count++;
        } else {
            st.push(make_pair(intervals[i][0], intervals[i][1]));
        }
    }
    return count;
}

int main() {
    vector<vector<int>> intervals{
            {2, 1},
            {1, 3},

    };
    cout << eraseOverlapIntervals(intervals) << "\n";
    return 0;
}
