//
// Created by Harsha Vardhan on 12/06/22.
//

#include <iostream>
#include <vector>

using namespace std;

int getIndex(vector<int> &potions, int spell, long long success) {
    int i = 0, j = potions.size() - 1;
    while (i <= j) {
        int mid = (i + j) / 2;
        long long t = (long long) potions[mid] * (long long) spell;
        if (t >= success) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    return i;
}

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
    sort(potions.begin(), potions.end());
    vector<int> ans(spells.size());
    int n = potions.size();
    for (int i = 0; i < spells.size(); i++) {
        int index = getIndex(potions, spells[i], success);
        cout << index << " ";
        ans[i] = index >= n ? 0 : n - index;
    }
    cout << "\n";
    return ans;
}

int main() {
    vector<int> spells{3, 1, 2};
    vector<int> potions{8, 5, 8};
    long long success = 16;
    vector<int> ans = successfulPairs(spells, potions, success);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
