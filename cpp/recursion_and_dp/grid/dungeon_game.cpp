//
// Created by Harsha Vardhan on 04/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool underBoundary(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

int calculateMinimumHPHelper(vector<vector<int>> &dungeon, int i, int j, int m, int n) {
    if (i == m - 1 && j == n - 1) {
        return dungeon[i][j];
    }
    int ans = INT_MIN;
    if (underBoundary(i, j, m, n)) {
        int tmp = dungeon[i][j];
        if (dungeon[i][j] > 0) {
            tmp = 0;
        }
        ans = max(ans, tmp + calculateMinimumHPHelper(dungeon, i, j + 1, m, n));
        ans = max(ans, tmp + calculateMinimumHPHelper(dungeon, i + 1, j, m, n));
    }
    return ans;
}

int calculateMinimumHP(vector<vector<int>> &dungeon) {
    return calculateMinimumHPHelper(dungeon, 0, 0, dungeon.size(), dungeon[0].size());
}

int main() {
    vector<vector<int>> dungeon{
            {-2, -3,  3},
            {-5, -10, 1},
            {10, 30,  -5}
    };
    cout << calculateMinimumHP(dungeon) << "\n";
    return 0;
}
