//
// Created by Harsha Vardhan on 27/05/22.
//

#include <iostream>
#include <vector>

using namespace std;


int minStepsHelper(int n, bool canCopy, int copiedChars, int screenChars) {
    if (screenChars > n) return INT_MAX;
    if (screenChars == n) return 0;
    int ans = INT_MAX;
    if (canCopy) {
        int z = minStepsHelper(n, false, screenChars, screenChars);
        if (z < INT_MAX) {
            ans = min(ans, 1 + z);
        }
    } else {
        int p = minStepsHelper(n, false, copiedChars, copiedChars + screenChars);
        if (p < INT_MAX) {
            ans = min(1 + p, ans);
        }
        int q = minStepsHelper(n, true, copiedChars, copiedChars + screenChars);
        if (q < INT_MAX) {
            ans = min(1 + q, ans);
        }
    }
    return ans;
}

int minSteps(int n) {
    return minStepsHelper(n, true, 0, 1);
}

int main() {
    cout << minSteps(9) << "\n";
    return 0;
}
