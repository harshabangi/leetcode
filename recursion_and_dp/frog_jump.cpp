//
// Created by Harsha Vardhan on 27/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

bool canCrossHelper(vector<int> &stones, int currPosition, int prevJump, unordered_map<int, int> &umap,
                    vector<vector<int>> &dp) {
    if (currPosition == stones.size() - 1) return true;
    if (currPosition >= stones.size()) return false;

    if (dp[currPosition][prevJump] != -1) return dp[currPosition][prevJump];
    vector<int> jumpsToMake{prevJump - 1, prevJump, prevJump + 1};

    bool ans = false;
    for (int g = 0; g < 3; g++) {
        if (jumpsToMake[g] > 0 && (umap.find(stones[currPosition] + jumpsToMake[g]) != umap.end())) {
            ans |= canCrossHelper(stones, umap[stones[currPosition] + jumpsToMake[g]], jumpsToMake[g], umap, dp);
        }
    }
    return dp[currPosition][prevJump] = ans;
}

bool canCross(vector<int> &stones) {
    unordered_map<int, int> umap;
    for (int i = 0; i < stones.size(); i++) {
        umap[stones[i]] = i;
    }
    vector<vector<int>> dp(stones.size() + 1, vector<int>(stones.size() + 1, -1));
    return canCrossHelper(stones, 0, 0, umap, dp);
}

int main() {
    vector<int> stones{0, 1, 3, 5, 6, 8, 12, 17};
    cout << canCross(stones) << "\n";
    return 0;
}
