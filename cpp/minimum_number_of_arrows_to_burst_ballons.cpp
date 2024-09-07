//
// Created by Harsha Vardhan on 06/08/22.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 (1, 6), (2, 8), (7, 12), (10, 16)

 (2, 6)

 (1, 2), (2, 3)

 (1, 2), (3, 4)

*/

int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end());
    vector<int> common = points[0];
    int ans = 0;
    for (int i = 1; i < points.size(); i++) {
        vector<int> t = points[i];
        if (t[0] <= common[1]) {
            common = vector<int>{t[0], min(common[1], t[1])};
        } else {
            ans++;
            common = points[i];
        }
    }
    return ans + 1;
}

int main() {
    // (1, 10), (3, 9), (4, 11), (6, 7), (6, 9), (8, 12), (9, 12)
    // (6, 7)
    vector<vector<int>> points{
            {9, 12},
            {1, 10},
            {4, 11},
            {8, 12},
            {3, 9},
            {6, 9},
            {6, 7}
    };
    cout << findMinArrowShots(points) << "\n";
    return 0;
}
