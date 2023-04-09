//
// Created by Harsha Vardhan on 31/07/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct comparator {
    bool operator()(const vector<int> &a, const vector<int> &b) {
        if (a[1] == b[1]) {
            return a[2] < b[2];
        } else {
            return a[1] < b[1];
        }
    }
};

bool carPooling(vector<vector<int>> &trips, int capacity) {
    int start = INT_MAX, end = INT_MIN;
    unordered_map<int, int> onboard, offboard;

    for (int i = 0; i < trips.size(); i++) {
        start = min(start, trips[i][1]);
        end = max(end, trips[i][2]);
        onboard[trips[i][1]] += trips[i][0];
        offboard[trips[i][2]] += trips[i][0];
    }

    for (int i = start; i <= end; i++) {
        if (offboard.find(i) != offboard.end()) {
            capacity += offboard[i];
        }
        if (onboard.find(i) != onboard.end()) {
            capacity -= onboard[i];
        }
        if (capacity < 0) return false;
    }
    return true;
}

int main() {
    vector<vector<int>> trips{
            {2, 1, 5},
            {3, 5, 7}
    };
    cout << carPooling(trips, 3) << endl;
    return 0;
}
