//
// Created by Harsha Vardhan on 15/05/22.
//

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> weight, vector<int> val, int w, int n) {
    if (n == 0 || w == 0) return 0;
    if (weight[n - 1] <= w) {
        return val[n - 1] + max(
                solve(weight, val, w - weight[n - 1], n - 1),
                solve(weight, val, w, n - 1)
        );
    } else if (weight[n - 1] > w) {
        return solve(weight, val, w, n - 1);
    }
    return 0;
}

int knapSackRec(vector<int> val, vector<int> wt, int W, int idx) {
    if (W == 0) return 0;
    if (idx >= val.size()) return 0;
    int ans = 0;
    for (int i = idx; i < wt.size(); i++) {
        if (wt[i] <= W) {
            ans = max(ans, val[i] + knapSackRec(val, wt, W - wt[i], i + 1));
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> wt = {
            {23, 31, 29, 44, 53, 38, 63, 85, 89, 82},
            {4, 5, 6},
            {4, 5, 1},
            {41, 50, 49, 59, 55, 57, 60},
            {4, 5, 6},
            {4, 5, 1, 3, 2, 5}
    };
    vector<vector<int>> val{
            {92, 57, 49, 68, 60, 43, 67, 84, 87, 72},
            {1, 2, 3},
            {1, 2, 3},
            {442, 525, 511, 593, 546, 564, 617},
            {1, 2, 3},
            {2, 3, 1, 5, 4, 7}
    };

    vector<int> W{165, 3, 4, 170, 15, 15};
    vector<int> output{309, 0, 3, 1735, 6, 19};

    for (int i = 0; i < wt.size(); i++) {
        int t = knapSackRec(val[i], wt[i], W[i], 0);
        cout << t << "\n";
        assert(t == output[i]);
    }
    return 0;
}
