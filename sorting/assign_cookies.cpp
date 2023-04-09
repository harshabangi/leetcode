//
// Created by Harsha Vardhan on 06/10/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0, ans = 0;
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) {
            ans++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    return ans;
}

int main() {
    return 0;
}
