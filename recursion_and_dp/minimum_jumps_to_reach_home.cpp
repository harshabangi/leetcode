//
// Created by Harsha Vardhan on 13/05/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int minimumJumpsHelper(int a, int b, int x, unordered_set<int> &uset, int init, int bound, bool hasJumpedBackward) {
    if (init == x) return 0;
    int ans = 1e9;
    if (init > 0 && init <= bound && uset.find(init) != uset.end()) {
        ans = min(ans, 1 + minimumJumpsHelper(a, b, x, uset, init + a, bound, false));
        if (!hasJumpedBackward) {
            ans = min(ans, 1 + minimumJumpsHelper(a, b, x, uset, init - b, bound, true));
        }
    }
    return ans;
}

int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
    unordered_set<int> uset;
    for (int i = 0; i < forbidden.size(); i++) {
        uset.insert(forbidden[i]);
    }
    int bound = a + b + max(x, *max_element(forbidden.begin(), forbidden.end()));
    int mn = minimumJumpsHelper(a, b, x, uset, 0, bound, false);
    return mn >= 1e9 ? -1 : mn;
}

int main() {

    return 0;
}
