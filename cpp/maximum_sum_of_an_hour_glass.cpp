//
// Created by Harsha Vardhan on 05/10/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxSum(vector<vector<int>> &grid) {
    int ans = INT_MIN;
    for (int i = 0; i < grid.size() - 2; i++) {
        for (int j = 0; j < grid[i].size()-2; j++) {
            int l = 0;
            l += grid[i][j] + grid[i][j+1] + grid[i][j+2];
            l += grid[i+1][j+1];
            l += grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

            ans = max(ans, l);
        }
    }
    return ans;
}

int main() {
    return 0;
}
